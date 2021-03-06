/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deddara <deddara@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 16:25:23 by deddara           #+#    #+#             */
/*   Updated: 2020/06/13 08:49:13 by deddara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	char	*ptr;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (count == -2)
			break ;
		ptr = (char *)str;
		if (*str != '%')
		{
			write(1, &*str, 1);
			count++;
		}
		else if (!(str = form_parser(str, &args, &count)))
			str = ptr;
		str++;
	}
	va_end(args);
	if (count == -2)
		return (-1);
	return (count);
}
