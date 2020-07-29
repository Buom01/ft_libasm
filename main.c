/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 21:00:25 by badam             #+#    #+#             */
/*   Updated: 2020/07/29 13:39:54 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libasm.h"

int	main(void)
{
	printf("Testing ft_strlen\n");
	printf("%li:0\n", ft_strlen(""));
	printf("%li:4\n", ft_strlen("test"));
	printf("%li:1\n", ft_strlen("t"));
	printf("%li:13\n", ft_strlen("Well tested !"));
	printf("%li:0\n", ft_strlen(NULL));
}
