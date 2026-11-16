/* ************************************************************************** */
/*                                                                            */
/*                                                       .     codam.nl       */
/*   ft_printf.c                                        ":"                   */
/*                                                    ___:____     |"\/"|     */
/*   By: embrugge <embrugge@student.codam.nl>       ,'        `.    \  /      */
/*                                                  |  v~       \___/  |      */
/*   Created: 2026/10/17 14:28:36 by embrugge     ~^~^~^~^~^~^~^~^~^~^~^~^~   */
/*   Updated: 2026/11/16 19:03:30 by embrugge        ~       ~       ~        */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

#include "ft_printf.h"

int	print_conversion(const char *str, va_list args);

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		ret;
	int		bleh;

	va_start(args, str);
	ret = 0;
	while (*str)
	{
		bleh = 1;
		if (*str == '%')
			bleh += print_conversion(++str, args);
		else
			write(1, str++, 1);
		ret += bleh;
	}
	va_end(args);
	return (ret);
}

int	print_conversion(const char *str, va_list args)
{
	str++;
	if (*str++ == 'c')
		return (0);
	return (0);
}
