.data

A: .word    2,-1,-1,-2, 0,-7
            1,-4, 0, 0, 1, 2
            1, 2, 8, 2,-2,-3
            0, 4,-2, 3, 0, 1                                                                    

.text
.globl  main
main:
	li $t0, 0 #i=0
	li $t3, 4 #$t3 = 4
for1: 	bge $t0, $t3, fii #+++++++++++++++1
	li $t1, 0 #j = 0
for2:	bge $t1, $t0, fij  #+++++++++++++++2
	la $t4, A #adreça A
	li $t6, 6
	mult $t0, $t6 #i*6
	mflo $t6 #sll $t5, $t0, 6 #i*6	addu $t5, $t5, $t1 #i*6+j
	addu $t6, $t6, $t1 #i*6+j
	sll $t6, $t6, 2 #(j*6+1)*4
	addu $t6, $t6, $t4  #adreça final
	lw $t6, 0($t6)
	bge $t6, $zero, else
	sll $t6, $t6, 1
	li $t5, 6
	mult $t1, $t5 #j*6
	mflo $t5 #sll $t5, $t0, 6 #i*6	addu $t5, $t5, $t1 #i*6+j
	addu $t5, $t5, $t0 #j*6+i
	sll $t5, $t5, 2 #(j*6+1)*4
	addu $t5, $t5, $t4  #adreça final
	lw $t5, 0($t5) 
	subu $t2, $t5, $t6
	
else:
	move $t2, $t6
	li $t5, 6
	mult $t1, $t5 #j*6
	mflo $t5 #sll $t5, $t0, 6 #i*6	addu $t5, $t5, $t1 #i*6+j
	addu $t5, $t5, $t0 #j*6+i
	sll $t5, $t5, 2 #(j*6+1)*4
	addu $t5, $t5, $t4  #adreça final
	sw $t2, 0($t5)
	addiu $t1, $t1, 2
	b for2
fij:
	addiu $t0, $t0, 1
	b for1
	
fii: 
      jr  $ra 

