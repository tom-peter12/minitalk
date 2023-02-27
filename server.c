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

#include "minitalk.h"

void	signal_handler(int signo, siginfo_t *info, void *context)
{
	static char	*assembler;

	(void)info;
	(void)context;
	if (!assembler)
		assembler = ft_strdup("");
	if (signo == SIGUSR1)
		assembler = ft_strjoin(assembler, "0");
	else if (signo == SIGUSR2)
		assembler = ft_strjoin(assembler, "1");
	if (ft_strlen(assembler) == 8)
	{
		ft_printf("%c", to_char(assembler));
		free(assembler);
		assembler = NULL;
	}
	else
		return ;
}

int	main(void)
{
	struct sigaction	act;

	ft_memset(&act, 0, sizeof(act));
	act.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	ft_printf("Server PID: || %d ||\n", getpid());
	while (1)
		pause();
	return (0);
}
