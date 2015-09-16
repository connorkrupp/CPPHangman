app : main.cpp compile
			./Hangman
			rm -vf Hangman *~ *.out

build : main.cpp compile

compile : main.cpp
					g++ -Wall -Werror -pedantic -O1 main.cpp -o Hangman

clean :
					rm -vf Hangman *~ *.out
