sorting_tests: main.o sorting.o
	g++ -o sorting_tests main.o sorting.o

main.o: main.cpp sorting.h
	g++ -c main.cpp

sorting.o: sorting.cpp sorting.h
	g++ -c sorting.cpp

clean:
	rm -f *.o sorting_tests
