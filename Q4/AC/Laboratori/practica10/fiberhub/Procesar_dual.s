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
	imul %edx, %edx 	#edx = n*n

	movl 8(%ebp), %eax	#eax = @mata
	movl 12(%ebp), %ebx 	#ebx = @matb

	addl %eax, %edx 	#edx = @mata[n*n]

  	movl %eax, %ecx		#ecx = @mata
  	andl $0xF, %ecx		#ecx = ecx & 0xF
  	cmp $0, %ecx
  	jne unaligned		#jmp if ecx != 0

  	movl %ebx, %ecx		#ecx = @matb
  	andl $0xF, %ecx
  	cmp $0, %ecx
  	jne unaligned		#jmp if ecx != 0

aligned:cmp %eax, %edx
	jle fifor

	movdqa (%eax), %xmm0 	#xmm0 = mata[0] .. mata[15]

	paddb %xmm0, %xmm0
	paddb %xmm0, %xmm0
	paddb %xmm0, %xmm0
	paddb %xmm0, %xmm0 	#xmm0 = mata[0]*16 .. mata[15]*16
	
	movdqa %xmm0, (%ebx) 	#matb[0]..matb[15] = mata[0]*16 .. mata[15]*16

	addl $16, %eax
	addl $16, %ebx

	jmp aligned

unaligned:cmp %eax, %edx
	jle fifor

	movdqu (%eax), %xmm0 	#xmm0 = mata[0] .. mata[15]

	paddb %xmm0, %xmm0
	paddb %xmm0, %xmm0
	paddb %xmm0, %xmm0
	paddb %xmm0, %xmm0 	#xmm0 = mata[0]*16 .. mata[15]*16
	
	movdqu %xmm0, (%ebx) 	#matb[0]..matb[15] = mata[0]*16 .. mata[15]*16

	addl $16, %eax
	addl $16, %ebx

	jmp unaligned

fifor:


# El final de la rutina ya esta programado

	emms	# Instruccion necesaria si os equivocais y usais MMX
	popl	%edi
	popl	%esi
	popl	%ebx
	movl %ebp,%esp
	popl %ebp
	ret
