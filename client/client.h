/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:34:27 by tpetros           #+#    #+#             */
/*   Updated: 2023/02/15 20:34:29 by tpetros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H
# include "../helpers/libft/libft.h"
# include <signal.h>

char	*to_binary(unsigned int c);
char	*ft_strrev(char *str);
void	send_the_string(pid_t proc_id, char *str);
#endif
