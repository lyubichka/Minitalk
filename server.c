/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlyubick <vlyubick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 21:22:36 by vlyubick          #+#    #+#             */
/*   Updated: 2022/04/29 21:33:32 by vlyubick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

static int	bin2dec(char *bin)
{
	int	res;

	res = (bin[0] - '0') * 128 + (bin[1] - '0') * 64
		+ (bin[2] - '0') * 32 + (bin[3] - '0') * 16 + (bin[4] - '0') * 8
		+ (bin[5] - '0') * 4 + (bin[6] - '0') * 2 + (bin[7] - '0');
	return (res);
}

void	sigact(int sig)
{
	static char	mes[8];
	static int	i;

	if (sig == SIGUSR1)
		mes[i] = '0';
	else
		mes[i] = '1';
	i++;
	if (i == 8)
	{	
		ft_putchar_fd(bin2dec(mes), 1);
		i = 0;
	}
}

int	main(void)
{
	int	spid;

	spid = getpid();
	if (spid < 0)
		return (-1);
	ft_putnbr_fd(spid, 0);
	ft_putchar_fd('\n', 0);
	while (1)
	{
		signal(SIGUSR1, sigact);
		signal(SIGUSR2, sigact);
		pause();
	}
	return (0);
}
