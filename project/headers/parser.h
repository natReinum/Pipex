/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunier <nmunier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:46:45 by nmunier           #+#    #+#             */
/*   Updated: 2025/03/19 15:29:35 by nmunier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "error_handler.h"
# include "../struct/bool_struct.h"
# include "utils.h"
# include "../struct/family_struct.h"
# include "../struct/command_struct.h"
# include "../libft/libft.h"

char		*get_path(char **env);
t_error		check_input(int argc, char **argv, t_family *family);
void		free_commands(t_command *commands);
t_command	*parse_cmd(int argc, char **argv, t_family *family, t_error *err);

#endif // PARSER_H
