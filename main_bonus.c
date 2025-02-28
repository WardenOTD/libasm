#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

int	ft_atoi_base(char *str, char *base);
void ft_list_push_front(t_list **begin_list, void *data);
int ft_list_size(t_list *begin_list);
void ft_list_sort(t_list **begin_list, int (*cmp)());

char *italy(char *str){
	char *s = (char *)malloc(sizeof(char) * (strlen(str) + 1));
	int i = 0;
	for (; str[i]; ++i){
		s[i] = str[i];
	}
	s[i-1] = ';';
	s[i++] = '3';
	s[i++] = 'm';
	s[i] = '\0';
	return (s);
}

int print_lst(t_list *list, int print){
	int i = 0;
	while (list){
		if (print)
			printf("%s~~~ %s%s\n", RED, YEL, (char*)list->data);
		list = list->next;
		i++;
	}
	return (i);
}

void ft_lstclear(t_list **list){
	t_list *tmp;
	while (*list){
		tmp = (*list)->next;
		if ((*list)->data)
			free((*list)->data);
		free(*list);
		*list = tmp;
	}
}

t_list	*ft_lstnew(void *content)
{
	t_list	*head;

	head = (t_list *)malloc(sizeof(t_list));
	if (!head)
		return (0);
	head->data = content;
	head->next = 0;
	return (head);
}

int main(){
	printf("%s=================\natoi_base\n=================\n%s", CYAN, RES);
	printf("%sBase: %s%s%s\n32: %s%d%s\n", RED, MAG, B16, RED, YEL, ft_atoi_base("32", B16), RES);
	printf("%sBase: %s%s%s\n32AB: %s%d%s\n", RED, MAG, B16, RED, YEL, ft_atoi_base("32AB", B16), RES);
	printf("%sBase: %s%s%s\n72AFE: %s%d%s\n", RED, MAG, B16, RED, YEL, ft_atoi_base("72AFE", B16), RES);
	printf("%sBase: %s%s%s\n72EE: %s%d%s\n", RED, MAG, B16, RED, YEL, ft_atoi_base("72EE", B16), RES);
	printf("%sBase: %s%s%s\nFFFFFF: %s%d%s\n\n", RED, MAG, B16, RED, YEL, ft_atoi_base("FFFFFF", B16), RES);
	printf("%sBase: %s%s%s\n--+++-+--32: %s%d%s\n", RED, MAG, B16, RED, YEL, ft_atoi_base("--+++-+--32", B16), RES);
	printf("%sBase: %s%s%s\n                --++--+++32AB: %s%d%s\n", RED, MAG, B16, RED, YEL, ft_atoi_base("                --++--+++32AB", B16), RES);
	printf("%sBase: %s%s%s\n    			--72AFE: %s%d%s\n", RED, MAG, B16, RED, YEL, ft_atoi_base("    			--72AFE", B16), RES);
	printf("%sBase: %s%s%s\n++-----72EE: %s%d%s\n", RED, MAG, B16, RED, YEL, ft_atoi_base("++-----72EE", B16), RES);
	printf("%sBase: %s%s%s\nFFFFFF a: %s%d%s\n", RED, MAG, B16, RED, YEL, ft_atoi_base("FFFFFF a", B16), RES);
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
	printf("%sBase: %s%s%s\nduplicate: %s%d%s\n\n", RED, MAG, "apwokal", RED, YEL, ft_atoi_base("duplicate", "apwokal"), RES);

	printf("%s=================\nlist_push_front\n=================\n%s", CYAN, RES);
	t_list *list = ft_lstnew(strdup("1st List"));
	print_lst(list, 1);
	printf("%s---------------------\n", MAG);
	list->next = ft_lstnew(strdup("2nd List"));
	list->next->next = ft_lstnew(strdup("3rd List"));
	print_lst(list, 1);
	printf("%s---------------------\n", MAG);
	ft_list_push_front(&list, strdup("New List"));
	print_lst(list, 1);
	printf("%s---------------------\n", MAG);
	ft_list_push_front(&list, strdup("Another New List"));
	print_lst(list, 1);
	printf("%s---------------------\n", MAG);
	ft_list_push_front(&list, NULL);
	print_lst(list, 1);
	printf("\n%s", RES);

	printf("%s=================\nlist_size\n=================\n%s", CYAN, RES);
	printf("Size of list: %s%d%s\n\n", YEL, ft_list_size(list), RES);

	ft_lstclear(&list);
	
	printf("%s=================\nlist_sort\n=================\n%s", CYAN, RES);
	t_list *lst = ft_lstnew(strdup("0"));
	ft_list_push_front(&lst, strdup("1"));
	ft_list_push_front(&lst, strdup("2"));
	ft_list_push_front(&lst, strdup("A pretty long sentence"));
	ft_list_push_front(&lst, strdup("a pretty long sentence"));
	ft_list_push_front(&lst, strdup("maybe an even longer sentence ?"));
	ft_list_push_front(&lst, strdup("3"));
	ft_list_push_front(&lst, strdup("4"));
	ft_list_push_front(&lst, strdup("5"));
	ft_list_push_front(&lst, strdup("6"));
	ft_list_push_front(&lst, strdup("7"));
	ft_list_push_front(&lst, strdup("8"));
	ft_list_push_front(&lst, strdup("9"));
	ft_list_push_front(&lst, strdup(" "));
	ft_list_push_front(&lst, strdup("!"));
	ft_list_push_front(&lst, strdup("hi"));
	ft_list_push_front(&lst, strdup("0"));
	ft_list_push_front(&lst, strdup("16"));
	ft_list_push_front(&lst, strdup("2"));
	ft_list_push_front(&lst, strdup("17"));
	ft_list_push_front(&lst, strdup("20"));
	ft_list_push_front(&lst, strdup("hello"));
	ft_list_push_front(&lst, strdup("world"));
	ft_list_push_front(&lst, strdup("?"));
	ft_list_push_front(&lst, strdup("pi"));
	print_lst(lst, 1);
	printf("%s---------------------\n", MAG);
	ft_list_sort(&lst, &strcmp);
	print_lst(lst, 1);

	
	printf("%s---------------------\n", MAG);
	printf("%sDIF\n", RED);
	for (t_list *tmp = lst; tmp->next; tmp = tmp->next){
		printf("%s%s:%-8s", italy(MAG), (char *)tmp->data, RES);
		// char msg[1000];
		// strcpy(msg, "");
		for (t_list *nxt = lst; nxt->next; nxt = nxt->next){
			if (nxt == tmp){
				// int len = snprintf(NULL, 0, "%s\"%s\"%s ", MAG, "■", YEL);
				// char *str = malloc(len + 1);
				// snprintf(str, len + 1, "%s\"%s\"%s ", MAG, "■", YEL);
				// strcat(msg, str);
				// free(str);
				printf("%s%s ", MAG, "■" /*(char *)tmp->data*/);
			}
			else{
				// int len = snprintf(NULL, 0, "%d ", strcmp(tmp->data, nxt->data));
				// char *str = malloc(len + 1);
				// snprintf(str, len + 1, "%d ", strcmp(tmp->data, nxt->data));
				// strcat(msg, str);
				// free(str);
				printf("%s%d ", YEL, strcmp(tmp->data, nxt->data));
			}
		}
		printf("%s", YEL);
		// printf("%s", msg);
		printf("\n%s", RES);
	}
	printf("\n");
	ft_lstclear(&lst);
	return (0);
}