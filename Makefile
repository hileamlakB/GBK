CC = gcc
HEADER = gbk.h \
         ./builtins/help.h
 
SRC = ./builtins/builtins.c \
      ./builtins/expansions.c \
      ./builtins/help.c \
      ./builtins/history.c \
      ./builtins/unalias.c \
      ./builtins/alias.c \
      ./data_structures/cmdlist_struct.c \
      ./gbk.c \
      ./utils/env_utils.c\
      ./utils/gbk_utils.c\
      ./utils/memory_utils2.c\
      ./utils/memory_utils.c\
      ./utils/num_utils.c\
      ./utils/str_util_adv2.c\
      ./utils/str_util_adv.c\
      ./utils/str_util_basic.c\
      ./utils/sys_utils.c

OBJ = $(SRC:.c=.o)
NAME = gbk
CFLAGS = -Wall -Werror -Wextra -pedantic



.PHONY: all clean

all : $(OBJ)
	$(CC) $(OBJ) -o $(NAME)
	$(RM) $(OBJ)
clean: 
	$(RM)  $(OBJ) $(NAME)
re: clean all
