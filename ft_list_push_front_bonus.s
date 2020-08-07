# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_list_push_front_bonus.s                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: badam <badam@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/06 20:56:59 by badam             #+#    #+#              #
#    Updated: 2020/08/06 22:56:53 by badam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

%include "libasm.mac"

SECTION .TEXT
	GLOBAL	ft_list_push_front

ft_list_push_front:
	MOV	RAX, arg_1
	MOV	RBX, arg_2
	CMP	RAX, 0
	JZ	exit
	CMP	RBX, 0
	JZ	exit
	MOV	RCX, RBX
	ADD	RCX, 8
	MOV	RDX, [RAX]
	MOV [RCX], RDX
	MOV	[RAX], RBX
	exit:
		RET
