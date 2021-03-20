cmake_minimum_required(VERSION 3.17)
project(corewar C)

set(CMAKE_C_STANDARD 99)

add_executable(asm asm.c asm.h checks.c error_manager.c
        get_next_line.c get_next_line.h inits.c libft.h op.h parse.c
        libft/ft_strlen.c
        libft/ft_putstr.c
        libft/ft_strsub.c
        libft/ft_strdup.c
        libft/ft_strdel.c
        libft/ft_strnew.c
        libft/ft_strjoin.c
        libft/ft_strchr.c
        libft/ft_putstr_fd.c
        libft/ft_putnbr_fd.c
        libft/ft_putchar_fd.c
        libft/ft_strcmp.c
        libft/ft_isdigit.c
        libft/ft_isalpha.c
        libft/ft_memset.c
        libft/ft_strncpy.c
        libft/ft_strequ.c
        libft/ft_atoi.c
        libft/ft_memcpy.c
        libft/ft_putnbr.c // debug
        libft/ft_putchar.c // debug
        utils.c parse_tokens.c free.c debug.c hash.c
        parse_instr.c parse_args.c parse_instr_list.c len_arr.c get_bytes.c assemble.c get_final_str.c utils_2.c)
