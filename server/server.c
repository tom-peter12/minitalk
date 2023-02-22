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

char	*assembler;

void	signal_handler(int signo, siginfo_t *info, void *context)
{
	static int i;

	if (!assembler)
		assembler = ft_strdup("");
	if (signo == SIGUSR1)
		assembler = ft_strjoin(assembler, "0");
	else if (signo == SIGUSR2)
		assembler = ft_strjoin(assembler, "1");
	if (ft_strlen(assembler) % 8 != 0)
		;
	else
	{
		while (assembler[i] != '\0')
		{
			ft_printf("%c", to_char(ft_substr(assembler, i, 8)));
			i = i + 8;
		}
	}
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
