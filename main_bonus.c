/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 21:00:25 by badam             #+#    #+#             */
/*   Updated: 2020/08/07 04:14:21 by badam            ###   ########.fr       */
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

	bzero(&elem1, sizeof(elem1));
	bzero(&elem2, sizeof(elem2));
	bzero(&elem3, sizeof(elem3));

	printf("==> Testing ft_list_size\n\n");
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
