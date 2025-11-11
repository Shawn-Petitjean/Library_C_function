#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <bsd/string.h>

void	ft_print_zeros(unsigned long long addr)
{
	unsigned int		zero_count;

	zero_count = 16;
	while (addr > 0)
	{
		zero_count--;
		addr /= 16;
	}
	while (zero_count > 0)
	{
		write(1, "0", 1);
		zero_count--;
	}
}

void	ft_print_addr(unsigned long long addr)
{
	char				*hex;

	hex = "0123456789abcdef";
	if (addr >= 16)
	{
		ft_print_addr(addr / 16);
		ft_print_addr(addr % 16);
	}
	else
		write(1, &hex[addr], 1);
}

void	ft_print_line_hex(char *str, long long *count, long long *printed)
{
	unsigned int	i;
	char			*hex;

	i = 0;
	hex = "0123456789abcdef";
	*printed = 0;
	while (i < 16 && (*count)-- > 0)
	{
		write(1, &hex[str[i] / 16], 1);
		write(1, &hex[str[i] % 16], 1);
		if (i % 2 != 0 && i != 15)
			write(1, " ", 1);
		i++;
		(*printed)++;
	}
	while (i < 16)
	{
		write(1, "  ", 2);
		if (i % 2 != 0 && i != 15)
			write(1, " ", 1);
		i++;
	}
}

void	ft_print_line(char *str, long long *printed)
{
	unsigned int	i;

	i = 0;
	while (i < 16 && (*printed)-- > 0)
	{
		if (str[i] < 32 || str[i] == 127)
			write(1, ".", 1);
		else
			write(1, &str[i], 1);
		i++;
	}
	while (i < 16)
	{
		write(1, " ", 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	long long		count;
	long long		printed;
	char			*str_addr;

	i = 0;
	count = size;
	printed = 0;
	str_addr = (void *)addr;
	while (i * 16 < size)
	{
		ft_print_zeros((unsigned long long)str_addr);
		ft_print_addr((unsigned long long)str_addr);
		write(1, ": ", 2);
		ft_print_line_hex(str_addr, &count, &printed);
		write(1, " ", 1);
		ft_print_line(str_addr, &printed);
		write(1, " ", 1);
		
		write(1, "\n", 1);
		i++;
		str_addr += 16;
	}
	return (addr);
}

void	ft_replace(unsigned int i, char *c)
{
	if (i % 2 != 0)
	{
		if (i % 3 == 0)
			*c = '.';
		if (i % 3 == 1)
			*c = '-';
		if (i % 3 == 2)
			*c = '+';
	}
}

// t_list *ft_create_lst(char **tab)
// {
// 	t_list *head = NULL;
// 	int i = 0;
// 	while (tab[i])
// 	{
// 		ft_lstadd_back(&head, ft_lstnew(ft_strdup(tab[i++])));
// 		if (!head)
// 			return (NULL);
// 	}
// 	return (head);
// }

void	ft_print_lst(t_list *head)
{
	int i = 0;
	if (!head)
	{
		printf("There is no list...Sorry...\n");
		return ;
	}
	while (head)
	{
		printf("***************************************\n");
		printf("> Node : %d - Adress : %p\n\n", i++, head);
		printf(">> Content : \"%s\"\n", (char *)(head->content));
		printf(">> Next : %p\n\n", head->next);
		head = head->next;
	}
	printf("***************************************\n");
}

char	ft_sub_index(unsigned int i, char c)
{
	if (!ft_isalpha(c))
		return (c);
	return (c - i);
}

void	ft_del_content(void *content)
{
	free(content);
}

void	ft_capitalize(void *content)
{
	if (content)
		if (97 <= ((char *)content)[0] && ((char *)content)[0] <= 122)
			((char *)content)[0] -= 32;
}

void	*ft_reverse(void *content)
{
	if (!content)
		return (NULL); 
	int clen = ft_strlen((char *)content);
	int i = 0;
	char *new_content = ft_calloc(clen + 1, sizeof(char));
	while (clen > 0)
		new_content[i++] = ((char *)content)[clen-- - 1];
	new_content[i] = '\0';
	return ((void *)new_content);
}

int	main(void)
{
	printf(">>>>>>>>>>>>>>>>>>>>LIBFT_TEST<<<<<<<<<<<<<<<<<<<<\n\n\n");
	printf("------------IS_CHAR_FUNCTIONS------------\n\n");

	//isalpha

	printf(">> ft_isalpha :\n\n");
	printf("ft_isalpha('B') = %d,", ft_isalpha('B'));
	printf(" isalpha('B') = %d\n", isalpha('B'));
	printf("ft_isalpha('9') = %d,", ft_isalpha('9'));
	printf(" isalpha('9') = %d\n\n", isalpha('9'));


	//isdigit

	printf("\n>> ft_isdigit :\n\n");
	printf("ft_isdigit('4') = %d,", ft_isdigit('4'));
	printf(" isdigit('4') = %d\n", isdigit('4'));
	printf("ft_isdigit('z') = %d,", ft_isdigit('z'));
	printf(" isdigit('z') = %d\n\n", isdigit('z'));

	//isalnum

	printf("\n>> ft_isalnum :\n\n");
	printf("ft_isalnum('4') = %d,", ft_isalnum('4'));
	printf(" isalnum('4') = %d\n", isalnum('4'));
	printf("ft_isalnum('z') = %d,", ft_isalnum('z'));
	printf(" isalnum('z') = %d\n", isalnum('z'));
	printf("ft_isalnum('(') = %d,", ft_isalnum('('));
	printf(" isalnum('(') = %d\n\n", isalnum('('));

	//isprint

	printf("\n>> ft_isprint :\n\n");
	printf("ft_isprint('4') = %d,", ft_isprint('4'));
	printf(" isprint('4') = %d\n", isprint('4'));
	printf("ft_isprint('\\n') = %d,", ft_isprint('\n'));
	printf(" isprint('\\n') = %d\n\n", isprint('\n'));

	//isascii

	printf("\n>> ft_isascii :\n\n");
	printf("ft_isascii('4') = %d,", ft_isascii('4'));
	printf(" isascii('4') = %d\n", isascii('4'));
	printf("ft_isascii(130) = %d,", ft_isascii(130));
	printf(" isascii(130) = %d\n\n", isascii(130));

	//tolower

	printf("\n>> ft_tolower :\n\n");
	printf("ft_tolower('B') = %c,", ft_tolower('B'));
	printf(" tolower('B') = %c\n", tolower('B'));
	printf("ft_tolower('b') = %c,", ft_tolower('b'));
	printf(" tolower('b') = %c\n\n", tolower('b'));

	//toupper

	printf("\n>> ft_toupper :\n\n");
	printf("ft_toupper('z') = %c,", ft_toupper('z'));
	printf(" toupper('z') = %c\n", toupper('z'));
	printf("ft_toupper('L') = %c,", ft_toupper('L'));
	printf(" toupper('L') = %c\n\n", toupper('L'));


	printf("\n\n\n------------MEM_FUNCTIONS------------\n\n");

	//bzero

	printf(">> ft_bzero :\n\n");
	char *btest1 = calloc(50, sizeof(char));
	char *btest2 = calloc(50, sizeof(char));
	strlcat(btest1, "jesuisdelamemoirerandom", 50);
	strlcat(btest2, "jesuisdelamemoirerandom", 50);
	printf("50 bytes memory block before ft_bzero :\n\n");
	ft_print_memory(btest1, 50);
	ft_bzero(btest1, 50);
	printf("\n\n50 bytes memory block initialized by ft_bzero :\n\n");
	ft_print_memory(btest1, 50);
	printf("\n\n50 bytes memory block before bzero :\n\n");
	ft_print_memory(btest2, 50);
	bzero(btest2, 50);
	printf("\n\n50 bytes memory block initialized by bzero :\n\n");
	ft_print_memory(btest2, 50);
	free(btest1);
	free(btest2);

	//memset

	printf("\n\n>> ft_memset :\n\n");
	char *set1 = calloc(50, sizeof(char));
	char *set2 = calloc(50, sizeof(char));
	strlcat(set1, "jesuisdelamemoirerandom", 50);
	strlcat(set2, "jesuisdelamemoirerandom", 50);
	printf("50 bytes memory block before ft_memset :\n\n");
	ft_print_memory(set1, 50);
	ft_memset(set1, 97, 50);
	printf("\n\n50 bytes memory block initialized at 97 by ft_memset :\n\n");
	ft_print_memory(set1, 50);
	printf("\n\n50 bytes memory block before memset :\n\n");
	ft_print_memory(set2, 50);
	memset(set2, 97, 50);
	printf("\n\n50 bytes memory block initialized at 97 by memset :\n\n");
	ft_print_memory(set2, 50);
	free(set1);
	free(set2);

	//memcpy

	printf("\n\n>> ft_memcpy :\n\n");
	char *cpy1 = ft_calloc(50, sizeof(char));
	char *cpy2 = ft_calloc(50, sizeof(char));
	char *cpy3 = ft_calloc(50, sizeof(char));
	strlcat(cpy1, "Hello World", 50);
	printf("50 bytes source block :\n\n");
	ft_print_memory(cpy1, 50);
	printf("\n\n50 bytes dest1 initialized to 0 :\n\n");
	ft_print_memory(cpy2, 50);
	ft_memcpy(cpy2, cpy1, 50);
	printf("\n\ndest1 after ft_memcpy :\n\n");
	ft_print_memory(cpy2, 50);
	printf("\n\n50 bytes dest2 initialized to 0 :\n\n");
	ft_print_memory(cpy3, 50);
	memcpy(cpy3, cpy1, 50);
	printf("\n\ndest2 after memcpy :\n\n");
	ft_print_memory(cpy3, 50);
	free(cpy1);
	free(cpy2);
	free(cpy3);

	//memmove

	printf("\n\n>> ft_memmove :\n\n");
	char *mov1 = ft_calloc(50, sizeof(char));
	strlcat(mov1 + 10, "Hello World", 50);
	char *mov2 = ft_calloc(50, sizeof(char));
	strlcat(mov2 + 10, "Hello World", 50);
	char *mov3 = ft_calloc(50, sizeof(char));
	strlcat(mov3 + 10, "Hello World", 50);
	char *mov4 = ft_calloc(50, sizeof(char));
	strlcat(mov4 + 10, "Hello World", 50);
	printf("50 bytes source block :\n\n");
	ft_print_memory(mov1, 50);
	ft_memmove(mov1 + 5, mov1 + 10, 11);
	printf("\n\nsource after ft_memmove (5 bytes behind):\n\n");
	ft_print_memory(mov1, 50);
	ft_memmove(mov2 + 15, mov2 + 10, 11);
	printf("\n\nsource after ft_memmove (5 bytes after):\n\n");
	ft_print_memory(mov2, 50);
	memmove(mov3 + 5, mov3 + 10, 11);
	printf("\n\nsource after memmove (5 bytes behind):\n\n");
	ft_print_memory(mov3, 50);
	memmove(mov4 + 15, mov4 + 10, 11);
	printf("\n\nsource after memmove (5 bytes after):\n\n");
	ft_print_memory(mov4, 50);
	free(mov1);
	free(mov2);
	free(mov3);
	free(mov4);

	//memcmp

	printf("\n\n>> ft_memcmp :\n\n");
	char *s1 = calloc(50, sizeof(char));
	char *s2 = calloc(50, sizeof(char));
	memcpy(s1, "Hello World\0ohmygod", 20);
	memcpy(s2, "Hello World\0ahmygod", 20);
	printf("Comparing the two memory zones below :\n\ns1\n");
	ft_print_memory(s1, 50);
	printf("\n\ns2\n");
	ft_print_memory(s2, 50);
	printf("\n\nComparing s1 and s2 for 5 bytes :\n");
	printf("ft_memcmp : %d,", ft_memcmp(s1, s2, 5));
	printf(" memcmp : %d", memcmp(s1, s2, 5));
	printf("\n\nComparing s1 and s2 for 18 bytes :\n");
	printf("ft_memcmp : %d,", ft_memcmp(s1, s2, 18));
	printf(" memcmp : %d\n", memcmp(s1, s2, 18));
	free(s1);
	free(s2);

	//memchr

	printf("\n\n>> ft_memchr :\n\n");
	char schr[] = "Bonjour bonjour";
	printf("Looking for 'u' in %s :\n", schr);
	printf("ft_memchr : %s\n", (char *)ft_memchr(schr, 'u', 16));
	printf("memchr : %s\n", (char *)memchr(schr, 'u', 16));
	printf("\n\nLooking for 'z' in %s :\n", schr);
	printf("ft_memchr : %s\n", (char *)ft_memchr(schr, 'z', 16));
	printf("memchr : %s\n", (char *)memchr(schr, 'z', 16));


	printf("\n\n\n------------STRING_FUNCTIONS------------\n\n");

	//strlen
	
	char lt[] = "Bonjour cher evaluateur";
	printf("\n>> ft_strlen\n\n");
	printf("Lenght of \"%s\" :\n", lt);
	printf("ft_strlen : %zu, strlen : %zu\n\n", ft_strlen(lt), strlen(lt));
	printf("Lenght of \"%s\" :\n", "");
	printf("ft_strlen : %zu, strlen : %zu\n\n", ft_strlen(""), strlen(""));

	//atoi

	printf("\n\n>> ft_atoi\n\n");
	char at1[] = "     \t \t  -1234999abc  ";
	char at2[] = "    +   12...dfisfj234";
	char at3[] = "   ++230984";
	printf("string = \"%s\"\nft_atoi :", at1);
	printf("%d, atoi : %d\n\n", ft_atoi(at1), atoi(at1));
	printf("string = \"%s\"\nft_atoi : ", at2);
	printf("%d, atoi : %d\n\n", ft_atoi(at2), atoi(at2));
	printf("string = \"%s\"\nft_atoi : ", at3);
	printf("%d, atoi : %d\n", ft_atoi(at3), atoi(at3));

	//strncmp

	printf("\n\n>> ft_strncmp\n\n");
	char cmp1[] = "HELLO WORLD";
	char cmp2[] = "";
	printf("Comparing \"%s\" and \"%s\" :\n\nFor n = 5 :\n", cmp1, cmp2);
	printf("ft_strncmp : %d, ", ft_strncmp(cmp1, cmp2, 5));
	printf("strncmp : %d\n\n\n", strncmp(cmp1, cmp2, 5));
	printf("\n\nFor n = 10 :\nft_strncmp : %d, ", ft_strncmp(cmp1, cmp2, 10));
	printf("strncmp : %d\n\n\n", strncmp(cmp1, cmp2, 10));
	printf("\n\nFor n = 0 :\nft_strncmp : %d, ", ft_strncmp(cmp1, cmp2, 0));
	printf("strncmp : %d\n\n", strncmp(cmp1, cmp2, 0));

	//strlcpy

	printf("\n\n>> ft_strlcpy\n\n");
	char cp1[] = "Hello World";
	char cp2[30] = "bonjour";
	char cp3[] = "Hello World";
	char cp4[30] = "bonjour";
	char cp5[] = "Hello World";
	char cp6[30] = "bonjour";
	char cp7[] = "Hello World";
	char cp8[30] = "bonjour";
	printf("Copying src : \"%s\" into dest : \"%s\" (size 30) :\n", cp1, cp2);
	printf("ft_strlcpy :\nReturn value : %zu,", ft_strlcpy(cp2, cp1, 30));
	printf(" dest : \"%s\"\n", cp2);
	printf("strlcpy :\nReturn value : %zu,", strlcpy(cp4, cp3, 30));
	printf(" dest : \"%s\"\n", cp4);
	printf("\nCopying src : \"%s\" into dest : \"%s\" (size 8) :\n", cp5, cp6);
	printf("ft_strlcpy :\nReturn value : %zu,", ft_strlcpy(cp6, cp5, 8));
	printf(" dest : \"%s\"\n", cp6);
	printf("strlcpy :\nReturn value : %zu,", strlcpy(cp8, cp7, 8));
	printf(" dest : \"%s\"\n", cp8);

	//strlcat

	printf("\n\n>> ft_strlcat\n\n");
	char cat1[] = "Hello World";
	char cat2[30] = "bonjour";
	char cat3[] = "Hello World";
	char cat4[30] = "bonjour";
	char cat5[] = "Hello World";
	char cat6[30] = "bonjour";
	char cat7[] = "Hello World";
	char cat8[30] = "bonjour";
	printf("Concat src : \"%s\" after dest : \"%s\" (size 30) :\n", cat1, cat2);
	printf("ft_strlcat :\nReturn value : %zu,", ft_strlcat(cat2, cat1, 30));
	printf(" dest : \"%s\"\n", cat2);
	printf("strlcat :\nReturn value : %zu,", strlcat(cat4, cat3, 30));
	printf(" dest : \"%s\"\n", cat4);
	printf("\nConcat src : \"%s\"", cat5);
	printf(" after dest : \"%s\" (size 15) :\n", cat6);
	printf("ft_strlcat :\nReturn value : %zu,", ft_strlcat(cat6, cat5, 15));
	printf(" dest : \"%s\"\n", cat6);
	printf("strlcat :\nReturn value : %zu,", strlcat(cat8, cat7, 15));
	printf(" dest : \"%s\"\n", cat8);

	//strchr

	printf("\n\n>> ft_strchr\n\n");
	char chr1[] = "Salut c'est encore nous";
	printf("Searching for 'e' into \"%s\" :\nft_strchr : ", chr1);
	printf("\"%s\", strchr : ", ft_strchr(chr1, 'e'));
	printf("\"%s\"\n\n", strchr(chr1, 'e'));
	printf("Searching for 's' into \"%s\" :\nft_strchr : ", chr1);
	printf("\"%s\", strchr : ", ft_strchr(chr1, 's'));
	printf("\"%s\"\n\n", strchr(chr1, 's'));
	printf("Searching for 'z' into \"%s\" :\nft_strchr : ", chr1);
	printf("\"%s\", strchr : ", ft_strchr(chr1, 'z'));
	printf("\"%s\"\n\n", strchr(chr1, 'z'));

	//strrchr

	printf("\n\n>> ft_strrchr\n\n");
	char chr2[] = "Salut c'est encore nous et oui";
	printf("Searching for 'e' into \"%s\" :\nft_strrchr : ", chr2);
	printf("\"%s\", strrchr : ", ft_strrchr(chr2, 'e'));
	printf("\"%s\"\n\n", strrchr(chr2, 'e'));
	printf("Searching for 's' into \"%s\" :\nft_strrchr : ", chr2);
	printf("\"%s\", strrchr : ", ft_strrchr(chr2, 's'));
	printf("\"%s\"\n\n", strrchr(chr2, 's'));
	printf("Searching for 'z' into \"%s\" :\nft_strrchr : ", chr2);
	printf("\"%s\", strrchr : ", ft_strrchr(chr2, 'z'));
	printf("\"%s\"\n\n", strrchr(chr2, 'z'));

	//strjoin

	printf("\n\n>> ft_strjoin\n\n");
	char j1[] = "Je m'amuse a tout tester ";
	char j2[] = "mais en vrai c'est epuisant...";
	char *j3 = ft_strjoin(j1, j2);
	printf("Using join to glue s1 : \"%s\" and s2 : \"%s\"", j1, j2);
	printf(" together : \n\nft_strjoin(s1, s2) : \"%s\"\n\n", j3);
	free(j3);

	//split

	printf("\n\n>> ft_split\n\n");
	char spl[] = "Bonjour.les.amis.on.est.encore.sur.les.tests.it.never.ends";
	printf("Using split to breakdown this string : ");
	printf("\"%s\" using '.' as separator :\n\n", spl);
	char **splitted = ft_split(spl, '.');
	int	i = 0;
	while (splitted[i])
		printf("- \"%s\"\n", splitted[i++]);
	i = 0;
	while (splitted[i])
		free(splitted[i++]);
	free(splitted);
	printf("\n");

	//strtrim

	printf("\n\n>> ft_strtrim\n\n");
	char to_trim[] = "...?...Bonjo.????.ur..les..am...is.....???......???";
	char trims[] = ".?";
	printf("Using ft_strtrim to trim \"%s\" using \".?\" as seps :\n", to_trim);
	char *trim = ft_strtrim(to_trim, trims);
	printf("\n\"%s\"\n", trim);
	free(trim);

	//itoa

	printf("\n\n>> ft_itoa\n\n");
	int it1 = 123676;
	int it2 = -2147483648;
	int it3 = 0;
	char *res1 = ft_itoa(it1);
	char *res2 = ft_itoa(it2);
	char *res3 = ft_itoa(it3);
	printf("Using ft_itoa to store %d : \"%s\"\n", it1, res1);
	printf("Using ft_itoa to store %d : \"%s\"\n", it2, res2);
	printf("Using ft_itoa to store %d : \"%s\"\n", it3, res3);
	free(res1);
	free(res2);
	free(res3);

	//striteri

	printf("\n\n>> ft_striteri\n\n");
	char iteri[] = "We are near the end, good luck";
	printf("Using ft_striteri to apply the ft_replace function to ");
	printf("\"%s\" :\n(It will change some ", iteri);
	printf("characters into other depending on their indexes...");
	printf("(changing each uneven character to \"+\", \".\", or \"-\")");
	printf("\n\nBefore striteri :\"%s\"", iteri);
	ft_striteri(iteri, ft_replace);
	printf("\n\nAfter striteri :\"%s\"\n", iteri);

	//strmapi

	printf("\n\n>> ft_strmapi\n\n");
	char mapi[] = "Now let's go to the bonuseeeeeees";
	printf("Using ft_strmapi to apply the ft_replace function to ");
	printf("\"%s\" :\n(It will change some ", mapi);
	printf("characters into other depending on their indexes...");
	printf("(substracting the index from the ascii number)");
	printf("\n\nBefore strmapi :\"%s\"", mapi);
	char *mapres = ft_strmapi(mapi, ft_sub_index);
	printf("\n\nCopy after strmapi :\"%s\"\n", mapres);
	free(mapres);

	printf("\n\n\n------------FD_FUNCTIONS------------\n");

	//putchar_fd

	//printf("\n\n> ft_putchar_fd\n");
	ft_putstr_fd("\n\nft_putchar_fd('c', 1) = ", 1);
	ft_putchar_fd('c', 1);

	//putnbr_fd

	//printf("\n\n> ft_putnbr_fd\n");
	ft_putstr_fd("\n\nft_putnbr_fd(-23678, 1) = ", 1);
	ft_putnbr_fd(-23678, 1);

	//putstr_fd

	//printf("\n\n> ft_putstr_fd\n");
	ft_putstr_fd("\n\nft_putstr_fd(\"Hello World !\", 1) = ", 1);
	ft_putstr_fd("Hello World !", 1);

	//putendl_fd

	//printf("\n\n> ft_putendl_fd\n");
	ft_putstr_fd("\n\nft_putendl_fd(\"Salut le monde !!!\", 1) = ", 1);
	ft_putendl_fd("Salut le monde !!!", 1);
	ft_putendl_fd("Salut le monde !!!", 1);
	printf("ft_putendl in succession to show the newline appearing)\n");


// 	printf("\n------------BONUS_FUNCTIONS------------\n\n");

// 	//ft_lstnew

// 	printf(">> ft_lstnew\n\n");
// 	char *tab[6] = {"zero", "one", "two", "three", "four", NULL};
// 	t_list *new = ft_lstnew(ft_strdup(tab[0]));
// 	printf("\nCreating new node with \"%s\" as it's content :\n\n", tab[0]);
// 	ft_print_lst(new);
// 	free(new->content);
// 	free(new);

// 	//ft_lstadd_front

// 	printf("\n\n>> ft_lstadd_front\n\n");
// 	new = ft_lstnew(ft_strdup("NEW"));
// 	t_list *head = ft_create_lst(tab);
// 	printf("Here is our existing list :\n\n");
// 	ft_print_lst(head);
// 	printf("\nLet's add a new node at the front, ");
// 	printf("the node content being \"NEW\"...\n\n");
// 	ft_lstadd_front(&head, new);
// 	printf("Here is our linked list after adding the new node :\n\n");
// 	ft_print_lst(head);


// 	//ft_lstsize

// 	printf("\n\n>> ft_lstsize\n\n");
// 	printf("Let's find out the size of this list using ft_lstsize...\n");
// 	printf("This list is of size %d.", ft_lstsize(head));

// 	//ft_lstlast

// 	printf("\n\n>> ft_lstlast\n\n");
// 	printf("Let's find out the last element of ");
// 	printf("this list using ft_lstlast...\n\n");
// 	ft_print_lst(ft_lstlast(head));

// 	//ft_lstadd_back

// 	printf("\n\n>> ft_lstadd_back\n\n");
// 	printf("Let's add a new node at the back, ");
// 	printf("the node content being \"BACK\"...\n");
// 	new = ft_lstnew(ft_strdup("BACK"));
// 	ft_lstadd_back(&head, new);
// 	printf("Here is our linked list after adding the new node :\n\n");
// 	ft_print_lst(head);


// 	//ft_lstdelone

// 	printf("\n\n>> ft_lstdelone\n\n");
// 	printf("Let's try to delete a certain element ");
// 	printf("of our list using ft_lstdelone...\n");
// 	printf("We will delete the node where content = \"three\".\n");
// 	t_list *curr = head;
// 	t_list *to_del;
// 	while (curr->next)
// 	{
// 		if (!ft_strncmp((char *)curr->content, "three", 20))
// 		{
// 			to_del = curr;
// 			curr = curr->next;
// 			ft_lstdelone(to_del, ft_del_content);
// 		}
// 		else if (!ft_strncmp((char *)curr->next->content, "three", 20))
// 		{
// 			to_del = curr->next;
// 			if (curr->next->next)
// 				curr->next = curr->next->next;
// 			else
// 				curr->next = NULL;
// 			ft_lstdelone(to_del, ft_del_content);
// 			curr = curr->next;
// 		}
// 		else
// 			curr = curr->next;
// 	}
// 	printf("Let's look at our list after the deletion\n\n");
// 	ft_print_lst(head);
// 	printf("\nThe node was effectively deleted");

// 	//ft_lstclear

// 	printf("\n\n>> ft_lstclear\n\n");
// 	printf("Let's try to clear the whole list using ft_lstclear...\n");
// 	ft_lstclear(&head, ft_del_content);
// 	printf("Let's print the list just to see...\n\n");
// 	ft_print_lst(head);
// 	printf("The value of the head ptr is : %p", head);

// 	//lstiter

// 	printf("\n\n>> ft_lstiter\n\n");
// 	head = ft_create_lst(tab);
// 	printf("Let's create our list again :\n");
// 	ft_print_lst(head);
// 	printf("\nNow we will modify our list using ft_lstiter, and a ");
// 	printf("function that capitalize the first letter of each content.\n");
// 	ft_lstiter(head, ft_capitalize);
// 	printf("\nNow let's print our modified list :\n");
// 	ft_print_lst(head);
// 	printf("\nOur list has been successfully modified !!\n");

// 	//lstmap

// 	printf("\n\n>> ft_lstmap\n\n");
// 	printf("Let's create a modified copy of our list ");
// 	printf("using a function that reverse the string content :\n");
// 	t_list *new_head = ft_lstmap(head, ft_reverse, ft_del_content);
// 	printf("\nNow let's print our new list :\n");
// 	ft_print_lst(new_head);
// 	printf("\nOur new list has been successfully created !!\n\n");
// 	ft_lstclear(&head, ft_del_content);
// 	ft_lstclear(&new_head, ft_del_content);
// 	printf(">>>>>>>>>>>>>>>>>>>>LIBFT_TEST_SUCCESS<<<<<<<<<<<<<<<<<<<<\n\n");
 	return (0);
}
