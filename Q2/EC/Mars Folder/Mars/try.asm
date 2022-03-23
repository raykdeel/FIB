	.data
 a: 	.asciiz "abcd"
 b: 	.half 10, -7
 c: 	.word 0x10010006 #asignar l'adreça manualment
 d: 	.byte 0x03
	.align 1
 e: 	.space 4
 f: 	.word 256
 
	.text
	.globl main
main:
	li $t0, -3
	sra $t1, $t0, 31
	xor $t0, $t0, $t1
	subu $t0, $t0, $t1
	sll $t1, $t1, 31
	or $t0, $t0, $t1
