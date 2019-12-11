CXX = g++
CXXFLAGS = -std=c++0x -g

SRCS = Animal.cpp Tiger.cpp Penguin.cpp Turtle.cpp Zoo.cpp mainZoo.cpp

OBJS = Animal.o Tiger.o Penguin.o Turtle.o Zoo.o mainZoo.o

HEADERS = Animal.hpp Tiger.hpp Penguin.hpp Turtle.hpp Zoo.hpp 

ZooTycoon: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o ZooTycoon

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c ${@:.o=.cpp}

clean:
	rm ${OBJS} ZooTycoon
