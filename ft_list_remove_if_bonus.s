%include "libasm.mac"

section .data
	begin_list_ptr	DQ	0
	prev_next_ptr	DQ	0
	elem			DQ	0
	next_elem		DQ	0
	data_ref		DQ	0
	compare_fonct	DQ	0
	free_fonct		DQ	0

section .text
	EXTERN	free
	GLOBAL	ft_list_remove_if

ft_list_remove_if:
	MOV	[begin_list_ptr], arg_1
	MOV	[prev_next_ptr], arg_1
	MOV	[data_ref], arg_2
	MOV	[compare_fonct], arg_3
	MOV	[free_fonct], arg_4
	CMP	DWORD [begin_list_ptr], 0
	JZ	exit
	MOV	RAX, QWORD [begin_list_ptr]
	MOV	RAX, [RAX]
	MOV	QWORD [elem], RAX

	while_elem:
		CMP		QWORD [elem], 0
		JZ		end_while_elem
		MOV		RAX, [elem]
		ADD		RAX, 8
		MOV		RAX, [RAX]
		MOV		QWORD [next_elem], RAX

		MOV		RAX, [elem]
		MOV		arg_1, [RAX]
		MOV		arg_2, [data_ref]
		CALL	[compare_fonct]
		CMP		return, 0
		JNZ		end_if_remove
			MOV		RAX, [elem]
			MOV		arg_1, [RAX]
			CALL	[free_fonct]
			MOV		arg_1, [elem]
			CALL	free
			MOV		RAX, [next_elem]
			MOV		RBX, [prev_next_ptr]
			MOV		[RBX], RAX
		end_if_remove:

		MOV		RAX, [elem]
		ADD		RAX, 8
		MOV		[prev_next_ptr], RAX
		MOV		RAX, [next_elem]
		MOV		[elem], RAX
		JMP		while_elem
	end_while_elem:
	
	exit:
		RET
