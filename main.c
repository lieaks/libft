#include "libft.h"
#include <string.h>
#include <stdio.h>
#include "stdint.h"
#include "limits.h"

int main(int ac, char **av)
{
	// size_t a = sizeof(int) * 5;
	// char str1[] = "0123456789";
	// // char str2[] = "jesui";
	// int	num1[] = {1,2, 3,4 ,5};
	// // int	num2[] = {1,2, 3,4 ,5};

	// //memset
	// ft_memset(num1, 1, a);
	// for (size_t i = 0; i < 5; i++)
	// 	printf("ft_memcmp %ld: %d\n", i, num1[i]);
	// memset(num1, 3, a);
	// for (size_t i = 0; i < 5; i++)
	// 	printf("ft_memcmp %ld: %d\n", i, num1[i]);
	// // char *ptr = ft_strnstr(str1, str2, 4);
	// // printf("%d\n", *ptr);
	// printf("%d\n", ft_atoi("   -35"));
	// printf("%s\n", (char *)memmove(str1 + 2, str1, 4));

	// //ft_memcmp
	// // printf("ft_memcmp : %d\n", memcmp(num1, num2, a));
	// // printf("memcmp %d\n", ft_memcmp(num1, num2, a));

    // char str[100] = "Learningisfun";
    // char *first, *second;
    // first = str;
    // second = str;
    // printf("Original string :%s\n ", str);
      
    // // when overlap happens then it just ignore it
    // memcpy(first + 8, first, 10);
    // printf("memcpy overlap : %s\n ", str);

    // // when overlap it start from first position
    // memmove(second + 8, first, 10);
    // printf("memmove overlap : %s\n ", str);
	// int	*ptr;
	// ptr = ft_calloc(10, 4);
	// if (!ptr)
	// 	write(2, "eror", 4);
	// int i = 0;
	// char *test = (char *)ptr;
	// while (i < 10 * 4)
	// {
	// 	printf("%d : %d\n", i , test[i]);
	// 	i++;
	// }
	// free(ptr);
	// free(test);

	char	s[] = "12345 6789";
	// // char	s2[] = "45";
	
	// // char	*d = ft_itoa(-0);
	// // printf("%s\n", d);
	// // free(d);
	
	// printf("%s\n", ft_split(s, ' '));

	// char **t;
	// int i = 0;

	(void)ac;
	(void)av;
	
	// t = ft_split(s ,' ');

	// while (t[i])
	// {
	// 	printf("i : %d, %s\n", i , t[i]);
	// 	i++;
	// }
	// printf("%s", t[i]);
	// i = 0;
	// while (t[i])
	// 	free(t[i++]);
	// free(t);
	char	*test;
	test = ft_substr(s, , 5);
	printf("%s\n", test);
	return 0;
}