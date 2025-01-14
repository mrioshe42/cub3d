/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:45:58 by mrios-he          #+#    #+#             */
/*   Updated: 2024/03/08 12:10:06 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
			write(fd, &s[i++], 1);
	}
}
/*
int	main(void)
{
	char    c[] = "Hello";
        int     fd = STDOUT_FILENO;
        ft_putstr_fd(c, fd);
	return (0);
}*/
