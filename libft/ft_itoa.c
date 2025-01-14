/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:53:31 by mrios-he          #+#    #+#             */
/*   Updated: 2024/03/08 12:02:29 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_digits(long n)
{
	size_t	count;

	count = 0;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n >= 1)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_create(char *result, long nbr, int len, int isneg)
{
	if (nbr != 0)
		result = malloc(sizeof(char) * (len + 1));
	else
		return (result = ft_strdup("0"));
	if (!result)
		return (NULL);
	isneg = 0;
	if (nbr < 0)
	{
		isneg++;
		nbr = -nbr;
	}
	result[len] = '\0';
	while (--len)
	{
		result[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (isneg == 1)
		result[0] = '-';
	else
		result[0] = (nbr % 10) + '0';
	return (result);
}

char	*ft_itoa(int n)
{
	int		len;
	int		isneg;
	char	*result;
	long	nbr;

	nbr = n;
	len = ft_digits(nbr);
	result = 0;
	isneg = 0;
	result = ft_create(result, nbr, len, isneg);
	if (!result)
		return (NULL);
	return (result);
}
/*
int	main(void) 
{
    int num = -12345;

    printf("Integer: %d\n", num);
    printf("String: %s\n", ft_itoa(num));
    return 0;
}
*/
