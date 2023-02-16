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

void	send_the_string(int proc_id, char *str)
{

}

int	main(int argc, char *argv[])
{
	pid_t				the_process_id;
	char				*the_string;
	struct sigaction	sa;

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
		ft_printf("|| %s || ------ || %d ||\n", the_string, the_process_id);
		send_the_string(argv[1], argv[2]);
		free(the_string);
		return (0);
	}
}
