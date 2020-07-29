%include "libasm.mac"

GLOBAL ft_strlen

ft_strlen:
	MOV	RAX, arg_1
	MOV	RBX, 0
	CMP	RAX, 0
	JZ	endif
	CMP	BYTE [RAX], 0
	JZ	endif
	while_not_null:
		ADD	RAX, 1
		ADD	RBX, 1
		CMP BYTE [RAX], 0
		JNZ	while_not_null
	endif:
		MOV	return, RBX
		RET
