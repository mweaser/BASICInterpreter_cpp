#ifndef RETURN_STATEMENT_INCLUDED
#define RETURN_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"

class ReturnStatement: public Statement
{
private:
	std::string m_variableName;
	int m_value;


public:
	ReturnStatement();
	
	virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif
