**Alumno:** Daniel Aliaga Sánchez 

## Descripción

Proyecto de de la asignatura de Compiladores cursada en la universidad de murcia en el curso 2024/2025 que consiste en la implementación de un compilador
para un lenguaje de programación simplificado de C, utilizando las herramientas Flex para el analizador léxico y Bison para el analizador sintáctico.

## Estructura del Repositorio
  - **CompìladorMiniC/**: directorio fuente del proyecto.
    - lexico.l: Código C que contiene la implementación del analizador léxico.
    - sintactico.y: Código C que contiene la implementación del analizador sintáctico y semántico así como la generación del código maquina(MIPS) correspondiente.
    - makefile: fichero para la fácil compilación del proyecto con el comando "make" resolviendo las dependencias y compilando todo el código necesario.
    - lex.yy.c: código C resultante de compilar el fichero lexico.l con la herramienta flex(comando "flex lexico.l").
    - sintactico.tab.h y sintatico.tab.c: codigo C resultante de compilar el fichero sintatico.y con la herramiento Bison(comando "bison -d -v sintatico.y").
    - listaCodigo.c y listaCódigo.h: estructura de datos para manejar las distintas sentencias en código maquina resultantes de la traducción del codigo miniC.
    - listaSimbolos.c y listaSimbolos.h : estructura de datos para registrar y manejar las distintas variables declaradas en el código minic.
    - main.c: código C que funciona como punto de arranque del compilador.
    - minic: ejecutable final resultado compilar el proyecto con el comando "make".
    - spim: ejecutable simulador para ejecutar código MIPS.
    - Memoeria: fichero pdf que detalla la elaboración del proyecto.
    - pruebas/: directorio con entradas de prueba y sus salidas esperadas correspondientes para probar el correcto funcionamiento de cada parte del compilador:
      - Pruebas_léxico/: directorio con el analizador léxico y una serie de entradas y salidas de prueba:
        - lexico.l y lexico.h: codigo C que implementa el analizador léxico.
        - lex.yy.c: codigo C resultante de la compilación del analizador léxico con la herramiento flex(comando "flex lexico.l lexico.h").
        - a.out: fichero ejecutable del analizador léxico.
        - ficherosDeEntradaYSalida/: directorio con las distintas entradas y salidas de prueba:
          - entradaPruebaLexico1, salidaPruebaLexico1; entradaPruebaLexico2, salidaPruebaLexico2: entradas y salidas de prueba(ver memoria para ver en detalle el objetivo de estas pruebas).
      - Pruebas_sintactico/: fichero con los analizadores lexico y sintáctico ademas de una serie de ficheros de entrada y salida de prueba:
        - lexico.l: codigo C que implementa el analizador léxico.
        - lex.yy.c: codigo C resultante de la compilación del analizador léxico con la herramiento flex(comando "flex lexico.l lexico.h").
        - sintactico.tab.h y sintatico.tab.c: codigo C resultante de compilar el fichero sintatico.y con la herramiento Bison(comando "bison -d -v sintatico.y").
        - a.out: fichero ejecutable del analizador léxico y sintático.
        - ficherosDeEntradaYSalida/: directorio con las distintas entradas y salidas de prueba:
          - entradaPruebaSintactico1, salidaPruebaSintactico1; entradaPruebaSintactico2, salidaPruebaSintactico2: entradas y salidas de prueba(ver memoria para ver en detalle el objetivo de estas pruebas).
      - Pruebas_semantico_generacion_codigo/: fichero con una gran variedad de entradas y salidas de prueba; la extension .mc simboliza código minic y la extensión .s simboliza código mips.

      
        
