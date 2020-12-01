#include <dlfcn.h>

//Ok, this is weirder
//Useful for wrapping this standard functions in other things.
//Dynamic loading of functions
//1. dlopen dynamically opens a library (in this case libehllo.so)
//2. dlsym searches for a certain symbol in that library
//3. dlclose closes the library
int main(int argc, char* argv[]) {
  void* handle; /* handle for dynamic object */
  void (*hi)(); /* function pointer for symbol */
  int (*rep)(char*);
  handle = dlopen("./libhello.so", RTLD_LAZY); //Returns a handle
  if (handle) {
    hi = (void (*)())dlsym(handle, "hello"); //finds the symbol hello, return a pointer function?
    (*hi)(); //Call the function
    rep = (int (*)(char*))dlsym(handle, "repeat");
    rep("I dont't care what fox says");
    dlclose(handle);
  }
  return 0;
}
