/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ean <ean@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:44:59 by ean               #+#    #+#             */
/*   Updated: 2021/11/16 16:38:36 by ean              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "libft.h"
#define SUCCESS 1
#define FAILURE 0

static size_t	count_word(char const *s, char c);
static int		put_word(char **arr, char const *s, char c, size_t size);

char	**ft_split(char const *s, char c)
{
	char	**ret;
	char	**temp;
	size_t	word_cnt;
	bool	state;

	if (!s)
		return (NULL);
	word_cnt = count_word(s, c);
	ret = (char **)malloc(sizeof(*ret) * (word_cnt + 1));
	state = false;
	if (ret)
	{
		state = put_word(ret, s, c, word_cnt);
		if (state == FAILURE)
		{
			temp = ret;
			while (*temp)
			{
				free(*temp);
				++temp;
			}
			free(ret);
		}
	}
	return (ret);
}

static size_t	count_word(char const *s, char c)
{
	size_t	ret;
	bool	in_word;
	size_t	i;

	ret = 0;
	in_word = false;
	i = 0;
	while (s[i])
	{
		if (in_word && s[i] == c)
			in_word = false;
		else if (!in_word && s[i] != c)
		{
			++ret;
			in_word = true;
		}
		++i;
	}
	return (ret);
}

static int	put_word(char **arr, char const *s, char c, size_t size)
{
	size_t	arr_i;
	size_t	str_i;
	size_t	word_len;

	arr_i = 0;
	str_i = 0;
	while (arr_i < size)
	{
		while (s[str_i] && s[str_i] == c)
			++str_i;
		word_len = 0;
		while (s[str_i + word_len] && s[str_i + word_len] != c)
			++word_len;
		arr[arr_i] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (arr[arr_i])
			ft_strlcpy(arr[arr_i], &s[str_i], word_len + 1);
		else
			return (FAILURE);
		str_i += word_len;
		++arr_i;
	}
	arr[arr_i] = NULL;
	return (SUCCESS);
}
