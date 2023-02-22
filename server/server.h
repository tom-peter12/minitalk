/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:34:40 by tpetros           #+#    #+#             */
/*   Updated: 2023/02/15 20:34:41 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# include <signal.h>
 #include <unistd.h>
# include "../client/client.h"

int	ft_iterative_power(int nb, int power);
char	to_char(char *str);

#endif