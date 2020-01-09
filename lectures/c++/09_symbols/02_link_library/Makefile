EXE = ap
GDIR=../01_greetings_library

#we can actually engrave in our makefile where to look for libraries in runtime
#LDFLAGS = -lgreetings -L $(GDIR) -Wl, -rpath,$(GDIR)
#-Wl is: now i tell you something for the linke
#-rpath,($GIR) does the magic
#readelf -d name_of_the_binary. -d is the dynamic part of our binary.

LDFLAGS = -lgreetings -L $(GDIR)
CXX = c++
CXXFLAGS = -I include -I $(GDIR)/include -std=c++11

all: $(EXE)

%.o: %.cc
	$(CXX) -c $< -o $@ $(CXXFLAGS)


$(EXE): main.o src/date.o src/student.o
	$(CXX) $^ -o $(EXE) $(LDFLAGS)

main.o: src/student.o src/date.o

src/date.o: include/date.h

src/student.o: include/student.h

format: $(SRC) include/date.h include/student.h
	@clang-format -i $^ 2>/dev/null || echo "Please install clang-format to run this commands"
#The one above is a true || separator. If the first is true then does not execute the second one.

clean:
	rm -rf src/*.o *.o $(EXE) */*~ *~ a.out*

.PHONY: clean all format


