/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlyubick <vlyubick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 10:11:48 by vlyubick          #+#    #+#             */
/*   Updated: 2021/10/22 14:25:12 by vlyubick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	ptr = (char *) malloc(sizeof(*s) * (len + 1));
	if (!ptr || !s)
		return (NULL);
	j = 0;
	i = 0;
	while (s[j] != '\0')
	{
		if (i < len && j >= start)
		{
			ptr[i] = s[j];
			i++;
		}
		j++;
	}
	ptr[i] = '\0';
	return (ptr);
}
