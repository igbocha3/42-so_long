/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igbocha3 <igbocha3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 07:02:06 by igbocha3          #+#    #+#             */
/*   Updated: 2022/08/30 07:02:06 by igbocha3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_unsigned_int(unsigned int n)
{
	int		len;

	len = 1;
	if (n > 9)
		len += ft_print_unsigned_int(n / 10);
	ft_print_char(n % 10 + '0');
	return (len);
}
