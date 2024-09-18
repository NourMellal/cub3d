/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ../../include/parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <nmellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:48:30 by ielhasso          #+#    #+#             */
/*   Updated: 2024/09/18 00:03:05 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "../lib/libft/libft.h"
// map color index 0 for floor 1 for sky
char					*get_next_line(int fd);
struct					s_parse
{
	char				**file;
	size_t 				*longest;
	char				**map;
	int					pos[2];
	int					fd;
	int					lines;
	char				*elemets[6];
	char				direction;
	int					mapcolor[2][3];
};
typedef struct s_parse	t_parse;

char					**ft_splits(char *str);
char					**ft_spitv(char *str);
t_parse					*data(void);
int						isallspace(char *line);
void					initdata(void);
int						freefile(char **tofree);
int						freeelement(void);
int						checkmap(char *line);
void					charsinmap(void);
int						freetextuer(void);
int						ft_strcmp(char *s1,char *s2);
size_t					get_longest_line(void);
#endif