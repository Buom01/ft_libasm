%include "libasm.mac"

section .text
	EXTERN	get_errno
	GLOBAL	ft_read

ft_read:
	MOV		RBX, arg_1
	MOV		RCX, arg_2
	MOV		RDX, arg_3
	CMP		EBX, 0
	JS		bad_fd
	do:
		MOV		RAX, syscall_read
		SYSCALL
		CMP		RAX, 0
		JS		return_to_error
		RET
	bad_fd:
		CALL	get_errno
		MOV		qword [return], err_badfd
		JMP		error
	return_to_error:
		CMP		RAX, 1
		JZ		error
		MOV		RBX, RAX
		IMUL	RBX, -1
		CALL	get_errno
		MOV		qword [return], RBX
	error:
		MOV		return, -1
		RET
