FLAGS = -Wall

all: smalltest.o Pinball.o
	g++ $(FLAGS) smalltest.o Pinball.o  -o driver.out

Driver.o: driver.cpp
	g++ $(FLAGS) driver.cpp -c

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