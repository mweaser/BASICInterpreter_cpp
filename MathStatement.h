#ifndef MATH_STATEMENT_INCLUDED
#define MATH_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"

class MathStatement: public Statement
{
private:
	std::string m_variableName;
	std::string m_variableName2;
	int m_value;
	std::string m_arithmeticType;

	

public:
	MathStatement(std::string variableName, int value, std::string arithmeticType);

	MathStatement(std::string variableName1, std::string variableName2, std::string arithmeticType);
	
	virtual void execute(ProgramState * state, std::ostream &outf);

	bool isInt;
};

#endif
