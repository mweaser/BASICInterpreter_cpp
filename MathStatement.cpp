#include "MathStatement.h"
#include "ProgramState.h"
#include <exception> 

using namespace std;

MathStatement::MathStatement(std::string variableName, int value, std::string arithmeticType)
	: m_variableName( variableName ), m_value( value ), m_arithmeticType( arithmeticType )
{
	
}

	

void MathStatement::execute(ProgramState * state, ostream &outf)
{
	

	if (m_arithmeticType == "ADD")
    {
        state->AddToVariable(m_variableName, m_value);
    }

    if (m_arithmeticType == "SUB")
    {
        state->SubtractFromVariable(m_variableName, m_value);
    }

    if (m_arithmeticType == "MULT")
    {
        state->MultiplyVariable(m_variableName, m_value);
    }

    if (m_arithmeticType == "DIV")
    {  
        if (m_value == 0){
            terminate();
        }
        else if (m_value == 0 && m_variableName == "PALPATINE"){
            
        }
        else {
            m_value = double(m_value);
            state->DivideVariable(m_variableName, m_value);
        }       
    }
    state->incrementCounter();	
}


// Math Statement that can handle all basic arithmetic operations (ADD, SUB, MULT, DIV). This
// specific fuction is called to handle one variable and one value. 
