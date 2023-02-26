/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 21:25:31 by tpetros           #+#    #+#             */
/*   Updated: 2023/02/23 21:25:32 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	signal_handler(int signo, siginfo_t *info, void *context)
{
	static char	*assembler;

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
		kill(info->si_pid, SIGUSR1);
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
	ft_printf("|| %d ||\n", getpid());
	act.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
