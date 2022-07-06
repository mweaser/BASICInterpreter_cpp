#include "PrintStatement.h"

PrintStatement::PrintStatement(std::string variableName)
	: m_variableName( variableName )
{}


void PrintStatement::execute(ProgramState * state, std::ostream &outf)
{
	if (state->SearchInMap(m_variableName) == false)
	{
		state->AddToMap(m_variableName, 0);
	}
	outf << state->GetFromMap(m_variableName) << endl;

	state->incrementCounter();
}

// Print the value of variable *var* to output