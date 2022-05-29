/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlyubick <vlyubick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 21:22:24 by vlyubick          #+#    #+#             */
/*   Updated: 2022/04/29 21:30:26 by vlyubick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void	mhandler(int pid, char *byte)
{
	int	i;
	int	j;

	i = 0;
	while (1)
	{
		j = 128;
		while (j != 0)
		{
			usleep(500);
			if (byte[i] & j)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			j = j >> 1;
		}
		if (byte[i] == '\0')
		{
			ft_putstr_fd("Message was send\n", 1);
			break ;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		b;
	pid_t	pid;

	if (argc != 3)
		return (-1);
	i = 2;
	while (argv[1][i++])
	{
		if (!ft_strchr("0123456789", argv[1][i]))
			return (-1);
	}
	b = 0;
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (-1);
	while (argv[2][b])
	{
		mhandler(pid, &argv[2][b]);
		break ;
	}
	return (0);
}
