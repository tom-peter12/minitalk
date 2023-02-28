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

#include "minitalk.h"

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
	ft_printf("Sent bytes %s{ %d }%s : Equivalent to bits %s{ %d }%s\n", GREEN,
		i, NORMAL, GREEN, 8 * i, NORMAL);
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

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		ft_printf("%sUsage:\t./client [server id] [string]\n%s", RED, NORMAL);
		return (ERROR);
	}
	else
	{
		if (ft_validate_pid(argv[1]))
		{
			ft_printf("Sending %s{ %s }%s to process %s{ %s } %s\n\n", MAGENTA,
				argv[2], NORMAL, YELLOW, argv[1], NORMAL);
			send_the_string(ft_atoi(argv[1]), argv[2]);
		}
		else
		{
			ft_printf("%sThe process ID range should be b/n {0 - 4194304}.\n%s",
				RED, NORMAL);
			return (ERROR);
		}
	}
	return (0);
}
