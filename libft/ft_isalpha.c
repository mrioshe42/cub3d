/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:03:54 by mrios-he          #+#    #+#             */
/*   Updated: 2024/03/08 11:13:48 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
/*
#include <unistd.h>

int	main(void)
{
	if (ft_isalpha('4'))
		write(1, "Is alpha", 8);
	else
		write(1, "Is not alpha", 12);
	return (0);
}*/
