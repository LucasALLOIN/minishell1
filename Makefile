##
## EPITECH PROJECT, 2018
## Project mysh
## File description:
## Build mysh binary.
##

SRC     =	source/exec/get_real_path.c \
		source/exec/has_slash.c \
		source/exec/check_cmd.c \
		source/exec/launch_programm.c \
		source/exec/cmd_handler.c \
		source/exec/verify_path.c \
		source/shell/minishell_loop.c \
		source/shell/mysh.c \
		source/main.c \
		source/env/my_get_full_env.c \
		source/env/is_in_env_entry.c \
		source/env/env_len.c \
		source/env/get_var_name.c \
		source/env/free_env.c \
		source/env/add_env_to_list_manager.c \
		source/env/is_in_env.c \
		source/env/is_in_env_for_add.c \
		source/env/remove_env.c \
		source/env/get_env_varname_len.c \
		source/env/is_setenv.c \
		source/env/modifie_env_var.c \
		source/env/my_getenv.c \
		source/env/show_env.c \
		source/env/remove_from_env.c \
		source/env/get_env_varname.c \
		source/env/build_env_tab.c \
		source/env/is_env_valid.c \
		source/env/add_env_to_list.c \
		source/env/is_unset_valid.c \
		source/env/env_manager.c \
		source/env/display_env.c \
		source/env/build_env_list.c \
		source/tab_utils/my_str_to_array.c \
		source/tab_utils/count_to_split.c \
		source/tab_utils/tab_lengh.c \
		source/tab_utils/free_tab.c \
		source/errors/print_error_on_exec.c \
		source/errors/display_cd_error.c \
		source/errors/display_error_on.c \
		source/builtin/is_env.c \
		source/builtin/check_builtin.c \
		source/builtin/is_cd.c \
		source/builtin/is_unsetenv.c \
		source/builtin/is_exit.c \
		source/builtin/my_cd.c \
		source/builtin/is_empty_setenv.c \
		source/builtin/my_exit.c \
		source/utils/my_malloc.c \
		source/utils/my_puterror.c \
		source/utils/my_is_dir.c \
		source/utils/is_forking.c \
		source/utils/str_clear.c \
		source/utils/tild_replacer.c \
		source/gnl/get_next_line.c \
		source/signal/handler.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Werror -Wextra -W -Wall -Wparentheses -Wsign-compare -Wpointer-sign -Wuninitialized -Wunused-but-set-variable -I ./include/ -L lib/ -lmy -g

NAME	=	mysh

CC	=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

docker:
	sudo docker run -it -v `pwd`:/home/epitest -w /home/epitest epitechcontent/epitest-docker /bin/bash

re: fclean all
