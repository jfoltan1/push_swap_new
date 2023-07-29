/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_d,i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:03:04 by jfoltan           #+#    #+#             */
/*   Updated: 2023/03/22 14:03:34 by jfoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(long n)
{
	int		len;
	char	*num;

	len = 0;
	if (n > 0)
	{
		num = ft_uitoa(n);
		len = ft_printstr(num);
		free(num);
	}
	else if (n < 0)
	{
		num = ft_negitoa(n);
		len = ft_printstr(num);
		free(num);
	}
	else if (n == 0)
		len = ft_printchar(n + 48);
	return (len);
}

char	*ft_negitoa(long n)
{
	char	*num;
	int		len;

	n = n * -1;
	len = ft_num_lenght((long)n);
	num = (char *)malloc(sizeof(char) * (len + 2));
	if (!num)
		return (0);
	num[len + 1] = '\0';
	while (n != 0)
	{
		num[len] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	num[len] = '-';
	return (num);
}
