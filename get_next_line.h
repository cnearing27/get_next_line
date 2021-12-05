/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:14:51 by cnearing          #+#    #+#             */
/*   Updated: 2021/12/05 20:14:51 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
#include <fcntl.h>
#include <stdlib.h>
char	*get_next_line(int	fd);
char	*ft_strdup(char *src, int	i);
char	*ft_strcat(char	*dest, char	*src);
char	*ft_strcpy(char *dest, char *src, int	i);
#endif
