/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:00:03 by mrios-he          #+#    #+#             */
/*   Updated: 2024/03/08 12:13:12 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		write(fd, s++, 1);
	write(fd, "\n", 1);
}
/*
int	main(void)
{
	const char *str = "Hello, world!";
	int fd = STDOUT_FILENO;
	ft_putendl_fd(str, fd);
	return (0);
}*/
