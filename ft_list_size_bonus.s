# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_list_size_bonus.s                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: badam <badam@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/06 17:03:06 by badam             #+#    #+#              #
#    Updated: 2020/08/06 22:54:15 by badam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

%include "libasm.mac"

SECTION .TEXT
	GLOBAL	ft_list_size

ft_list_size:
	MOV	RAX, arg_1
	MOV	RBX, 0
	CMP	RAX, 0
	JZ	exit
	while_not_null:
		ADD	RAX, 8
		ADD	RBX, 1
		MOV	RAX, [RAX]
		CMP	RAX, 0
		JNZ	while_not_null
	exit:
		MOV	return, RBX
		RET 
