#include <stdio.h>

#define HEX "0123456789ABCDEF"

int	ft_atoi_base(char *str, char *base);

int main(){
	printf("1st: %d\n", ft_atoi_base("50", HEX));

	// char	*s = " 	-+++---+--+-214748dasdi3648";
	// int	i = ft_atoi_base(s, HEX);
	// printf("- %d\n", i);
	// printf("0 %d\n", ft_atoi_base("", HEX));
	// printf("0 %d\n", ft_atoi_base("a", HEX));
	// printf("+ %d\n", ft_atoi_base("12312", HEX));
	// printf("- %d\n", ft_atoi_base("-12312", HEX));
	// printf("0 %d\n", ft_atoi_base("--wada+-12312", HEX));
	// printf("0 %d\n", ft_atoi_base("wadawd-12312", HEX));
	// printf("- %d\n", ft_atoi_base("-12awdawd312", HEX));
	// printf("- %d\n", ft_atoi_base("-+++12312", HEX));
	// printf("+ %d\n", ft_atoi_base("--12312", HEX));
	// printf("- %d\n", ft_atoi_base("   --+-12312", HEX));
	// printf("0 %d\n", ft_atoi_base(" - 12312", HEX));

	return (0);
}