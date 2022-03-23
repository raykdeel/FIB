# (c) FIBerHub, https://fiberhub.tk
# Pràctica 2 - Activitat 2.A

	.data

	.text
	.globl main

main:
	li $s1, 23 # Y
	li $s0, 8  # X

	li $t0, 0x01
	sllv $t0, $t0, $s0
	addiu $t0, $t0, -1
	xor $s0, $s1, $t0
	
	jr $ra