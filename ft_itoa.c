/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:09:13 by zel-oirg          #+#    #+#             */
/*   Updated: 2023/11/05 20:15:43 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_digit(int n)
{
	int	i;

	i = 1;
	if (n < 0)
		i++;
	while (n / 10)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;
	long	nb;

	i = num_digit(n);
	nb = n;
	res = (char *)malloc(i + 1);
	if (!res)
		return (NULL);
	res[i--] = 0;
	if (nb < 0)
	{
		nb = -nb;
		res[0] = '-';
	}
	while (nb / 10)
	{
		res[i--] = '0' + (nb % 10);
		nb = nb / 10;
	}
	res[i] = nb + '0';
	return (res);
}
