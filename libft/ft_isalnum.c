/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:09:03 by mrios-he          #+#    #+#             */
/*   Updated: 2024/03/08 11:15:11 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)
		|| (c >= 48 && c <= 57))
		return (c);
	return (0);
}
/*
#include <unistd.h>

int	main(void)
{
	if (ft_isalnum('%'))
		write(1, "Is alphanumeric", 15);
	else
		write(1, "Is not alphanumeric", 19);
	return (0);
}*/
