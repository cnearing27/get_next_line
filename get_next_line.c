/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:14:44 by cnearing          #+#    #+#             */
/*   Updated: 2021/12/05 20:14:44 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>

char	*save_buf(char	*outstr)
{
	char	*new_out;
	int		count;
	int		finish_i;
	int		start_i;

	finish_i = 0;
	start_i = 0;
	while (outstr[start_i] != '\n')
		start_i++;
	start_i++;
	while (outstr[finish_i])
		finish_i++;
	new_out = malloc(sizeof(char) * (finish_i - start_i + 1));
	if (!new_out)
		return (NULL);
	count = 0;
	while (start_i <= finish_i)
	{
		new_out[count] = outstr[start_i];
		count++;
		start_i++;
	}
	return (new_out);
}

char	*ft_crop(char	*outstr)
{
	char	*dest;
	int		count;
	int		i;

	i = 0;
	count = 0;
	if (!outstr)
		return (NULL);
	while (outstr[i] && outstr[i] != '\n')
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	while (count <= i)
	{
		dest[count] = outstr[count];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}

int	inc_endl(char	*outstr)
{
	int	i;

	i = 0;
	if (!outstr)
		return (0);
	while (outstr[i])
	{
		if (outstr[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int	fd)
{
	char			*buf;
	int				ret;
	static char		*outstr;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	ret = 1;
	while (ret && !inc_endl(outstr))
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[ret] = '\0';
		outstr = ft_strjoin(outstr, buf);
	}
	free(buf);
	buf = ft_crop(outstr);
	outstr = save_buf(outstr);
	return (buf);
}
