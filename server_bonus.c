/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:16:14 by tpetros           #+#    #+#             */
/*   Updated: 2023/02/28 18:16:16 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signo, siginfo_t *info, void *context)
{
	static char	c;
	static int	i;

	(void)info;
	(void)context;
	if (signo == SIGUSR2)
		c |= (1);
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
	c = c << 1;
}

int	main(void)
{
	struct sigaction	act;

	ft_memset(&act, 0, sizeof(act));
	act.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	ft_printf("Server PID: %s|| %d ||\n%s", YELLOW, getpid(), NORMAL);
	while (1)
		pause();
	return (0);
}
