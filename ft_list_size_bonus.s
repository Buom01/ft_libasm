%include "libasm.mac"

section .text
	GLOBAL	ft_list_size

ft_list_size:
	MOV	RAX, arg_1
	MOV	RBX, 0
	CMP	RAX, 0
	JZ	exit
	while_not_null:
		ADD	RAX, 8
		ADD	RBX, 1
		MOV	RAX, [RAX]
		CMP	RAX, 0
		JNZ	while_not_null
	exit:
		MOV	return, RBX
		RET 
