/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_X,x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:03:18 by jfoltan           #+#    #+#             */
/*   Updated: 2023/03/22 14:03:37 by jfoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*strreverse(char *str)
{
	int		d;
	int		i;
	char	a;

	i = 0;
	d = 0;
	a = '0';
	i = ft_strlen(str);
	i--;
	while (i >= d)
	{
		a = str[d];
		str[d] = str[i];
		str[i] = a;
		i--;
		d++;
	}
	return (str);
}

int	ft_hexconvert(unsigned long d, char c)
{
	char	output[16];
	int		e;
	char	*hehe;
	char	*hehe2;

	hehe = "0123456789abcdef";
	hehe2 = "0123456789ABCDEF";
	if (d == 0)
		return (ft_printchar(48));
	e = 0;
	while (d > 0 && c == 88)
	{
		output[e] = (hehe2[d % 16]);
		d = d / 16;
		e++;
	}
	while (d > 0 && c == 120)
	{
		output[e] = (hehe[d % 16]);
		d = d / 16;
		e++;
	}
	output[e] = 0;
	strreverse(output);
	return (ft_printstr(output));
}
