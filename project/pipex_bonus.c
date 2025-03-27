/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunier <nmunier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:01:50 by nmunier           #+#    #+#             */
/*   Updated: 2025/03/25 17:04:01 by nmunier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/pipex_bonus.h"

static t_family	*init_pipex(char **env, t_error *err, int *params, \
								char *files[2])
{
	t_family	*family;

	*err = success;
	family = malloc(sizeof(t_family));
	if (!family)
		return (*err = malloc_err, NULL);
	family->pid = -1;
	family->env = env;
	family->infile = files[0];
	family->outfile = files[1];
	family->here_doc = params[0];
	family->commands = NULL;
	family->i_fd = 0;
	family->i_fd_max = params[1] - 3 - (family->here_doc);
	if (family->i_fd_max > 0)
	{
		family->fd = malloc((family->i_fd_max) * sizeof(int *));
		if (!family->fd)
			return (perform_illegal_act_on_family_2(&family, 0, 0), NULL);
		while (family->i_fd < family->i_fd_max)
			family->fd[family->i_fd++] = malloc(2 * sizeof(int));
		family->i_fd = 0;
	}
	return (family);
}

static void	free_fds(t_family *family)
{
	int	i;

	i = 0;
	if (!family || !family->fd)
		return ;
	while (i < family->i_fd_max)
	{
		if (family->fd[i][0] != -1)
			ft_close(&family->fd[i][0]);
		if (family->fd[i][1] != -1)
			ft_close(&family->fd[i][1]);
		free(family->fd[i++]);
	}
	free(family->fd);
}

void	perform_illegal_act_on_family_2(t_family **family, int del_here, \
										int close_fds)
{
	if (!*family)
		return ;
	if ((*family)->here_doc && del_here)
		delete_here_doc(*family);
	if ((*family)->commands)
		free_commands((*family)->commands);
	if (close_fds)
		free_fds(*family);
	free(*family);
}

static void	execute_processes(t_family *family)
{
	int	exit_code;

	conceive_better_child(family, family->commands);
	conceive_forgotten_children(family, family->commands->next, \
								get_list_last(family->commands));
	conceive_less_important_child(family, get_list_last(family->commands));
	exit_code = angry_parent_wait_for_children(family);
	perform_illegal_act_on_family_2(&family, 1, 1);
	exit(exit_code);
}

int	main(int argc, char **argv, char **env)
{
	t_error		error;
	t_family	*family;
	char		*files[2];
	t_bool		here_doc;
	int			params[2];

	if (!check_inp(argc, argv, &here_doc, files))
		return (perform_illegal_act_on_family_2(&family, 1, 1), \
				handle_error(&error));
	params[0] = here_doc;
	params[1] = argc;
	family = init_pipex(env, &error, params, files);
	if (!family)
		return (perform_illegal_act_on_family_2(&family, 1, 1), \
				handle_error(&error));
	fill_fd_array(family);
	family->commands = parse_cmd(argc, argv, family, &error);
	if (error == param_count_err)
		return (perform_illegal_act_on_family_2(&family, 1, 1), \
				handle_error(&error));
	if (family->here_doc)
		read_input(family, argv[2]);
	execute_processes(family);
}
