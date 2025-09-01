%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaSimbolos.h"
#include "listaCodigo.h"

/*flag para error léxico o semántico.*/
extern int hayError;

/*Lista de símbolos*/
Lista tablaSimb;
int contCadenas = 1;	/*Para no repetir identificadores de cadenas*/
Tipo tipo;

int esConst(char *simb);
void anadeEntrada(char *simb, Tipo t);
int perteneceTabla(char *simb);
void imprimirTabla();

/* Generación de código*/
int registros[8] = {0};
int contador_etiq = 1;	/*Para no repetir nombres de etiquetas*/
char * selectRegistro();
void liberaRegistro(char * r);
void imprimirCodigo(ListaC codigo);
char * nuevaEtiqueta() ;


void yyerror();
extern int yylex();
extern int yylineno;
%}

%code requires{
#include "listaCodigo.h"
}

%union{
char *lexema;
ListaC codigo;
}

%type <codigo> expression relational statement statement_list print_item print_list read_list declarations identifier_list identifier

%token VAR CONST WHILE DO FOR TO IF ELSE PRINT READ PARI PARD LLAVI LLAVD PYCO COMA ASIG 
%token <lexema> IDEN ENTERO CAD


/*Para resolver la ambigüedad de operadores aritméticos*/
%left SUMA REST
%left MULT DIVI 
%left UMINUS	/*Precedencia maxima para "-" como operador unario*/

/* Para resolver la ambigúedad de operadores relacionales */
%left OR AND
%left LE LT GE GT


%expect 1

%%

program :
       {
              tablaSimb=creaLS();
       }
       IDEN PARI PARD LLAVI declarations statement_list LLAVD
       {

              concatenaLC($6, $7);
              if (hayError) {
                     printf("Se han producido errores.\n");
              }
              else {
                     imprimirTabla();
                     imprimirCodigo($6);
              }
              liberaLS(tablaSimb);
              liberaLC($6);
       }
       ;         

/*Reglas de produccion para declaraciones*/
declarations : declarations VAR {tipo = VARIABLE;} identifier_list PYCO
       {
              $$ = $1;
              concatenaLC($$, $4);
              liberaLC($4);
       }       
       | declarations CONST {tipo = CONSTANTE;} identifier_list PYCO
       {
              $$ = $1;
              concatenaLC($$, $4);
              liberaLC($4);
       }        
       |
       {
              $$ = creaLC();
       }                              
       ;

/*Reglas de produccion para varias asignaciones seguidas*/
identifier_list : identifier
       {
              $$ = $1;
       }                                      
       | identifier_list COMA identifier
       {
              $$ = $1;
              concatenaLC($$, $3);
              liberaLC($3);
       }                        
       ;

/*Reglas de produccion para una asignacion*/
identifier : IDEN 
       {
              if(!perteneceTabla($1)) {
                     anadeEntrada($1,tipo);
              }
              else {	/*No se puede declarar una variable ya declarada*/
                     printf("Error semántico: Variable %s ya declarada. Linea: %d\n", $1, yylineno);
                     hayError = 1;
              }
              $$ = creaLC();
       }                  
       | IDEN ASIG expression
       {
              if(!perteneceTabla($1)) {
                     anadeEntrada($1,tipo);
              }
              else {	/*No se puede declarar una variable ya declarada*/
                     printf("Error semántico: Variable %s ya declarada. Linea: %d.\n", $1, yylineno);
                     hayError = 1;
              }
              $$ = $3;
              char * id = (char *) malloc(strlen($1)+1);
              strcpy(id, "_");
              Operacion oper = (Operacion) {"sw", recuperaResLC($3), strdup(strcat(id, $1)), NULL};
              free(id);
              insertaLC($$, finalLC($$), oper);
              liberaRegistro(oper.res);
       }                               
       ;

/*Reglas de produccion para derivar varias varias sentencias*/
statement_list : statement_list statement
       {
              $$ = $1;
              concatenaLC($$, $2);
              liberaLC($2);
       }
       |
       {
              $$ = creaLC();
       }                                                 
       ;

/*Reglas de produccón para poder derivar los diferentes tipos de sentencias*/
statement : IDEN ASIG expression PYCO
       {
              if(!perteneceTabla($1)) {
                     printf("Error semántico: Variable %s no declarada. Linea: %d.\n", $1, yylineno);
                     hayError = 1;
              }
              else if (esConst($1)) {
                     printf("Error semántico: Asignación a constante %s. Linea: %d.\n", $1, yylineno);
                     hayError = 1;
              }
              $$ = $3;
              char * id = (char *) malloc(strlen($1)+1);
              strcpy(id, "_");
              Operacion oper = (Operacion) {"sw", recuperaResLC($3), strdup(strcat(id, $1)), NULL};
              free(id);
              insertaLC($$, finalLC($$), oper);
              liberaRegistro(oper.res);
       }                    
       | LLAVI statement_list LLAVD 
       {
              $$ = $2;
       }       //Las reglas de produccion if, if-else son ambiguas, pero bison lo soluciona con su acción por defecto.
       | IF PARI expression PARD statement ELSE statement
       {
              $$ = $3;
              char * etiq1 = nuevaEtiqueta();
              char * etiq2 = nuevaEtiqueta();

              // beqz $ti, $lj1
              Operacion oper1 = (Operacion) {"beqz", recuperaResLC($3), etiq1, NULL};
              // b $lj2
              Operacion oper2 = (Operacion) {"b", etiq2, NULL, NULL};
              // etiq1:
              Operacion oper3 = (Operacion) {"etiq", etiq1, NULL, NULL};
              // etiq2:
              Operacion oper4 = (Operacion) {"etiq", etiq2, NULL, NULL};

              insertaLC($$, finalLC($$), oper1);
              concatenaLC($$, $5);
              insertaLC($$, finalLC($$), oper2);
              insertaLC($$, finalLC($$), oper3);
              concatenaLC($$, $7);
              insertaLC($$, finalLC($$), oper4);

              liberaRegistro(recuperaResLC($3));
              liberaLC($5);
              liberaLC($7);
       }
       | IF PARI expression PARD statement    
       {
              $$ = $3;
              char * etiq = nuevaEtiqueta();
              // beqz $ti, etiq
              Operacion oper1 = (Operacion) {"beqz", recuperaResLC($3), etiq, NULL};
              // etiq:
              Operacion oper2 = (Operacion) {"etiq", etiq, NULL, NULL};
              
              insertaLC($$, finalLC($$), oper1);
              concatenaLC($$, $5);
              insertaLC($$, finalLC($$), oper2);

              liberaRegistro(recuperaResLC($3));
              liberaLC($5);
       }             
       | WHILE PARI expression PARD statement    
       {
              $$ = creaLC();
              char * etiq1 = nuevaEtiqueta();
              char * etiq2 = nuevaEtiqueta();
              // etiq1:
              Operacion oper1 = (Operacion) {"etiq", etiq1, NULL, NULL};
              // beqz $ti, etiq2
              Operacion oper2 = (Operacion) {"beqz", recuperaResLC($3), etiq2, NULL};
              // b etiq 1
              Operacion oper3 = (Operacion) {"b", etiq1, NULL, NULL};
              // etiq2:
              Operacion oper4 = (Operacion) {"etiq", etiq2, NULL, NULL};
              
              insertaLC($$, finalLC($$), oper1);
              concatenaLC($$, $3);
              insertaLC($$, finalLC($$), oper2);
              concatenaLC($$, $5);
              insertaLC($$, finalLC($$), oper3);
              insertaLC($$, finalLC($$), oper4);
              
              liberaRegistro(recuperaResLC($3));
              liberaLC($3);
              liberaLC($5);
       }
       | DO statement WHILE PARI relational PARD PYCO
       {
	      $$ = creaLC();
              char * etiq1 = nuevaEtiqueta();
	      /* etiq1 */
	      Operacion oper1 = (Operacion) {"etiq", etiq1, NULL, NULL};
	      /* beqz $ti, etiq2 (saltar al inicio del bucle si se cumple la condicion del bucle) */
              Operacion oper2 = (Operacion) {"beqz", recuperaResLC($5), etiq1, NULL};

	      /* etiqueta de inicio del bucle */
	      insertaLC($$, finalLC($$), oper1);
	      /* sentencias */
	      concatenaLC($$, $2);
	      /* condicion del bucle */
	      concatenaLC($$, $5);
	      /* comprobación de la condicion */
	      insertaLC($$, finalLC($$), oper2);
	      
	      liberaRegistro(recuperaResLC($5));
	      liberaLC($2);
	      liberaLC($5);
       }
       | FOR PARI IDEN ASIG expression TO expression PYCO relational PARD statement
       {
              if(!perteneceTabla($3)) {
		     /* Si la variable no ha sido declarada no se le puede asignar un valor */
                     printf("Error semántico: Variable %s no declarada. Linea: %d.\n", $3, yylineno);
                     hayError = 1;
              }
              else if (esConst($3)) {
		     /* No se puede usar una constante como iterador por que su valor no puede cambiar */
                     printf("Error semántico: Asignación a constante %s. Linea: %d.\n", $3, yylineno);
                     hayError = 1;
              }

	      $$ = creaLC();
              char * etiq1 = nuevaEtiqueta();
              char * etiq2 = nuevaEtiqueta();
	      Operacion oper1 = (Operacion) {"etiq", etiq1, NULL, NULL};
              char * id = (char *) malloc(strlen($3)+1);
              strcpy(id, "_");
              Operacion oper2 = (Operacion) {"sw", recuperaResLC($5), strdup(strcat(id, $3)), NULL};
	      free(id);
	      Operacion oper3 = (Operacion) {"bgt", recuperaResLC($5), recuperaResLC($7), etiq2};
  	      Operacion oper4 = (Operacion) {"beqz", recuperaResLC($9), etiq2, NULL};
	      Operacion oper5 = (Operacion) {"addi", recuperaResLC($5), recuperaResLC($5), "1"};
	      Operacion oper6 = (Operacion) {"b", etiq1, NULL, NULL};
	      Operacion oper7 = (Operacion) {"etiq", etiq2, NULL, NULL};

	      /* etiqueta inicio del bucle */
	      insertaLC($$, finalLC($$), oper1);

	      /* cargar en la variable el valor del iterador */
	      insertaLC($$, finalLC($$), oper2);

	      /* comprobar que el iterador no ha excedido su valor máximo */
	      insertaLC($$, finalLC($$), oper3);

	      /* comprbación de la condicion de finalización */
	      insertaLC($$, finalLC($$), oper4);
	
	      /* bloque de sentencuas del bucle for */
	      concatenaLC($$, $11);

	      /* incrementar el iterador en 1 */
	      insertaLC($$, finalLC($$), oper5);

	      /* saltar al inicio del bucle */
	      insertaLC($$, finalLC($$), oper6);

	      /* etiqueta del final del bucle */
	      insertaLC($$, finalLC($$), oper7);

	      liberaRegistro(recuperaResLC($5));
	      liberaRegistro(recuperaResLC($7));
	      liberaRegistro(recuperaResLC($5));
	      liberaLC($5);
	      liberaLC($7);
	      liberaLC($9);
	      liberaLC($11);
       }	  
       | PRINT PARI print_list PARD PYCO
       {
              $$ = $3;
       }                         
       | READ PARI read_list PARD PYCO
       {
              $$ = $3;
       }
       ;

/*Regla de produccion para lista de elementos a imprimir*/
print_list : print_item
       {
              $$ = $1;
       }                                     
       | print_list COMA print_item
       {
              $$ = $1;
              concatenaLC($$, $3);
              liberaLC($3);
       }                   
       ;                                  

/*Reglas de produccion de los elementos que se pueden imprimir*/
print_item : expression
       {
              $$ = $1;
              Operacion oper1 = (Operacion) {"li", "$v0", "1", NULL};
              Operacion oper2 = (Operacion) {"move", "$a0", recuperaResLC($1), NULL};
              Operacion oper3 = (Operacion) {"syscall", NULL, NULL, NULL};
              insertaLC($$,finalLC($$), oper1);
              insertaLC($$,finalLC($$), oper2);
              insertaLC($$,finalLC($$), oper3);
              liberaRegistro(recuperaResLC($1));
       }           
       | CAD
       {
              anadeEntrada($1, CADENA);

              $$ = creaLC();
              Operacion oper1 = (Operacion) {"li", "$v0", "4", NULL};
              char * str = (char *) malloc(10);
              sprintf(str, "%s%d", "$str", contCadenas);                              
              Operacion oper2 = (Operacion) {"la", "$a0", strdup(str), NULL};
              free(str);
              Operacion oper3 = (Operacion) {"syscall", NULL, NULL, NULL};
              insertaLC($$, finalLC($$), oper1);
              insertaLC($$, finalLC($$), oper2);
              insertaLC($$, finalLC($$), oper3);

              contCadenas++;
       }                                                                                          
       ;

/*Reglas de produccion para poder leer por teclado diferentes elementos*/
read_list : IDEN
       {
              if (!perteneceTabla($1)) {	//Si la variable no ha sido declarada no se le puede asignar un valor
                     printf("Error semántico: Variable %s no declarada. Linea: %d.\n", $1, yylineno);
                     hayError = 1;
              }					//Si es una constante su valor no se puede cambiar
              else if (esConst($1)) {
                     printf("Error semántico: Asignación a constante %s. Linea: %d.\n", $1, yylineno);
                     hayError = 1;
              }
              
              $$ = creaLC();
              Operacion oper1 = (Operacion) {"li", "$v0", "5", NULL};
              Operacion oper2 = (Operacion) {"syscall", NULL, NULL, NULL};
              char * id = (char *) malloc(strlen($1) + 1);
              strcpy(id, "_");
              Operacion oper3 = (Operacion) {"sw", "$v0", strdup(strcat(id, $1)), NULL};
              free(id);
              insertaLC($$, finalLC($$), oper1);
              insertaLC($$, finalLC($$), oper2);
              insertaLC($$, finalLC($$), oper3);

       }                                         
       | read_list COMA IDEN
       {
              if (!perteneceTabla($3)) {	//Si la variable no ha sido declarada no se le puede asignar un valor
                     printf("Error semántico: Variable %s no declarada. Linea: %d.\n", $3, yylineno);
                     hayError = 1;
              }
              else if (esConst($3)) {		//Si es una constante su valor no se puede cambiar
                     printf("Error semántico: Asignación a constante %s. Linea: %d.\n", $3, yylineno);
                     hayError = 1;
              }
              
              $$ = $1;
              Operacion oper1 = (Operacion) {"li", "$v0", "5", NULL};
              Operacion oper2 = (Operacion) {"syscall", NULL, NULL, NULL};
              char * id = (char *) malloc(strlen($3) + 1);
              strcpy(id, "_");
              Operacion oper3 = (Operacion) {"sw", "$v0", strdup(strcat(id, $3)), NULL};
              free(id);
              insertaLC($$, finalLC($$), oper1);
              insertaLC($$, finalLC($$), oper2);
              insertaLC($$, finalLC($$), oper3);
       }                                 
       ;

/*Reglas de produccion para expresiones aritmeticas*/
expression : expression SUMA expression
       {	
              $$ = $1;
              concatenaLC($$,$3);
              Operacion oper = (Operacion) {"add", recuperaResLC($1), recuperaResLC($1), recuperaResLC($3)};
              insertaLC($$, finalLC($$), oper);
              liberaLC($3);
              liberaRegistro(oper.arg2);
       }                   
       | expression REST expression       
       {
              $$ = $1;
              concatenaLC($$,$3);
              Operacion oper = (Operacion) {"sub", recuperaResLC($1), recuperaResLC($1), recuperaResLC($3)};
              insertaLC($$, finalLC($$), oper);
              liberaLC($3);
              liberaRegistro(oper.arg2);
       }                  
       | expression MULT expression   
       {
              $$ = $1;
              concatenaLC($$,$3);
              Operacion oper = (Operacion) {"mul", recuperaResLC($1), recuperaResLC($1), recuperaResLC($3)};
              insertaLC($$, finalLC($$), oper);
              liberaLC($3);
              liberaRegistro(oper.arg2);
       }                          
       | expression DIVI expression
       {
              $$ = $1;
              concatenaLC($$,$3);
              Operacion oper = (Operacion) {"div", recuperaResLC($1), recuperaResLC($1), recuperaResLC($3)};
              insertaLC($$, finalLC($$), oper);
              liberaLC($3);
              liberaRegistro(oper.arg2);
       }
	//Cambiar la precedencia de "-" como operador unario
       | REST expression        %prec UMINUS
       {
              $$ = $2;
              char * reg = recuperaResLC($2);
              Operacion oper = (Operacion) {"neg", reg, reg};
              insertaLC($$, finalLC($$), oper);
       }                                  
       | PARI expression PARD
       {
              $$ = $2;
       }                  
       | IDEN
       {
              if (!perteneceTabla($1)) {	//Si el identificador no ha sido declarado no se puede operar con el
                     printf("Error semántico: Variable %s no declarada. Linea: %d.\n", $1, yylineno);
                     hayError = 1;
              }

              $$ = creaLC();
              char * reg = selectRegistro();
              char * id = (char *) malloc(strlen($1)+1);
              strcpy(id, "_");
              Operacion oper = (Operacion) {"lw", reg, strdup(strcat(id, $1)), NULL};
              free(id);
              insertaLC($$, finalLC($$), oper);
              guardaResLC($$, reg);
       }         
       | ENTERO
       {
              $$ = creaLC();
              char * reg = selectRegistro();
              Operacion oper = (Operacion) {"li", reg, $1, NULL};
              insertaLC($$, finalLC($$), oper);
              guardaResLC($$, reg);
       }                                           
       ;
relational : expression GT expression 
       {
       
       	      $$ = $1;
              concatenaLC($$,$3);
              Operacion oper = (Operacion) {"glt", recuperaResLC($1), recuperaResLC($1), recuperaResLC($3)};
              insertaLC($$, finalLC($$), oper);
              liberaLC($3);
              liberaRegistro(oper.arg2);
              }
       | expression GE expression 
       {
	      $$ = $1;
              concatenaLC($$,$3);
	      char * auxiliar = selectRegistro();
	      char * etiq1 = nuevaEtiqueta();
	      Operacion oper1 = (Operacion) {"li", auxiliar, "0", NULL};		/* Poner valor a 0 */
	      Operacion oper2 = (Operacion) {"blt", recuperaResLC($1), recuperaResLC($3), etiq1}; /* Saltar sin poner el resultado a 1 */
	      Operacion oper3 = (Operacion) {"li", auxiliar, "1", NULL};		/* Poner valor a 1 */
  	      Operacion oper4 = (Operacion) {"etiq", etiq1, NULL, NULL};	
              Operacion oper5 = (Operacion) {"move", recuperaResLC($1), auxiliar, NULL}; /* Cargar resultado */
              insertaLC($$, finalLC($$), oper1);
              insertaLC($$, finalLC($$), oper2);
              insertaLC($$, finalLC($$), oper3);
  	      insertaLC($$, finalLC($$), oper4);
	      insertaLC($$, finalLC($$), oper5);
              liberaLC($3);
              liberaRegistro(auxiliar);
       }
       | expression LT expression 
       {
	      $$ = $1;
              concatenaLC($$,$3);
              Operacion oper = (Operacion) {"slt", recuperaResLC($1), recuperaResLC($1), recuperaResLC($3)};
              insertaLC($$, finalLC($$), oper);
              liberaLC($3);
              liberaRegistro(oper.arg2);
       }
       | expression LE expression 
       {
	      $$ = $1;
              concatenaLC($$,$3);
	      char * auxiliar = selectRegistro();
	      char * etiq1 = nuevaEtiqueta();
	      Operacion oper1 = (Operacion) {"li", auxiliar, "0", NULL};		/* Poner valor a 0 */
	      Operacion oper2 = (Operacion) {"bgt", recuperaResLC($1), recuperaResLC($3), etiq1}; /* Saltar sin poner el resultado a 1 */
	      Operacion oper3 = (Operacion) {"li", recuperaResLC($1), "1", NULL};	/* Poner valor a 1 */
	      Operacion oper4 = (Operacion) {"etiq", etiq1, NULL, NULL};
              Operacion oper5 = (Operacion) {"move", recuperaResLC($1), auxiliar, NULL}; /* Cargar resultado */
              insertaLC($$, finalLC($$), oper1);
              insertaLC($$, finalLC($$), oper2);
              insertaLC($$, finalLC($$), oper3);
	      insertaLC($$, finalLC($$), oper4);
	      insertaLC($$, finalLC($$), oper5);
              liberaLC($3);
              liberaRegistro(oper3.arg2);
       }
       | relational AND relational
       {

	      $$ = $1;
              concatenaLC($$,$3);
              Operacion oper = (Operacion) {"and", recuperaResLC($1), recuperaResLC($1), recuperaResLC($3)};
              insertaLC($$, finalLC($$), oper);
              liberaLC($3);
              liberaRegistro(oper.arg2);
       }
       | relational OR relational
       {

	      $$ = $1;
              concatenaLC($$,$3);
              Operacion oper = (Operacion) {"or", recuperaResLC($1), recuperaResLC($1), recuperaResLC($3)};
              insertaLC($$, finalLC($$), oper);
              liberaLC($3);
              liberaRegistro(oper.arg2);
       }
       | expression
       {      	
	      $$ = $1;
       }
       ;


%%

void yyerror()
{
printf("Se ha producido un error sintactico en esta expresion.\n");
}

/*Función que imprime el segmento de datos del programa*/
void imprimirTabla() {

       printf("####################\n");
       printf("# Seccion de datos\n");
       printf("\t.data\n\n");
       PosicionLista p = inicioLS(tablaSimb);
       while (p != finalLS(tablaSimb)) {
              Simbolo aux = recuperaLS(tablaSimb, p);

              switch(aux.tipo) {
                     case VARIABLE:
                     case CONSTANTE:
                            printf("_%s:\n\t.word 0\n", aux.nombre);
                            break;
                     case CADENA:
                            printf("$str%d:\n\t.asciiz %s\n", aux.valor, aux.nombre);
                            break;
                     default:
                            printf("Tipo no reconocido\n");
                            break;
              }
              p = siguienteLS(tablaSimb, p);
       }

}

/*Función que comprueba si un identificador esta definido en la tabla de simbolos*/
int perteneceTabla(char *simb){

       PosicionLista p = buscaLS(tablaSimb, simb);
       return p != finalLS(tablaSimb); 
}

/*Función que añade un identificador en la tabla de simbolos*/
void anadeEntrada(char *simb, Tipo t){

       Simbolo aux;
       aux.nombre = simb;
       aux.tipo = t;
       aux.valor = contCadenas;
       insertaLS(tablaSimb, finalLS(tablaSimb), aux);
}

/*Función que comprueba si el identificador corresponde con una constante*/
int esConst(char *simb){

       PosicionLista p = buscaLS(tablaSimb, simb);
       Simbolo aux = recuperaLS(tablaSimb, p);
       return aux.tipo == CONSTANTE;
}

/*Funcion que busca el primer registro libre. En su defecto causa un error*/
char * selectRegistro(){

       int i = 0;
       while (i < 8 && registros[i]) i++;
       if(i < 8) {
              char r[3];
              snprintf(r, 4, "$t%d", i);         
              registros[i] = 1;
              return strdup(r);
       }
       printf("* ERROR: Registros agotados. Programa abortado.\n");
       exit(1);
}

/*Función que marca como libre un registro*/
void liberaRegistro(char *r){

       int i = r[2] - '0';
       registros[i] = 0;
}

/*Función que imprime el segmento de codigo del programa*/
void imprimirCodigo(ListaC codigo){

       printf("\n####################\n");
       printf("# Seccion de codigo\n");
       printf("\t.text\n\t.globl main\nmain:\n");
       
       PosicionListaC p = inicioLC(codigo);
       Operacion oper;
       while (p != finalLC(codigo)) {
              oper = recuperaLC(codigo,p);
              if (!strcmp(oper.op, "etiq")) {
                     printf("%s:\n", oper.res);
                     p = siguienteLC(codigo,p);
                     continue;
              }
              printf("\t%s",oper.op);
              if (oper.res) printf(" %s",oper.res);
              if (oper.arg1) printf(",%s",oper.arg1);
              if (oper.arg2) printf(",%s",oper.arg2);
              printf("\n");
              p = siguienteLC(codigo,p);
       }
       printf("####################\n");
       printf("# Fin\n");
       printf("\tli $v0,10\n\tsyscall\n");
}
/*Función para generar una nueva etiqueta de salto*/
char * nuevaEtiqueta() {

       char aux[10];
       sprintf(aux, "$l%d", contador_etiq++);           
       return strdup(aux);
}
