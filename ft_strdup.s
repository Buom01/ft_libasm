%include "libasm.mac"

section .text
	EXTERN	malloc
	EXTERN	ft_strlen
	EXTERN	ft_strcpy
	GLOBAL	ft_strdup

ft_strdup:
	MOV		return, 0
	PUSH	arg_1
	CALL	ft_strlen
	MOV		arg_1, return
	ADD		arg_1, 1
	CALL	malloc
	POP		RBX
	CMP		return, 0
	JZ		exit
	MOV		BYTE [return], 0
	MOV		arg_1, return
	MOV		arg_2, RBX
	PUSH	return
	CALL	ft_strcpy
	POP		return
	exit:
		RET
		
