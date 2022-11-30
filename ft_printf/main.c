#include "ft_printf.h"
#include <stdio.h>

int main ()
{
	char str[] = "je suis ";
	int vrai = printf("print : %u  %s\n", 23, str);
	int faux = ft_printf("fakef : %u  %s\n", 23, str);
	printf("---------------------\n");
	printf("print count = %d \n", vrai);
	printf("ft count= %d \n", faux);
	return 0;	
}
