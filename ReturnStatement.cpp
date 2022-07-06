#include "ReturnStatement.h"
#include "ProgramState.h"
using namespace std;

ReturnStatement::ReturnStatement()
{
}

void ReturnStatement::execute(ProgramState * state, ostream &outf)
{
	state->jumpToLine(state->stk.top());

    state->stk.pop();
}
