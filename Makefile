NAME		=	cub3D
NAME_BONUS  =	cub3D_bonus

CC			=	gcc

LIBFT 		:=	./libft/libft.a

CFLAGS		=	-Werror -Wall -Wextra #-fsanitize=address -g3

SRCS = mandatory/main.c \
		mandatory/parse/check_filename.c \
		mandatory/parse/check_elem.c \
		mandatory/parse/set_elem.c \
		mandatory/parse/utils.c \
		mandatory/parse/utils2.c \
		mandatory/parse/check_map.c \
		mandatory/parse/gnl/get_next_line.c \
		mandatory/parse/gnl/get_next_line_utils.c \

SRCS_BONUS  =	 gnl/get_next_line.c gnl/get_next_line_utils.c main.c bonus/check_filename_bonus.c bonus/check_elem_bonus.c bonus/set_elem_bonus.c bonus/utils_bonus.c bonus/utils2_bonus.c bonus/check_map_bonus.c
				
OBJS		=	$(SRCS:.c=.o)
OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				make -C libft/
				$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

bonus 		:	$(NAME_BONUS)

$(NAME_BONUS) : $(OBJS_BONUS)
				make -C libft/
				$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(NAME_BONUS)


clean		:
				rm -f $(OBJS)
				rm -f $(OBJS_BONUS)
				make clean -C libft/

fclean		:	clean
				rm -f $(NAME)
				rm -f $(NAME_BONUS)
				make fclean -C libft/

re			:	fclean all