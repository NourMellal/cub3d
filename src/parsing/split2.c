/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <nmellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:43:50 by ielhasso          #+#    #+#             */
/*   Updated: 2024/09/18 00:16:57 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"
#include <stdio.h>
#include <stdlib.h>

t_parse	*data(void)
{
	static struct s_parse	data;

	return (&data);
}

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
		while (str[i] && str[i] == ',')
			i++;
		if (str[i])
			wc++;
		while (str[i] && str[i] != ',')
			i++;
	}
	return (wc);
}

char	**ft_spitv(char *str)
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
		while (str[i] && str[i] == ',')
			i++;
		j = i;
		while (str[i] && str[i] != ',')
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
