/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:52:42 by mrios-he          #+#    #+#             */
/*   Updated: 2024/03/08 11:24:41 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c + ('a' - 'A'));
	}
	return (c);
}
/*
#include <unistd.h>

int	main(void)
{
	char	c;

	c = ft_tolower('C');
	write(1, &c, 1);
	return (0);
}*/
