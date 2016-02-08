/*
MAIN FUNCTION WRITTEN BY HITESH JHURANI
*/

#include "List.h"
#include "Cell.h"
#include "Node.h"
#include "NumericCell.h"
#include "StringCell.h"
#include "Functioncell.h"
#include <iostream>
#include<sstream>
#include<exception>
int main(int argc, char** argv)
{
	int htmp = 0, wtmp = 0;
	int height;
	int width;
	std::string x;

	//TESTS IF THE NUMBER OF INPUTS ARE VALID 
	if (argc != 3)
	{
		return 1;
	}

	//TEST IF THE INPUT IS A NUMBER OR STRING
	try
	{
		width = std::stoi(std::string(argv[1]));
		height = std::stoi(std::string(argv[2]));
	}

	catch (std::exception e)
	{
		std::cout << "Got wrong values";
		return 1;
	}


	//TEST IF THE INPUT IS NEGATIVE
	if (width < 0 || height < 0)
	{
		std::cout << "Cell dimensions cant be negative \n ";
		return 1;
	}

	//TEST IF THE INPUT IS ZERO
	if (width == 0 || height == 0)
	{
		std::cout << "Cannot enter value as zero";
		return 1;
	}


	LList<LList<Cell*>> rows;

	for (int i = 0; i < height; ++i) {
		LList<Cell*> empty;
		rows.push_back(empty);
		Cell cellobj();
		//Make a new empty cell in this row for every column
		for (int j = 0; j < width; ++j) {
			//The back() operator returns a reference to the last element in the list
			rows.back().push_back(new Cell());
		}
	}

	while (std::getline(std::cin, x))
	{
		htmp = 0;
		std::istringstream ss(x);
		std::string input;
		ss >> input;

		if (input == "set")
		{
			int column, row;
			//Returns true if we can read two numbers, false if this fails
			if (ss >> column >> row)
			{
				if ((column + 1)>width || (row + 1) > height)
				{
					std::cout << "Error: cell out of range\n";
				}
				else
				{
					for (LList<LList<Cell*>>::iterator I = rows.begin(); I != rows.end(); I++)
					{
						htmp++;
						wtmp = 0;
						for (LList<Cell*>::iterator J = (*I).begin(); J != (*I).end(); J++)
						{
							wtmp++;

							if (htmp == row + 1 && wtmp == column + 1)
							{
								std::string type;
								ss >> type;
								if (type == "number")//CHECK IF THE TYPE IS NUMBER
								{

									double value;
									if (ss >> value) //CHECK FOR VALID INPUT
									{
										delete *J;
										*J = new NumericClass(value);
										for (LList<LList<Cell*>>::iterator M = rows.begin(); M != rows.end(); M++)
										{
											for (LList<Cell*>::iterator N = (*M).begin(); N != (*I).end(); N++)
											{
												if (dynamic_cast<Functioncell*>(*N) != NULL)
												{
													dynamic_cast<Functioncell*>(*N)->update();
												}
											}
										}
									}
									else
									{
										std::cout << "Error: Bad input for set number\n";
									}
								}
								else if (type == "string")//CHECK IF TYPE IS STRING
								{

									std::string value, final;
									int chk = 0;
									while (ss >> value)
										if (chk == 0)
										{
										chk++;
										final = final + value;
										}
										else
											final = final + " " + value;
									delete *J;
									*J = new SCell(final);

								}

								else if (type == "mean" || type == "min" || type == "max")//CHECK IF TYPE IS MEAN MIN MAX
								{
									LList<LList<Cell*>> *spreadsheet;
									spreadsheet = &rows;
									int rownum, start, end;
									if (ss >> rownum >> start >> end)
									{
										*J = new Functioncell(row, column, rownum, start, end, type, spreadsheet);
									}

								}
							}
						}
					}
				}
			}

		}
		else if (input == "quit")// COMMAND TO QUIT
		{
			std::cout << "Count = " <<Cell::count;
			for (LList<LList<Cell*>>::iterator I = rows.begin(); I != rows.end(); I++)
			{
				for (LList < Cell*>::iterator J = (*I).begin(); J != (*I).end(); J++)
				{
					delete *J;
					std::cout << "Count value" << Cell::count;
				}
			}

			return 0;
		}
		else if (input == "addrow")//COMMAND TO ADDROW
		{

			std::string row_a;
			ss >> row_a;
			try
			{
				int row = std::stoi(std::string(row_a));
				int h = 0;
				LList<Cell*> empty;
				if (row<0 || row>height)
				{
					std::cout << "Error: row out of range\n";
				}
				else{
					for (LList<LList<Cell*>>::iterator I = rows.begin(); I != rows.end(); I++)
					{
						if (h == row)
						{
							for (LList<Cell*>::iterator J = (*I).begin(); J != (*I).end(); J++)
							{
								//COMMAND TO INSERT THE ROW
								I = rows.insert(I, empty, row);
								for (int k = 0; k < width; k++)
								{
									(*I).push_back(new Cell());
									height++;
								}
								break;
							}
						}
						h++;
					}
				}
			}
			catch (std::exception e){
				std::cout << "Error: row out of range\n";
			}

		}

		else if (input == "removerow") //COMMAND TO REMOVEROW
		{
			std::string row_r;
			ss >> row_r;

			try
			{
				int row = std::stoi(std::string(row_r));
				LList<LList<Cell*> >::iterator I = rows.begin();
				int h = 0;
				LList<Cell*> empty;
				if (row<0 || row>height)
				{
					std::cout << "Error: row out of range\n";
				}
				else{
					for (LList<LList<Cell*>>::iterator I = rows.begin(); I != rows.end(); I++)
					{
						if (h == row)
						{

							LList<LList<Cell*> >::iterator K = nullptr;
							LList<LList<Cell*> >::iterator L = nullptr;
							//CALLING ERASE FUNCTION FROM THE LIST CLASS
							L = rows.erase(I, row);
							height--;
							break;

						}
						h++;
					}
				}
			}
			catch (std::exception e){
				std::cout << "Error: row out of range\n";
			}
		}




		else if (input == "print")
		{
			//PRINTING THE LINKED LIST
			for (LList<LList<Cell*>>::iterator M = rows.begin(); M != rows.end(); M++)
			{
				for (LList<Cell*>::iterator N = (*M).begin(); N != (*M).end(); N++)
				{
					if (dynamic_cast<Functioncell*>(*N) != NULL)
					{
						dynamic_cast<Functioncell*>(*N)->update();
					}
				}
			}

			for (LList<LList<Cell*>>::iterator I = rows.begin(); I != rows.end(); I++)
			{
				for (LList<Cell*>::iterator J = (*I).begin(); J != (*I).end(); J++)
				{

					if (*J == (*I).back())
					{
						std::cout << (**J).toString();
					}
					else
					{
						std::cout << (**J).toString() << ",";
					}
				}
				std::cout << "\n";
			}
		}

		else
		{
			std::cout << "Error: unknown command\n";

		}




	}

}
