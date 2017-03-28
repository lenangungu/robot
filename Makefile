CXXFLAGS += --std=c++11

all: main

debug: CXXFLAGS += -g
debug: main

rebuild: clean main

main: main.o Robort_parts.o
	g++ $(CXXFLAGS) main.o Robort_parts.o





safe:
	git -a *.cpp
	git commit -m
clean:
	-rm -f *.o *~ a.out
