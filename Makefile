app : main.cpp
			g++ -Wall -Werror -pedantic -O1 main.cpp -o app
			./app
			rm -vf app *~ *.out
