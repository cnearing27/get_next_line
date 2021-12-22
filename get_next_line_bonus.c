/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnearing <cnearing@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:14:44 by cnearing          #+#    #+#             */
/*   Updated: 2021/12/05 20:14:44 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*save_buf(char	*outstr)
{
	char	*new_out;
	int		count;
	int		start_i;
	int		finish_i;

	start_i = 0;
	while (outstr[start_i] && outstr[start_i] != '\n')
		start_i++;
	start_i++;
	finish_i = 0;
	while (outstr[finish_i])
		finish_i++;
	new_out = malloc(sizeof(char) * (finish_i - start_i + 1));
	if (!new_out)
		return (NULL);
	count = 0;
	while (start_i < finish_i)
	{
		new_out[count] = outstr[start_i];
		count++;
		start_i++;
	}
	new_out[count] = '\0';
	return (new_out);
}

char	*ft_crop(char	*outstr)
{
	char	*dest;
	int		count;
	int		i;


	if (outstr[0] == '\0')
	{
		free(outstr);
		return ("\0");
	}
	i = 0;
	while (outstr[i] && outstr[i] != '\n')
		i++;
	count = 0;
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
	int				ret;
	char			*buf;
	static char		*outstr[4096];

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (BUFFER_SIZE <= 0 || fd < 0 || !buf)
	{
		free(buf);
		return (NULL);
	}
	ret = 1;
	while (ret && !inc_endl(outstr[fd]))
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[ret] = '\0';
		outstr[fd] = ft_strcat(outstr[fd], buf);
	}
	free(buf);
	buf = ft_crop(outstr[fd]);
	outstr[fd] = save_buf(outstr[fd]);
	return (buf);
}
