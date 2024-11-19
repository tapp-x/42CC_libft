/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:23:35 by tappourc          #+#    #+#             */
/*   Updated: 2023/12/03 17:50:12 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

unsigned int    ft_convert_from_base(char *str, char *base)
{
    size_t    i;
    size_t    c;
    unsigned int        total;
    unsigned int        base_len;

    i = 0;
    total = 0;
    base_len = ft_strlen(base);
    while (str[i] && ft_strchr(base, ft_toupper(str[i])))
    {
        c = 0;
        while (base[c] != ft_toupper(str[i]) && base[c])
            c++;
        total = (total * base_len) + c;
        i++;
    }
    return (total);
}
unsigned int    ft_atoi_base(char *str, char *base)
{
    unsigned int        total;
    size_t    i;

    total = 0;
    i = 0;
	printf("enter atoi base\n");
    while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
        i++;
    if (str[i] == '0')
    {
        i++;
        if (str[i] == 'x')
            i++;
    }
    total = ft_convert_from_base(&str[i], base);
    return (total);
}

