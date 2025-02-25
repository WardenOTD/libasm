#include <stdio.h>

#define RED "\033[0;31m"
#define YEL "\033[0;33m"
#define MAG "\033[0;35m"
#define CYAN "\033[0;3;36m"
#define RES "\033[0m"


#define B16 "0123456789ABCDEF"
#define B20 "0123456789ABCDEFGHIJ"
#define B2 "01"
#define B4 "0123"
#define BS "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
#define BS2 "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$^&*()_={}[]|;:',.?"

int	ft_atoi_base(char *str, char *base);

int main(){
	printf("%s=================\natoi_base\n=================\n%s", CYAN, RES);
	printf("%sBase: %s%s%s\n32: %s%d%s\n", RED, MAG, B16, RED, YEL, ft_atoi_base("32", B16), RES);
	printf("%sBase: %s%s%s\n32AB: %s%d%s\n", RED, MAG, B16, RED, YEL, ft_atoi_base("32AB", B16), RES);
	printf("%sBase: %s%s%s\n72AFE: %s%d%s\n", RED, MAG, B16, RED, YEL, ft_atoi_base("72AFE", B16), RES);
	printf("%sBase: %s%s%s\n72EE: %s%d%s\n", RED, MAG, B16, RED, YEL, ft_atoi_base("72EE", B16), RES);
	printf("%sBase: %s%s%s\nFFFFFF: %s%d%s\n", RED, MAG, B16, RED, YEL, ft_atoi_base("FFFFFF", B16), RES);
	printf("\n");

	printf("%sBase: %s%s%s\n32: %s%d%s\n", RED, MAG, B20, RED, YEL, ft_atoi_base("32", B20), RES);
	printf("%sBase: %s%s%s\n32ABFJ: %s%d%s\n", RED, MAG, B20, RED, YEL, ft_atoi_base("32ABFJ", B20), RES);
	printf("%sBase: %s%s%s\nJHG: %s%d%s\n", RED, MAG, B20, RED, YEL, ft_atoi_base("JHG", B20), RES);
	printf("%sBase: %s%s%s\nGHIJ: %s%d%s\n", RED, MAG, B20, RED, YEL, ft_atoi_base("GHIJ", B20), RES);
	printf("%sBase: %s%s%s\nB78I7JG: %s%d%s\n", RED, MAG, B20, RED, YEL, ft_atoi_base("B78I7JG", B20), RES);
	printf("\n");

	printf("%sBase: %s%s%s\n1111010100111101100011011: %s%d%s\n", RED, MAG, B2, RED, YEL, ft_atoi_base("1111010100111101100011011", B2), RES);
	printf("%sBase: %s%s%s\n10001010110: %s%d%s\n", RED, MAG, B2, RED, YEL, ft_atoi_base("10001010110", B2), RES);
	printf("%sBase: %s%s%s\n100101011110001000010001: %s%d%s\n", RED, MAG, B2, RED, YEL, ft_atoi_base("100101011110001000010001", B2), RES);
	printf("%sBase: %s%s%s\n1101001110101: %s%d%s\n", RED, MAG, B2, RED, YEL, ft_atoi_base("1101001110101", B2), RES);
	printf("%sBase: %s%s%s\n11100000010: %s%d%s\n", RED, MAG, B2, RED, YEL, ft_atoi_base("11100000010", B2), RES);
	printf("\n");

	printf("%sBase: %s%s%s\n30222310203: %s%d%s\n", RED, MAG, B4, RED, YEL, ft_atoi_base("30222310203", B4), RES);
	printf("%sBase: %s%s%s\n33213: %s%d%s\n", RED, MAG, B4, RED, YEL, ft_atoi_base("33213", B4), RES);
	printf("%sBase: %s%s%s\n200: %s%d%s\n", RED, MAG, B4, RED, YEL, ft_atoi_base("200", B4), RES);
	printf("%sBase: %s%s%s\n32: %s%d%s\n", RED, MAG, B4, RED, YEL, ft_atoi_base("32", B4), RES);
	printf("%sBase: %s%s%s\n10313303020323: %s%d%s\n", RED, MAG, B4, RED, YEL, ft_atoi_base("10313303020323", B4), RES);
	printf("\n");

	printf("%sBase: %s%s%s\nabc: %s%d%s\n", RED, MAG, BS, RED, YEL, ft_atoi_base("abc", BS), RES);
	printf("%sBase: %s%s%s\nAbCdEfG: %s%d%s\n", RED, MAG, BS, RED, YEL, ft_atoi_base("AbCdEfG", BS), RES);
	printf("%sBase: %s%s%s\nz: %s%d%s\n", RED, MAG, BS, RED, YEL, ft_atoi_base("z", BS), RES);
	printf("%sBase: %s%s%s\nzZyX: %s%d%s\n", RED, MAG, BS, RED, YEL, ft_atoi_base("zZyX", BS), RES);
	printf("%sBase: %s%s%s\n103AKXmZyv: %s%d%s\n", RED, MAG, BS, RED, YEL, ft_atoi_base("103AKXmZyv", BS), RES);
	printf("\n");

	printf("%sBase: %s%s%s\n!@#$^: %s%d%s\n", RED, MAG, BS2, RED, YEL, ft_atoi_base("!@#$^", BS2), RES);
	printf("%sBase: %s%s%s\n&*()_=: %s%d%s\n", RED, MAG, BS2, RED, YEL, ft_atoi_base("&*()_=", BS2), RES);
	printf("%sBase: %s%s%s\n??: %s%d%s\n", RED, MAG, BS2, RED, YEL, ft_atoi_base("??", BS2), RES);
	printf("%sBase: %s%s%s\n!09]{2}: %s%d%s\n", RED, MAG, BS2, RED, YEL, ft_atoi_base("!09]{2}", BS2), RES);
	printf("%sBase: %s%s%s\n.,;:': %s%d%s\n", RED, MAG, BS2, RED, YEL, ft_atoi_base(".,;:'", BS2), RES);
	printf("%sBase: %s%s%s\n33!?: %s%d%s\n", RED, MAG, BS2, RED, YEL, ft_atoi_base("33!?", BS2), RES);
	printf("\n");

	printf("%sBase: %s%s%s\nempty: %s%d%s\n", RED, MAG, "", RED, YEL, ft_atoi_base("empty", ""), RES);
	printf("%sBase: %s%s%s\nspace only: %s%d%s\n", RED, MAG, "    ", RED, YEL, ft_atoi_base("space only", "    "), RES);
	printf("%sBase: %s%s%s\nspace after: %s%d%s\n", RED, MAG, "b ", RED, YEL, ft_atoi_base("space after", "b "), RES);
	printf("%sBase: %s%s%s\nspace before: %s%d%s\n", RED, MAG, " p", RED, YEL, ft_atoi_base("space before", " p"), RES);
	printf("%sBase: %s%s%s\nspace between: %s%d%s\n", RED, MAG, "2pal; o", RED, YEL, ft_atoi_base("space between", "2pal; o"), RES);
	printf("%sBase: %s%s%s\ntab before: %s%d%s\n", RED, MAG, "	d", RED, YEL, ft_atoi_base("tab before", "	d"), RES);
	printf("%sBase: %s%s%s\ntab after: %s%d%s\n", RED, MAG, "a	", RED, YEL, ft_atoi_base("tab after", "a	"), RES);
	printf("%sBase: %s%s%s\ntab between: %s%d%s\n", RED, MAG, "a	d", RED, YEL, ft_atoi_base("tab between", "a	d"), RES);
	printf("%sBase: %s%s%s\nduplicate: %s%d%s\n", RED, MAG, "apwokal", RED, YEL, ft_atoi_base("duplicate", "apwokal"), RES);
	printf("\n");

	return (0);
}