#include "LetStatement.h"
using namespace std;

LetStatement::LetStatement(std::string variableName, int value)
	: m_variableName( variableName ), m_value( value )
{}


// The LetStatement version of execute() should make two changes to the
// state of the program:
//
//    * set the value of the appropriate variable
//    * increment the program counter
void LetStatement::execute(ProgramState * state, ostream &outf)
{
	if (state->SearchInMap(m_variableName) == false)
	{
		state->AddToMap(m_variableName, m_value);
	}
	else
	{
		state->OverrideInMap(m_variableName, m_value);
	}

	state->incrementCounter();

}

// Change the value of variable *var* to the integer *int*