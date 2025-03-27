/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunier <nmunier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:46:45 by nmunier           #+#    #+#             */
/*   Updated: 2025/02/25 19:32:36 by nmunier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/parser.h"

char	*get_path(char **env)
{
	int (i) = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (ft_strdup(env[i] + 5));
		i++;
	}
	return (NULL);
}

static t_bool	check_argv(int argc, char **argv, t_bool *here_doc)
{
	*here_doc = false;
	if (argc > 1 && ft_strncmp(argv[1], "here_doc", 9) == 0)
		*here_doc = true;
	if (argc < 5)
	{
		handle_error(&(t_error){param_count_err});
		return (false);
	}
	return (true);
}

t_bool	check_inp(const int argc, char **argv, t_bool *here_doc, \
					char **files)
{
	if (!check_argv(argc, argv, here_doc))
		return (false);
	files[0] = argv[1];
	files[1] = argv[argc - 1];
	return (true);
}
