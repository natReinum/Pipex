# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmunier <nmunier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 20:10:35 by nmunier           #+#    #+#              #
#    Updated: 2025/03/25 19:44:51 by nmunier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

NAME = libft.a

MANDATORY = ft_bzero.c ft_memmove.c ft_calloc.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_memcpy.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_free_array.c ft_close.c

BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

SRCS = $(MANDATORY)

SRCSB = $(MANDATORY) $(BONUS)

OBJ = $(SRCS:.c=.o)

OBJB = $(SRCSB:.c=.o)

.c.o:
	@echo "$(RED)Compiling: $(DEF_COLOR)$(YELLOW)" $< "$(DEF_COLOR)"
	@${CC} ${CFLAGS} -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): yellow_start $(OBJ) yellow_end
	@ar rcs $(NAME) $(OBJ)
	@echo "$(GREEN)libft created!$(DEF_COLOR)"

yellow_start:
	@echo "$(YELLOW)"

yellow_end:
	@echo "$(DEF_COLOR)"

bonus: yellow_start $(OBJB) yellow_end
	@ar rcs $(NAME) $(OBJB)
	@echo "$(BLUE)╔════════════════════════════════════════╗$(DEF_COLOR)"
	@echo "$(BLUE)║$(DEF_COLOR)$(GREEN)       libft bonus library created!     $(DEF_COLOR)$(BLUE)║$(DEF_COLOR)"
	@echo "$(BLUE)╚════════════════════════════════════════╝$(DEF_COLOR)"
clean:
	@rm -f $(OBJB)
	@echo "$(BLUE)libft has been cleaned from object files!$(DEF_COLOR)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(BLUE)libft has been cleaned from the library file!$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re bonus
