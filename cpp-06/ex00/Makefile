NAME = ScalarConverter

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror 

SRCS = main.cpp \
		ScalarConverter.cpp


OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) 
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re