/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 21:00:25 by badam             #+#    #+#             */
/*   Updated: 2020/09/21 21:56:44 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <strings.h>
#include <string.h>
#include "libasm.h"

int		cmp(char *str1, char *str2)
{
	printf("%c %c, %s %s, %i\n", *str1, *str2, str1, str2, strcmp(str1, str2));
	return (strcmp(str1, str2));
}

int		main(void)
{
	t_list	elem1;
	t_list	elem2;
	t_list	elem3;
	t_list	*elem1_p;
	t_list	*elem2_p;
	t_list	*elem3_p;
	t_list	*elem4_p;
	t_list	*elem5_p;
	void	*pointer;
	t_list	*list;
	
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
	
	printf("\n==> Testing ft_create_elem\n\n");
	pointer = strdup("test");
	elem1_p = ft_create_elem(pointer);
	printf("%s:test | %p:(nil)\n", (char*)elem1_p->data, elem1_p->next);
	free(pointer);
	free(elem1_p);
	elem1_p = ft_create_elem(NULL);
	printf("%s:(null) | %p:(nil)\n", (char*)elem1_p->data, elem1_p->next);
	free(elem1_p);

	printf("\n==> Testing ft_list_push_front\n\n");
	list = &elem1;
	pointer = strdup("testdata");
	printf("(&&elem1, strdup(\"testdata\")) => ");
	ft_list_push_front(&list, pointer);
	printf(list->data == pointer && list->next == &elem1 ? "OK\n" : "Fail\n");
	printf("%s:testdata | %p:%p\n", (char*)list->data, list->next, &elem1);
	if (list->data == pointer)
		free(list);
	free(pointer);
	list = NULL;
	pointer = strdup("data");
	printf("(&null, strdup(\"data\")) => ");
	ft_list_push_front(&list, pointer);
	printf(list->data == pointer && list->next == NULL ? "OK\n" : "Fail\n");
	printf("%s:data | %p:(nil)\n", (char*)list->data, list->next);
	if (list->data == pointer)
		free(list);
	free(pointer);
	list = &elem1;
	printf("(&&elem1, NULL) => ");
	ft_list_push_front(&list, NULL);
	printf(list->data == NULL && list->next == &elem1 ? "OK\n" : "Fail\n");
	printf("%s:(null) | %p:%p\n", (char*)list->data, list->next, &elem1);
	if (list->next == &elem1)
		free(list);

	printf("\n==> Testing ft_list_remove_if\n\n");
	elem1_p = ft_create_elem(strdup("data"));
	elem2_p = ft_create_elem(strdup("data2"));
	elem3_p = ft_create_elem(strdup("data3"));
	elem1_p->next = elem2_p;
	elem2_p->next = elem3_p;
	list = elem1_p;
	printf("Initial: %s:data | %s:data2 | %s:data3 | %p:(nil)\n", (char*)list->data, (char*)list->next->data, (char*)list->next->next->data, list->next->next->next);
	pointer = strdup("data2");
	ft_list_remove_if(&list, pointer, strcmp, free);
	free(pointer);
	printf("%s:data | %s:data3 | %p:(nil)\n", (char*)list->data, (char*)list->next->data, list->next->next);
	pointer = strdup("data");
	ft_list_remove_if(&list, pointer, strcmp, free);
	free(pointer);
	printf("%s:data3 | %p:(nil)\n", (char*)list->data, list->next);
	pointer = strdup("data3");
	ft_list_remove_if(&list, pointer, strcmp, free);
	free(pointer);
	printf("%p:(nil)\n", list);

	elem1_p = ft_create_elem(strdup("data"));
	elem2_p = ft_create_elem(strdup("data"));
	elem3_p = ft_create_elem(strdup("data"));
	elem1_p->next = elem2_p;
	elem2_p->next = elem3_p;
	list = elem1_p;
	printf("Initial: %s:data | %s:data | %s:data | %p:(nil)\n", (char*)list->data, (char*)list->next->data, (char*)list->next->next->data, list->next->next->next);
	pointer = strdup("data2");
	ft_list_remove_if(&list, pointer, strcmp, free);
	free(pointer);
	printf("%s:data | %s:data | %s:data | %p:(nil)\n", (char*)list->data, (char*)list->next->data, (char*)list->next->next->data, list->next->next->next);
	pointer = strdup("data");
	ft_list_remove_if(&list, pointer, strcmp, free);
	free(pointer);
	printf("%p:(nil)\n", list);

	printf("\n==> Testing ft_list_sort\n\n");
	elem1_p = ft_create_elem(strdup("c"));
	elem2_p = ft_create_elem(strdup("b"));
	elem3_p = ft_create_elem(strdup("e"));
	elem4_p = ft_create_elem(strdup("a"));
	elem5_p = ft_create_elem(strdup("d"));
	elem1_p->next = elem2_p;
	elem2_p->next = elem3_p;
	elem3_p->next = elem4_p;
	elem4_p->next = elem5_p;
	list = elem1_p;
	printf("Initial: %s:a | %s:c | %s:b | %s:d | %s:e | %p:(nil)\n", (char*)list->data, (char*)list->next->data, (char*)list->next->next->data, (char*)list->next->next->next->data, (char*)list->next->next->next->next->data, list->next->next->next->next->next);
	ft_list_sort(&list, cmp);
	printf("%s:a | %s:b | %s:c | %s:d | %s:e | %p:(nil)\n", (char*)list->data, (char*)list->next->data, (char*)list->next->next->data, (char*)list->next->next->next->data, (char*)list->next->next->next->next->data, list->next->next->next->next->next);
	free(elem1_p->data);
	free(elem1_p);
	free(elem2_p->data);
	free(elem2_p);
	free(elem3_p->data);
	free(elem3_p);
	free(elem4_p->data);
	free(elem4_p);
	free(elem5_p->data);
	free(elem5_p);
}
