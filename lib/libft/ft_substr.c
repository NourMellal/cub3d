/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielhasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:24:53 by ielhasso          #+#    #+#             */
/*   Updated: 2023/11/12 17:45:12 by ielhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*memoir;
	size_t	j;

	s_len = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	memoir = malloc(len + 1);
	if (memoir != NULL)
	{
		j = 0;
		while (j < len)
		{
			memoir[j] = s[start++];
			j++;
		}
		memoir[j] = '\0';
	}
	return (memoir);
}
