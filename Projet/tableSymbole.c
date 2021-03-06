#include "include/tableSymbole.h"

/* Fonctions sur la TDS */
tableSymbole new_tds(){
  return NULL;
}

tableSymbole add_variable(tableSymbole table, variable var){
  if (lookup_tds(table, var->id) != NULL) {
    fprintf(stderr, "\nERROR : La variable %s est déjà défini dans la Table des Symboles\n", var->id);
    exit(OTHER_ERROR);
  }
	tableSymbole ajout = malloc(sizeof(struct tds_struct));
	ajout->var = var;
	ajout->next = NULL;

	if (table==NULL)
	{
		return ajout;
	}
	else
	{
		tableSymbole temp = table;
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next = ajout;
		return table;
	}
}

void print_tds(tableSymbole table){

  printf("Table des symboles :\n");
  if (table==NULL)
  {
    ;
  }
  else
  {
    tableSymbole temp = table;
    while(temp->next!=NULL)
    {
      print_variable(temp->var);
      temp = temp->next;
    }
    print_variable(temp->var);
    printf("\n");
  }
}

void free_tds(tableSymbole table){
  tableSymbole temp = table;
	tableSymbole tempNext;

	while(temp!=NULL)
	{
  	tempNext = temp->next;
  	free_variable(temp->var);
  	free(temp);
  	temp = tempNext;
  }
}

variable lookup_tds(tableSymbole table, char *id){
  tableSymbole temp = table;

  while(temp!=NULL && strcmp(temp->var->id, id) != 0)
	{
    temp = temp->next;
  }
  if (temp == NULL) {
    return NULL;
  }
  return temp->var;

}

void gen_assembleur_data(FILE *assembleur_file, tableSymbole table_symbole){
  tableSymbole temp = table_symbole;

  while(temp!=NULL)
	{
    variable var = temp->var;
    switch (var->type) {
      case TYPE_INT:
        fprintf(assembleur_file, "var_%s: %s %d\n", var->id, ".word", var->val.iValue);
        break;
      case TYPE_FLOAT:
        fprintf(assembleur_file, "var_%s: %s %f\n", var->id, ".float", var->val.dValue);
        break;
      case TYPE_BOOL:
        fprintf(assembleur_file, "var_%s: %s %d\n", var->id, ".word", var->val.iValue);
        break;
      case TYPE_STRING:
        fprintf(assembleur_file, "var_%s: %s %s\n", var->id, ".asciiz", var->val.sValue);
        break;

      default:
        printf("\nERROR, génération de code assembleur. Type non reconnu\n");
        break;
    }
    temp = temp->next;
  }
  if (temp == NULL) {
    return ;
  }
}
