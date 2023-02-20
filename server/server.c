/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:33:20 by tpetros           #+#    #+#             */
/*   Updated: 2023/02/15 20:33:22 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	signal_handler(int signo, siginfo_t *info, void *context)
{
	if (signo == SIGUSR1)
		ft_printf("signal1 is recieved");
	else if (signo == SIGUSR2)
		ft_printf("signal2 is recieved");
}

int	main(void)
{
	struct sigaction	act;
	ft_memset(&act, 0, sizeof(act));

	ft_printf("|| %d ||\n", getpid());
	act.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &act, NULL);
	while (1)
	{
		
	}
	return (0);
}
