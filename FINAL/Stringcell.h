/*
  STRINGCELL BY HITESH JHURANI
  */

#ifndef __STRINGCELL_H__
#define __STRINGCELL_H__
#include "Cell.h"

class SCell : public Cell
{
private:
	std::string x;
public:
	std::string toString();
	SCell(std::string value)
	{
		x = value;
	}
	~SCell(){}
};

#endif