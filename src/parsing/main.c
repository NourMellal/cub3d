/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielhasso <ielhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:43:48 by ielhasso          #+#    #+#             */
/*   Updated: 2024/09/22 19:11:20 by ielhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/shared.h"
#include "../../include/raycasting.h"

int	countlines(void)
{
	char	*line;
	int		height;

	height = 0;
	line = get_next_line(data()->fd);
	if (!line)
	{
		return (printf("Error\nin file\n"), -1);
	}
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(data()->fd);
	}
	free(line);
	return (height);
}

int	stepone(char *av)
{
	int (i);
	data()->fd = open(av, O_RDONLY);
	if (data()->fd == -1)
		return (printf("Error\nin file\n"), 0);
	data()->lines = countlines();
	close(data()->fd);
	data()->fd = open(av, O_RDONLY);
	i = 0;
	if (data()->lines == -1)
		return (0);
	data()->file = (char **)malloc(sizeof(char *) * data()->lines);
	if (!data()->file)
		return (printf("Error\nin malloc\n"), 0);
	initdata();
	while (i < data()->lines)
	{
		data()->file[i] = get_next_line(data()->fd);
		i++;
	}
	return (1);
}

void	steptwo(void)
{
	int (i), (j);
	i = -1;
	while (++i < data()->lines)
	{
		if (isallspace(data()->file[i]))
		{
			free(data()->file[i]);
			data()->file[i] = NULL;
		}
	}
	i = 0;
	while (i < data()->lines)
	{
		if (data()->file[i])
		{
			j = checkmap(data()->file[i]);
			if (j == 0)
				exit(freefile(NULL));
			else if (j == 1)
				break ;
			free(data()->file[i]);
			data()->file[i] = NULL;
		}
		i++;
	}
}

int	freeelement(void)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		free(data()->elemets[i]);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 2 || ft_strcmp(av[1] + ft_strlen(av[1]) - 4, ".cub"))
		return (printf("Error\nin args\n"));
	if (stepone(av[1]) == 0)
		return (0);
	steptwo();
	charsinmap();
	for (int i = 0; i < 6; i++)
	{
		printf("%s\n", data()->elemets[i]);
	}
	printf("------------------------------------------------\n");
	data()->longest = get_longest_line();
	data()->map_width = data()->longest;
	fix_map();
	for (int i = 0; data()->map[i];i++)
	{
		puts(data()->map[i]);
	}
	start_mlx();
	return (freefile(data()->map) + freeelement());
	// return (0);
}
