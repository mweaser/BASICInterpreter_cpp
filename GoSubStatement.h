#ifndef GOSUB_STATEMENT_INCLUDED
#define GOSUB_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"

class GoSubStatement: public Statement
{
private:
	std::string m_variableName;
	int m_value;


public:
	GoSubStatement(int LineNum);
	
	virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif
