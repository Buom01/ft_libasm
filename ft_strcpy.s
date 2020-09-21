%include "libasm.mac"

section .text
	GLOBAL ft_strcpy

ft_strcpy:
	MOV	RAX, arg_1
	MOV	RBX, arg_2
	CMP	RAX, 0
	JZ	end
	CMP	RBX, 0
	JZ	end
	while_not_null:
		MOV	RCX, [RBX]
		MOV	[RAX], RCX
		ADD	RAX, 1
		ADD	RBX, 1
		CMP	BYTE [RBX], 0
		JNZ	while_not_null
	end:
		MOV	return, arg_1	
		RET	
