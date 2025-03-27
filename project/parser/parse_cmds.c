/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunier <nmunier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:37:33 by nmunier           #+#    #+#             */
/*   Updated: 2025/02/21 19:06:49 by nmunier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static void	free_array(char ***array)
{
	char	**arr;

	if (!*array)
		return ;
	arr = *array;
	while (*arr)
		free(*arr++);
	free(*array);
}

static char	*get_cmd_path(char **cmd, char **path_dirs, char *cmd_base)
{
	char	*joined_str;
	char	*tmp;
	char	**array;

	int (i) = 0;
	array = ft_split(cmd_base, ' ');
	if (!array || !array[0])
		return (ft_free_array(&array), NULL);
	tmp = ft_strdup(array[0]);
	if (access(tmp, X_OK) == 0 || ft_strchr(tmp, '/') != 0)
		return (free_array(&array), tmp);
	(free(tmp), free_array(&array));
	while (path_dirs[i])
	{
		tmp = ft_strjoin(path_dirs[i], "/");
		joined_str = ft_strjoin(tmp, cmd[0]);
		if (tmp)
			free(tmp);
		if (joined_str && access(joined_str, X_OK) == 0)
			return (joined_str);
		free(joined_str);
		i++;
	}
	return (ft_strdup(cmd[0]));
}

void	free_commands(t_command *commands)
{
	if (commands->next)
		free_commands(commands->next);
	if (commands->cmd_path)
		free(commands->cmd_path);
	free_array(&commands->cmd_arg);
	free(commands);
}

void	new_command(char *cmd, t_command **base_addr, char **path_dirs, \
						t_error *err)
{
	t_command (*new) = malloc(sizeof(t_command));
	if (!new)
		return ;
	new->next = NULL;
	new->cmd_arg = get_cmd_args(ft_split(cmd, ' '));
	if (!new->cmd_arg && ft_strlen(cmd) > 0)
	{
		*err = malloc_err;
		return (free(new));
	}
	new->cmd_path = get_cmd_path(new->cmd_arg, path_dirs, cmd);
	if (!new->cmd_path && ft_strlen(cmd) > 0)
	{
		*err = path_err;
		handle_error(err);
	}
	if (!*base_addr)
		*base_addr = new;
	while ((*base_addr)->next)
		*base_addr = (*base_addr)->next;
	if (*base_addr != new)
		(*base_addr)->next = new;
}

t_command	*parse_cmd(int argc, char **argv, t_family *family, t_error *err)
{
	int			i;
	char		*path_line;
	char		**path_dirs;
	t_command	*cmd_chained_list;

	i = 1;
	path_line = get_path(family->env);
	path_dirs = NULL;
	path_dirs = ft_split(path_line, ':');
	if (path_line)
		free(path_line);
	cmd_chained_list = NULL;
	while (path_dirs && (*err == success || *err == path_err) \
			&& ++i < argc - 1)
		new_command(argv[i], &cmd_chained_list, path_dirs, err);
	free_array(&path_dirs);
	if (cmd_chained_list)
		return (cmd_chained_list);
	return (NULL);
}
