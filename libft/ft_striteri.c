/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:35:25 by mrios-he          #+#    #+#             */
/*   Updated: 2024/03/08 12:07:08 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_striteri(char *str, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (str == NULL || f == NULL)
		return ;
	while (str[i] != '\0')
	{
		(*f)(i, &str[i]);
		i++;
	}
}
/*
void	print_index_and_character(unsigned int index, char *c)
{
	printf("Index: %u, Character: %c\n", index, *c);
}

int	main(void)
{
	char	str[] = "hello";

	printf("Original string: %s\n", str);
	ft_striteri(str, print_index_and_character);
	return (0);
}*/
