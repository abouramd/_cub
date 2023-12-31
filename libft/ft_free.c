/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouramd <abouramd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 06:39:50 by abouramd          #+#    #+#             */
/*   Updated: 2023/02/25 04:07:25 by abouramd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(char **s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
			free(s[i++]);
		free(s);
	}
}
