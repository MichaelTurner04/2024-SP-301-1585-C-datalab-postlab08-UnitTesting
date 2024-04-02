default: average

main: main.o 
	g++ ${CFLAGS} main.o -o main
main.o: main.cpp list.h list.hpp
	g++ ${CFLAGS} -c main.cpp


coverage: test
	gcov -mr test_vector.cpp

test: CFLAGS=--coverage

test: testsuite
	@./testsuite

testsuite: test_main.o
	g++ ${CFLAGS} $^ -o testsuite

test_main.o: test_main.cpp
	g++ -O3 -c test_main.cpp

cleancoverage:
	-@rm -f *.gcov *.gcno *.gcda

clean: cleancoverage
	-@rm -f *.o
	-@rm -f testsuite
	-@rm -f average