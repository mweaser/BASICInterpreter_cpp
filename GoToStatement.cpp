
#include "GoToStatement.h"
#include "ProgramState.h"
using namespace std;

GoToStatement::GoToStatement(int LineNum)
{
	m_value = LineNum;
}

void GoToStatement::execute(ProgramState * state, ostream &outf)
{
	state->jumpToLine(m_value);
}

// Jumps execution of the program to the line numbered *linenum*
