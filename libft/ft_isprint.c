/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:15:47 by mrios-he          #+#    #+#             */
/*   Updated: 2024/03/08 11:17:50 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
/*
#include <unistd.h>

int	main(void)
{
	if(ft_isprint('j'))
		write(1, "Is printable", 12);
	else
		write(1, "Is not printable", 16);
	return (0);
}*/
