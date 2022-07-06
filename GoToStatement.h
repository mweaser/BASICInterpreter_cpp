#ifndef GOTO_STATEMENT_INCLUDED
#define GOTO_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"

class GoToStatement: public Statement
{
private:
	std::string m_variableName;
	int m_value;


public:
	GoToStatement(int LineNum);
	
	virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif
