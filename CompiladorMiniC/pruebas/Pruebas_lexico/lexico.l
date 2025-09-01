/* Codigo c */
%{
#include "lexico.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const long RANGO_ENTERO=2147483648;	/* 2³¹= 2.147.483.648 */
const int MAX_CARACTERES=32;
int hayError = 0;

/* Macros de expresiones  regulares */
%}
digito              [0-9]
letra               [a-zA-Z]
escape              (\\\"|\\\\)
modo_panico	    [^a-zA-Z0-9();,+\-{}=*"_/\t\n]+

%x COMENTARIO

%option yylineno

%%
[ \n\t]+                                    ;
"//"(.*)[\n]                                ;                   /* comentario 1 linea */
var                                         return VAR;
const                                       return CONST;
if                                          return IF;
else                                        return ELSE;
while                                       return WHILE;
print                                       return PRINT;
read                                        return READ;   
({letra}|_)({letra}|{digito}|_)*            {			/* Indentificador. No puede ser demasiado largo. */
                                            if(yyleng > MAX_CARACTERES) {
                                                printf("Error léxico: Identificador %s excede el limite de caracteres (32). Linea: %d. \n", yytext, yylineno);
                                                hayError = 1;
                                            }
                                            return IDEN;
                                            }
{digito}+                                   {			/* Entero, no puede salir del rango de los enteros */
                                            if(atoll(yytext) > RANGO_ENTERO) {
                                                printf("Error léxico: Entero %s fuera de rango (-2^31, 2^31 - 1). Linea: %d. \n", yytext, yylineno);
                                                hayError = 1;
                                            }
                                            return ENTERO;
                                            }
"("                                         return PARI;		
")"                                         return PARD;
"{"                                         return LLAVI;
"}"                                         return LLAVD;
";"                                         return PYCO;
","                                         return COMA;
"+"                                         return SUMA;
"-"                                         return REST;
"="                                         return ASIG;
"/"                                         return DIVI;
"*"                                         return MULT;


\"([^"\n]|{escape})*\"                      {
					    return CAD;
					    }
\"([^"\n]|{escape})*                        {
					    printf("Error léxico: Cadena abierta sin cerrar en la linea %d.\n", yylineno); 
					    hayError = 1;
					    } /*cadenna sin cerrar*/

"/*"                                            BEGIN(COMENTARIO);          /*comienzo de un comentario*/
<COMENTARIO>(.)                                    ;	  	     /*se valida caracter a caracter de un comentario*/
<COMENTARIO>"*/"                                BEGIN(0);            /*fin de un comentario*/
<COMENTARIO><<EOF>>                                { printf("Error léxico: Comentario abierto sin cerrar.\n"); hayError = 1; return 0; }   /*comentario sin cerrar*/

{modo_panico}			            {
					    printf("* Error léxico: Carácter \"%s\" no reconocido. Linea: %d.\n", yytext, yylineno); 
				            hayError = 1;
					    }
%%

int main(int argc, char *argv[]){

    int tok;
    while ( (tok = yylex()) !=0){
        printf("%s Token: %d\n", yytext, tok);

    }
}
