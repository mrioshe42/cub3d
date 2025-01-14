/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:13:48 by mrios-he          #+#    #+#             */
/*   Updated: 2024/03/08 11:24:11 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (c - ('a' - 'A'));
	}
	return (c);
}
/*
#include <unistd.h>

int	main (void)
{
	char	c;

	c = ft_toupper('c');
	write(1, &c, 1);
	return (0);
}
*/
