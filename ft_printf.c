/* ************************************************************************** */
/*                                                                            */
/*                                                       .     codam.nl       */
/*   ft_printf.c                                        ":"                   */
/*                                                    ___:____     |"\/"|     */
/*   By: embrugge <embrugge@student.codam.nl>       ,'        `.    \  /      */
/*                                                  |  v~       \___/  |      */
/*   Created: 2026/10/17 14:28:36 by embrugge     ~^~^~^~^~^~^~^~^~^~^~^~^~   */
/*   Updated: 2026/11/19 15:09:55 by embrugge        ~       ~       ~        */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#include "ft_printf.h"
#include "libft/libft.h"

char	*convert_char(va_list arg);
char	*convert_str(va_list arg);
char	*convert_int(va_list arg);
char	*convert_ptr(va_list arg);
char	*convert_percent(void);

int		print_conversion(const char *str, va_list args);

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
			write(1, str, 1);
		ret += bleh;
		str++;
	}
	va_end(args);
	return (ret);
}

int	write_arg(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		write(1, str++, 1);
		i++;
	}
	return (i);
}

int	print_conversion(const char *str, va_list args)
{
	char	*print;
	int		ret;

	print = NULL;
	ret = 0;
	if (*str == 'c')
		print = convert_char(args);
	else if (*str == 's')
		print =	convert_str(args);
	else if (*str == 'i')
		print =	convert_int(args);
	else if (*str == 'p')
		print =	convert_int(args);
	else if (*str == '%')
		print =	convert_percent();
	if (print && *print)
		ret = write_arg(print);
	free(print);
	return (ret);
}

char	*convert_char(va_list arg)
{
	char	*ret;
	char	c;

	c = (char)va_arg(arg, int);
	ret = malloc(2);
	if (!ret)
		return (NULL);
	ret[0] = c;
	ret[1] = '\0';
	return (ret);
}

char	*convert_str(va_list arg)
{
	char	*ret;

	ret = ft_strdup(va_arg(arg, char *));
	if (!ret)
		return (NULL);
	return (ret);
}

char	*convert_int(va_list arg)
{
	char	*ret;

	ret = ft_itoa(va_arg(arg, int));
	if (!ret)
		return (NULL);
	return (ret);
}

char	*convert_ptr(va_list arg)
{
	char	*ret;

	ret = ft_itoa(va_arg(arg, void *));
	if (!ret)
		return (NULL);
	return (ret);
}

char	*convert_percent(void)
{
	char	*ret;

	ret = malloc(2);
	if (!ret)
		return (NULL);
	ret[0] = '%';
	ret[1] = '\0';
	return (ret);
}
