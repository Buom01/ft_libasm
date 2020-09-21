%include "libasm.mac"

section .data
	begin_list_ptr	DQ	0
	prev_next_ptr	DQ	0
	elem			DQ	0
	next			DQ	0
	compare_fonct	DQ	0
	swapped			DW	0

section .text
	GLOBAL	ft_list_sort

ft_list_sort:
	CMP	arg_2, 0
	JZ	exit
	MOV [begin_list_ptr], arg_1
	MOV	[compare_fonct], arg_2
	do_while_swapped:
		MOV	WORD [swapped], 0

		MOV	RAX, [begin_list_ptr]
		CMP	RAX, 0
		JZ	exit
		MOV	[prev_next_ptr], RAX
		MOV	RAX, [RAX]
		MOV	[elem], RAX
		ADD	RAX, 8
		CMP	QWORD [RAX], 0
		JZ	exit
		MOV	[next], RAX
		while_next:
			MOV		RAX, [next]
			CMP		QWORD [RAX], 0
			JZ		end_while_next

			MOV		arg_1, [elem]
			MOV		arg_1, [arg_1]
			MOV		arg_2, [next]
			MOV		arg_2, [arg_2]
			MOV		arg_2, [arg_2]
			CALL	[compare_fonct]
			CMP		EAX, 0
			JLE		end_if_greater
				MOV	RBX, [next]
				MOV	RBX, [RBX]
				MOV	RCX, [elem]
				MOV	RAX, [prev_next_ptr]
				MOV	[RAX], RBX

				ADD	RBX, 8
				MOV	RDX, [RBX]
				ADD	RCX, 8
				MOV	[RCX], RDX
				SUB	RCX, 8
				MOV	[RBX], RCX

				MOV	RAX, [elem]
				MOV	RBX, [next]
				MOV	[elem], RBX
				MOV	[next], RAX 

				MOV	WORD [swapped], 1
			end_if_greater:

			MOV		RBX, [elem]
			ADD		RBX, 8
			MOV		[prev_next_ptr], RBX
			MOV		RAX, [next]
			MOV		RAX, [RAX]
			MOV		[elem], RAX
			ADD		RAX, 8
			MOV		[next], RAX
			JMP		while_next
		end_while_next:

		CMP	WORD [swapped], 0
		JNZ	do_while_swapped
	end_do_while_swapped:
		
	exit:
		RET
