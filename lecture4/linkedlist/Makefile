CXXFLAGS=-std=c++11

OBJS=driver.o list.o

all: list

list: $(OBJS)
	$(CXX) -o list $(OBJS) $(CXXFLAGS)

%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

clean:
	rm $(OBJS) list
