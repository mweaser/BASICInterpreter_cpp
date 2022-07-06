#include "PrintAllStatement.h"
#include "ProgramState.h"
using namespace std;

PrintAllStatement::PrintAllStatement()
{
	
}

void PrintAllStatement::execute(ProgramState * state, ostream &outf)
{

	state->PrintWholeMap(outf);
	state->incrementCounter();
}

// Prints the value of all used variables to output, one per line.