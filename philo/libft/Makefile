# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfournie <marvin@42quebec.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/10 10:07:12 by sfournie          #+#    #+#              #
#    Updated: 2021/11/25 18:37:16 by sfournie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilation
CC		= @gcc
CFLAGS	= -Wall -Wextra -Werror
DFLAGS	= -g

# Library name
NAME	= libft.a

# Main directories
DIR_SRC	= srcs
DIR_OBJ	= objs
DIR_INC	= includes

# Subdirectories
DIR_DLST	= $(DIR_SRC)/dlist

# Global includes
INC		= -I$(DIR_DLST) -I$(DIR_INC)

# Headers files
_HEAD		= libft.h dlist.h
HEAD		= $(patsubst %,$(DIR_INC)/%,$(_HEAD))

# Basic sources files
_SRC_BASE	= ft_isalpha.c ft_isdigit.c ft_isnumber.c ft_isalnum.c \
		ft_isascii.c ft_isprint.c ft_isnumber.c \
		ft_toupper.c ft_tolower.c \
		ft_atoi.c ft_atod.c \
		ft_itoa.c ft_ultoa.c ft_uitoa.c ft_llitoa.c \
		ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
		ft_strchr.c ft_strlcpy.c ft_strlcat.c ft_strdup.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_strmapi.c \
		ft_strpchr.c \
		ft_split.c \
		ft_calloc.c ft_bzero.c ft_memset.c ft_memmove.c \
		ft_memcpy.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
		ft_free.c \
		ft_array_clear.c ft_free_array.c ft_free_split.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
		ft_lstmap.c \
		ft_countdigits.c ft_countminus.c \
		ft_nbrtobase.c  \
		ft_power.c \
		ft_get_next_line.c
SRC_BASE	= $(patsubst %,$(DIR_SRC)/%,$(_SRC_BASE))

# Double list sources files
_SRC_DLST	= ft_dlist.c ft_dlist_node.c ft_dlist_utils.c
SRC_DLST	= $(patsubst %,$(DIR_DLST)/%,$(_SRC_DLST))

# All sources files
SRC	= $(SRC_BASE) $(SRC_DLST)

# Sources vpath
vpath %.c $(DIR_SRC)
vpath %.c $(DIR_DLST)

_OBJ	= $(_SRC_BASE:.c=.o) $(_SRC_DLST:.c=.o)
OBJ		= $(patsubst %,$(DIR_OBJ)/%,$(_OBJ))

IS_COMP	:=
$(DIR_OBJ)/%.o :  %.c
		@ $(or $(IS_COMP),$(eval IS_COMP := :)echo "# Compiling libft objects files...")
		@ $(CC) $(CFLAGS) $(INC) -c $< -o $@

all		: $(NAME)

$(NAME) : $(HEAD) $(SRC) $(DIR_OBJ) $(OBJ)
		@ ar crs $(NAME) $(OBJ)
		# $(shell echo "libft library created")

$(DIR_OBJ)	: 
		@ mkdir -p objs

clean	:
		@ rm -rf $(DIR_OBJ)

fclean	: clean
		@ rm -rf $(NAME)

re		: fclean all

debug	: _debug $(NAME)

_debug	:
		$(eval CFLAGS=$(CFLAGS) $(DFLAGS))

.PHONY		: clean all re fclean bonus debug
