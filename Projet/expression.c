#include "include/expression.h"

expr new_expr(quad_list code, variable resultat, quad_list true_list, quad_list false_list, enum type ty)
{
  expr new = malloc(sizeof(struct expr_struct));
  new->code = code;
  new->resultat = resultat;
  new->true_list = true_list;
  new->false_list = false_list;
  new->type_ex = ty;
  return new;
}

void print_expr(expr ex)
{


  switch (ex->type_ex) {
    case BOOL:
      printf("Expression (BOOL)\n");
      break;
    case ARITHM:
      printf("Expression (ARITHM)\n");
      break;
    case IDT:
      printf("Expression (ID)\n");
      break;
    case CONST:
      printf("Expression (CONST)\n");
      break;
    default:
      printf("Expression (INCONNU)\n");
      break;
  }

  printf("\n Code :");
  print_quad_list(ex->code);
  printf("Resultat : \n");
  print_variable(ex->resultat);
  printf("\n True List :");
  print_quad_list(ex->true_list);
  printf("\n False List :");
  print_quad_list(ex->false_list);
}

void free_expr(expr ex)
{
  free(ex);
}
