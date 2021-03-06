#if !defined( TABLESYMBOLE_H )

#define TABLESYMBOLE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "variable.h"

//Structure pour notre TDS (chained list)
typedef struct tds_struct
{
	variable var;
	struct tds_struct *next;
}*tableSymbole;

tableSymbole new_tds();

tableSymbole add_variable(tableSymbole table, variable var);

void print_tds(tableSymbole table);

void free_tds(tableSymbole table);
variable lookup_tds(tableSymbole table, char *id);
void gen_assembleur_data(FILE *assembleur_file, tableSymbole table_symbole);
#endif
