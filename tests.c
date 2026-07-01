/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 14:39:35 by msowinsk          #+#    #+#             */
/*   Updated: 2026/07/01 16:57:54 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#define BUFF_SIZE 400

#define ASSERT(check) do{\
		if (check)\
			fprintf(stderr, "\e[32mOK\e[0m ");\
		else\
			fprintf(stderr, "\e[31mKO\e[0m ");\
	}while(0);

int std_sav = -1;

static int redirect_stdout()
{
	int fds[2];
	pipe2(fds, O_NONBLOCK);
	if ((std_sav = dup(1)) < 0) return -1;
	if (dup2(fds[1], 1) < 0) return -1;
	//close(fds[1]);	
	return (fds[0]);
}

static void restore_stdout(int fd)
{
	close(fd);
	dup2(std_sav, 1);
	close(std_sav);
}

int main(void)
{
	int l;
	int ftl;
	int out = redirect_stdout();
	char buff[BUFF_SIZE];
	char ftbuff[BUFF_SIZE];

	fprintf(stderr, "Some strings to print\n");
	char *c[] = {0, "", "hello", "hello world", "\n\b\t\\\r"};

	memset(buff, 0, BUFF_SIZE);
	memset(ftbuff, 0, BUFF_SIZE);

	for (int i = 0; i < sizeof(c)/sizeof(c[0]); i++)
	{
		l = printf(c[i]);
		fflush(stdout);
		read(out, buff, BUFF_SIZE);
		ftl = ft_printf(c[i]);
		read(out, ftbuff, BUFF_SIZE);
		ASSERT(!memcmp(buff, ftbuff, BUFF_SIZE) && l == ftl);
	}
	
	fprintf(stderr, "\nPrinted as argument\n");
	memset(buff, 0, BUFF_SIZE);
	memset(ftbuff, 0, BUFF_SIZE);
	for (int i = 0; i < sizeof(c)/sizeof(c[0]); i++)
	{
		l = printf("%s\n", c[i]);
		fflush(stdout);
		read(out, buff, BUFF_SIZE);
		// fprintf(stderr, "%s, %i\n", buff, l)
		ftl = ft_printf("%s\n", c[i]);
		read(out, ftbuff, BUFF_SIZE);
		ASSERT(!memcmp(buff, ftbuff, BUFF_SIZE) && l == ftl);
	}

	fprintf(stderr, "\nPrinted as argument\n");
	memset(buff, 0, BUFF_SIZE);
	memset(ftbuff, 0, BUFF_SIZE);
	for (int i = 0; i < sizeof(c)/sizeof(c[0]); i++)
	{
		l = printf("%s\n", c[i]);
		fflush(stdout);
		read(out, buff, BUFF_SIZE);
		// fprintf(stderr, "%s, %i\n", buff, l)
		ftl = ft_printf("%s\n", c[i]);
		read(out, ftbuff, BUFF_SIZE);
		ASSERT(!memcmp(buff, ftbuff, BUFF_SIZE) && l == ftl);
	}
	restore_stdout(out);
}
