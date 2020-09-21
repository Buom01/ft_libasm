%include "libasm.mac"

section .text
	EXTERN	malloc
	GLOBAL	ft_create_elem

ft_create_elem:
	PUSH	arg_1
	MOV		arg_1, 32 
	CALL	malloc
	MOV		RBX, return
	POP		RCX
	CMP		RBX, 0
	JZ		exit
	MOV		QWORD [RBX], RCX
	MOV		QWORD [RBX+16], 0
	exit:
		RET
