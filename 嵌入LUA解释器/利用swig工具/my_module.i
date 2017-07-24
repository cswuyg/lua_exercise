%module my_module 
%include "std_string.i" 
%{
#include "my_module.h"
%}
%include "my_module.h"
