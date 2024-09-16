/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielhasso <ielhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:48:30 by ielhasso          #+#    #+#             */
/*   Updated: 2024/09/16 19:10:32 by ielhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
// map color index 0 for floor 1 for sky
char					*get_next_line(int fd);
struct					s_parse
{
	char				**file;
	int					fd;
	int					lines;
	char				*elemets[6];
	char				direction;
	int					mapcolor[2][3];
};
typedef struct s_parse	t_parse;

char					**ft_split(char *str);
char					**ft_spitv(char *str);
t_parse					*data(void);
int						isallspace(char *line);
void					initdata(void);
int						freefile(char **tofree);
int						freeelement(void);
int						checkmap(char *line);
void					charsinmap(void);
int						freetextuer(void);
#endif