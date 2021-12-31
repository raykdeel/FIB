# (c) FIBerHub, https://fiberhub.tk

.text
	.align 4
	.globl procesar
	.type	procesar, @function
procesar:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	pushl	%ebx
	pushl	%esi
	pushl	%edi

# Aqui has de introducir el codigo

	movl 16(%ebp), %edx 	#edx = n
	imul %edx, %edx 		#edx = n^2

	movl 8(%ebp), %eax		#eax = @mata
	movl 12(%ebp), %ebx 	#ebx = @matb

	addl %eax, %edx 		#edx = @mata[n^2]

for:	cmp %eax, %edx
	jle fifor

	movdqu (%eax), %xmm0 	#xmm0 = mata[0] .. mata[15]

	paddb %xmm0, %xmm0
	paddb %xmm0, %xmm0
	paddb %xmm0, %xmm0
	paddb %xmm0, %xmm0 		#xmm0 = mata[0]*16 .. mata[15]*16
	
	movdqu %xmm0, (%ebx) 	#matb[0] .. matb[15] = mata[0]*16 .. mata[15]*16

	addl $16, %eax
	addl $16, %ebx

	jmp for
	
fifor:


# El final de la rutina ya esta programado

	emms	# Instruccion necesaria si os equivocais y usais MMX
	popl	%edi
	popl	%esi
	popl	%ebx
	movl %ebp,%esp
	popl %ebp
	ret
