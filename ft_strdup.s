# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strdup.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: badam <badam@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/06 05:19:08 by badam             #+#    #+#              #
#    Updated: 2020/08/13 13:49:33 by badam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
	IMUL	arg_1, 8
	CALL	malloc
	POP		RBX
	CMP		return, 0
	JZ		exit
	MOV		byte [return], 0
	MOV		arg_1, return
	MOV		arg_2, RBX
	CALL	ft_strcpy
	exit:
		RET
		
