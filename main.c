#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

/*	Ah yes coloured text,
	displays nicely, but the code,
	horrendous.						*/

#define RED "\033[0;31m"
#define YEL "\033[0;33m"
#define MAG "\033[0;35m"
#define CYAN "\033[0;36m"
#define RES "\033[0m"

int ft_strlen(char *str);
char *ft_strcpy(char *dst, char *src);
int ft_strcmp(char *s1, char *s2);
int	ft_write(int fd, char *buf, int count);

int main(){
	printf("%s=================\nstrlen\n=================\n%s", CYAN, RES);
	printf("strlen: %s%d%s\n", YEL, (int)strlen("Hello World!"), RES);
	printf("ft_strlen: %s%d%s\n\n", YEL, ft_strlen("Hello World!"), RES);

	printf("%s=================\nstrcpy\n=================\n%s", CYAN, RES);
	char *dst1 = (char *)malloc(sizeof(char) + 13);
	char *dst2 = (char *)malloc(sizeof(char) + 13);
	char *src = "Hello World!";
	printf("strcpy: %s%s%s\n", YEL, strcpy(dst1, src), RES);
	printf("ft_strcpy: %s%s%s\n\n", YEL, ft_strcpy(dst2, src), RES);
	free(dst1); free(dst2);

	printf("%s=================\nstrcmp\n=================\n%s", CYAN, RES);
	char *s1 = "Hellow World!"; char *s2 = "askdajdwuasodl";
	printf("strcmp: %s%d%s %s■%s ", YEL, strcmp(s1, s2), RES, RED, RES);
	printf("s1: %s %s■%s s2: %s\n", s1, RED, RES, s2);
	printf("ft_strcmp: %s%d%s %s■%s ", YEL, ft_strcmp(s1, s2), RES, RED, RES);
	printf("s1: %s %s■%s s2: %s\n\n", s1, RED, RES, s2);

	s1 = "abc"; s2 = "abd";
	printf("strcmp: %s%d%s %s■%s ", YEL, strcmp(s1, s2), RES, RED, RES);
	printf("s1: %s %s■%s s2: %s\n", s1, RED, RES, s2);
	printf("ft_strcmp: %s%d%s %s■%s ", YEL, ft_strcmp(s1, s2), RES, RED, RES);
	printf("s1: %s %s■%s s2: %s\n\n", s1, RED, RES, s2);

	s1 = "hihi"; s2 = "hihi";
	printf("strcmp: %s%d%s %s■%s ", YEL, strcmp(s1, s2), RES, RED, RES);
	printf("s1: %s %s■%s s2: %s\n", s1, RED, RES, s2);
	printf("ft_strcmp: %s%d%s %s■%s ", YEL, ft_strcmp(s1, s2), RES, RED, RES);
	printf("s1: %s %s■%s s2: %s\n\n", s1, RED, RES, s2);

	s1 = "abc!"; s2 = "abc ";
	printf("strcmp: %s%d%s %s■%s ", YEL, strcmp(s1, s2), RES, RED, RES);
	printf("s1: %s %s■%s s2: %s\n", s1, RED, RES, s2);
	printf("ft_strcmp: %s%d%s %s■%s ", YEL, ft_strcmp(s1, s2), RES, RED, RES);
	printf("s1: %s %s■%s s2: %s\n\n", s1, RED, RES, s2);

	s1 = "x"; s2 = "a";
	printf("strcmp: %s%d%s %s■%s ", YEL, strcmp(s1, s2), RES, RED, RES);
	printf("s1: %s %s■%s s2: %s\n", s1, RED, RES, s2);
	printf("ft_strcmp: %s%d%s %s■%s ", YEL, ft_strcmp(s1, s2), RES, RED, RES);
	printf("s1: %s %s■%s s2: %s\n\n", s1, RED, RES, s2);

	printf("%s=================\nwrite\n=================\n%s", CYAN, RES);
	write(1, RES, strlen(RES));
	s1 = "Hellow World!\n";
	printf("write: %s%d%s\n", YEL, (int)write(1, s1, strlen(s1)), RES);
	printf("errno: %s%d%s\n", RED, errno, RES);
	perror("Error:"MAG);
	write(1, RES, strlen(RES));
	write(1, "\n", 1);

	printf("ft_write: %s%d%s\n", YEL, ft_write(1, s1, strlen(s1)), RES);
	printf("errno: %s%d%s\n", RED, errno, RES);
	perror("Error:"MAG);
	write(1, RES, strlen(RES));
	write(1, "\n", 1);

	printf("write: %s%d%s\n", YEL, (int)write(3, s1, strlen(s1)), RES);
	printf("errno: %s%d%s\n", RED, errno, RES);
	perror("Error:"MAG);
	write(1, RES, strlen(RES));
	write(1, "\n", 1);

	printf("ft_write: %s%d%s\n", YEL, ft_write(3, s1, strlen(s1)), RES);
	printf("errno: %s%d%s\n", RED, errno, RES);
	perror("Error:"MAG);
	write(1, RES, strlen(RES));
	write(1, "\n", 1);
	return (0);
}