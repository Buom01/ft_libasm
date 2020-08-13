# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_list_remove_if_bonus.s                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: badam <badam@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/13 14:56:08 by badam             #+#    #+#              #
#    Updated: 2020/08/13 15:02:36 by badam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

%include "libasm.mac"

section .data
	begin_list_ptr	DQ	0
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
		JNZ		keep_elem
		MOV		RAX, [elem]
		MOV		arg_1, [RAX]
		CALL	[free_fonct]
		MOV		arg_1, [elem]
		CALL	free
		keep_elem:

		MOV		RAX, [next_elem]
		MOV		[elem], RAX
		JMP		while_elem
	end_while_elem:
	
	exit:
		RET
