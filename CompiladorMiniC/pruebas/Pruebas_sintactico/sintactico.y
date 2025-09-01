%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*flag para error léxico.*/
extern int hayError;

int main();
void yyerror();
extern int yylex();
extern int yylineno;
%}

%union{
char *lexema;
}

%token VAR CONST WHILE DO FOR TO IF ELSE PRINT READ PARI PARD LLAVI LLAVD PYCO COMA ASIG
%token <lexema> IDEN ENTERO CAD

/*Para resolver la ambigüedad de operadores aritméticos*/
%left SUMA REST
%left MULT DIVI 
%left UMINUS	/*Precedencia maxima para "-" como operador unario*/




%expect 1

%%

program : IDEN PARI PARD LLAVI declarations statement_list LLAVD
       {
	printf("program -> IDEN PARI PARD LLAVI declarations statement_list LLAVD\n");
       }
       ;         

/*Reglas de produccion para declaraciones*/
declarations : declarations VAR identifier_list PYCO
       {
	printf("declarations -> declarations VAR identifier_list PYCO\n");
       }       
       | declarations CONST identifier_list PYCO
       {
	printf("declarations -> declarations CONST identifier_list PYCO\n");
       }        
       |
       {
	printf("declarations -> lambda\n");
       }                              
       ;

/*Reglas de produccion para varias asignaciones seguidas*/
identifier_list : identifier
       {
	printf("identifier_list -> identifier\n");
       }                                      
       | identifier_list COMA identifier
       {
	printf("identifier_list -> identifier_list COMA identifier\n");
       }                        
       ;

/*Reglas de produccion para una asignacion*/
identifier : IDEN 
       {
	printf("identifier -> IDEN\n");
       }                  
       | IDEN ASIG expression
       {
	printf("identifier -> IDEN ASIG expression\n");
       }                               
       ;

/*Reglas de produccion para derivar varias varias sentencias*/
statement_list : statement_list statement
       {
	printf("statement_list -> statement_list statement\n");
       }
       |
       {
	printf("statement_list -> lambda\n");
       }                                                 
       ;

/*Reglas de produccón para poder derivar los diferentes tipos de sentencias*/
statement : IDEN ASIG expression PYCO
       {
	printf("statement -> IDEN ASIG expression PYCO\n");
       }                    
       | LLAVI statement_list LLAVD 
       {
	printf("statement -> LLAVI statement_list LLAVD\n");
       }       
       | IF PARI expression PARD statement ELSE statement
       {
	printf("statement -> IF PARI expression PARD statement ELSE statement\n");
       }
       | IF PARI expression PARD statement    
       {
	printf("statement -> IF PARI expression PARD statement\n");
       }             
       | WHILE PARI expression PARD statement    
       {
	printf("statement -> WHILE PARI expression PARD statement\n");
       }	  
       | PRINT PARI print_list PARD PYCO
       {
        printf("statement -> PRINT PARI print_list PARD PYCO\n");
       }                         
       | READ PARI read_list PARD PYCO
       {
        printf("statement -> READ PARI read_list PARD PYCO\n");  
       }
       ;

/*Regla de produccion para lista de elementos a imprimir*/
print_list : print_item
       {
        printf("print_list -> print_item\n"); 
       }                                     
       | print_list COMA print_item
       {
        printf("print_list -> print_list COMA print_item\n"); 
       }                   
       ;                                  

/*Reglas de produccion de los elementos que se pueden imprimir*/
print_item : expression
       {
	printf("print_item -> expression\n"); 
       }           
       | CAD
       {
        printf("print_item -> CAD\n"); 
       }                                                                                          
       ;

/*Reglas de produccion para poder leer por teclado diferentes elementos*/
read_list : IDEN
       {
        printf("read_list -> IDEN\n"); 
       }                                         
       | read_list COMA IDEN
       {
        printf("read_list -> read_list COMA IDEN\n");     
       }                                 
       ;

/*Reglas de produccion para expresiones aritmeticas*/
expression : expression SUMA expression
       {	
	printf("expression -> expression SUMA expression\n"); 
       }                   
       | expression REST expression       
       {
        printf("expression -> expression REST expression\n"); 
       }                  
       | expression MULT expression   
       {
        printf("expression -> expression MULT expression\n"); 
       }                          
       | expression DIVI expression
       {
        printf("expression -> expression DIVI expression\n");   
       }
	//Cambiar la precedencia de "-" como operador unario
       | REST expression        %prec UMINUS
       {
        printf("expression -> REST expression\n");  
       }                                  
       | PARI expression PARD
       {
        printf("expression -> PARI expression PARD\n");     
       }                  
       | IDEN
       {
        printf("expression -> IDEN\n");  
       }         
       | ENTERO
       {
        printf("expression -> ENTERO\n");   
       }                                           
       ;


%%

void yyerror()
{
printf("Se ha producido un error sintactico en esta expresion.\n");
}

int main() {
	
	return yyparse();
  
}
