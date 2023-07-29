/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:03:09 by jfoltan           #+#    #+#             */
/*   Updated: 2023/03/22 14:03:35 by jfoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_ptrgod(unsigned long long ptr)
{
	int		numofchars;
	char	identity;

	numofchars = 0;
	identity = 'x';
	if (ptr == 0)
		return (ft_printstr("(nil)"));
	numofchars += write(1, "0x", 2);
	numofchars += ft_hexconvert((unsigned long)ptr, identity);
	return (numofchars);
}
