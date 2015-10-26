CXXFLAGS=-std=c++11 -g -fPIC

TARGETS = test_tree test_memory driver libcis190.so

all: $(TARGETS)

libcis190.so: memory.o malloc.o primitives.o
	g++ -o libcis190.so -fPIC -shared malloc.o memory.o primitives.o $(CXXFLAGS) -ldl

driver: driver.o
	g++ -o driver driver.o $(CXXFLAGS)

test_tree: test_tree.o
	g++ -o test_tree test_tree.o $(CXXFLAGS)

test_memory: test_memory.o memory.o primitives.o
	g++ -o test_memory test_memory.o memory.o primitives.o $(CXXFLAGS) -ldl

%.o: %.cpp tree.hpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

clean:
	rm -f *.o $(TARGETS)
