/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ean <ean@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 10:42:37 by ean               #+#    #+#             */
/*   Updated: 2021/11/17 10:42:41 by ean              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#define MAX_LEN 11

void	ft_putnbr_fd(int n, int fd)
{
	char	arr[MAX_LEN];
	int		sign;
	int		len;

	if (fd == -1)
		return ;
	sign = 1;
	if (n < 0)
		sign = -1;
	len = 0;
	arr[len++] = sign * (n % 10) + '0';
	n /= 10;
	while (n)
	{
		arr[len++] = sign * (n % 10) + '0';
		n /= 10;
	}
	if (sign < 0)
		arr[len++] = '-';
	while (len)
	{
		write(fd, &arr[len - 1], 1);
		--len;
	}
}
