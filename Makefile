all: romanos.o testa_romanos.cpp
	python cpplint.py *.*
	g++ -std=c++11 -Wall -fprofile-arcs -ftest-coverage -g romanos.o testa_romanos.cpp -o testa_romanos
	cppcheck --enable=warning .
	./testa_romanos
	gcov *.cpp	
	valgrind --leak-check=yes --log-file=valgrind.rpt testa_romanos
	#use comentario se necessario 


romanos.o : romanos.cpp romanos.hpp
	g++ -std=c++11 -Wall  -c romanos.cpp
	
	

clean:
	rm -rf *.o *.exe
	
	
