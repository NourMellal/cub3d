/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielhasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:02:37 by ielhasso          #+#    #+#             */
/*   Updated: 2023/11/08 17:54:05 by ielhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_len(long nbr)
{
	int	len;

	if (nbr < 0 || nbr == 0)
	{
		len = 1;
	}
	else
		len = 0;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

static void	ft_convert_number(char *result, long n, int len, int i)
{
	while (len >= i)
	{
		result[len] = n % 10 + '0';
		n /= 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;
	int		i;
	long	nbr;

	len = ft_len(n);
	i = 0;
	nbr = n;
	result = (char *)malloc(len + 1);
	if (!result)
		return (0);
	if (nbr == 0)
		result[0] = '0';
	result[len--] = '\0';
	if (nbr < 0)
	{
		result[0] = '-';
		nbr = -nbr;
		i++;
	}
	ft_convert_number(result, nbr, len, i);
	return (result);
}
