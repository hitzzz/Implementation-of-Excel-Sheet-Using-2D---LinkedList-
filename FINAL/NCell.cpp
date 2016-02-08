#include"NumericCell.h"
#include<iostream>
#include<string>
std::string NumericClass::toString()
{
	return std::to_string(val);
}

double NumericClass::getvalue()
{
	return val;
}