I = -IInclude -IInclude/Towers -IInclude/Enemies \
		-I../Vector2/Include

SRCS = Src/Interface.cpp Src/Towers/Light_Tower.cpp Src/Enemies/Skeleton.cpp

all:
	g++ main.cpp $(SRCS) -o main $(I) -Wall -Wextra -ggdb

