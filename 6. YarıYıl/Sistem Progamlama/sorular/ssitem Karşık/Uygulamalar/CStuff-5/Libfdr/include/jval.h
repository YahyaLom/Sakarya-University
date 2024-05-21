/* Libraries for fields, doubly-linked lists and red-black trees.
   Copyright (C) 2018 James S. Plank */

#ifndef	_JVAL_H_
#define	_JVAL_H_

/* The Jval -- a type that can hold any 8-byte type */

typedef union {
    int i;
    long l;
    float f;
    double d;
    void *v;
    char *s;
    char c;
    unsigned char uc;
    short sh;
    unsigned short ush;
    unsigned int ui;
    int iarray[2];
    float farray[2];
    char carray[8];
    unsigned char ucarray[8];
  } Jval;  

extern Jval new_jval_i(int);
extern Jval new_jval_l(long);
extern Jval new_jval_f(float);
extern Jval new_jval_d(double);
extern Jval new_jval_v(/* void */);
extern Jval new_jval_s(char *);
extern Jval new_jval_c(char);
extern Jval new_jval_uc(unsigned char);
extern Jval new_jval_sh(short);
extern Jval new_jval_ush(unsigned short);
extern Jval new_jval_ui(unsigned int);
extern Jval new_jval_iarray(int, int);
extern Jval new_jval_farray(float, float);
extern Jval new_jval_carray_nt(char *);  /* Carray is null terminated */
extern Jval new_jval_carray_nnt(char *);  /* Carray is not null terminated */
       /* For ucarray -- use carray, because it uses memcpy */

extern Jval JNULL;

extern int jval_i(Jval);
extern long jval_l(Jval);
extern float jval_f(Jval);
extern double jval_d(Jval);
extern void *jval_v(Jval);
extern char *jval_s(Jval);
extern char jval_c(Jval);
extern unsigned char jval_uc(Jval);
extern short jval_sh(Jval);
extern unsigned short jval_ush(Jval);
extern unsigned int jval_ui(Jval);

#endif
