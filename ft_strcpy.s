# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcpy.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: badam <badam@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/30 14:06:56 by badam             #+#    #+#              #
#    Updated: 2020/08/05 18:02:57 by badam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

%include "libasm.mac"

SECTION .TEXT
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
