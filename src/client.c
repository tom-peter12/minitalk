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

size_t	g_strlen;

static char	*to_binary(unsigned int c)
{
	char	*bin_holder;
	size_t	h;
	char	*temp;

	bin_holder = (char *)ft_calloc(9, 1);
	h = 0;
	while (c > 0)
	{
		h = c % 2;
		temp = ft_itoa(h);
		bin_holder = ft_strjoin(bin_holder, temp);
		c = c / 2;
		free(temp);
		temp = NULL;
	}
	while (8 - ft_strlen(bin_holder))
	{
		bin_holder = ft_strjoin(bin_holder, "0");
	}
	return (ft_strrev(bin_holder));
}

void	send_the_string(pid_t proc_id, char *str)
{
	size_t	i;
	size_t	c;
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
			usleep(100);
		}
		i++;
		free(value);
	}
	ft_printf("Sent bytes %s{ %d }%s : Equivalent to bits %s{ %d }%s\n", GREEN,
		i, NORMAL, GREEN, c * i, NORMAL);
}

int	ft_proc_id_error(void)
{
	ft_printf("%sThe process ID range should be b/n {0 - 4194304}.\n%s",
		RED, NORMAL);
	return (ERROR);
}

int	ft_validate_pid(char *proc_id)
{
	size_t	i;

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
