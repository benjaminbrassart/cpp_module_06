# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/20 08:17:11 by bbrassar          #+#    #+#              #
#    Updated: 2022/04/20 08:46:42 by bbrassar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= identify

CXX					= c++
CXXFLAGS			= -Wall -Werror -Wextra -c -MMD -MP -Iinclude -std=c++98

RM					= rm -f

DIR_SRC				= src
DIR_OBJ				= obj

SRC					= main.cpp utils.cpp
OBJ					= $(SRC:%.cpp=$(DIR_OBJ)/%.o)
DEP					= $(OBJ:.o=.d)

$(NAME):			$(OBJ)
					$(CXX) $^ -o $@

$(DIR_OBJ)/%.o:		$(DIR_SRC)/%.cpp
					@mkdir -p $(@D)
					$(CXX) $(CXXFLAGS) $< -o $@

-include $(DEP)

all:				$(NAME)

clean:
					$(RM) -r $(DIR_OBJ)

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re
