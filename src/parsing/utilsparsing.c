/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsparsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielhasso <ielhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:43:56 by ielhasso          #+#    #+#             */
/*   Updated: 2024/09/18 19:46:47 by ielhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

int	isallspace(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	initdata(void)
{
	int	i;

	i = 0;
	while (i < data()->lines)
	{
		data()->file[i] = NULL;
		i++;
	}
}

void	charscheck(char *element, char **split)
{
	if (ft_strcmp(element, "NO") && ft_strcmp(element, "SO")
		&& ft_strcmp(element, "WE") && ft_strcmp(element, "EA")
		&& ft_strcmp(element, "C") && ft_strcmp(element, "F"))
	{
		printf("Error\nin map2");
		exit(freefile(split) + freeelement());
	}
}

int	checkmap(char *line)
{
	static int	index = 0;
	char		**split;
	int			i;

	i = 0;
	split = ft_splits(line);
	if (!split)
		return (0);
	if (index < 6)
	{
		if (split[1] == NULL)
			exit(freefile(split) + printf("Error\nin map1\n") + freeelement());
		charscheck(split[0], split);
		data()->elemets[index] = ft_strdup(line);
	}
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	if (index == 6)
		return (1);
	index++;
	return (5);
}

int	freefile(char **tofree)
{
	int	i;

	i = 0;
	while (i < data()->lines)
	{
		free(data()->file[i]);
		i++;
	}
	close(data()->fd);
	free(data()->file);
	if (tofree == NULL)
		return (0);
	else
	{
		i = 0;
		while (tofree[i])
		{
			free(tofree[i]);
			i++;
		}
		free(tofree);
	}
	return (0);
}

void	fix_map(void)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (data()->map[i])
	{
		j = ft_strlen(data()->map[i]);
		if (data()->map[i][j - 1] == '\n')
				data()->map[i][j - 1] = '\0';
		// if ((int)i == data()->map_hight - 1)
		// 	j++;
		while (j < data()->longest)
		{
			data()->map[i] = ft_strjoin(data()->map[i], " ");
			j++;
		}
		data()->map[i] = ft_strjoin(data()->map[i], "\0");
		i++;
	}
}

size_t get_longest_line(void)
{
	int	i;
	int	max;
	int	len;

	i = 0;
	max = 0;
	while (data()->map[i])
	{
		len = ft_strlen(data()->map[i]);
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}