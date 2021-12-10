# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 20:58:38 by sfournie          #+#    #+#              #
#    Updated: 2021/12/09 19:50:03 by sfournie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilation
CC		= gcc
CFLAGS	= -Wall -Wextra
DFLAGS	= -g

C_OBJS	= $(CC) $(CFLAGS) $(INCS) -c $< -o $@
C_MAIN	= $(CC) $(CFLAGS) $(INCS) $(L_LFT)

# NAME
NAME	= philo

# Mains
MAIN	= $(D_MAIN)/main.c

# Directories
D_SRCS	= srcs
D_INCS	= includes
D_OBJS	= objs
D_MAIN	= main
D_LFT	= libft

INCS	= -I$(D_INCS) -I$(D_LFT)/includes

# Libraries
L_LFT	= $(D_LFT)/libft.a
MK_LFT		= make -C $(D_LFT)

# Headers
HEAD_PHILO	= $(D_INCS)/philo.h
HEAD_LFT	= $(D_LFT)/includes/libft.h
HEADS		= $(HEAD_PHILO) $(HEAD_LFT)

# Sources
_SRCS	= threads.c mutex.c dinertime_thread.c \
		philo.c \
		philo_fork.c philo_states.c \
		diner.c diner_utils.c\
		ft_time.c 
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

$(NAME)	: $(L_LFT) $(HEADS) $(SRCS) $(D_OBJS) $(OBJS) $(MAIN)
		@ $(C_MAIN) $(MAIN) $(OBJS) -o $(NAME)
		# $(shell echo "Compiling philosophers done!")
		# $(shell echo "Executable is : $(NAME)")

$(L_LFT): $(D_LFT)
		$(MK_LFT) all

$(D_OBJS):
		@ mkdir $(D_OBJS)

clean	: 
		@ rm -rf $(D_OBJS)
		@ $(MK_LFT) clean
		# $(shell echo "Cleaning done!")

fclean	: clean
		@ rm -f $(NAME)
		@ $(MK_LFT) fclean

re		: fclean all

debug	: _debug $(NAME)

_debug	:
		$(eval CFLAGS=$(CFLAGS) $(DFLAGS))
		@ $(MK_LFT) debug


.PHONY	: all clean fclean re debug
		