CXXFLAGS=-std=c++11

TARGETS = driver test_null test_bounds test_delete
OBJS=driver.o test_null.o test_bounds.o test_delete.o

all: $(TARGETS)

driver: driver.o
	g++ -o driver driver.o $(CXXFLAGS)

test_null: test_null.o
	g++ -o test_null test_null.o $(CXXFLAGS)

test_bounds: test_bounds.o
	g++ -o test_bounds test_bounds.o $(CXXFLAGS)

test_delete: test_delete.o
	g++ -o test_delete test_delete.o $(CXXFLAGS)

%.o: %.cpp ptr.hpp array_ptr.hpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

clean:
	rm $(OBJS) $(TARGETS)
