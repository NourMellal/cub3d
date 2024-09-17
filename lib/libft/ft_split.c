/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielhasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:02:21 by ielhasso          #+#    #+#             */
/*   Updated: 2023/11/10 11:20:15 by ielhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_countword(char const *s, char c)
{
	size_t	count;

	count = 0;
	if (!s)
		return (count);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static void	freen(char **lst, int i)
{
	while (i > 0)
	{
		free(lst[i - 1]);
		i--;
	}
	free(lst);
}

static char	*create_substring(char const *s, char c)
{
	size_t	word_len;
	char	*substring;

	if (!ft_strchr(s, c))
		word_len = ft_strlen(s);
	else
		word_len = ft_strchr(s, c) - s;
	substring = ft_substr(s, 0, word_len);
	return (substring);
}

static char	*ft_check(char *substring, char **lst, int i)
{
	if (!substring)
	{
		freen(lst, i);
		return (NULL);
	}
	return (substring);
}

char	**ft_split(char const *s, char c)
{
	char	**lst;
	int		i;
	char	*substring;

	i = 0;
	lst = (char **)malloc((ft_countword(s, c) + 1) * sizeof(char *));
	if (!lst || !s)
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			substring = create_substring(s, c);
			if (!ft_check(substring, lst, i))
				return (NULL);
			lst[i++] = substring;
			s += ft_strlen(substring);
		}
	}
	lst[i] = NULL;
	return (lst);
}
