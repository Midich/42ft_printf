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
#include <stdlib.h>
#define __USE_GNU
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#define BUFF_SIZE 400

static size_t g_total = 0;
static size_t g_failed = 0;

static char buff[BUFF_SIZE];
static char ftbuff[BUFF_SIZE];
static int l = 0;
static int ftl = 0;

#define ASSERT(check) do{\
		g_total++;\
		if (check){\
			/*fprintf(stderr, "\e[32mOK\e[0m ");*/\
		}else\
		{\
			g_failed++;\
			fprintf(stderr, "\norg: %s, %i\nft:  %s, %i", buff, l, ftbuff, ftl);\
			fprintf(stderr, "\e[31mKO\e[0m ");\
		}\
	}while(0);

int std_sav = -1;

static int redirect_stdout()
{
	int fds[2];
	pipe2(fds, O_NONBLOCK);
	if ((std_sav = dup(1)) < 0) return -1;
	if (dup2(fds[1], 1) < 0) return -1;
	close(fds[1]);	
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
	int out = redirect_stdout();

	fprintf(stderr, "Some strings to print\n");
	char *c[] = {0, "", "hello", "hello world", "\n\b\t\\\r"};


	for (int i = 0; i < sizeof(c)/sizeof(c[0]); i++)
	{
		memset(buff, 0, BUFF_SIZE);
		memset(ftbuff, 0, BUFF_SIZE);
		l = printf(c[i]);
		fflush(stdout);
		read(out, buff, BUFF_SIZE);
		ftl = ft_printf(c[i]);
		read(out, ftbuff, BUFF_SIZE);
		ASSERT(!memcmp(buff, ftbuff, BUFF_SIZE) && l == ftl);
	}
	
	fprintf(stderr, "\nPrinted as argument\n");
	for (int i = 0; i < sizeof(c)/sizeof(c[0]); i++)
	{
		memset(buff, 0, BUFF_SIZE);
		memset(ftbuff, 0, BUFF_SIZE);
		l = printf("%s\n", c[i]);
		fflush(stdout);
		read(out, buff, BUFF_SIZE);
		// fprintf(stderr, "%s, %i\n", buff, l)
		ftl = ft_printf("%s\n", c[i]);
		read(out, ftbuff, BUFF_SIZE);
		ASSERT(!memcmp(buff, ftbuff, BUFF_SIZE) && l == ftl);
	}

	char *set = "-";
	char flags[6];
	for (int i = 0; i < 1<<1; i++)
	{
		memset(flags, 0, 6);
		int j = 0;
		int k = 0;
		while(i>>j)
		{
			if ((i>>j)&1)
				flags[k++] = set[j];
			j++;
		}
		//fprintf(stderr,"\n%s", flags);
		for(int width = -1; width < 10; width++)
		{
			for(int prec = -2; prec < 11; prec++)
			{
				char base[100] = {0};
				char test[200] = {0};
				char w[5] = {0};
				char p[5] = {0};
				if (width >= 0)
				 	snprintf(w, 5, "%i", width);
				if (prec > -1)
					snprintf(p, 5, ".%i", prec);
				else if (prec > -2)
					p[0] = '.';
				snprintf(base, 100, "%s%s%s", flags, w, p);
				// string
				snprintf(test, 200, "a%%%ssz", base);
				fprintf(stderr, "\nFOR %s\n", test);
				for (int i = 0; i < sizeof(c)/sizeof(c[0]); i++)
				{
					memset(buff, 0, BUFF_SIZE);
					memset(ftbuff, 0, BUFF_SIZE);
					l = printf(test, c[i]);
					fflush(stdout);
					read(out, buff, BUFF_SIZE);
					// fprintf(stderr, "%s, %i\n", buff, l)
					ftl = ft_printf(test, c[i]);
					read(out, ftbuff, BUFF_SIZE);
					ASSERT(!memcmp(buff, ftbuff, BUFF_SIZE) && l == ftl);
				}
			}
		}
	}
	set = "-0# +";
	for (int i = 0; i < 1<<5; i++)
	{
		memset(flags, 0, 6);
		int j = 0;
		int k = 0;
		while(i>>j)
		{
			if ((i>>j)&1)
				flags[k++] = set[j];
			j++;
		}
			//fprintf(stderr,"\n%s", flags);
		for(int width = -1; width < 10; width++)
		{
			for(int prec = -1; prec < 11; prec++)
			{
				char base[100] = {0};
				char test[200] = {0};
				char w[5] = {0};
				char p[5] = {0};
				if (width >= 0)
					snprintf(w, 5, "%i", width);
				if (prec > -1)
					snprintf(p, 5, ".%i", prec);
				else if (prec > -2)
					p[0] = '.';
				snprintf(base, 100, "%s%s%s", flags, w, p);
				// char
				snprintf(test, 200, "a%%%scz", base);
				fprintf(stderr, "\nFOR %s\n", test);
				for (int i = -1; i < 128; i++)
				{
					memset(buff, 0, BUFF_SIZE);
					memset(ftbuff, 0, BUFF_SIZE);
					l = printf(test, i);
					fflush(stdout);
					read(out, buff, BUFF_SIZE);
					// fprintf(stderr, "%s, %i\n", buff, l)
					ftl = ft_printf(test, i);
					read(out, ftbuff, BUFF_SIZE);
					ASSERT(!memcmp(buff, ftbuff, BUFF_SIZE) && l == ftl);
				}

				// int
				char *c = "diuxX";
				for (int j = 0; j < strlen(c); j++){
					snprintf(test, 200, "a%%%s%cz", base, c[j]);
					fprintf(stderr, "\nFOR %s\n", test);
					for (int i = INT_MIN; i < 5122; i = i<0 ? i/10: i == 0 ? 1: i * 4)
					{
						memset(buff, 0, BUFF_SIZE);
						memset(ftbuff, 0, BUFF_SIZE);
						l = printf(test, i);
						fflush(stdout);
						read(out, buff, BUFF_SIZE);
						ftl = ft_printf(test, i);
						read(out, ftbuff, BUFF_SIZE);
						//fprintf(stderr, "\n%s, %i\n%s, %i", buff, l, ftbuff, ftl);
						ASSERT(!memcmp(buff, ftbuff, BUFF_SIZE) && l == ftl);
					}
				}

				//pointer
				snprintf(test, 200, "a%%%spz", base);
				fprintf(stderr, "\nFOR %s\n", test);
				for (int i = -1; i < 20; i++)
				{
					memset(buff, 0, BUFF_SIZE);
					memset(ftbuff, 0, BUFF_SIZE);
					void *t = malloc(200);
					l = printf(test, t);
					fflush(stdout);
					read(out, buff, BUFF_SIZE);
					// fprintf(stderr, "%s, %i\n", buff, l)
					ftl = ft_printf(test, t);
					read(out, ftbuff, BUFF_SIZE);
					free(t);
					ASSERT(!memcmp(buff, ftbuff, BUFF_SIZE) && l == ftl);
				}

				snprintf(test, 200, "a%%%s%%z", base);
				fprintf(stderr, "\nFOR %s\n", test);
				memset(buff, 0, BUFF_SIZE);
				memset(ftbuff, 0, BUFF_SIZE);
				l = printf(test);
				fflush(stdout);
				read(out, buff, BUFF_SIZE);
				// fprintf(stderr, "%s, %i\n", buff, l)
				ftl = ft_printf(test);
				read(out, ftbuff, BUFF_SIZE);
				ASSERT(!memcmp(buff, ftbuff, BUFF_SIZE) && l == ftl);
				
			}
		}
	}
	restore_stdout(out);
	fprintf(stderr, "\ntotal: %lu\nsucceed: %lu\nfailed: %lu\n", g_total, g_total - g_failed, g_failed);
}
