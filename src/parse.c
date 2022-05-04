/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ean <ean@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 13:38:32 by ean               #+#    #+#             */
/*   Updated: 2022/03/18 12:10:06 by ean              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "parse.h"
#include "../libft/libft.h"
#include "get_next_line.h"
#include "parse_utils.h"
#include "utils.h"
#define	DEFAULT_CASE_SIZE 20
#define DEFAULT_Z_SIZE 20

static void		get_points(t_table *tab, const int fd);
static t_point	*get_point_row(char **words, t_table *tab);
static void		plot_points(t_table *tab, const int c, const int z_size);
static void		make_table_from_list(t_table *tab, t_list *head);

void	plot_points_in_space(t_table *tab, int argc, char *argv[])
{
	int	fd;
	int	case_size;
	int	z_size;

	if (argc < 2 || argc == 3 || argc > 4)
		exit_with_message("Invalid argument");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit_with_message("open() failed");
	get_points(tab, fd);
	if (close(fd) == -1)
		exit_with_message("close() failed");
	case_size = DEFAULT_CASE_SIZE;
	z_size = DEFAULT_Z_SIZE;
	if (argc == 4)
	{
		case_size = ft_atoi(argv[2]);
		z_size = ft_atoi(argv[3]);
	}
	plot_points(tab, case_size, z_size);
}

static void	get_points(t_table *tab, const int fd)
{
	char	*line;
	char	**words;
	t_list	*point_rows;
	t_list	*new_node;

	tab->column_size = 0;
	tab->row_size = 0;
	point_rows = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		words = ft_split(line, ' ');
		if (words == NULL)
			exit_with_message("ft_split() failed");
		new_node = ft_lstnew(get_point_row(words, tab));
		free(words);
		if (new_node == NULL)
			exit_with_message("ft_lstnew() failed");
		free(line);
		ft_lstadd_front(&point_rows, new_node);
		line = get_next_line(fd);
	}
	make_table_from_list(tab, point_rows);
}

static t_point	*get_point_row(char **words, t_table *tab)
{
	t_point	*point_row;
	int		i;

	i = 0;
	while (words[i] != NULL)
		++i;
	if (tab->column_size == 0)
		tab->column_size = i;
	else if (i != tab->column_size)
		exit_with_message("Invalid map");
	point_row = malloc(sizeof(*point_row) * i);
	if (point_row == NULL)
		exit_with_message("get_point_row()'s malloc failed");
	i = 0;
	while (words[i] != NULL)
	{
		point_row[i].z = ft_atoi(words[i]);
		point_row[i].color.color = read_color(words[i]);
		free(words[i]);
		++i;
	}
	++tab->row_size;
	return (point_row);
}

static void	plot_points(t_table *tab, const int c, const int z_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < tab->row_size)
	{
		j = 0;
		while (j < tab->column_size)
		{
			tab->points[i][j].x = j * c;
			tab->points[i][j].y = (i - tab->row_size + 1) * c;
			tab->points[i][j].z *= z_size;
			++j;
		}
		++i;
	}
}

static void	make_table_from_list(t_table *tab, t_list *head)
{
	t_list	*curr;
	int		i;

	tab->points = malloc(sizeof(*tab->points) * tab->row_size);
	if (tab->points == NULL)
		exit_with_message("make_table_from_list()'s malloc failed");
	curr = head;
	i = tab->row_size - 1;
	while (curr != NULL)
	{
		head = curr->next;
		tab->points[i] = curr->content;
		--i;
		free(curr);
		curr = head;
	}
}
