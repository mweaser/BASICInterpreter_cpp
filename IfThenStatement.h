#ifndef IFTHEN_STATEMENT_INCLUDED
#define IFTHEN_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"

class IfThenStatement: public Statement
{
private:
	std::string m_variableName;
    std::string m_op;
	int m_value;
    int m_value2;

public:
	IfThenStatement(string variableName, string op, int value, int value2);
	
	virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif
