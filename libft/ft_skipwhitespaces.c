/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimberl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 00:37:39 by jkimberl          #+#    #+#             */
/*   Updated: 2019/09/14 00:59:47 by jkimberl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_skipwhitespaces(const char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0' && ((str[i] == ' ') || (str[i] == '\t')
		|| (str[i] == '\n') || (str[i] == '\v')
		|| (str[i] == '\r') || (str[i] == '\f')))
		i++;
	return (i);
}
