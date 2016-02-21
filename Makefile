all: AQTest

AQTest: Aqueuemain.o
	g++ Aqueuemain.o -o AQTest

Aqueuemain.o: Aqueuemain.cpp
	g++ -c Aqueuemain.cpp

clean:
	rm -rf *o AQTest