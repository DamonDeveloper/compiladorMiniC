####################
# Seccion de datos
	.data

_x:
	.word 0
_y:
	.word 0
$str1:
	.asciiz "Hola mundo"
$str2:
	.asciiz "Adios mundo"

####################
# Seccion de codigo
	.text
	.globl main
main:
	li $t0,3
	sw $t0,_x
	li $t0,1
	sw $t0,_y
$l2:
	lw $t0,_x
	beqz $t0,$l3
	lw $t1,_x
	li $t1,1
	sub $t1,$t1,$t1
	sw $t1,_x
	lw $t1,_x
	beqz $t1,$l1
	lw $t1,_x
	li $v0,1
	move $a0,$t1
	syscall
$l1:
	lw $t1,_x
	li $v0,1
	move $a0,$t1
	syscall
	li $v0,4
	la $a0,$str1
	syscall
	li $v0,4
	la $a0,$str2
	syscall
	b $l2
$l3:
####################
# Fin
	li $v0,10
	syscall
