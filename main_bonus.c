/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 21:00:25 by badam             #+#    #+#             */
/*   Updated: 2020/08/13 15:45:20 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <strings.h>
#include "libasm.h"

int		main(void)
{
	t_list	elem1;
	t_list	elem2;
	t_list	elem3;
	t_list	*pointer;
	
	printf("==> Testing ft_atoi_base\n\n");
	printf("(NULL, NULL) => ");
	printf("%i:0\n", ft_atoi_base(NULL, NULL));
	printf("(NULL, \"abc\") => ");
	printf("%i:0\n", ft_atoi_base(NULL, "abc"));
	printf("(\"abc\", NULL) => ");
	printf("%i:0\n", ft_atoi_base("abc", NULL));
	printf("(\"abc\", \"abc\") => ");
	printf("%i:5\n", ft_atoi_base("abc", "abc"));
	printf("(\"a\", \"abc\") => ");
	printf("%i:0\n", ft_atoi_base("a", "abc"));
	printf("(\"b\", \"abc\") => ");
	printf("%i:1\n", ft_atoi_base("b", "abc"));

	printf("(\"1\", \"0123456789\") => ");
	printf("%i:1\n", ft_atoi_base("1", "0123456789"));
	printf("(\"2\", \"0123456789\") => ");
	printf("%i:2\n", ft_atoi_base("2", "0123456789"));
	printf("(\"5\", \"0123456789\") => ");
	printf("%i:5\n", ft_atoi_base("5", "0123456789"));
	printf("(\"9\", \"0123456789\") => ");
	printf("%i:9\n", ft_atoi_base("9", "0123456789"));
	printf("(\"09\", \"0123456789\") => ");
	printf("%i:9\n", ft_atoi_base("09", "0123456789"));
	printf("(\"90\", \"0123456789\") => ");
	printf("%i:90\n", ft_atoi_base("90", "0123456789"));

	printf("(\"55\", \"0123456789\") => ");
	printf("%i:55\n", ft_atoi_base("55", "0123456789"));
	printf("(\"555\", \"0123456789\") => ");
	printf("%i:555\n", ft_atoi_base("555", "0123456789"));
	printf("(\"5555\", \"0123456789\") => ");
	printf("%i:5555\n", ft_atoi_base("5555", "0123456789"));
	printf("(\"9999\", \"0123456789\") => ");
	printf("%i:9999\n", ft_atoi_base("9999", "0123456789"));
	printf("(\"0000\", \"0123456789\") => ");
	printf("%i:0\n", ft_atoi_base("0000", "0123456789"));
	printf("(\"5385\", \"0123456789\") => ");
	printf("%i:5385\n", ft_atoi_base("5385", "0123456789"));
	printf("(\"-0000\", \"0123456789\") => ");
	printf("%i:0\n", ft_atoi_base("-0000", "0123456789"));
	printf("(\"-\", \"0123456789\") => ");
	printf("%i:0\n", ft_atoi_base("-", "0123456789"));
	printf("(\"-1\", \"0123456789\") => ");
	printf("%i:-1\n", ft_atoi_base("-1", "0123456789"));
	printf("(\"--1\", \"0123456789\") => ");
	printf("%i:1\n", ft_atoi_base("--1", "0123456789"));
	printf("(\"+-+99\", \"0123456789\") => ");
	printf("%i:-99\n", ft_atoi_base("+-+99", "0123456789"));
	printf("(\"\\t\\t-+---0990\", \"0123456789\") => ");
	printf("%i:990\n", ft_atoi_base("\t\t-+---0990", "0123456789"));

	printf("(\"1\", \"00123456789\") => ");
	printf("%i:0\n", ft_atoi_base("1", "00123456789"));
	printf("(\"1\", \"01234567890\") => ");
	printf("%i:0\n", ft_atoi_base("1", "01234567890"));
	printf("(\"1\", \"0123-456789\") => ");
	printf("%i:0\n", ft_atoi_base("1", "0123-456789"));
	printf("(\"1\", \"+0123456789\") => ");
	printf("%i:0\n", ft_atoi_base("1", "+0123456789"));
	printf("(\"1\", \"0123456789 \") => ");
	printf("%i:0\n", ft_atoi_base("1", "0123456789 "));
	printf("(\"1\", \"0123456789\\v\") => ");
	printf("%i:0\n", ft_atoi_base("1", "0123456789\v"));

	bzero(&elem1, sizeof(elem1));
	bzero(&elem2, sizeof(elem2));
	bzero(&elem3, sizeof(elem3));

	printf("\n==> Testing ft_list_size\n\n");
	printf("(NULL) -> ");
	printf("%i : OK (nocrash)\n", ft_list_size(NULL));
	printf("(elem1) -> 1:");
	printf("%i\n", ft_list_size(&elem1));
	elem1.next = &elem2;
	printf("(elem1) -> 2:");
	printf("%i\n", ft_list_size(&elem1));
	elem2.next = &elem3;
	printf("(elem1) -> 3:");
	printf("%i\n", ft_list_size(&elem1));

	bzero(&elem1, sizeof(elem1));
	bzero(&elem2, sizeof(elem2));
	bzero(&elem3, sizeof(elem3));
	
	printf("\n==> Testing ft_list_push_front\n\n");
	printf("(NULL, NULL) -> ");
	ft_list_push_front(NULL, NULL);
	printf("OK (no crash)\n");
	pointer = &elem1;
	printf("(&&elem1, NULL) -> ");
	ft_list_push_front(&pointer, NULL);
	printf(pointer == &elem1 ? "OK\n" : "Fail\n");
	pointer = NULL;
	printf("(&NULL, elem2) -> ");
	ft_list_push_front(&pointer, &elem2);
	printf(pointer == &elem2 && elem2.next == NULL ? "OK\n" : "Fail\n");
	pointer = &elem1;
	printf("(&&elem1, elem2) -> ");
	ft_list_push_front(&pointer, &elem2);
	printf(pointer == &elem2 && elem2.next == &elem1 ? "OK\n" : "Fail\n");
}
