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
	static int	i;
	static char	*g_assembler;
	(void)info;
	(void)context;

	if (!g_assembler)
		g_assembler = ft_strdup("");
	if (signo == SIGUSR1)
		g_assembler = ft_strjoin(g_assembler, "0");
	if (signo == SIGUSR2)
		g_assembler = ft_strjoin(g_assembler, "1");
	if (ft_strlen(g_assembler) == 8)
	{
		ft_printf("%c", to_char(ft_substr(g_assembler, i, 8)));
		free(g_assembler);
		g_assembler = NULL;
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
		
	}
	return (0);
}
