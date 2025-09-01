####################
# Seccion de datos
	.data

_a:
	.word 0
_b:
	.word 0
_c:
	.word 0

####################
# Seccion de codigo
	.text
	.globl main
main:
	li $t0,2
	sw $t0,_a
	li $t0,3
	sw $t0,_c
	li $t0,4
	sw $t0,_a
	li $t0,4
	sw $t0,_b
	li $v0,5
	syscall
	sw $v0,_a
	lw $t0,_c
	li $v0,1
	move $a0,$t0
	syscall
####################
# Fin
	li $v0,10
	syscall
