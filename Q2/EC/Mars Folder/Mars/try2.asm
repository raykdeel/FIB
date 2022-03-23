.data
 a: .asciiz "AB"
 b: .word -5
 c: .half 8, 12, -16
 d: .float 1.75
 e: .word 0x1001000c
 
	.text
	.globl main
main:
	la $t0, d
	lwc1 $f0, 0($t0)
	div.s $f1, $f0, $f0
	sub.s $f0, $f0, $f1
