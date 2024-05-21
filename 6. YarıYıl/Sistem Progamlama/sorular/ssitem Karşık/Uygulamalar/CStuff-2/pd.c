/* This program defines several structs and then prints their sizes.
   This is to highlight the fact that the compiler puts in bytes of
   padding to make sure that each data type in the struct is aligned. */

#include <stdio.h>
#include <stdlib.h>

typedef unsigned long UL;

typedef struct {
  char b;
  int i;
} Char_Int;

typedef struct {
  char b1;
  char b2;
  char b3;
  char b4;
  int i1;
} CCCC_Int;

typedef struct {
  char b1;
  int i1;
  char b2;
  int i2;
} C_I_C_I;

typedef struct {
  int i;
  char b;
} Int_Char;

int main()
{
  Char_Int *ci;
  CCCC_Int *cccci;
  C_I_C_I *cici;
  Int_Char *ic;

  /* Print out information about the Char_Int). */

  ci = (Char_Int *) malloc(sizeof(Char_Int)*2);
  printf("The size of a Char_Int is %ld\n", sizeof(Char_Int));
  printf("I have allocated an array, ci, of two Char_Int's at location 0x%lx\n", (UL) ci);
  printf("&(ci[0].b) = 0x%lx\n", (UL) &(ci[0].b));
  printf("&(ci[0].i) = 0x%lx\n", (UL) &(ci[0].i));
  printf("&(ci[1].b) = 0x%lx\n", (UL) &(ci[1].b));
  printf("&(ci[1].i) = 0x%lx\n", (UL) &(ci[1].i));
  printf("\n");

  cccci = (CCCC_Int *) malloc(sizeof(CCCC_Int)*2);
  printf("The size of a CCCC_Int is %ld\n", sizeof(CCCC_Int));
  printf("I have allocated an array, cccci, of two CCCC_Int's at location 0x%lx\n", (UL) cccci);
  printf("&(cccci[0].b1) = 0x%lx\n", (UL) &(cccci[0].b1));
  printf("&(cccci[0].b2) = 0x%lx\n", (UL) &(cccci[0].b2));
  printf("&(cccci[0].b3) = 0x%lx\n", (UL) &(cccci[0].b3));
  printf("&(cccci[0].b4) = 0x%lx\n", (UL) &(cccci[0].b4));
  printf("&(cccci[0].i1) = 0x%lx\n", (UL) &(cccci[0].i1));
  printf("&(cccci[1].b1) = 0x%lx\n", (UL) &(cccci[1].b1));
  printf("&(cccci[1].b2) = 0x%lx\n", (UL) &(cccci[1].b2));
  printf("&(cccci[1].b3) = 0x%lx\n", (UL) &(cccci[1].b3));
  printf("&(cccci[1].b4) = 0x%lx\n", (UL) &(cccci[1].b4));
  printf("&(cccci[1].i1) = 0x%lx\n", (UL) &(cccci[1].i1));
  printf("\n");

  cici = (C_I_C_I *) malloc(sizeof(C_I_C_I)*2);
  printf("The size of a C_I_C_I is %ld\n", sizeof(C_I_C_I));
  printf("I have allocated an array, cici, of two C_I_C_I's at location 0x%lx\n", (UL) cici);
  printf("&(cici[0].b1) = 0x%lx\n", (UL) &(cici[0].b1));
  printf("&(cici[0].i1) = 0x%lx\n", (UL) &(cici[0].i1));
  printf("&(cici[0].b2) = 0x%lx\n", (UL) &(cici[0].b2));
  printf("&(cici[0].i2) = 0x%lx\n", (UL) &(cici[0].i2));
  printf("&(cici[1].b1) = 0x%lx\n", (UL) &(cici[1].b1));
  printf("&(cici[1].i1) = 0x%lx\n", (UL) &(cici[1].i1));
  printf("&(cici[1].b2) = 0x%lx\n", (UL) &(cici[1].b2));
  printf("&(cici[1].i2) = 0x%lx\n", (UL) &(cici[1].i2));
  printf("\n");

  ic = (Int_Char *) malloc(sizeof(Int_Char)*2);
  printf("The size of a Int_Char is %ld\n", sizeof(Int_Char));
  printf("I have allocated an array, ic, of two Int_Char's at location 0x%lx\n", (UL) ic);
  printf("&(ic[0].i) = 0x%lx\n", (UL) &(ic[0].i));
  printf("&(ic[0].b) = 0x%lx\n", (UL) &(ic[0].b));
  printf("&(ic[1].i) = 0x%lx\n", (UL) &(ic[1].i));
  printf("&(ic[1].b) = 0x%lx\n", (UL) &(ic[1].b));
  printf("\n");

  return 0;
}
