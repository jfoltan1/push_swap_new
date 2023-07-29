/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:03:12 by jfoltan           #+#    #+#             */
/*   Updated: 2023/03/22 14:03:35 by jfoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printstr(char *s)
{
	int	i;
	int	numofchars;

	numofchars = 0;
	i = 0;
	if (s != NULL)
	{	
		while (s[i])
		{
			numofchars += write(1, &s[i], 1);
			i++;
		}
	}
	else if (s == NULL)
		return (ft_printstr("(null)"));
	return (numofchars);
}
