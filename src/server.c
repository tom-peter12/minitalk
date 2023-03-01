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

static char	to_char(char *str)
{
	int	i;
	int	c;
	int	len;

	i = 0;
	c = 0;
	len = ft_strlen(str);
	while (str[i])
	{
		c = c + (ft_iterative_power(2, len - i - 1) * (str[i] - '0'));
		i++;
	}
	return (c);
}

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
	ft_printf("Server PID: %s|| %d ||\n%s", YELLOW, getpid(), NORMAL);
	while (1)
		pause();
	return (0);
}
