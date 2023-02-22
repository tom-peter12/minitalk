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

#include "client.h"

void	send_the_string(pid_t proc_id, char *str)
{
	int		i;
	char	*value;

	i = 0;
	value = (char *) ft_calloc((8 + 1), 1);
	while (str[i])
	{
		value = to_binary(str[i]);
		ft_printf("%s||\n", value);
		while (*value)
		{
			if (*value == '0')
				kill(proc_id, SIGUSR1);
			else if (*value == '1')
				kill(proc_id, SIGUSR2);
			value++;
			usleep(10);
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	pid_t				the_process_id;
	char				*the_string;

	if (argc != 3)
	{
		ft_printf("Usage:\t./client [server id] [string]\n");
		return (64);
	}
	else
	{
		the_string = (char *) malloc(sizeof(char) * (ft_strlen(argv[2]) + 1));
		ft_strlcpy(the_string, argv[2], ft_strlen(argv[2]) + 1);
		the_process_id = ft_atoi(argv[1]);
		send_the_string(the_process_id, the_string);
		free(the_string);
		return (0);
	}
}
