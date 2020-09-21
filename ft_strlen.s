%include "libasm.mac"

section .text
	GLOBAL ft_strlen

ft_strlen:
	MOV	RAX, arg_1
	MOV	RBX, 0
	CMP	RAX, 0
	JZ	end
	CMP	BYTE [RAX], 0
	JZ	end
	while_not_null:
		INC	RAX
		INC	RBX
		CMP BYTE [RAX], 0
		JNZ	while_not_null
	end:
		MOV	return, RBX
		RET
