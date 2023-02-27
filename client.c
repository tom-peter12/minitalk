/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:33:04 by tpetros           #+#    #+#             */
/*   Updated: 2023/02/15 20:33:07 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_the_string(pid_t proc_id, char *str)
{
	int		i;
	int		c;
	char	*value;

	i = 0;
	while (str[i])
	{
		c = 0;
		value = to_binary(str[i]);
		while (value[c])
		{
			if (value[c] == '0')
				kill(proc_id, SIGUSR1);
			if (value[c] == '1')
				kill(proc_id, SIGUSR2);
			c++;
			usleep(350);
		}
		i++;
		free(value);
	}
	ft_printf("Sent bytes { %d } : Equivalent to { %d } bits\n", i, c * i);
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
		ft_printf("Usage:\t./client [server id] [string]\n");
		return (64);
	}
	else
	{
		if (ft_validate_pid(argv[1]))
		{
			ft_printf("Sending {%s} to process {%s}\n\n", argv[2], argv[1]);
			send_the_string(ft_atoi(argv[1]), argv[2]);
		}
		else
			ft_printf("The process ID range should be b/n {0 - 4194304}.\n");
	}
	return (0);
}
