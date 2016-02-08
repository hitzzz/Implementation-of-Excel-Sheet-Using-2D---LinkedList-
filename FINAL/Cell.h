/*
  CELLCLASS WRITTEN BY HITESH JHURANI
  */

#ifndef __CELL_H__
#define __CELL_H__
#include<iostream>
#include<string>
class Cell
{
public:
	static unsigned count;
	virtual std::string toString();
	
	Cell()
	{
		count++;
	}
 
	~Cell()
	{
		count--;
	}
};

#endif