#include "GoSubStatement.h"
#include "ProgramState.h"
using namespace std;

GoSubStatement::GoSubStatement(int LineNum)
{
	m_value = LineNum;
}


void GoSubStatement::execute(ProgramState * state, ostream &outf)
{
	state->stk.push(state->getProgramCounter()+1);
	state->jumpToLine(m_value);
}

// GoSub temporarily jumps to line *linenum*, and jumps back after a RETURN

