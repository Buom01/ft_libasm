# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcmp.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: badam <badam@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/02 23:25:59 by badam             #+#    #+#              #
#    Updated: 2020/08/13 13:49:09 by badam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

%include "libasm.mac"

section .text
	GLOBAL ft_strcmp

ft_strcmp:
	MOV	RAX, arg_1
	MOV	RBX, arg_2
	CMP	RAX, 0
	JZ	return_null
	CMP	RBX, 0
	JZ	return_null
	SUB	RAX, 1
	SUB	RBX, 1
	while_equal:
		ADD	RAX, 1
		ADD	RBX, 1
		MOV	CL, [RAX]
		CMP	byte [RAX], 0
		JZ	end
		CMP	BYTE [RBX], CL
		JZ	while_equal
	end:
		MOV	RCX, 0
		MOV	RDX, 0
		MOV	CL, BYTE [RAX]
		MOV DL, BYTE [RBX]
		SUB	RCX, RDX
		MOV	return, RCX
		RET
	return_null:
		MOV	return, 0
		RET
