	.data
X: 	.word 1, 2, 3, 4
Y:	.word 1, 2, 3, 4
	.align 2
Z:	.space 64

	.text
	.globl main
main:
	la	$t0, X
	la	$t1, Y
	la	$t2, Z

	move	$t3, $zero # $t3 = i = 0
	li	$t4, 4	
outer:
	bge	$t3, $t4, out # i < 4?
	sll	$t5, $t3, 2
	addu	$t5, $t5, $t0
	lw	$t5, 0($t5) # $t5 = X[i]
	addu	$t5, $t5, $t5 # $t5 = 2*X[i]
	
	move	$t6, $zero # $t6 = j = 0
inner:
	bge	$t6, $t4, out_inner # j < 4?
	sll	$t7, $t6, 2
	addu	$t7, $t7, $t1
	lw	$t7, 0($t7) # $t7 = Y[j]
	addu	$t7, $t5, $t7 # $t7 = 2*X[i] + Y[j]
	sw	$t7, 0($t2) # store a Z[i][j]
	
	addiu	$t2, $t2, 4 # Sumem a Z el stride entre dos elements de la matriu
	addiu	$t6, $t6, 1 # j++
	b 	inner
	
out_inner:
	addiu	$t3, $t3, 1 # i++
	b 	outer

out:
	jr 	$ra

		