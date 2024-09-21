/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <nmellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:43:45 by ielhasso          #+#    #+#             */
/*   Updated: 2024/09/20 01:42:26 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	int		byte;
	char	c;
	char	*str_buffer;
	int		i;

	if (fd < 0)
		return (NULL);
	i = 0;
	str_buffer = (char *)malloc(5000);
	if (!str_buffer)
		return (NULL);
	byte = read(fd, &c, 1);
	while (byte > 0)
	{
		str_buffer[i] = c;
		i++;
		if (c == '\n' || c == EOF)
			break ;
		byte = read(fd, &c, 1);
	}
	if (i == 0 || byte < 0)
		return (free(str_buffer), NULL);
	str_buffer[i] = '\0';
	return (str_buffer);
}
