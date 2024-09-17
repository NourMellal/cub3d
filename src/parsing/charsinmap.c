/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charsinmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielhasso <ielhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:43:42 by ielhasso          #+#    #+#             */
/*   Updated: 2024/09/17 12:28:20 by ielhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

void	freedouble(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
}

int	assigmnet(char *str)
{
	if (strcmp(str, "NO") == 0)
		return (-3);
	else if (strcmp(str, "SO") == 0)
		return (-4);
	else if (strcmp(str, "WE") == 0)
		return (-5);
	else if (strcmp(str, "EA") == 0)
		return (-6);
	else if (strcmp(str, "F") == 0)
		return (-7);
	else if (strcmp(str, "C") == 0)
		return (-8);
	return (0);
}

void	sameelemet(void)
{
	char	**str;

	int (i), (j) = 0;
	i = 33;
	while (j < 6)
	{
		str = ft_split(data()->elemets[j]);
		if (str[2])
			i += 100;
		if (str)
		{
			i += assigmnet(str[0]);
		}
		freedouble(str);
		j++;
	}
	if (i != 0)
		exit(printf("Error\nmissing element") + freefile(NULL) + freeelement());
}

void	issurrendbywalls(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < data()->lines - 1)
	{
		if (data()->file[i])
		{
			j = 0;
			while (data()->file[i][j])
			{
				if (data()->file[i][j] == '0' || data()->file[i][j] == 'N'
					|| data()->file[i][j] == 'S' || data()->file[i][j] == 'E'
					|| data()->file[i][j] == 'W')
				{
					if (!data()->file[i - 1] || !data()->file[i + 1]
						|| data()->file[i][j + 1] == ' ' || data()->file[i][j
						- 1] == ' ' || data()->file[i + 1][j] == ' '
						|| data()->file[i - 1][j] == ' ' || data()->file[i][j
						+ 1] == '\n' || data()->file[i][j - 1] == '\n'
						|| data()->file[i + 1][j] == '\n' || data()->file[i
						- 1][j] == '\n')
					{
						printf("Error\nin map10\n");
						exit(freefile(NULL) + freeelement());
					}
				}
				j++;
			}
		}
		i++;
	}
	j = 0;
	while (data()->file[i][j])
	{
		if (data()->file[i][j] == '0' || data()->file[i][j] == 'N'
			|| data()->file[i][j] == 'S' || data()->file[i][j] == 'E'
			|| data()->file[i][j] == 'W')
		{
			printf("Error\nin map11\n");
			exit(freefile(NULL) + freeelement());
		}
		j++;
	}
}

void	isdupchars(void)
{
	int (i), (j), (c);
	i = 0;
	c = 0;
	while (i < data()->lines)
	{
		if (data()->file[i])
		{
			j = 0;
			while (data()->file[i][j])
			{
				if (data()->file[i][j] == 'N' || data()->file[i][j] == 'S'
					|| data()->file[i][j] == 'E' || data()->file[i][j] == 'W')
				{
					c++;
					data()->direction = data()->file[i][j];
					data()->pos[0] = i;
					data()->pos[1] = j;
				}
				j++;
			}
		}
		i++;
	}
	if (c != 1)
		exit(freefile(NULL) + freeelement() + printf("Error\nin map\n"));
}

void	copymap(void)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	data()->map = malloc(sizeof(char *) * (data()->lines + 1));
	if (!data()->map)
		exit(freefile(NULL) + freeelement());
	while (i < data()->lines)
	{
		if (data()->file[i])
		{
			data()->map[j] = strdup(data()->file[i]);
			if (!data()->map[j])
				exit(freefile(data()->map) + freeelement());
			j++;
		}
		i++;
	}
	data()->map[j] = NULL;
}

void	checkelements(void)
{
	int		i;
	char	**split;
	int		fd;

	i = 0;
	while (i < 4)
	{
		split = ft_split(data()->elemets[i]);
		fd = open(split[1], O_RDONLY);
		if (fd == -1)
		{
			printf("Error\nin map13 %s-\n", split[1]);
			freedouble(split);
			exit(freefile(NULL) + freeelement());
		}
		freedouble(split);
		close(fd);
		i++;
	}
	copymap();
}

void	getcolor(void)
{
	char	**floor;
	char	**ceiling;
	int		i;
	char	**toaoitf;
	char	**toaoitc;

	i = 0;
	floor = ft_split(data()->elemets[4]);
	ceiling = ft_split(data()->elemets[5]);
	toaoitc = ft_spitv(ceiling[1]);
	toaoitf = ft_spitv(floor[1]);
	while (i < 3)
	{
		if (!toaoitf[i] || !toaoitc[i])
		{
			printf("Error\nin map50\n");
			freedouble(floor);
			freedouble(ceiling);
			freedouble(toaoitf);
			freedouble(toaoitc);
			exit(freefile(NULL) + freeelement());
		}
		if (strlen(toaoitf[i]) > 3 || strlen(toaoitc[i]) > 3
			|| strlen(toaoitf[i]) < 1 || strlen(toaoitc[i]) < 1)
		{
			printf("Error\nin map2\n");
			freedouble(floor);
			freedouble(ceiling);
			freedouble(toaoitf);
			freedouble(toaoitc);
			exit(freefile(NULL) + freeelement());
		}
		data()->mapcolor[0][i] = atoi(toaoitf[i]);
		data()->mapcolor[1][i] = atoi(toaoitc[i]);
		if (data()->mapcolor[0][i] > 255 || data()->mapcolor[1][i] > 255
			|| data()->mapcolor[0][i] < 0 || data()->mapcolor[1][i] < 0)
		{
			printf("Error\nin map1\n");
			freedouble(floor);
			freedouble(ceiling);
			freedouble(toaoitf);
			freedouble(toaoitc);
			exit(freefile(NULL) + freeelement());
		}
		i++;
	}
	freedouble(floor);
	freedouble(ceiling);
	freedouble(toaoitf);
	freedouble(toaoitc);
	checkelements();
}

void	charsinmap(void)
{
	int (i), (j);
	i = 0;
	sameelemet();
	while (i < data()->lines)
	{
		if (data()->file[i])
		{
			j = -1;
			while (data()->file[i][++j])
			{
				if (data()->file[i][j] != ' ' && data()->file[i][j] != '1'
					&& data()->file[i][j] != '0' && data()->file[i][j] != 'N'
					&& data()->file[i][j] != 'S' && data()->file[i][j] != 'E'
					&& data()->file[i][j] != 'W' && data()->file[i][j] != '\n')
				{
					printf("Error\nin map3");
					exit(freefile(NULL) + freeelement());
				}
			}
		}
		i++;
	}
	issurrendbywalls();
	isdupchars();
	getcolor();
}
