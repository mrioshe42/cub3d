/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:35:23 by mrios-he          #+#    #+#             */
/*   Updated: 2024/03/08 11:26:25 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
int	main(void)
{
	const char	*s1 = "Hello world";
	const char	*s2 = "Hello c";
	int	result;

	result = ft_strncmp(s1, s2, 7);

	if (result > 0)
		printf("The first is bigger.");
	else if (result < 0)
		printf("The second is bigger.");
	else
		printf("Equals");
	return (0);
}*/
