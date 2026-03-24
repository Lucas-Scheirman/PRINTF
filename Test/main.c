#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	n;
	int	r1;
	int	r2;

	// %c
	printf("=== %%c ===\n");
	ft_printf("%c\n", 'A');
	printf("%c\n", 'A');
	// %s
	printf("=== %%s ===\n");
	ft_printf("%s\n", "hello");
	printf("%s\n", "hello");
	ft_printf("%s\n", "");
	printf("%s\n", "");
	ft_printf("%s\n", (char *)NULL);
	printf("%s\n", (char *)NULL);
	// %d
	printf("=== %%d ===\n");
	ft_printf("%d\n", 0);
	printf("%d\n", 0);
	ft_printf("%d\n", 42);
	printf("%d\n", 42);
	ft_printf("%d\n", -42);
	printf("%d\n", -42);
	ft_printf("%d\n", 2147483647);
	printf("%d\n", 2147483647);
	ft_printf("%d\n", -2147483647);
	printf("%d\n", -2147483647);
	// %i
	printf("=== %%i ===\n");
	ft_printf("%i\n", 0);
	printf("%i\n", 0);
	ft_printf("%i\n", 42);
	printf("%i\n", 42);
	ft_printf("%i\n", -42);
	printf("%i\n", -42);
	ft_printf("%i\n", 2147483647);
	printf("%i\n", 2147483647);
	ft_printf("%i\n", -2147483647 - 1);
	printf("%i\n", -2147483647 - 1);
	// %u
	printf("=== %%u ===\n");
	ft_printf("%u\n", 0);
	printf("%u\n", 0);
	ft_printf("%u\n", 42);
	printf("%u\n", 42);
	ft_printf("%u\n", (unsigned int)4294967295);
	printf("%u\n", (unsigned int)4294967295);
	ft_printf("%u\n", (unsigned int)-1);
	printf("%u\n", (unsigned int)-1);
	// %x
	printf("=== %%x ===\n");
	ft_printf("%x\n", 0);
	printf("%x\n", 0);
	ft_printf("%x\n", 255);
	printf("%x\n", 255);
	ft_printf("%x\n", (unsigned int)4294967295);
	printf("%x\n", (unsigned int)4294967295);
	ft_printf("%x\n", (unsigned int)-1);
	printf("%x\n", (unsigned int)-1);
	// %X
	printf("=== %%X ===\n");
	ft_printf("%X\n", 0);
	printf("%X\n", 0);
	ft_printf("%X\n", 255);
	printf("%X\n", 255);
	ft_printf("%X\n", (unsigned int)4294967295);
	printf("%X\n", (unsigned int)4294967295);
	// %p
	printf("=== %%p ===\n");
	n = 42;
	ft_printf("%p\n", &n);
	printf("%p\n", &n);
	ft_printf("%p\n", NULL);
	printf("%p\n", NULL);
	// %%
	printf("=== %%%% ===\n");
	ft_printf("100%%\n");
	printf("100%%\n");
	ft_printf("%%%%\n");
	printf("%%%%\n");
	// mixed
	printf("=== mixed ===\n");
	ft_printf("char:%c str:%s int:%d hex:%x ptr:%p\n", 'A', "hello", 42, 255,
		&n);
	printf("char:%c str:%s int:%d hex:%x ptr:%p\n", 'A', "hello", 42, 255, &n);
	// valeur de retour
	printf("=== return (value ===\n");
	r1 = ft_printf("hello");
	r2 = printf("hello");
	ft_printf("\nft_printf: %d\n", r1);
	printf("\nprintf:    %d\n", r2);
	r1 = ft_printf("%d", -2147483647 - 1);
	r2 = printf("%d", -2147483647 - 1);
	ft_printf("\nft_printf: %d\n", r1);
	printf("\nprintf:    %d\n", r2);
}
