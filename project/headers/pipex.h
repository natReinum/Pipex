/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunier <nmunier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:13:29 by nmunier           #+#    #+#             */
/*   Updated: 2025/03/19 16:20:43 by nmunier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include "parser.h"
# include "error_handler.h"
# include "../struct/family_struct.h"

void	perform_illegal_act_on_family(t_family **family);

#endif // PIPEX_H
