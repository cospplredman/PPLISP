# PPLISP
this is a set of 45 macros that allow for lisp-like preprocessor meta programming.

# USAGE
to use PPLISP in your project just include PPLISP.h
```c
#include "PPLISP.h"
```
including PPLISP.h a second time will undefine all of the PPLISP macros.

to evaluate a PPLISP:TM: expression use the following
```c
EXP( EVAL ( /*expr*/ ) )
```
the `EXP` macro applies 3^10 or so scans of the preprocessor and the `EVAL` macro does all of the hard work of figuring out what your expression means.

## expressions
a pplisp expression has the following format
`(MACRO, EXPR1, EXPR2, ..., EXPRN)`
the result of evaluating EXPR1, ..., EXPRN are passed to MACRO as ARG1, ... ARGN

## primitives
the following macros are defined for use as PPLISP primitives
- QUOTE ($)
    evaluates to the list of its unevaluated arguments

    the $ macro appends QUOTE to the front of its argument list
    EX: $(a, b, c) => (QUOTE, a, b, c)

- CONCAT
    concatenates arrays passed to ARG1 and ARG2 and returns the result

- IF
    if ARG1 evaluates to (T)
    then return the result of evaluating ARG2

    if ARG2 evaluates to (F)
    then return the result of evaluting ARG3

- FST
    returns the first element of the list passed to ARG1

- RST
    returns all but the first of the elements passed to ARG2

- IS_NIL
    if the list passed to ARG1 is empty evaluates to (T) otherwise it evaluates to (F)


## defining additional PPLISP primitives

to define additional primitives simply make a macro like so
```c
#define M_MACRONAME MACRONAME
#define MACRONAME(ARG1, ARG2, ..., ARGN)EVAL( /*expr*/ )
```
recursive primitives are totally allowed, feel free to experiment! 

## examples
here is an example of a NOT macro
```c
#define M_NOT NOT

/* the trailing \ tells the preprocessor to delete the newline allowing for multiline macro definitions*/
#define NOT(a) EVAL\
((IF,$ a,\
	$(F),\
	$(T)))

/*without the $() EVAL will attempt to evaluate T or F which doesn't make any sense*/

EXP(
EVAL(
    (NOT, $(T)) /*evaluates to (F)*/
)
EVAL(
    (NOT, $(F)) /*evaluates to (T)*/)
)
)
```
