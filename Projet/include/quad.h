#if !defined( QUAD_H )

#define QUAD_H
#include <stdio.h>
#include <stdlib.h>
#include "variable.h"

//Structure pour notre code 3 adresses
typedef struct quad_struct
{
  int operateur;
  variable arg1;
  variable arg2;
  variable res;
}*quad;



quad new_quad(int operateur, variable arg1, variable arg2, variable res);
void print_quad(quad q);
void free_quad(quad q);
void print_op(int operator);
void assembleur_quad(FILE *assembleur_file, quad q);
#endif
