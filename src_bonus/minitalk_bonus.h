/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:31:58 by tpetros           #+#    #+#             */
/*   Updated: 2023/03/01 20:32:00 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# include "../libft/libft.h"
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

#endif

