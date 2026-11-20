/* ************************************************************************** */
/*                                                                            */
/*                                                       .     codam.nl       */
/*   main.c                                             ":"                   */
/*                                                    ___:____     |"\/"|     */
/*   By: embrugge <embrugge@student.codam.nl>       ,'        `.    \  /      */
/*                                                  |  v~       \___/  |      */
/*   Created: 2026/11/16 16:52:57 by embrugge     ~^~^~^~^~^~^~^~^~^~^~^~^~   */
/*   Updated: 2026/11/19 13:22:54 by embrugge        ~       ~       ~        */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "ft_printf.h"

int	main(void)
{
	int	number = 42;
	int	*pointer = &number;
	printf("\n^%i^\n",    printf("hello world "));
	printf("\n^%i^\n",    printf("%s, % -5i, %i, %f\n", "bleh", 64, -54, 1.35));
	printf("\n^%i^\n",    printf("%010f", 1234567.5437));
	printf("\n^%i^\n",    printf("%50i", 8584));
	printf("\n^%i^\n",    printf("\n^%i^ %% %p\n", number, pointer));

	printf("\n^%i^\n", ft_printf("hello world "));
	printf("\n^%i^\n", ft_printf("%s, % -5i, %i, %f\n", "bleh", 64, -54, 1.35));
	printf("\n^%i^\n", ft_printf("%010f", 1234567.5437));
	printf("\n^%i^\n", ft_printf("%50i", 8584));
	printf("\n^%i^\n", ft_printf("\n^%i^ %% %p\n", number, pointer));
}
