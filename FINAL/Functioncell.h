/*
FUNCTION CELL CLASS DEFINATION WRITTEN BY HITESH JHURANI
*/
#ifndef __FUNCTIONCELL_H__
#define __FUNCTIONCELL_H__

#include<iostream>
#include<string>
#include"Cell.h"
#include"NumericCell.h"
#include"Node.h"
#include"List.h"



class Functioncell : public NumericClass
{
private:
	double value;
	int start, end, rownum, frow, fcol;
	LList<LList<Cell*>> *x;
	std::string otype;
public:
	void mean();
	void min();
	void max();
	void update();
	//FUNCTION CELL CONSTRUCTOR TO INTIALIZE THE VALUES
	Functioncell(int rowl, int columnl, int row_number, int cstart, int cend, std::string type, LList<LList<Cell*>> *y) :NumericClass(value)
	{
		frow = rowl;
		fcol = columnl;
		otype = type;
		start = cstart;
		end = cend;
		x = y;
		rownum = row_number;

		//CALLING FUNCTIONS DEPENDING UPON THE TYPE OF OPERATION
		if (otype == "mean")
		{
			mean();
		}
		else if (otype == "min")
		{
			min();
		}
		else if (otype == "max")
		{
			max();
		}

	}
	~Functioncell(){}
};
#endif