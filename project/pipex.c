/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunier <nmunier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:13:29 by nmunier           #+#    #+#             */
/*   Updated: 2025/03/29 16:18:31 by nmunier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/pipex.h"

static t_family	*init_pipex(char **env, t_error *err, int argc)
{
	t_family	*family;

	*err = success;
	family = malloc(sizeof(t_family));
	if (!family)
	{
		*err = malloc_err;
		return (NULL);
	}
	family->pid = -1;
	family->env = env;
	family->here_doc = 0;
	family->commands = NULL;
	family->fd = NULL;
	family->i_fd = 0;
	family->i_fd_max = argc - 4;
	if (family->i_fd_max > 0)
	{
		family->fd = malloc((argc - 4) * sizeof(int *));
		while (family->i_fd < argc - 4)
			family->fd[family->i_fd++] = malloc(2 * sizeof(int));
		family->i_fd = 0;
	}
	return (family);
}

void	perform_illegal_act_on_family(t_family **family)
{
	int	i;

	if (!family || !*family)
		return ;
	if ((*family)->commands)
		free_commands((*family)->commands);
	i = 0;
	while (i < (*family)->i_fd_max)
	{
		ft_close(&(*family)->fd[i][0]);
		ft_close(&(*family)->fd[i][1]);
		free((*family)->fd[i++]);
	}
	if ((*family)->fd)
		free((*family)->fd);
	ft_close(&(*family)->fd_in);
	free(*family);
}

static void	execute_processes(t_family *family)
{
	int	exit_code;

	conceive_better_child(family, family->commands);
	conceive_less_important_child(family, get_list_last(family->commands));
	exit_code = angry_parent_wait_for_children(family);
	perform_illegal_act_on_family(&family);
	exit(exit_code);
}

int	main(int argc, char **argv, char **env)
{
	t_error		error;
	t_family	*family;

	family = init_pipex(env, &error, argc);
	if (!family)
		return (perform_illegal_act_on_family(&family), \
				handle_error(&error));
	fill_fd_array(family);
	error = check_input(argc, argv, family);
	family->commands = parse_cmd(argc, argv, family, &error);
	if (error == param_count_err)
		return (perform_illegal_act_on_family(&family), handle_error(&error));
	execute_processes(family);
}
