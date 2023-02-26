/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 21:25:20 by tpetros           #+#    #+#             */
/*   Updated: 2023/02/23 21:25:21 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

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
			usleep(50);
		}
		i++;
		free(value);
	}
	ft_printf("Sent bytes {%d} : Equivalent to {%d} bits\n", i, c * i);
}

void	signal_handler(int signo, siginfo_t *info, void *context)
{
	static size_t i;

	(void)context;
	(void)info;
	if (signo == SIGUSR1)
		i++;
	else
		ft_printf("Recieved bytes {%d} : Equivalent to {%d} bits\n", i, 8 * i);
}

int	main(int argc, char *argv[])
{
	pid_t				the_process_id;
	char				*the_string;
	struct sigaction	act;
	static int			i;

	if (argc != 3)
	{
		ft_printf("Usage:\t./client [server id] [string]\n");
		return (64);
	}
	else
	{
		the_string = (char *) ft_calloc((ft_strlen(argv[2]) + 1), sizeof(char));
		ft_strlcpy(the_string, argv[2], ft_strlen(argv[2]) + 1);
		the_process_id = ft_atoi(argv[1]);
		send_the_string(the_process_id, the_string);
		free(the_string);
		ft_memset(&act, 0, sizeof(act));
		act.sa_sigaction = signal_handler;
		sigaction(SIGUSR1, &act, NULL);
		while (i++ < ft_strlen(the_string))
		{
			pause();
		}
		return (0);
	}
}
