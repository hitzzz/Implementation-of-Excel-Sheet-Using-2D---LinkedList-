#include<iostream>
#include<string>
#include<limits>
#include"Functioncell.h"


//MEAN OPERATION
void Functioncell::mean()

{
	int tempr = 0;
	int tempc = 0;
	int numcellcount = 0;
	double sum = 0.0;
	int qnan = 0;
	double mean = 0.0;

	for (LList<LList<Cell*>>::iterator I = (*x).begin(); I != (*x).end(); I++)
	{
		tempc = 0;
		for (LList<Cell*>::iterator J = (*I).begin(); J != (*I).end(); J++)
		{
			if (tempr == rownum && (tempc == start || tempc <= end))
			{
				if (dynamic_cast<NumericClass*>(*J) != NULL)
				{
					sum = sum + dynamic_cast<NumericClass*>(*J)->getvalue();
					std::cout << "sum =" << sum;
					numcellcount++;
					qnan = 1;
				}
			}
			tempc++;
		}
		tempr++;
	}

	mean = sum / (numcellcount);
	//TESTING FOR QNAN
	if (qnan)
	{
		NumericClass::val = mean;
	}
	if (!qnan)
	{
		double m = std::numeric_limits<double>::quiet_NaN();
		NumericClass::val = m;
	}
	tempr = 0;
	tempc = 0;
};

//MINIMUM OPERATION
void Functioncell::min()
{
	int tempr = 0;
	int tempc = 0;
	int numcellcount = 0;
	double sum = 0.0;
	int qnan = 0;
	int chk = 0;
	double tempm, min;

	for (LList<LList<Cell*>>::iterator I = (*x).begin(); I != (*x).end(); I++)
	{
		tempc = 0;
		for (LList<Cell*>::iterator J = (*I).begin(); J != (*I).end(); J++)
		{
			if (tempr == rownum && (tempc >= start))
			{
				if (tempc <= end)
				{
					if (dynamic_cast<NumericClass*>(*J) != NULL)
					{
						qnan = 1;
						tempm = dynamic_cast<NumericClass*>(*J)->getvalue();
						if (chk == 0)
						{
							min = tempm;
							chk++;
						}

						else if (min > tempm)
						{
							min = tempm;
						}
					}
				}
			}
			tempc++;
		}
		tempr++;
	}
	//TESTING FOR QNAN
	if (qnan)
	{
		NumericClass::val = min;
	}
	else if (!qnan)
	{
		double m = std::numeric_limits<double>::quiet_NaN();

		NumericClass::val = m;
	}
	tempc = 0;
	tempr = 0;

};

//MAXIMUM FUNCTION
void Functioncell::max()
{
	int tempr = 0;
	int tempc = 0;
	int numcellcount = 0;
	double sum = 0.0;
	int qnan = 0, flag = 1;
	double mean;
	double tempm, m;

	for (LList<LList<Cell*>>::iterator I = (*x).begin(); I != (*x).end(); I++)
	{
		tempc = 0;
		for (LList<Cell*>::iterator J = (*I).begin(); J != (*I).end(); J++)
		{
			if (tempr == rownum && tempc >= start)
			{
				if (tempc <= end)
				{
					if (dynamic_cast<NumericClass*>(*J) != NULL)
					{
						qnan = 1;
						tempm = dynamic_cast<NumericClass*>(*J)->getvalue();
						if (flag)
						{
							m = tempm;
							flag = 0;
						}

						else if (m < tempm)
						{
							m = tempm;
						}
					}
				}
			}
			tempc++;
		}
		tempr++;
	}

	tempc = 0;
	tempr = 0;
	NumericClass::val = m;
};

//UPDATE FUNCTION
void Functioncell::update()
{
	if (otype == "max")
	{

		Functioncell::max();
	}
	if (otype == "min")
	{

		Functioncell::min();
	}
	if (otype == "mean")
	{
		Functioncell::mean();
	}
};