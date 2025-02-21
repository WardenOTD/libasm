#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

/*	Ah yes coloured text,
	displays nicely, but the code,
	horrendous.						*/

#define RED "\033[0;31m"
#define YEL "\033[0;33m"
#define MAG "\033[0;35m"
#define CYAN "\033[0;3;36m"
#define RES "\033[0m"

size_t ft_strlen(const char *str);
char *ft_strcpy(char *dst, const char *src);
int ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fd, const void *buf, size_t count);
ssize_t	ft_read(int fd, void *buf, size_t count);

int main(){
	printf("%s=================\nstrlen\n=================\n%s", CYAN, RES);
	printf("strlen: %s%ld%s\n", YEL, strlen("Hello World!"), RES);
	printf("ft_strlen: %s%ld%s\n\n", YEL, ft_strlen("Hello World!"), RES);

	printf("%s=================\nstrcpy\n=================\n%s", CYAN, RES);
	char *dst1 = (char *)malloc(sizeof(char) + 13);
	char *dst2 = (char *)malloc(sizeof(char) + 13);
	char *src = "Hello World!";
	printf("strcpy: %s%s%s\n", YEL, strcpy(dst1, src), RES);
	printf("ft_strcpy: %s%s%s\n\n", YEL, ft_strcpy(dst2, src), RES);
	free(dst1); free(dst2);

	printf("%s=================\nstrcmp\n=================\n%s", CYAN, RES);
	char *s1 = "Hellow World!"; char *s2 = "askdajdwuasodl";
	printf("s1: %s %s■%s s2: %s\n", s1, RED, RES, s2);
	printf("strcmp: %s%d%s\n", YEL, strcmp(s1, s2), RES);
	printf("ft_strcmp: %s%d%s\n\n", YEL, ft_strcmp(s1, s2), RES);

	s1 = "abc"; s2 = "abd";
	printf("s1: %s %s■%s s2: %s\n", s1, RED, RES, s2);
	printf("strcmp: %s%d%s\n", YEL, strcmp(s1, s2), RES);
	printf("ft_strcmp: %s%d%s\n\n", YEL, ft_strcmp(s1, s2), RES);

	s1 = "hihi"; s2 = "hihi";
	printf("s1: %s %s■%s s2: %s\n", s1, RED, RES, s2);
	printf("strcmp: %s%d%s\n", YEL, strcmp(s1, s2), RES);
	printf("ft_strcmp: %s%d%s\n\n", YEL, ft_strcmp(s1, s2), RES);

	s1 = "abc!"; s2 = "abc ";
	printf("s1: %s %s■%s s2: %s\n", s1, RED, RES, s2);
	printf("strcmp: %s%d%s\n", YEL, strcmp(s1, s2), RES);
	printf("ft_strcmp: %s%d%s\n\n", YEL, ft_strcmp(s1, s2), RES);

	s1 = "x"; s2 = "a";
	printf("s1: %s %s■%s s2: %s\n", s1, RED, RES, s2);
	printf("strcmp: %s%d%s\n", YEL, strcmp(s1, s2), RES);
	printf("ft_strcmp: %s%d%s\n\n", YEL, ft_strcmp(s1, s2), RES);

	printf("%s=================\nwrite\n=================\n%s", CYAN, RES);
	write(1, RES, strlen(RES));
	s1 = "Hellow World!\n";

	errno = 0;
	printf("write: %s%ld%s\n", YEL, write(1, s1, strlen(s1)), RES);
	printf("errno: %s%d%s\n", RED, errno, RES);
	perror("Error:"MAG);
	write(1, RES, strlen(RES));
	write(1, "\n", 1);

	errno = 0;
	printf("ft_write: %s%ld%s\n", YEL, ft_write(1, s1, strlen(s1)), RES);
	printf("errno: %s%d%s\n", RED, errno, RES);
	perror("Error:"MAG);
	write(1, RES, strlen(RES));
	write(1, "\n", 1);

	errno = 0;
	printf("write: %s%ld%s\n", YEL, write(3, s1, strlen(s1)), RES);
	printf("errno: %s%d%s\n", RED, errno, RES);
	perror("Error:"MAG);
	write(1, RES, strlen(RES));
	write(1, "\n", 1);

	errno = 0;
	printf("ft_write: %s%ld%s\n", YEL, ft_write(3, s1, strlen(s1)), RES);
	printf("errno: %s%d%s\n", RED, errno, RES);
	perror("Error:"MAG);
	write(1, RES, strlen(RES));
	write(1, "\n", 1);

	errno = 0;
	printf("write: %s%ld%s\n", YEL, write(1, s1, strlen(s1) - 15), RES);
	printf("errno: %s%d%s\n", RED, errno, RES);
	perror("Error:"MAG);
	write(1, RES, strlen(RES));
	write(1, "\n", 1);

	errno = 0;
	printf("ft_write: %s%ld%s\n", YEL, ft_write(1, s1, strlen(s1) - 15), RES);
	printf("errno: %s%d%s\n", RED, errno, RES);
	perror("Error:"MAG);
	write(1, RES, strlen(RES));
	write(1, "\n", 1);

	errno = 0;
	printf("write: %s%ld%s\n", YEL, write(1, s1, strlen(s1) + 15), RES);
	printf("errno: %s%d%s\n", RED, errno, RES);
	perror("Error:"MAG);
	write(1, RES, strlen(RES));
	write(1, "\n", 1);

	errno = 0;
	printf("ft_write: %s%ld%s\n", YEL, ft_write(1, s1, strlen(s1) + 15), RES);
	printf("errno: %s%d%s\n", RED, errno, RES);
	perror("Error:"MAG);
	write(1, RES, strlen(RES));
	write(1, "\n", 1);

	printf("%s=================\nread\n=================\n%s", CYAN, RES);
	dst1 = (char *)calloc(sizeof(char), 12);
	dst2 = (char *)calloc(sizeof(char), 12);
	int fd1 = open("read.txt", O_RDONLY);
	int fde1 = open("", O_RDONLY);
	int fd2 = open("read.txt", O_RDONLY);
	int fde2 = open("", O_RDONLY);

	for (int x = 0; x < 5; ++x){
		printf("len1: %ld  ||  len2: %ld\n", strlen(dst1), strlen(dst2));
		errno = 0;
		printf("read: %s%ld%s\n", YEL, read(fd1, dst1, 12), RES);
		printf("read: %s%s || len: %ld%s\n", YEL, dst1, strlen(dst1), RES);
		printf("errno: %s%d%s\n", RED, errno, RES);
		perror("Error:"MAG);
		write(1, RES, strlen(RES));
		write(1, "\n", 1);

		errno = 0;
		printf("ft_read: %s%ld%s\n", YEL, ft_read(fd2, dst2, 12), RES);
		printf("ft_read: %s%s || len: %ld%s\n", YEL, dst2, strlen(dst2), RES);
		printf("errno: %s%d%s\n", RED, errno, RES);
		perror("Error:"MAG);
		write(1, RES, strlen(RES));
		write(1, "\n", 1);
	}

	errno = 0;
	printf("read invalid fd: %s%ld%s\n", YEL, read(fde1, dst1, 12), RES);
	printf("read invalid fd: %s%s || len: %ld%s\n", YEL, dst1, strlen(dst1), RES);
	printf("errno: %s%d%s\n", RED, errno, RES);
	perror("Error:"MAG);
	write(1, RES, strlen(RES));
	write(1, "\n", 1);

	errno = 0;
	printf("ft_read invalid fd: %s%ld%s\n", YEL, ft_read(fde2, dst2, 12), RES);
	printf("ft_read invalid fd: %s%s || len: %ld%s\n", YEL, dst2, strlen(dst2), RES);
	printf("errno: %s%d%s\n", RED, errno, RES);
	perror("Error:"MAG);
	write(1, RES, strlen(RES));
	write(1, "\n", 1);

	close(fd1);
	close(fde1);
	close(fd2);
	close(fde2);
	free(dst1);
	free(dst2);
	return (0);
}