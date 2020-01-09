CXX = c++
LANG = ITALIANO

SRC = src/greetings.cc src/conclusion.cc
OBJ = $(SRC:.cc=.o)

all: libgreetings.so

libgreetings.so: $(OBJ)
	$(CXX) -shared -o $@ $^

%.o:%.cc
	$(CXX) -fpic -D$(LANG) -o $@ -c $< -Iinclude

src/greetings.o: include/greetings.h

src/conclusion.o: include/conclusion.h

format: $(SRC) include/greetings.h include/conclusion.h
	@clang-format -i $^ 2>/dev/null || echo "Please install clang-format to run this commands"

#This will not work if we create a file named clean!
clean:
	@rm -f *~ */*~ libgreetings.so src/*.o
#The @ in front of remove "mutes" the command on command line. It still executes but it does
#not echo anything.

#The one below is magic! in the .PHONY target you are begging the make file to trust you when calling
#make clean make all make format
.PHONY: clean all format

#make -B: forces recompilation, does not check time-stamps
#make -j: parallel compilation! put number of processors + 1
#make -n: prints the action but does not actually do the actions.