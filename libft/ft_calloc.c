/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlyubick <vlyubick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 12:55:16 by vlyubick          #+#    #+#             */
/*   Updated: 2021/10/15 10:20:30 by vlyubick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	tsize;
	void	*dst;

	tsize = size * count;
	dst = malloc(tsize);
	if (!dst)
		return (0);
	ft_memset(dst, 0, tsize);
	return (dst);
}
