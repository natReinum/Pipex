/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunier <nmunier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:06:05 by nmunier           #+#    #+#             */
/*   Updated: 2025/03/25 18:19:14 by nmunier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HERE_DOC_BONUS_H
# define HERE_DOC_BONUS_H
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include "utils_bonus.h"
# include "error_handler.h"
# include "../struct/family_struct.h"
# include "pipex_bonus.h"

void	delete_here_doc(t_family *family);
void	read_input(t_family *family, char *limiter);

#endif // HERE_DOC_BONUS_H
