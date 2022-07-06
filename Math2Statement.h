#ifndef MATH2_STATEMENT_INCLUDED
#define MATH2_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"

class Math2Statement: public Statement
{
private:
	std::string m_variableName;
	std::string m_variableName2;
	int m_value;
	std::string m_arithmeticType;

	

public:

	Math2Statement(std::string variableName1, std::string variableName2, std::string arithmeticType);
	
	virtual void execute(ProgramState * state, std::ostream &outf);

};

#endif
