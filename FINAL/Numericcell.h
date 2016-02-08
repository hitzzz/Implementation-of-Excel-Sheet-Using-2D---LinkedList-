/*
NUMERICCLASS WRITTEN BY HITESH JHURANI
*/

#ifndef __NUMERICLASS_H__
#define __NUMERICLASS_H__
#include<iostream>
#include<string>
#include"Cell.h"


class NumericClass : public Cell
{
protected:
	double val;
public:
	std::string toString();
	NumericClass(double value)
	{
		val = value;
	}
	double getvalue();

	~NumericClass(){}
};
#endif
