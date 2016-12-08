FLAGS = -Wall

all: myDriver.o Pinball.o
	g++ $(FLAGS) myDriver.o Pinball.o  -o driver.out

myDriver.o: driver.cpp
	g++ $(FLAGS) myDriver.cpp -c

mediumtest.o: mediumtest.cpp
	g++ $(FLAGS) mediumtest.cpp -c

Pinball.o: Pinball.h Pinball.cpp
	g++ $(FLAGS) Pinball.h Pinball.cpp -c

smalltest.o: smalltest.cpp
	g++ $(FLAGS) smalltest.cpp -c

clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~ *.h.gch *#

#val:
#       valgrind ./driver.out $(INPUT) $(RANGE)

run:
	./driver.out $(INPUT) $(FLAG)

#make run INPUT=input1.txt RANGE=range1.txt