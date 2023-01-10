# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mal-hadr <mal-hadr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 14:25:39 by mal-hadr          #+#    #+#              #
#    Updated: 2023/01/10 13:02:42 by mal-hadr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3d
CC			=	clang
SRCS		=	src/main.c \
				parcening/check_arg.c \
				parcening/read_map.c \
				parcening/map.c \
				parcening/color_character.c \
				parcening/valid_color.c \
				parcening/utils.c \
				parcening/texture.c \
				parcening/wall.c \
				parcening/free_struct.c \
				msg/msg.c \
				drawing/3D.c \
				drawing/draw_utils.c \
				drawing/rays_utils.c \
				drawing/rays.c \
				drawing/render_game.c \
				game/actions.c \
				utils/maps_utlis.c \
				utils/mlx_utlis.c \
				utils/start_utils.c \
				utils/utils.c \
				utils/raycast_sides.c \

LIBFT		=	libft/libft.a \
# CFLAGS		=	-Wall -Wextra -Werror -g
# MLXFLAGS	=	-framework OpenGL -framework AppKit -lz

CFLAGS		=	-Wall -Wextra -Werror -g
MLXFLAGS	=	-L ./mlx -lmlx -framework OpenGL -framework AppKit -lz
RM			=	rm -f
OBJDIR		= objects
# OBJS		= $(addprefix $(OBJDIR)/, $(addsuffix .o, $(SRCS)))
OBJS		=	$(SRCS:%.c=%.o)

# $(OBJDIR)/%.o : %.c
# 	@mkdir -p $(OBJDIR)
# 	@mkdir -p $(OBJDIR)/drawing
# 	@mkdir -p $(OBJDIR)/game
# 	@mkdir -p $(OBJDIR)/msg
# 	@mkdir -p $(OBJDIR)/parcening
# 	@mkdir -p $(OBJDIR)/src
# 	@mkdir -p $(OBJDIR)/utils
# 	$(CC) $(CFLAGS) -c $< -o $@
	

all:		$(NAME)

$(NAME):	$(OBJS)
			make -C mlx	
			make -C libft
			$(CC) $(SRCS) $(LIBFT) $(MLXFLAGS) $(CFLAGS) -o $(NAME)
#			$(CC) $(SRCS) $(LIBFT) $(CFLAGS) -o $(NAME)

%o:			%.c
			$(CC) $(CFLAGS) -Imlx -c $< -o $@

run:		all

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)
			$(RM) *.out
			make fclean -C libft/
			make clean -C mlx/

re:			fclean all
