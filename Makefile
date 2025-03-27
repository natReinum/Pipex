# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmunier <nmunier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/18 18:42:28 by nmunier           #+#    #+#              #
#    Updated: 2025/03/19 16:32:21 by nmunier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

CC = cc
CFLAGS = -Werror -Wall -Wextra -g3
LIB_NAME = pipex.a
LIBFT = libft.a
NAME = pipex

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

# Directories

PROJECT_DIR = project
PARSER_DIR = $(PROJECT_DIR)/parser
LIBFT_DIR = $(PROJECT_DIR)/libft
ERROR_DIR = $(PROJECT_DIR)/error
PROCESS_DIR = $(PROJECT_DIR)/process
COMMON_DIR = $(PROJECT_DIR)/common

# Files

MAIN_FILE = $(PROJECT_DIR)/pipex.c
ERROR_FILE = $(ERROR_DIR)/error_handler.c
PARSER_FILES = $(PARSER_DIR)/parser.c \
			   $(PARSER_DIR)/parse_cmds.c
COMMON_FILES = $(COMMON_DIR)/utils.c \
			   $(COMMON_DIR)/utils2.c
PROCESS_FILES = $(PROCESS_DIR)/child.c

MAIN_BONUS = $(PROJECT_DIR)/pipex_bonus.c
PARSER_BONUS = $(PARSER_DIR)/parse_cmds_bonus.c \
			   $(PARSER_DIR)/parser_bonus.c \
			   $(PARSER_DIR)/here_doc_bonus.c
UTILS_BONUS = $(COMMON_DIR)/utils_bonus.c \
			  $(COMMON_DIR)/utils_bonus2.c
ERROR_BONUS = $(ERROR_DIR)/error_handler_bonus.c
PROCESS_BONUS = $(PROCESS_DIR)/child_bonus.c

# File Group


MANDATORY_FILES = $(ERROR_FILE) $(PARSER_FILES) $(COMMON_FILES) $(PROCESS_FILES)
BONUS_FILES = $(COMMON_FILES) $(PARSER_BONUS) $(UTILS_BONUS) $(ERROR_BONUS) $(PROCESS_BONUS)

OBJECTS = $(MANDATORY_FILES:.c=.o)
OBJECTS_BONUS = $(BONUS_FILES:.c=.o)

# Header

HEADERS = -I $(PROJECT_DIR)/headers -I $(LIBFT_DIR) -I $(PROJECT_DIR)/struct -I $(PROJECT_DIR)/headers/bonus

# Making

%.o: %.c
	@echo "$(RED)Compiling: $(DEF_COLOR)$(YELLOW)" $< "$(DEF_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

all : $(LIBFT) $(NAME)

$(LIBFT):
	@make --no-print-directory -C $(LIBFT_DIR) bonus
	@cp $(LIBFT_DIR)/$(LIBFT) .
	@mv $(LIBFT) $(LIB_NAME)

$(NAME): $(OBJECTS)
	@ar rcs $(LIB_NAME) $(OBJECTS)
	@$(CC) $(CFLAGS) -o $(NAME) $(MAIN_FILE) $(LIB_NAME)
	@echo "$(BLUE)╔════════════════════════════════════════╗$(DEF_COLOR)"
	@echo "$(BLUE)║$(DEF_COLOR)$(GREEN)        pipex executable created!       $(DEF_COLOR)$(BLUE)║$(DEF_COLOR)"
	@echo "$(BLUE)╚════════════════════════════════════════╝$(DEF_COLOR)"

clean:
	@make --no-print-directory -C $(LIBFT_DIR) fclean
	@rm -f $(OBJECTS) $(OBJECTS_BONUS)
	@echo "$(BLUE)pipex has been cleaned from object files!$(DEF_COLOR)"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIB_NAME)
	@echo "$(BLUE)pipex has been cleaned from the library and executable!$(DEF_COLOR)"

re: fclean all

bonus: fclean $(LIBFT) $(OBJECTS_BONUS)
	@ar rcs $(LIB_NAME) $(OBJECTS_BONUS)
	@$(CC) $(CFLAGS) -o $(NAME) $(MAIN_BONUS) $(LIB_NAME)
	@echo "$(BLUE)╔════════════════════════════════════════╗$(DEF_COLOR)"
	@echo "$(BLUE)║$(DEF_COLOR)$(GREEN)     pipex bonus executable created!    $(DEF_COLOR)$(BLUE)║$(DEF_COLOR)"
	@echo "$(BLUE)╚════════════════════════════════════════╝$(DEF_COLOR)"

.PHONY: all clean fclean re bonus
