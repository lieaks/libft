#include "ft_printf.h"
#include <stdio.h>

int main ()
{
	unsigned int  a = 0;
	char *nul = NULL;
	char str[] = "je suis ";
	int vrai = printf("print :%p %x %u %s %s\n", (void*)a, a, a, str, nul);
	int faux = ft_printf("fakef :%p %x %u %s %s\n", (void*)a, a, a, str, nul);
	printf("---------------------\n");
	printf("print count = %d \n", vrai);
	printf("ft count= %d \n", faux);
	ft_itoa_base(a, "0123456789abcdef");
	return 0;	
}
