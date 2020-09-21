%include "libasm.mac"

section .text
	EXTERN	ft_create_elem
	GLOBAL	ft_list_push_front

ft_list_push_front:
	CMP		arg_1, 0
	JZ		exit
	PUSH	arg_1
	MOV		arg_1, arg_2
	CALL	ft_create_elem
	POP		RCX
	CMP		return, 0
	JZ		exit
	MOV		RBX, return
	ADD		RBX, 8
	MOV		RDX, [RCX]
	MOV		[RBX], RDX
	MOV		[RCX], return
	exit:
		RET
