#/usr/bin/env python3

#Honestly, the following lines are kind of a mess at first glance.
#Need more proficiency in py to understand this.

from ctypes import *
dso = CDLL("./libhello.so") # import shared object on POSIX compatible OS

## functions w/o args
dso.hello() #This invokes our c function


## strings
dso.repeat.argtypes = [c_char_p] #this defines the argument type (always a list)
dso.repeat.restype = c_int #this defines a return type(always a single value)
res = dso.repeat(b"ctypes are great") # use b to pass read-only variable

# use create_string_buffer for a "mutable string"
buf = create_string_buffer(b"this could be modified")
dso.repeat(buf)


## arrays
size = 10
d_array = (c_double*size)()  # better do the allocation on the python side

for i in range(size):
    d_array[i] = i

array_sum = dso.array_sum

#These again set our python stuff to be interpretable c stuff
array_sum.argtypes = [POINTER(c_double), c_size_t] # note the use of POINTER
#We don't have c_double_p as for chars
array_sum.restype = c_double

print("the sum of d_array is", array_sum(d_array,size))


## structs
class data(Structure): #Structure is defined by ctypes
    _fields_ = [("i",c_int), #The list of tuples must be in order
                ("name",c_char_p),
                ("energy",c_double)] # order is crucial otherwise seg-fault

param = data(name=b"Alberto", energy=99.9, i=42) #Now data is a normal python class

#dso.use_by_value.argtypes = [data]
dso.use_by_value(param) # default is by value

param.i=77
param.name=b"ciao ciao"

# dso.use_by_reference.argtypes = [POINTER(data)]
# dso.use_by_reference(param)
dso.use_by_reference(byref(param))

dso.set_energy.argtypes = [POINTER(data), c_double]

dso.set_energy(param, 32.45)

dso.use_by_value(param)

