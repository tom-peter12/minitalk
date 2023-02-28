/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 23:14:40 by tomas             #+#    #+#             */
/*   Updated: 2023/02/26 23:14:53 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include "libft/libft.h"
# include <signal.h>

# define RED "\x1b[31m"
# define NORMAL "\x1b[m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define MAGENTA "\x1b[35m"
# define ERROR 64

void	signal_handler(int signo, siginfo_t *info, void *context);
void	send_the_string(pid_t proc_id, char *str);
int		ft_validate_pid(char *proc_id);
char	to_char(char *str);
char	*to_binary(unsigned int c);

#endif
