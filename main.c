/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 21:00:25 by badam             #+#    #+#             */
/*   Updated: 2020/07/30 19:09:23 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libasm.h"

void	test_ft_strlen(const char *str, const size_t len)
{
	printf("%li:%zu\n", ft_strlen(str), len);
}

void	test_ft_strcpy(const char *str)
{
	char	*out;

	if (!(out = malloc((strlen(str) + 1) * sizeof(str))))
	{
		printf("Mallocation failed\n");
		return;
	}
	printf("IN: '%s' - ", str);
	printf("OUT: '%s'\n", ft_strcpy(out, str));
}

int		main(void)
{
	printf("Testing ft_strlen\n");
	test_ft_strlen("", 0);
	test_ft_strlen("t", 1);
	test_ft_strlen("test", 4);
	test_ft_strlen("Well tested !", 13);
	test_ft_strlen(NULL, 0);
	printf("Testing ft_strcpy\n");
	test_ft_strcpy("");
	test_ft_strcpy("t");
	test_ft_strcpy("test");
	test_ft_strcpy("Well tested !");
	printf(ft_strcpy(NULL, NULL) ? "Fail !\n" : "OK\n");
	printf(ft_strcpy(NULL, "Test mem") ? "Fail !\n" : "OK\n");
	printf(!ft_strcpy("Should not be touched", NULL) ? "Fail !\n" : "OK\n");
	//++ additionnal NULL tests
}
