# (c) FIBerHub, https://fiberhub.tk
# Pràctica 1 - Activitat 1.A

	.data

	.byte -5
	.half -344
	.dword -3
	.byte 0xA0
	.word 5799
	.half -1

	.text
	.globl main
main:
	jr $ra		# main retorna al codi de startup