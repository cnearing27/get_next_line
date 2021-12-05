/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <cnearing@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:13:01 by cnearing          #+#    #+#             */
/*   Updated: 2021/12/05 20:13:01 by cnearing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include <stdio.h>

char	*save_buf(char	*outstr, int	start_i)
{
	char	*new_out;
	int		count;
	int		finish_i;

	finish_i = 0;
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

char	*ft_crop(int	i, char	*outstr)
{
	char	*dest;
	int		count;

	count = 0;
	dest = malloc(sizeof(char) * (i + 1));
	if (dest == NULL)
		return (NULL);
	while (count <= i)
	{
		dest[count] = outstr[count];
		count++;
	}
	dest[count] = '\0';
	outstr = save_buf(outstr, i + 1);
	return (dest);
}

char	*get_line(char	*buf, int	fd)
{
	char			*tempstr;
	unsigned int	ret;
	int				i;
	static char		*outstr[4096];

	ret = 1;
	i = 0;
	while (ret)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		tempstr = ft_strdup(buf, BUFFER_SIZE);
		outstr[fd] = ft_strcat(outstr[fd], tempstr);
		while (outstr[fd][i])
		{
			if (outstr[fd][i] == '\n' || outstr[fd][i] == '\0')
			{
				tempstr = ft_crop(i, outstr[fd]);
				outstr[fd] = save_buf(outstr[fd], i + 1);
				return (tempstr);
			}
			i++;
		}
	}
	return (NULL);
}

char	*get_next_line(int	fd)
{
	char	*tempstr;
	char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (BUFFER_SIZE <= 0 || fd < 0 || !buf)
		return (NULL);
	tempstr = get_line(buf, fd);
	free(buf);
	return (tempstr);
}

/*int main(void)
{
//	int fd = 0;
//	char *outp = get_next_line(fd);
//	printf("\n1: %s", outp);
//	outp = get_next_line(fd);
//	printf("2: %s", outp);
//	outp = get_next_line(fd);
//	printf("3: %s", outp);
//	outp = get_next_line(fd);
//	printf("4: %s", outp);
//	outp = get_next_line(fd);
//	printf("5: %s", outp);
//	outp = get_next_line(fd);
//	printf("6: %s", outp);
//	outp = get_next_line(fd);
//	printf("7: %s", outp);
//	outp = get_next_line(fd);
//	printf("8: %s", outp);


	int fd1 = open("test.txt", O_RDONLY);
	int fd2 = open("test2.txt", O_RDONLY);
	int fd3 = open("test3.txt", O_RDONLY);
	char *outp = get_next_line(fd1);
	printf("1 - test1: %s", outp);
	outp = get_next_line(fd1);
	printf("2 - test1: %s", outp);
	outp = get_next_line(fd2);
	printf("1 - test2: %s", outp);
	outp = get_next_line(fd3);
	printf("1 - test3: %s", outp);
	outp = get_next_line(fd1);
	printf("3 - test1: %s", outp);
	outp = get_next_line(fd3);
	printf("2 - test3: %s", outp);
	outp = get_next_line(fd2);
	printf("2 - test2: %s", outp);
	outp = get_next_line(fd1);
	printf("4 - test1: %s", outp);
	outp = get_next_line(fd1);
	printf("5 - test1: %s", outp);
	outp = get_next_line(fd2);
	printf("3 - test2: %s", outp);
}
*/
