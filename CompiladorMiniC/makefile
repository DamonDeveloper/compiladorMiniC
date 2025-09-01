minic: main.c sintactico.tab.c lex.yy.c listaSimbolos.c sintactico.tab.h listaSimbolos.h listaCodigo.h listaCodigo.c
	gcc lex.yy.c main.c sintactico.tab.c listaSimbolos.c listaCodigo.c -lfl -o minic
sintactico.tab.c sintactico.tab.h: sintactico.y
	bison -d -v sintactico.y
lex.yy.c: lexico.l
	flex lexico.l
clear:
	rm lex.yy.c sintactico.tab.c sintactico.tab.h sintactico.output minic

