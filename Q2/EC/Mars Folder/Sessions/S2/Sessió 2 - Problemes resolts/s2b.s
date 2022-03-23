# (c) FIBerHub, https://fiberhub.tk
# Pràctica 2 - Activitat 2.B

	.data
result: .word 0
num:	.byte '7'

	.text
	.globl main

main:
	la $t0, num
	lb $t0, 0($t0)
	la $t1, result

	li $t2, 'a'
	blt $t0, $t2, if
	li $t2, 'z'
	ble $t0, $t2, end

if:	li $t2, 'A'
	blt $t0, $t2, if2
	
	li $t2, 'Z'
	ble $t0, $t2, end

if2:	li $t2, '0'
	blt $t0, $t2, else

	li $t2, '9'
	bgt $t0, $t2, else

	addiu $t0, $t0, -48
	b end
	
else:	li $t0, -1

end:	sw $t0, 0($t1) 

	jr $ra