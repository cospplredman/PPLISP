/*
PPLISP example

this PPLISP code implements basic addition on arrays of bools

compile with `gcc -E` to see the preprocessor output
*/

#include "../PPLISP.h"

/*
reverses a list
*/
#define M_REVERSE REVERSE
#define REVERSE(a) EVAL\
((IF, (IS_NIL, (FST, $ a)),\
	$(),\
	(CONCAT, (REVERSE, (RST, $ a)), (FST, $ a))))

/*
returns the boolean negation of its input

(T) -> (F)
(F) -> (T)
*/
#define M_NOT NOT
#define NOT(a) EVAL\
((IF,$ a,\
	$(F),\
	$(T)))

/*
boolean AND of its first two arguments
*/
#define M_AND AND
#define AND(a,b) EVAL\
((IF, $ a,\
	(IF, $ b,\
		$(T),\
		$(F)),\
	$(F)))

/*
boolean OR of its first two arguments
*/
#define M_OR OR
#define OR(a,b) EVAL\
((NOT,\
	(AND,\
		(NOT, $ a),\
		(NOT, $ b))))

/*
boolean XOR of its first two arguments
*/
#define M_XOR XOR
#define XOR(a,b) EVAL\
((AND,\
	(OR, $ a, $ b),\
	(NOT, (AND, $ a, $ b))))

/*
incrament a bool array
or more specifically perform addition by carry

second argument is the carry

the number is represented with the least significant bit on the left and the most significant bit on the right
(LSB, ..., MSB)


(T, F) -> (F, T)
(T) -> (F, T)
() -> (T)
*/
#define M_INC INC
#define INC(a, c) EVAL\
((IF, (IS_NIL, (FST, $ a)),\
	(IF, $ c,\
		$(T),\
		$()),\
	(CONCAT,\
		(XOR,(FST, $ a), $ c),\
		(INC, (RST, $ a), (AND, (FST, $ a), $ c)))))

/*
addition of two bool arrays
*/
#define M_ADD ADD
#define ADD(a, b, c) EVAL\
((IF, (IS_NIL, (FST, $ a)),\
	(INC, $ b, $ c),\
	(IF, (IS_NIL, (FST, $ b)),\
		(INC, $ a, $ c),\
		(CONCAT,\
			(XOR, (FST, $ a), (XOR, (FST, $ b), $ c)),\
			(ADD, (RST, $ a), (RST, $ b), (OR,\
				(AND, (FST, $ a), (FST, $ b)),\
				(AND, (OR, (FST, $ a), (FST, $ b)), $ c)))))))


EXP(
//EVAL ($(B,C))
//EVAL ((NOT, $(T)))
//EVAL ((XOR, $(F), $(T)))
//EVAL ((CONCAT, $(T), $(F)))
//EVAL ((INC, $(T, T), $(T)))
EVAL ((ADD, $(T, T), $(T, T), $(F)))
//EVAL ((CONPCAT, $(1, 2, 3), $(5)))
)

