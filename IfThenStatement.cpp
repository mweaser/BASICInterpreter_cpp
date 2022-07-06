
#include "IfThenStatement.h"
#include "ProgramState.h"
using namespace std;

IfThenStatement::IfThenStatement(string variableName, string op, int value, int value2)
{
    m_variableName = variableName;
    m_op = op;
	m_value = value;
    m_value2 = value2;

}

void IfThenStatement::execute(ProgramState * state, ostream &outf)
{
	if (m_op == "<")
    {
        if (state->GetFromMap(m_variableName) < m_value)
        {
            state->jumpToLine(m_value2);
        }
        else
        {
            state->incrementCounter();
        }
    }

    else if (m_op == "<=")
    {
        if (state->GetFromMap(m_variableName) <= m_value)
        {
            state->jumpToLine(m_value2);
        }
        else
        {
            state->incrementCounter();
        }
    }

    else if (m_op == ">")
    {
        if (state->GetFromMap(m_variableName) > m_value)
        {
            state->jumpToLine(m_value2);
        }
        else
        {
            state->incrementCounter();
        }
    }

    else if (m_op == ">=")
    {
        if (state->GetFromMap(m_variableName) >= m_value)
        {
            state->jumpToLine(m_value2);
        }
        else
        {
            state->incrementCounter();
        }
    }

    else if (m_op == "=")
    {
        if (state->GetFromMap(m_variableName) == m_value)
        {
            state->jumpToLine(m_value2);
        }
        else
        {
            state->incrementCounter();
        }
    }
    
}

// Compares the value of the variable *var* to the integer *int*
// *int* THEN via the operator *op* (<, <=, >, >=, =, <>), and jumps
// *linenum* execution of the program to line *linenum* if true.
