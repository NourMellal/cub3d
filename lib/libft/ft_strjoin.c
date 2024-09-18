/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmellal <nmellal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 19:54:19 by ielhasso          #+#    #+#             */
/*   Updated: 2024/09/18 01:09:53 by nmellal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	totallen;
	char	*result;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	totallen = ft_strlen(s1) + ft_strlen(s2) + 1;
	result = (char *)malloc(totallen);
	if (result == NULL)
		return (NULL);
	if (ft_strlcpy(result, s1, totallen) >= totallen)
	{		
		return (NULL);
	}
	if (ft_strlcat(result, s2, totallen) >= totallen)
	{		
		return (NULL);
	}
	free((char *)s1);
	return (result);
}
