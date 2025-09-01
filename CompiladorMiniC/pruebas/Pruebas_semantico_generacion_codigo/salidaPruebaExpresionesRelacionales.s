####################
# Seccion de datos
	.data

_x:
	.word 0
$str1:
	.asciiz "Valor de x:"

####################
# Seccion de codigo
	.text
	.globl main
main:
	li $t0,3
	sw $t0,_x
$l2:
	li $v0,4
	la $a0,$str1
	syscall
	lw $t0,_x
	li $v0,1
	move $a0,$t0
	syscall
	lw $t0,_x
	li $t1,1
	sub $t0,$t0,$t1
	sw $t0,_x
	lw $t0,_x
	li $t1,0
	li $t1,0
	blt $t0,$t1,$l1
	li $t1,1
$l1:
	move $t0,$t1
	beqz $t0,$l2
####################
# Fin
	li $v0,10
	syscall
