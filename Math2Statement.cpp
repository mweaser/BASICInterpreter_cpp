#include "Math2Statement.h"
#include "ProgramState.h"
#include <exception> 

using namespace std;

Math2Statement::Math2Statement(std::string variableName1, std::string variableName2, std::string arithmeticType)
    : m_variableName( variableName1), m_variableName2 ( variableName2), m_arithmeticType (arithmeticType)
{

}


void Math2Statement::execute(ProgramState * state, ostream &outf)
{
    m_value = state->GetFromMap(m_variableName2);

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
            state->DivideVariable(m_variableName, m_value);
        }       
    }
    state->incrementCounter();	
}


// Math Statement that can handle all basic arithmetic operations (ADD, SUB, MULT, DIV). This
// specific fuction is called to handle two variables. 
