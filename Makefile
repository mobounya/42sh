# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mobounya <mobounya@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/08 10:36:53 by ylagtab           #+#    #+#              #
#    Updated: 2021/05/20 14:04:21 by mobounya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	variables																   #
# **************************************************************************** #

# name
NAME = 42sh
LIBFT = libft/libft.a
PARSER = src/parser/parser.a
JOBS = src/execution/job_control/job_control.a
READLINE = readline/readline.a
EXPANSION = src/expansion/expansion.a
LIBFT_OPT = "LIBFT_EXIT_ON_ALLOC_FAIL=1"

# compilation variables
CFLAGS = -Wall -Wextra -Werror $(INCLUDES) -g
CC = gcc
LIBS_ENV= 42sh_headers=$(mkfile_dir)/includes/forty_two_sh.h 42sh_include_dirs=-I$(mkfile_dir)includes/

# 42sh																		   #
INCLUDES =	-I includes

42sh_INC =	includes/forty_two_sh.h includes/typedefs.h includes/constants.h \
			src/errors/errors.h

42sh = 	delete_functions.o main.o signal.o errors/errors.o free_funcs.o \
	execution/exec_tools.o \
	execution/execute_commands.o \
	execution/execute_logic_seq.o \
	execution/execute_pipe_seq.o \
	execution/execute_simple_cmd.o \
	execution/pipes_and_red.o \
	execution/redirections_helper.o \
	execution/get_exit_code.o \
	execution/redirections.o \
	execution/remove_quotes.o \
	execution/wait_children.o \
	prompt.o \
	builtins/export.o \
	builtins/job_builtins.o \
	builtins/ft_echo.o \
	builtins/ft_exit.o \
	builtins/hash/ft_add_hash.o \
	builtins/hash/ft_forget_name.o \
	builtins/hash/ft_hash.o \
	builtins/hash/ft_hash_helpers.o \
	builtins/hash/ft_new_hash.o \
	builtins/hash/ft_parse_options.o \
	builtins/hash/ft_print_hash.o \
	builtins/hash/hash_str.o \
	builtins/hash/print_errors.o \
	builtins/hash/ft_print_this_many_chars.o \
	builtins/hash/ft_free_hash.o \
	builtins/type/ft_parse_type_options.o \
	builtins/type/ft_type.o \
	builtins/type/ft_type_checks.o \
	builtins/type/ft_type_errors.o \
	builtins/type/ft_type_print.o \
	builtins/type/ft_execute_type.o \
	builtins/test/ft_test.o \
	builtins/test/ft_builtin_test_errors.o \
	builtins/test/ft_check_file_type.o \
	builtins/test/ft_do_operations.o \
	builtins/test/ft_is_test_operator.o \
	builtins/cd.o \
	builtins/cd_helper.o \
	builtins/cd_helper2.o \
	execution/builtins.o \
	read_cmd_multiline/read_cmd_multiline.o \
	utils/is_quote.o utils/is_close_red.o utils/is_space.o \
	builtins/set.o builtins/unset.o \
	env/env.o env/env_dup.o env/env_get.o env/env_operations.o env/utils.o \
	print_signal.o utils/ft_tcsetpgrp.o


42sh_OBJS = $(addprefix $(OBJS_DIR)/, ${42sh})

# objects directory
OBJS_DIR = objs

#
mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
mkfile_dir := $(dir $(mkfile_path))

# **************************************************************************** #
#	rules																	   #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(42sh_OBJS) $(LIBFT) $(PARSER) $(READLINE) $(JOBS) $(EXPANSION)
	$(CC) -o $(NAME) $(42sh_OBJS) $(PARSER) $(READLINE) $(JOBS) $(EXPANSION) $(LIBFT) -ltermcap

$(LIBFT): force
	@env $(LIBFT_OPT) make -C libft/

$(PARSER): force
	@env $(LIBS_ENV) make -C src/parser/

$(EXPANSION): force
	@env $(LIBS_ENV) make -C src/expansion/

$(JOBS): force
	make -C src/execution/job_control

 $(READLINE) : force
	@make -C readline

force:

$(OBJS_DIR)/%.o : src/%.c $(42sh_INC)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)
	make clean -C src/execution/job_control
	make clean -C readline

fclean: clean
	make fclean -C libft/
	make fclean -C src/parser/
	make fclean -C src/expansion/
	make fclean -C src/execution/job_control
	make fclean -C readline
	rm -f $(NAME)

re:
	@make fclean
	@make all

.PHONY: all clean fclean re libft force
