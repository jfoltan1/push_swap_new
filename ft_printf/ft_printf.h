/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfoltan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:33:48 by jfoltan           #+#    #+#             */
/*   Updated: 2023/03/22 14:03:38 by jfoltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>

char	*ft_uitoa(unsigned long n);
char	*strreverse(char *str);
char	*ft_negitoa(long n);
size_t	ft_strlen(const char *s);
int		minatoldmetomakeaseparatefunctiontoprintapercentsignlol(void);
int		ft_printnbr(long n);
int		ft_printchar(int c);
int		ft_printstr(char *str);
int		ft_num_lenght(long f);
int		ft_print_unsigned(unsigned long n);
int		ft_hexconvert(unsigned long d, char c);
int		ft_ptrgod(unsigned long long ptr);
int		ft_printf(const char *lststring, ...);
#endif
