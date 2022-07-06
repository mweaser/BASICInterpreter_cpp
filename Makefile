all: interpreter

interpreter: interpreter.cpp
	g++ -g -Wall interpreter.cpp LetStatement.cpp PrintStatement.cpp EndStatement.cpp ProgramState.cpp PrintAllStatement.cpp MathStatement.cpp Math2Statement.cpp GoToStatement.cpp GoSubStatement.cpp ReturnStatement.cpp IfThenStatement.cpp -o interpreter

clean:
	rm -f *.o interpreter