#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int ft_strlen(char *str);

int main(){
	printf("strlen: %d\n", (int)strlen("Hello World!"));
	printf("ft_strlen: %d\n", ft_strlen("Hello World!"));
	return (0);
}