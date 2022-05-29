/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlyubick <vlyubick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 04:24:34 by vlyubick          #+#    #+#             */
/*   Updated: 2021/10/22 15:00:51 by vlyubick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	count;
	size_t	countdst;
	size_t	i;

	countdst = 0;
	i = 0;
	count = 0;
	while (src[count] != '\0')
		count++;
	while (dst[countdst] != '\0')
		countdst++;
	if (countdst > dstsize)
		count = count + dstsize;
	else
		count = count + countdst;
	while (src[i] != '\0' && (countdst + i + 1) < (dstsize))
	{
		dst[countdst + i] = src[i];
		i++;
	}
	dst[countdst + i] = '\0';
	return (count);
}
