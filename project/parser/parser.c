/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunier <nmunier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:46:45 by nmunier           #+#    #+#             */
/*   Updated: 2025/04/02 14:37:12 by nmunier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

char	*get_path(char **env)
{
	if (!env || !*env)
		return (NULL);
	int (i) = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (ft_strdup(env[i] + 5));
		i++;
	}
	return (NULL);
}

t_error	check_input(const int argc, char **argv, t_family *family)
{
	if (argc != 5)
		return (param_count_err);
	family->infile = argv[1];
	family->outfile = argv[argc - 1];
	return (success);
}
