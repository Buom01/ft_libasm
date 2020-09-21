/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badam <badam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 21:00:25 by badam             #+#    #+#             */
/*   Updated: 2020/09/10 12:47:36 by badam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include "libasm.h"

void	test_ft_strlen(const char *str, const size_t len)
{
	printf("%li:%zu\n\n", ft_strlen(str), len);
}

void	test_ft_strcpy(const char *str)
{
	char	*out;

	if (!(out = malloc((strlen(str) + 1) * sizeof(str))))
	{
		printf("Mallocation failed\n");
		return;
	}
	printf("%s:", str);
	printf("%s\n\n", ft_strcpy(out, str));
	free(out);
}

void	test_ft_strcmp(const char *str1, const char *str2)
{
	printf("%i", ft_strcmp(str1, str2));
	printf(":%i\n\n", strcmp(str1, str2));
}

void	test_ft_write(int fd, const void *buf, size_t count)
{
	ssize_t	return_orig;
	ssize_t	return_cust;
	int		errno_orig;
	int		errno_cust;

	errno = 0;
	return_orig = write(fd, buf, count);
	errno_orig = errno;

	errno = 0;
	return_cust = ft_write(fd, buf, count);
	errno_cust = errno;

	printf("Return: %s; ",
		(return_orig == return_cust) ? "OK" : "Fail");
	printf("errno: %s\n",
		errno_orig == errno_cust ? "OK" : "Fail");
	if (return_orig != return_cust)
		printf("Returned %zd instead of %zd\n", return_cust, return_orig);
	if (errno_orig != errno_cust)
		printf("Set errno at %i instead of %i\n", errno_cust, errno_orig);
	printf("\n");
}

void	test_ft_read(const void *buf, size_t count)
{
	int		pipefd[2];
	char	buf_orig[256];
	char	buf_cust[256];
	ssize_t	return_orig;
	ssize_t	return_cust;
	int		errno_orig;
	int		errno_cust;

	bzero(buf_orig, 256);
	bzero(buf_cust, 256);
	if (pipe(pipefd) != -1)
	{
		errno = 0;
		write(pipefd[1], buf, count);
		return_orig = read(pipefd[0], buf_orig, count);
		errno_orig = errno;

		errno = 0;
		write(pipefd[1], buf, count);
		return_cust = ft_read(pipefd[0], buf_cust, count);
		errno_cust = errno;

		write(1, buf_orig, 256);
		write(1, ":", 1);
		write(1, buf_cust, 256);
		write(1, "\n", 1);
		printf("Return: %s; ",
			(return_orig == return_cust) ? "OK" : "Fail");
		printf("errno: %s\n",
			errno_orig == errno_cust ? "OK" : "Fail");
		if (return_orig != return_cust)
			printf("Returned %zd instead of %zd\n", return_cust, return_orig);
		if (errno_orig != errno_cust)
			printf("Set errno at %i instead of %i\n", errno_cust, errno_orig);

		close(pipefd[0]);
		close(pipefd[1]);
	}
	else
		printf("Pipe creation failed !\n");
	printf("\n");
}

void	test_ft_read_custom_fd(int fd, size_t count)
{
	char	buf_orig[256];
	char	buf_cust[256];
	ssize_t	return_orig;
	ssize_t	return_cust;
	int		errno_orig;
	int		errno_cust;

	bzero(buf_orig, 256);
	bzero(buf_cust, 256);

	errno = 0;
	return_orig = read(fd, buf_orig, count);
	errno_orig = errno;

	errno = 0;
	return_cust = ft_read(fd, buf_cust, count);
	errno_cust = errno;

	write(1, buf_orig, 256);
	write(1, ":", 1);
	write(1, buf_cust, 256);
	write(1, "\n", 1);
	printf("Return: %s; ",
		(return_orig == return_cust) ? "OK" : "Fail");
	printf("errno: %s\n",
		errno_orig == errno_cust ? "OK" : "Fail");
	if (return_orig != return_cust)
		printf("Returned %zd instead of %zd\n", return_cust, return_orig);
	if (errno_orig != errno_cust)
		printf("Set errno at %i instead of %i\n", errno_cust, errno_orig);
	printf("\n");
}

void	test_ft_strdup(const char *str)
{
	char	*dup;

	dup = ft_strdup(str);
	if (!dup)
	{
		printf("KO: Got NULL\n");
		return;
	}
	printf("`%s`:`%s`\n\n", dup, str == NULL ? "" : str);  // strdup always malloc
	free(dup);
}

int		main(void)
{
	printf("==> Testing ft_strlen\n\n");
	test_ft_strlen("", 0);
	test_ft_strlen("t", 1);
	test_ft_strlen("test", 4);
	test_ft_strlen("Well tested !", 13);
	test_ft_strlen(NULL, 0);

	printf("\n==> Testing ft_strcpy\n\n");
	test_ft_strcpy("");
	test_ft_strcpy("t");
	test_ft_strcpy("test");
	test_ft_strcpy("Well tested !");
	printf(ft_strcpy(NULL, NULL) ? "Fail !\n\n" : "OK\n\n");
	printf(ft_strcpy(NULL, "Test mem") ? "Fail !\n\n" : "OK\n\n");
	printf(!ft_strcpy("Should not be touched", NULL) ? "Fail !\n\n" : "OK\n\n");

	printf("\n==> Testing ft_strcmp\n\n");
	test_ft_strcmp("qwerty", "qwertu");
	test_ft_strcmp("a", "b");
	test_ft_strcmp("a", "c");
	test_ft_strcmp("c", "a");
	test_ft_strcmp("", "a");
	test_ft_strcmp("a", "");
	test_ft_strcmp("", "aa");
	test_ft_strcmp("aa", "");
	test_ft_strcmp("", "");
	printf(ft_strcmp("buff", NULL) ? "Fail !\n\n" : "OK\n\n");
	printf(ft_strcmp(NULL, "mocktext") ? "Fail !\n\n" : "OK\n\n");
	printf(ft_strcmp(NULL, NULL) ? "Fail !\n\n" : "OK\n\n");

	printf("\n==> Testing ft_write\n\n");
	ft_write(0, "OK\n\n", 4);
	ft_write(0, "OK\n '-> it's not\n", 3);
	ft_write(1, "\nOK\n\n", 5);
	ft_write(2, "OK\n\n", 4);
	test_ft_write(1, "Test\n\nFail !!!\n", 6);
	test_ft_write(42, "Arbitrary fd", 12);
	test_ft_write(42, NULL, 12);
	test_ft_write(42, "Arbitrary fd", 0);
	test_ft_write(42, NULL, 0);
	test_ft_write(1, "Fail\0 is not for today\n\n", 24);
	test_ft_write(1, "OK\n\n", 4);
	test_ft_write(-1, "Fail\n\n", 6);
	test_ft_write(1, NULL, 3);
	test_ft_write(-1, NULL, 3);
	test_ft_write(1, "OK\n", 0);
	test_ft_write(1, NULL, 0);
	test_ft_write(-1, "Fail\n", 0);
	test_ft_write(-1, NULL, 0);

	printf("\n==> Testing ft_read\n\n");
	test_ft_read("test", 5);
	test_ft_read("te\0st", 6);
	test_ft_read("Splited on\ntwo lines", 20);
	test_ft_read_custom_fd(-1, 5);
	test_ft_read_custom_fd(42, 12);
	test_ft_read_custom_fd(9999, 12);

	printf("\n==> Testing ft_strdup\n\n");
	test_ft_strdup("OK");
	test_ft_strdup("OK\n");
	test_ft_strdup("");
	test_ft_strdup(NULL);
	test_ft_strdup("Very very ultra long string of very very ultra long string of very very ultra long string of very very ultra long string of very very ultra long string of very very ultra long string of very very ultra long string of very very ultra long string of very very ultra long string of very very ultra long string of very very ultra long string of very very ultra long string of very very ultra long string of very very ultra long string of very very ultra long string of very very ultra long string of very very ultra long string of very very ultra long string of very very ultra long string of very very ultra long string of very very ultra long string of very very ultra long string of very very ultra long string of very very ultra long string of very very ultra long string of very very ultra long string of very very ultra long string of very very ultra long string of very very ultra long string of very very ultra long string of very very ultra long string of very very ultra long string of very very ultra long string of very very ultra long string of very very ultra long string of very very ultra long string string");
}
