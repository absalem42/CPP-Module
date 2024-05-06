NAME = Bureaucrat

SRCS = main.cpp Bureaucrat.cpp
FILEH = Bureaucrat.hpp
CXX = c++

OBJS = $(SRCS:.cpp=.o)

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(FILEH)
	$(CXX) $(CXXFLAGS)  -o $(NAME) $(OBJS)

clean:
	rm -fr $(OBJS)
fclean: clean
	rm -fr $(SRCS)

re: fclean all

.PHONY: clean fclean all re