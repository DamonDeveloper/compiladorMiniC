####################
# Seccion de datos
	.data

_x:
	.word 0
$str1:
	.asciiz "Hola"

####################
# Seccion de codigo
	.text
	.globl main
main:
	li $t0,0
	sw $t0,_x
$l1:
	lw $t0,_x
	li $t1,1
	add $t0,$t0,$t1
	sw $t0,_x
	li $v0,4
	la $a0,$str1
	syscall
	lw $t0,_x
	li $t1,5
	slt $t0,$t0,$t1
	beqz $t0,$l1
####################
# Fin
	li $v0,10
	syscall
