/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunier <nmunier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:30:21 by nmunier           #+#    #+#             */
/*   Updated: 2025/03/25 16:27:56 by nmunier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_BONUS_H
# define PARSER_BONUS_H
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "error_handler.h"
# include "../struct/bool_struct.h"
# include "utils.h"
# include "../struct/family_struct.h"
# include "../struct/command_struct.h"
# include "../libft/libft.h"
# include "utils_bonus.h"

char		*get_path(char **env);
t_bool		check_inp(int argc, char **argv, t_bool *here_doc, char **files);
void		free_commands(t_command *commands);
t_command	*parse_cmd(int argc, char **argv, t_family *family, t_error *err);

#endif // PARSER_BONUS_H
