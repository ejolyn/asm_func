/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejolyn <ejolyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 14:38:19 by ejolyn            #+#    #+#             */
/*   Updated: 2021/05/11 12:47:26 by ejolyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "stddef.h"
#include "stdio.h"
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

size_t ft_strlen(char *s);
char *ft_strcpy(char *dst, char *src);
int ft_strcmp(const char *s1, const char *s2);
char *ft_strdup(const char *s1);
ssize_t ft_read(int, void *, size_t);
ssize_t ft_write(int fd, const void *buf, size_t nbyte);


void test_strlen(char *str)
{
	size_t num1 = ft_strlen(str);
	size_t num2 = strlen(str);
	if (num1 == num2)
		printf("" "\033[32m" "[OK] ""\033[0m""");
	else
		printf("Ошибочка-ошибка\n");
}

void	test_strcpy(void)
{
	char	*ar;
	char	*ar3 = (char*)malloc(200);
	char	*ar4 = (char*)malloc(200);
	printf("Check ft_strcpy: \n");
	ar = "1234567890";
	ft_strcpy(ar3, ar);
	strcpy(ar4, ar);
	if (strcmp(ar3, ar4) == 0)
		printf("" "\033[32m" "[OK] ""\033[0m""");
	else
		printf("Ошибочка-ошибка\n");
	ar = "";
	ft_strcpy(ar3, ar);
	strcpy(ar4, ar);
	if (strcmp(ar3, ar4) == 0)
		printf("" "\033[32m" "[OK] ""\033[0m""");
	else
		printf("Ошибочка-ошибка\n");
	ar = "qwaersdtfyguhijokpl[;]'[;plkoijdedtfyguhijokpijuhygftdresdtfyguhijoihugyftdrsdtfyguhiojpkjihugyftdryfguihojpkjihugyftdryfugihojpkjihugyftdyfugihojpiugytfyguhijokpl[;lpoijuhygtfguhijop";
	ft_strcpy(ar3, ar);
	strcpy(ar4, ar);
	if (strcmp(ar3, ar4) == 0)
		printf("" "\033[32m" "[OK] ""\033[0m""");
	else
		printf("Ошибочка-ошибка\n");
}

void	test_strcmp(char *s1, char *s2)
{
	if (strcmp(s1, s2) == ft_strcmp(s1, s2))
		printf("" "\033[32m" "[OK] ""\033[0m""");
	else
		printf("Ошибочка-ошибка\n");
}

void	test_strdup(char *s)
{
	if (strcmp(strdup(s), ft_strdup(s)) == 0)
		printf("" "\033[32m" "[OK] ""\033[0m""");
	else
		printf("Ошибочка-ошибка\n");
}

void	test_read(void)
{
	char	*buf1 = malloc(1000);
	char	*buf2 = malloc(1000);
	int		fd;
	int		ch1;
	int		ch2;
	fd = open("main.c", O_RDONLY);
	ch1 = read(fd, buf1, 1000);
	fd = open("main.c", O_RDONLY);
	ch2 = ft_read(fd, buf2, 1000);
	if (strcmp(buf1, buf2) == 0 && ch1 == ch2)
		printf("" "\033[32m" "[OK] ""\033[0m""");
	bzero(buf1, 1000);
	bzero(buf2, 1000);
	fd = 1;
	ch1 = read(fd, buf1, 1000);
	fd = 1;
	ch2 = ft_read(fd, buf2, 1000);
	if (strcmp(buf1, buf2) == 0 && ch1 == ch2)
		printf("" "\033[32m" "[OK] ""\033[0m""");
	bzero(buf1, 1000);
	bzero(buf2, 1000);
	fd = -1;
	ch1 = read(fd, buf1, 1000);
	fd = -1;
	ch2 = ft_read(fd, buf2, 1000);
	if (strcmp(buf1, buf2) == 0 && ch1 == ch2)
		printf("" "\033[32m" "[OK] ""\033[0m""");
	bzero(buf1, 1000);
	bzero(buf2, 1000);
}

void test_write(void)
{
	char	*buf;
	buf = "1234567890";
	write(1, "\n", 1);
	write(1, "LINE = ", 7);
	write(1, buf, strlen(buf));
	write(1, "\n\n", 2);
	write(1, "MINE = ", 7);
	ft_write(1, buf, ft_strlen(buf));
	write(1, "\n", 1);
	write(1, "ORIG = ", 7);
	write(1, buf, strlen(buf));
	write(1, "\n", 1);
	buf = "";
	write(1, "\n", 1);
	write(1, "LINE = ", 7);
	write(1, buf, strlen(buf));
	write(1, "\n\n", 2);
	write(1, "MINE = ", 7);
	ft_write(1, buf, ft_strlen(buf));
	write(1, "\n", 1);
	write(1, "ORIG = ", 7);
	write(1, buf, strlen(buf));
	write(1, "\n", 1);
	buf = "sdfknjsdfjkl123jewfdfsdf 	ogjh'qohrgoihoeqihroi'hgeoi'hreiohioerhoiehoqhgvjkljhbknl;jhbknlm;jhgghjbknlm;jihugyftdfghjklp[ojihugyfghjklkojihgfghv";
	write(1, "\n", 1);
	write(1, "LINE = ", 7);
	write(1, buf, strlen(buf));
	write(1, "\n\n", 2);
	write(1, "MINE = ", 7);
	ft_write(1, buf, ft_strlen(buf));
	write(1, "\n", 1);
	write(1, "ORIG = ", 7);
	write(1, buf, strlen(buf));
	write(1, "\n", 1);
}

int main(void)
{
	printf("Check ft_strlen: \n");
	test_strlen("123124");
	test_strlen("");
	test_strlen("aasssssssss124srdffbFdgferg132");
	
	printf("\n");
	test_strcpy();
	
	printf("\nCheck ft_strcmp: \n");
	test_strcmp("123", "123");
	test_strcmp("123", "1235325");
	test_strcmp("123", "");
	test_strcmp("", "123");
	test_strcmp("", "");
	
	printf("\nCheck ft_strdup: \n");
	test_strdup("12345");
	test_strdup("");
	test_strdup("12345fesflkjkfgjsdfgjdfg;jop3qjfsdjfldskfjnvslkvnklsdfjeopiwfj");
	
	printf("\nCheck ft_read: \n");
	test_read();

	printf("\nCheck ft_write: \n");
	test_write();
}