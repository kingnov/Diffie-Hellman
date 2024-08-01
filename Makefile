CXX = g++
SYSTEMC_HOME = /path/to/systemc
INCLUDES = -I. -I$(SYSTEMC_HOME)/include
LIBDIR = -L$(SYSTEMC_HOME)/lib-linux64
LIBS = -lsystemc -lm

all: main.x

main.x: dhdemo.o dh_hw_mult.o dh_sw.o
	$(CXX) $(LIBDIR) -o main.x dhdemo.o dh_hw_mult.o dh_sw.o $(LIBS)

dhdemo.o: dhdemo.cpp dh_hw_mult.h dh_sw.h
	$(CXX) $(INCLUDES) -c dhdemo.cpp

dh_hw_mult.o: dh_hw_mult.cpp dh_hw_mult.h
	$(CXX) $(INCLUDES) -c dh_hw_mult.cpp

dh_sw.o: dh_sw.cpp dh_sw.h
	$(CXX) $(INCLUDES) -c dh_sw.cpp

clean:
	rm -f *.o main.x
