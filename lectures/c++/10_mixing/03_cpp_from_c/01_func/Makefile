CC = cc
CXX = c++
EXE = exe

all: $(EXE)

$(EXE): cpp2c.o main.o
	$(CC) $^ -lstdc++ -o $@

#This -lstdc++ is to link against the c++ library in order to find our cout function
main.o: main.c

cpp2c.o: cpp2c.cc
	$(CXX) -std=c++11 -c $< -o $@

clean:
	rm -f *~ *.o $(EXE)

.PHONY: all clean format


format: cpp2c.cc main.c
	@clang-format -i $^ 2>/dev/null || echo "Please install clang-format to run this commands"
