/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <nmellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:43:50 by ielhasso          #+#    #+#             */
/*   Updated: 2024/09/19 04:36:17 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shared.h"
#include <stdio.h>
#include <stdlib.h>

static char	*ft_strncpy(char *s1, char *s2, int n)
{
	int	i;

	i = -1;
	while (++i < n && s2[i])
		s1[i] = s2[i];
	s1[i] = '\0';
	return (s1);
}

static int	word_cout(char *str)
{
	int	i;
	int	wc;

	i = 0;
	wc = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i])
			wc++;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
	}
	return (wc);
}

char	**ft_splits(char *str)
{
	char	**out;

	int (i), (j), (k), (wc);
	i = 0;
	j = 0;
	k = 0;
	wc = word_cout(str);
	out = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!out)
		return (NULL);
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		j = i;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
		if (i > j)
		{
			out[k] = (char *)malloc(sizeof(char) * ((i - j) + 1));
			ft_strncpy(out[k++], &str[j], i - j);
		}
	}
	out[k] = NULL;
	return (out);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2++)
		if (*s1++ == '\0')
			return (0);
	return (*(const unsigned char *)s1 - *(const unsigned char *)(s2 - 1));
}
