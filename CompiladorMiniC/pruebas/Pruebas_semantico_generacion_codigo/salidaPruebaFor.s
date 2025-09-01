####################
# Seccion de datos
	.data

_x:
	.word 0
$str1:
	.asciiz "Valor de x: "
$str2:
	.asciiz "Fin bucle"

####################
# Seccion de codigo
	.text
	.globl main
main:
$l1:
	sw $t0,_x
	bgt $t0,$t1,$l2
	beqz $t1,$l2
	li $v0,4
	la $a0,$str1
	syscall
	lw $t1,_x
	li $v0,1
	move $a0,$t1
	syscall
	addi $t0,$t0,1
	b $l1
$l2:
	li $v0,4
	la $a0,$str2
	syscall
####################
# Fin
	li $v0,10
	syscall
