/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lessie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 16:44:56 by lessie            #+#    #+#             */
/*   Updated: 2020/12/06 16:18:38 by lessie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_numlen(long int nbr)
{
	int		len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

static	char	*ft_numchar(int len, long int nbr, int is_neg)
{
	char	*str;
	int		i;

	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	if (is_neg)
		str[i++] = '-';
	str[len] = '\0';
	while (--len >= i)
	{
		str[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	int				is_neg;
	int				len;
	long int		nbr;
	char			*str;

	str = NULL;
	is_neg = 0;
	if (n < 0)
	{
		nbr = (long int)n * (-1);
		is_neg = 1;
	}
	else
		nbr = n;
	len = ft_numlen(nbr) + is_neg;
	if (!(str = ft_numchar(len, nbr, is_neg)))
		return (NULL);
	return (str);
}
