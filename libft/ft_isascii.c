/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:14:16 by mrios-he          #+#    #+#             */
/*   Updated: 2024/03/08 11:17:05 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c < 128);
}
/*
#include <unistd.h>

int	main(void)
{
	if(ft_isascii('h'))
		write(1, "Is ascii", 8);
	else
		write(1, "Is not ascii", 12);
	return (0);
}*/
