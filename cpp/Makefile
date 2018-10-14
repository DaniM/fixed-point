CXXFLAGS += -g

.PHONY: clean

default: fixed.o

test_fixed: fixed.o test_fixed.cpp
	$(CXX) -o $@ $(CXXFLAGS) $+

clean:
	rm -f *.o
