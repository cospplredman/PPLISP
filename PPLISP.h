#ifndef PPLISP_H
    #define PPLISP_H
    #define PPLISP_EXP10(...)__VA_ARGS__
    #define PPLISP_EXP9(...)PPLISP_EXP10(PPLISP_EXP10(PPLISP_EXP10(__VA_ARGS__)))
    #define PPLISP_EXP8(...)PPLISP_EXP9(PPLISP_EXP9(PPLISP_EXP9(__VA_ARGS__)))
    #define PPLISP_EXP7(...)PPLISP_EXP8(PPLISP_EXP8(PPLISP_EXP8(__VA_ARGS__)))
    #define PPLISP_EXP6(...)PPLISP_EXP7(PPLISP_EXP7(PPLISP_EXP7(__VA_ARGS__)))
    #define PPLISP_EXP5(...)PPLISP_EXP6(PPLISP_EXP6(PPLISP_EXP6(__VA_ARGS__)))
    #define PPLISP_EXP4(...)PPLISP_EXP5(PPLISP_EXP5(PPLISP_EXP5(__VA_ARGS__)))
    #define PPLISP_EXP3(...)PPLISP_EXP4(PPLISP_EXP4(PPLISP_EXP4(__VA_ARGS__)))
    #define PPLISP_EXP2(...)PPLISP_EXP3(PPLISP_EXP3(PPLISP_EXP3(__VA_ARGS__)))
    #define PPLISP_EXP1(...)PPLISP_EXP2(PPLISP_EXP2(PPLISP_EXP2(__VA_ARGS__)))
    #define EXP(...)PPLISP_EXP1(__VA_ARGS__)
    //utility macros
    #define PPLISP_CONS_(...)__VA_ARGS__)
    #define PPLISP_CONS(...)(__VA_ARGS__,PPLISP_CONS_
    #define PPLISP_WRAP(...)((__VA_ARGS__))
    #define PPLISP_SWP(a,...)(__VA_ARGS__,a)
    #define PPLISP_FST(a,...)(a)
    #define PPLISP_SEC_(a,b,...)(b)
    #define PPLISP_SEC(a,...)PPLISP_SEC_(a,__VA_ARGS__,)
    #define PPLISP_RST(a,...)(__VA_ARGS__)
    #define PPLISP_CAT(a,b)a##b
    //avoiding blue paint macros
    #define M_(...)__VA_ARGS__
    #define PPLISP_CALL_(a)M_##a
    #define M_PPLISP_CALL PPLISP_CALL
    #define PPLISP_CALL(a,...)PPLISP_CAT M_()(PPLISP_CALL,_)(a)(__VA_ARGS__)
    //prediPPLISP_cate macros
    #define PPLISP_COM(...),
    #define PPLISP_IS_PAREN(a)PPLISP_SEC(PPLISP_COM a T,F)
    #define PPLISP_IS_WHITE(a)PPLISP_IF PPLISP_IS_PAREN(a)((F),PPLISP_SEC(PPLISP_COM a()T,F))
    #define PPLISP_IS_QUOTE_QUOTE ()
    #define PPLISP_IS_QUOTE(a)PPLISP_IS_PAREN(PPLISP_IS_QUOTE_##a)
    #define PPLISP_IS_IF_IF ()
    #define PPLISP_IS_IF(a)PPLISP_IS_PAREN(PPLISP_IS_IF_##a)
    #define PPLISP_IFT(T,F)T
    #define PPLISP_IFF(T,F)F
    #define PPLISP_IF(a)PPLISP_IF##a
    //macro lisp eval
    #define M_PPLISP_MAP_1(a,b,c)PPLISP_MAP PPLISP_SWP PPLISP_CONS PPLISP_WRAP PPLISP_SWP PPLISP_CONS PPLISP_WRAP PPLISP_CALL(M_ a,M_ PPLISP_FST b)c(a,PPLISP_RST b)
    #define M_PPLISP_MAP PPLISP_MAP
    #define PPLISP_MAP(a,b,c)PPLISP_CALL PPLISP_IF PPLISP_IS_WHITE PPLISP_FST b((,c),(PPLISP_MAP_1,a,b,c))
    #define M_PPLISP_EVAL_3(a,b,c,d)PPLISP_IF PPLISP_CALL(EVAL,b)((EVAL,c),(EVAL,d))
    #define M_PPLISP_EVAL_2(a,...)PPLISP_CALL PPLISP_CALL PPLISP_IF PPLISP_IS_IF (a)((PPLISP_EVAL_3,a,__VA_ARGS__),(PPLISP_MAP,(EVAL),(__VA_ARGS__),(a)))
    #define M_EVAL EVAL
    #define EVAL(a)PPLISP_CALL PPLISP_IF PPLISP_IS_QUOTE PPLISP_FST a((,PPLISP_RST a),(PPLISP_EVAL_2,M_ a))
    //macro lisp primitives
    #define $(...)(QUOTE,__VA_ARGS__)
    #define M_IS_NIL(a)PPLISP_IS_WHITE a
    #define M_FST(a)PPLISP_FST a
    #define M_RST(a)PPLISP_RST a
    #define M_CONCAT(a, b)PPLISP_IF PPLISP_IS_WHITE PPLISP_FST a(b,PPLISP_IF PPLISP_IS_WHITE PPLISP_FST b(a,PPLISP_CONS a b))

#else

    #undef PPLISP_H
    #undef PPLISP_EXP10
    #undef PPLISP_EXP9
    #undef PPLISP_EXP8
    #undef PPLISP_EXP7
    #undef PPLISP_EXP6
    #undef PPLISP_EXP5
    #undef PPLISP_EXP4
    #undef PPLISP_EXP3
    #undef PPLISP_EXP2
    #undef PPLISP_EXP1
    #undef EXP
    #undef PPLISP_CONS_
    #undef PPLISP_CONS
    #undef PPLISP_WRAP
    #undef PPLISP_SWP
    #undef PPLISP_FST
    #undef PPLISP_SEC_
    #undef PPLISP_SEC
    #undef PPLISP_RST
    #undef PPLISP_CAT
    #undef M_
    #undef PPLISP_CALL_
    #undef M_PPLISP_CALL
    #undef PPLISP_CALL
    #undef PPLISP_COM
    #undef PPLISP_IS_PAREN
    #undef PPLISP_IS_WHITE
    #undef PPLISP_IS_QUOTE_QUOTE
    #undef PPLISP_IS_QUOTE
    #undef PPLISP_IS_IF_IF
    #undef PPLISP_IS_IF
    #undef PPLISP_IFT
    #undef PPLISP_IFF
    #undef PPLISP_IF
    #undef M_PPLISP_MAP_1
    #undef M_PPLISP_MAP
    #undef PPLISP_MAP
    #undef M_PPLISP_EVAL_3
    #undef M_PPLISP_EVAL_2
    #undef M_EVAL
    #undef EVAL
    #undef M_IS_NIL
    #undef M_FST
    #undef M_RST
    #undef M_CONCAT

#endif
