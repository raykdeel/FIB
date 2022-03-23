# (c) FIBerHub, https://fiberhub.tk
# Pràctica 1 - Activitat 1.B

	.data
	
aa:	.byte -5
	
	.text
	.globl main
	
main:
	la $s3, aa
	li $s4, 65535
	li $s5, 65536
	move $s0, $s1

	jr $ra		# main retorna al codi de startup
