#include "Statement.h"
#include "LetStatement.h"
#include "PrintStatement.h"
#include "EndStatement.h"
#include "ProgramState.h"
#include "PrintAllStatement.h"
#include "MathStatement.h"
#include "Math2Statement.h"
#include "GoToStatement.h"
#include "GoSubStatement.h"
#include "ReturnStatement.h"
#include "IfThenStatement.h"
#include <vector>
#include <string>
#include <sstream> 
#include <fstream>
#include <cstdlib>
#include <typeinfo>

// take out
#include <iostream>
using namespace std;

void parseProgram(istream& inf, vector<Statement *> & program);

Statement * parseLine(string line);

void interpretProgram(istream& inf, ostream& outf);


int main()
{
        cout << "Enter BASIC program file name: ";
        string filename;
        getline(cin, filename);
        ifstream infile(filename.c_str());
        if (!infile)
        {
                cout << "Cannot open " << filename << "!" << endl;
                return 1;
        }
        interpretProgram(infile, cout);
}



void parseProgram(istream &inf, vector<Statement *> & program)
{
	program.push_back(NULL);
	
	string line;
	while( ! inf.eof() )
	{
		getline(inf, line);
		program.push_back( parseLine( line ) );
	}
}


Statement * parseLine(string line)
{
	Statement * statement;	
	stringstream ss;
	string lineNum;
	string var;
	string type;
	int val;
	int val2;
	string var2;
	string op;
	string then;
	

	ss << line;
	ss >> lineNum;
	ss >> type;
	
	if ( type == "LET" )
	{
		ss >> var;
		ss >> val;
		// Note:  Because the project spec states that we can assume the file
		//	  contains a syntactically legal program, we know that
		//	  any line that begins with "LET" will be followed by a space
		//	  and then a variable and then an integer value.
		statement = new LetStatement(var, val);
	}

	else if (type == "PRINT")
	{
		ss >> var;

		statement = new PrintStatement(var);
	}

	else if (type == "PRINTALL")
	{
		statement = new PrintAllStatement();
	}
	
	else if (type == "ADD" || type == "SUB" || type == "MULT" || type == "DIV"){
		ss >> var;
		ss >> var2;
		if (isdigit(var2[0]) == true)
		{
			val = stoi(var2);
			statement = new MathStatement(var, val, type);
		}
		else
		{
			statement = new Math2Statement(var, var2, type);
		}
	}

	else if (type == "GOTO"){
		ss >> val;
		statement = new GoToStatement(val);
	}

	else if (type == "GOSUB"){
		ss >> val;
		statement = new GoSubStatement(val);
	}

	else if (type == "RETURN"){
		statement = new ReturnStatement();
	}

	else if (type == "IF"){
		ss >> var;
		ss >> op;
		ss >> val;
		ss >> then;
		ss >> val2;

		statement = new IfThenStatement(var, op, val, val2);

	}


	else if (type == "END" || type == ".")
	{
		statement = new EndStatement();
	}


		
	return statement;
}


void interpretProgram(istream& inf, ostream& outf)
{
	vector<Statement *> program;
	parseProgram( inf, program );

		
	ProgramState* state = new ProgramState(program.size());

	int programIterator = 1;

	while (state->isProgramTerminated() == false){
		program[programIterator]->execute(state, outf);
		programIterator = state->getProgramCounter();
	}

}




