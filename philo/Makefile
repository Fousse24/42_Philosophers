# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfournie <sfournie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 20:58:38 by sfournie          #+#    #+#              #
#    Updated: 2021/12/16 20:12:26 by sfournie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilation
CC		= gcc
CFLAGS	= -Wall -Wextra
DFLAGS	= -g

C_OBJS	= $(CC) $(CFLAGS) $(INCS) -c $< -o $@
C_MAIN	= $(CC) $(CFLAGS) $(INCS)

# NAME
NAME	= philo

# Mains
MAIN	= $(D_MAIN)/main.c

# Directories
D_SRCS	= srcs
D_INCS	= includes
D_OBJS	= objs
D_MAIN	= main

INCS	= -I$(D_INCS)

# Headers
HEAD_PHILO	= $(D_INCS)/philo.h
HEADS		= $(HEAD_PHILO)

# Sources
_SRCS	= threads.c mutex.c dinertime_thread.c \
		philo.c \
		philo_fork.c philo_states.c \
		diner.c diner_utils.c diner_meal.c\
		ft_time.c ft_time_math.c \
		utils.c get_options.c parse.c parse_utils.c
SRCS	= $(patsubst %, $(D_SRCS)/%, $(_SRCS))

# Objects
_OBJS	= $(_SRCS:.c=.o)
OBJS	= $(patsubst %, $(D_OBJS)/%, $(_OBJS))

# vpath
vpath %.c $(D_SRCS)

$(D_OBJS)/%.o :  %.c $(HEADS)
		 @ $(C_OBJS)

# Rules/Recipes
all		: $(NAME)

$(NAME)	: $(HEADS) $(SRCS) $(D_OBJS) $(OBJS) $(MAIN)
		@ $(C_MAIN) $(MAIN) $(OBJS) -o $(NAME)
		# $(shell echo "Compiling philosophers done!")
		# $(shell echo "Executable is : $(NAME)")

$(D_OBJS):
		@ mkdir $(D_OBJS)

clean	: 
		@ rm -rf $(D_OBJS)
		# $(shell echo "Cleaning done!")

fclean	: clean
		@ rm -f $(NAME)

re		: fclean all

debug	: _debug $(NAME)

_debug	:
		$(eval CFLAGS=$(CFLAGS) $(DFLAGS))

.PHONY	: all clean fclean re debug
		