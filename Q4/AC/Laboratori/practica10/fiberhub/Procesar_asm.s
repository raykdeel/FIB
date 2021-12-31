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

    movl 8(%ebp), %eax      #eax = mata
    movl 12(%ebp), %ebx     #ebx = matb
    
    movl 16(%ebp), %ecx     #ecx = n
    imul %ecx, %ecx        	#ecx = n^2
    addl %eax, %ecx        	#ecx = @mata[n^2]


for:cmp %eax, %ecx
    jle fifor          		#jmp if @mata[n^2] <= @mata[i]

    movb (%eax), %dl      	#dl = mata[i]
    salb $4, %dl			#dl = dl << 4
    movb %dl, (%ebx)    	#matb[i] = dl

    incl %eax
    incl %ebx
    jmp for
    
fifor:  

# El final de la rutina ya esta programado

	popl	%edi
	popl	%esi
	popl	%ebx
	movl %ebp,%esp
	popl %ebp
	ret

