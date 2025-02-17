#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int ft_strlen(char *str);
char *ft_strcpy(char *dst, char *src);

int main(){
	printf("strlen: %d\n", (int)strlen("Hello World!"));
	printf("ft_strlen: %d\n", ft_strlen("Hello World!"));

	char *dst1 = (char *)malloc(sizeof(char) + 13);
	char *dst2 = (char *)malloc(sizeof(char) + 13);
	char *src = "Hello World!";
	printf("strcpy: %s\n", strcpy(dst1, src));
	printf("ft_strcpy: %s\n", ft_strcpy(dst2, src));
	free(dst1); free(dst2);
	return (0);
}