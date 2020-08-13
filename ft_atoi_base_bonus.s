# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_atoi_base_bonus.s                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: badam <badam@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/13 13:48:15 by badam             #+#    #+#              #
#    Updated: 2020/08/13 15:46:02 by badam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

%include "libasm.mac"

section .data
	numstr		DQ	0
	base		DQ	0
	numstrlen	DQ	0
	baselen		DQ	0
	num			DQ	0
	sign		DQ	1

section .text
	EXTERN	ft_strlen
	GLOBAL	ft_atoi_base

is_char_space:
	CMP BYTE [arg_1], `\t`
	JZ	char_is_space
	CMP BYTE [arg_1], `\n`
	JZ	char_is_space
	CMP BYTE [arg_1], `\v`
	JZ	char_is_space
	CMP BYTE [arg_1], `\f`
	JZ	char_is_space
	CMP BYTE [arg_1], `\r`
	JZ	char_is_space
	CMP BYTE [arg_1], ' '
	JZ	char_is_space
	char_isnt_space:
		MOV	return, 0
		RET
	char_is_space:
		MOV return, 1
		RET

is_char_sign:
	CMP BYTE [arg_1], '+'
	JZ	char_is_sign
	CMP BYTE [arg_1], '-'
	JZ	char_is_sign
	char_isnt_sign:
		MOV	return, 0
		RET
	char_is_sign:
		MOV return, 1
		RET

test_base:
	MOV	RAX, arg_1
	MOV	RBX, arg_2
	CMP	RBX, 1
	JS	invalid_base

	MOV	RBX, RAX
	while_not_null:
		CMP		BYTE [RBX], 0
		JZ		end_while_not_null

		MOV		arg_1, RBX
		CALL	is_char_sign
		CMP		return, 1
		JZ		invalid_base
		MOV		arg_1, RBX
		CALL	is_char_space
		CMP		return, 1
		JZ		invalid_base

		MOV		RCX, RBX
		ADD		RCX, 1
		MOV		DL, BYTE [RBX]

		while_not_null_2:
			CMP	BYTE [RCX], 0
			JZ	end_while_not_null_2

			CMP	DL, BYTE [RCX]
			JZ	invalid_base

			INC	RCX
			JMP	while_not_null_2
		end_while_not_null_2:

		INC		RBX
		JMP 	while_not_null
	end_while_not_null:

	valid_base:
		MOV	return, 1
		RET
	invalid_base:
		MOV	return, 0
		RET

ft_atoi_base:
	MOV		QWORD [numstr], arg_1
	MOV		QWORD [base], arg_2
	MOV		QWORD [num], 0
	MOV		QWORD [sign], 1
	CMP		QWORD [numstr], 0
	JZ		exit
	CMP		QWORD [base], 0
	JZ		exit
	CALL	ft_strlen
	MOV		[numstrlen], return
	CMP		QWORD [numstrlen], 0
	JZ		exit
	MOV		arg_1, [base]
	CALL	ft_strlen
	MOV		[baselen], return
	MOV		arg_1, [base]
	MOV		arg_2, [baselen]
	CALL	test_base
	CMP		return, 1
	JNZ		exit

	while_space:
		MOV		RBX, [numstr]
		CMP		BYTE [RBX], 0
		JZ		exit
		MOV		arg_1, [numstr]
		CALL	is_char_space
		CMP		return, 0
		JZ		end_while_space

		INC	QWORD [numstr]
		JMP	while_space
	end_while_space:
	
	while_sign:
		MOV		RBX, [numstr]
		CMP		BYTE [RBX], 0
		JZ		exit
		MOV		arg_1, [numstr]
		CALL	is_char_sign
		CMP		return, 0
		JZ		end_while_sign

		MOV		RBX, [numstr]
		CMP		BYTE [RBX], '-'
		JNZ		not_neg
		MOV		RBX, QWORD [sign]
		IMUL	RBX, -1
		MOV		QWORD [sign], RBX
		not_neg:

		INC		QWORD [numstr]
		JMP		while_sign
	end_while_sign:

	MOV		RAX, [num]
	while_digit:
		MOV		RBX, [numstr]
		CMP		BYTE [RBX], 0
		JZ		end_while_digit
		
		MOV		RCX, [base]
		while_not_in_base:
			CMP	BYTE [RCX], 0
			JZ	end_while_digit
			MOV	RDX, [numstr]
			MOV DL, BYTE [RDX]
			CMP BYTE [RCX], DL
			JZ	end_while_not_in_base

			INC	RCX
			JMP	while_not_in_base
		end_while_not_in_base:

		SUB		RCX, [base]

		IMUL	RAX, [baselen]
		ADD		RAX, RCX

		INC		QWORD [numstr]
		JMP		while_digit
	end_while_digit:
	MOV		[num], RAX

	finish:
		MOV		return, [num]
		IMUL	return, [sign]
		RET
	exit:
		MOV return, 0
		RET
