#ifndef PRINTALL_STATEMENT_INCLUDED
#define PRINTALL_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"

class PrintAllStatement: public Statement
{
private:
	std::string m_variableName;
	int m_value;


public:
	PrintAllStatement();
	
	virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif
