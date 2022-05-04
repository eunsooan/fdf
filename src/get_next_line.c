/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ean <ean@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:52:20 by ean               #+#    #+#             */
/*   Updated: 2022/03/17 14:30:14 by ean              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "../libft/libft.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4096
#endif

static int	flush_buffer(char **p_buf, char **p_line);
static int	get_next_chunk(int fd, char **p_buf, char **p_line);
static void	process_last_buffer(char **p_buf, char *p_delim, char **p_line);

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*ret;
	char		*p_delim;
	char		*temp;

	if (BUFFER_SIZE < 1)
		return (NULL);
	ret = NULL;
	p_delim = NULL;
	if (buf)
		p_delim = ft_strchr(buf, '\n');
	while (!p_delim)
	{
		if (!flush_buffer(&buf, &ret) || !get_next_chunk(fd, &buf, &ret))
			break ;
		p_delim = ft_strchr(buf, '\n');
	}
	if (p_delim)
		process_last_buffer(&buf, p_delim, &ret);
	temp = ret;
	ret = ft_strtrim(temp, " \n");
	free(temp);
	return (ret);
}

static int	flush_buffer(char **p_buf, char **p_line)
{
	char	*temp;

	if (!*p_buf)
		return (1);
	temp = NULL;
	if (*p_line)
		temp = ft_strjoin(*p_line, *p_buf);
	else
		temp = ft_strjoin("", *p_buf);
	free(*p_buf);
	*p_buf = NULL;
	free(*p_line);
	*p_line = temp;
	if (*p_line)
		return (1);
	return (0);
}

static int	get_next_chunk(int fd, char **p_buf, char **p_line)
{
	int		n_read;

	n_read = -1;
	*p_buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (*p_buf)
		n_read = read(fd, *p_buf, BUFFER_SIZE);
	if (n_read < 1)
	{
		free(*p_buf);
		*p_buf = NULL;
		if (n_read == -1)
		{
			free(*p_line);
			*p_line = NULL;
		}
		return (0);
	}
	(*p_buf)[n_read] = '\0';
	return (1);
}

static void	process_last_buffer(char **p_buf, char *p_delim, char **p_line)
{
	char	*temp;

	temp = NULL;
	if (*(p_delim + 1))
	{
		temp = ft_strdup(p_delim + 1);
		if (!temp)
		{
			free(*p_buf);
			*p_buf = NULL;
			free(*p_line);
			*p_line = NULL;
			return ;
		}
		*(p_delim + 1) = '\0';
	}
	if (!flush_buffer(p_buf, p_line))
	{
		free(temp);
		return ;
	}
	*p_buf = temp;
}
