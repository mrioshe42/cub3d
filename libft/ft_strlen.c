/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:22:22 by mrios-he          #+#    #+#             */
/*   Updated: 2024/03/08 11:19:41 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}
/*
#include <unistd.h>

int	main(void)
{
	if (ft_strlen("hello") == 5)
		write(1, "counted correctly", 17);
	else
		write(1, "error", 5);
	return (0);
}*/
