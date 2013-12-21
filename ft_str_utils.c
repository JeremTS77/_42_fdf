/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 10:10:21 by aaubin            #+#    #+#             */
/*   Updated: 2013/12/16 10:10:49 by aaubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

char		*ft_fdf_group_char(char const *s, char c)
{
	char		*clone;
	int		counter;
	int		c_counter;

	if ( s == NULL )
		return (NULL);
	counter = 0;
	c_counter = 0;
	clone = ft_strnew (ft_strlen(s) + 1);
	while (s[counter] != '\0')
	{
		clone[c_counter] = s[counter];
		while (s[counter] == c && s[counter + 1] == c)
			counter++;
		counter++;
		c_counter++;
	}
	return (clone);
}

int		ft_fdf_count_char(char const *s, char c)
{
	int		len;
	int		counter;
	int		count;

	if (s == NULL)
		return (0);
	count = 0;
	counter = 0;
	len = ft_strlen(s);
	while (counter < len)
	{
		if (s[counter] == c && s[counter + 1] != c)
		{
			count++;
		}
		counter++;
	}
	return (count);
}

char		*ft_fdf_strchartrim(char const *s, char ch)
{
	int				d;
	int				trim_start;
	unsigned int		c;
	char				*new_str;

	d = 0;
	c = 0;
	trim_start = 0;
	new_str = ft_strnew (ft_strlen (s) + 1);
	while (c < ft_strlen (s))
	{
		if (!trim_start && s[c] == ch)
			c++;
		else
		{
			trim_start = 1;
			new_str[d++] = s[c++];
		}
	}
	while (new_str[--d] == ch)
		new_str[d] = '\0';
	return (new_str);
}


char		*ft_fdf_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int		counter;
	char				*dest;

	if (s == NULL)
		return (NULL);
	dest = ft_strnew (len + 1);
	counter = 0;
	if (dest == NULL)
		return (NULL);
	while (counter < len + start)
	{
		if (counter >= start)
			dest[counter - start] = s[counter];
		counter++;
	}
	return (dest);
}

char		**ft_fdf_strsplit(char const *s, char c)
{
	int		n;
	int		sub_counter;
	int		counter;
	char		**final;
	char		*clone;

	counter = 0;
	sub_counter = 0;
	n = ft_count_char(s, c) + 2;
	clone = ft_strchartrim( ft_group_char(s, c), c);
	final = (char**) malloc(n * sizeof(char**));
	n = 0;
	while (clone[counter] != '\0')
	{
		if (clone[counter] == c)
		{
			final[n] = ft_strsub(clone, sub_counter, counter - sub_counter);
			n++;
			sub_counter = counter + 1;
		}
		counter++;
	}
	final[n] = ft_strsub(clone, sub_counter, counter - sub_counter);
	return (final);
}
