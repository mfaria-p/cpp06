SRCS =	Base.cpp \
        main.cpp

OBJS = $(SRCS:.cpp=.o)

NAME = base
CXX = c++
CXXFLAGS = -g -std=c++98 -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all