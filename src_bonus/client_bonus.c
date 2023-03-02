/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:16:27 by tpetros           #+#    #+#             */
/*   Updated: 2023/02/28 18:16:28 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

size_t	g_strlen;

void	send_the_string(pid_t proc_id, char *str)
{
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		j = 7;
		while (j >= 0)
		{
			if (str[i] & (1 << j))
				kill(proc_id, SIGUSR2);
			else
				kill(proc_id, SIGUSR1);
			j--;
			usleep(100);
		}
		i++;
	}
}

int	ft_validate_pid(char *proc_id)
{
	int	i;

	i = 0;
	while (proc_id[i])
	{
		if (!(ft_strchr("0123456789", proc_id[i])))
			return (0);
		i++;
	}
	if (ft_atoi(proc_id) < 4194304 && ft_atoi(proc_id) > 0)
		return (1);
	else
		return (0);
}

void	signal_handler(int signo, siginfo_t *info, void *context)
{
	static size_t	i;

	(void)context;
	(void)info;
	if (signo == SIGUSR1)
		i++;
	if (g_strlen == i)
		ft_printf("Recieved %s{ %d }%s Equivalent to bits %s{ %d }%s from"
			" process %s{ %u } %s\n\n", MAGENTA, i, NORMAL, BLUE, i * 8, NORMAL,
			YELLOW, info->si_pid, NORMAL);
}

int	ft_proc_id_error(void)
{
	ft_printf("%sThe process ID range should be b/n {0 - 4194304}.\n%s",
		RED, NORMAL);
	return (ERROR);
}

int	main(int argc, char *argv[])
{
	struct sigaction	act;

	if (argc != 3)
	{
		ft_printf("%sUsage:\t./client [server id] [string]\n%s", RED, NORMAL);
		return (ERROR);
	}
	else
	{
		ft_memset(&act, 0, sizeof(act));
		if (ft_validate_pid(argv[1]))
		{
			act.sa_sigaction = signal_handler;
			sigaction(SIGUSR1, &act, NULL);
			g_strlen = ft_strlen(argv[2]);
			ft_printf("Sending %s{ %d }%s Equivalent to bits  %s{ %d }%s to"
				" process %s{ %s } %s\n\n", MAGENTA, g_strlen, NORMAL, BLUE,
				g_strlen * 8, NORMAL, YELLOW, argv[1], NORMAL);
			send_the_string(ft_atoi(argv[1]), argv[2]);
		}
		else
			ft_proc_id_error();
	}
	return (0);
}
