//void is put in the arguments because this is needed to say: I only accept no arguments
//If you would just do hello_from_cpp() this might mean you want any number of parameters
//extern can be avoided because function get external linkage by default
//C: strongly typed weakly checked, C++ strongly typed, strongly checked

//The steps of our code

//  SRC ->(this move is language dependent) IL -> Optimization -> Assembly -> .o (ELF)
//The Intermediate Language is common in between the languages. Is kind of a common ground.
//The IL has a sort of signature of the symbols
//hello C
//-Z5helov
//hello_ fortran
//Then is the linker job to merge all this stuff.
//The c++ linker links automatically against C libraries, THE OPPOSITE IS NOT TRUE
extern void hello_from_cpp(void);

int main(int argc, char* argv[]) {
  hello_from_cpp();
  return 0;
}
