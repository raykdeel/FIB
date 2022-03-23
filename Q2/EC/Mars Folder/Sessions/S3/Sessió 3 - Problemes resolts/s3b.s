# (c) FIBerHub, https://fiberhub.tk
# Pràctica 3 - Activitat 3.B

	.data 
mat1: 	.space 120
mat4: 	.word 2, 3, 1, 2, 4, 3
col:	.word 2

	.text 
	.globl main
main:
	addiu $sp, $sp, -4
	sw $ra, 0($sp)
	
	la $a0, mat4
	lw $a1, 8($a0)
	la $a2, col
	lw $a2, 0($a2)
	jal subr
	
	la $t0, mat1
	sw $v0, 108($t0)
	la $a0, mat4
	li $a1, 1
	li $a2, 1
	jal subr
	
	la $t0, mat1
	sw $v0, 0($t0)
	
	lw $ra, 0($sp)
	addiu $sp, $sp, 4
	jr $ra

subr:
	la $t0, mat1
	li $t1, 24
	multu $a2, $t1
	mflo $t1
	addu $t0, $t0, $t1
	li $t1, 6
	mult $a1, $t1
	mflo $t1
	addu $t1, $t1, $a2
	sll $t1, $t1, 2
	addu $t1, $a0, $t1
	lw $t1, -12($t1)
	sw $t1, 20($t0)
	move $v0, $a1
	
	jr $ra