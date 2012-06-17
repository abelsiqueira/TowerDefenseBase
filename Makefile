I = -IInclude -IInclude/Towers -IInclude/Enemies \
		-I../Vector2/Include

SRCS = Src/Interface.cpp Src/Towers/Light_Tower.cpp Src/Enemies/Skeleton.cpp
GRAPHIC_LIB = -lallegro_ttf -lallegro_font -lallegro_primitives -lallegro \
							Src/AllegroDraw.cpp -D'GraphicLibrary=ALLEGRO'

all:
	g++ main.cpp $(SRCS) $(GRAPHIC_LIB) -o main $(I) -Wall -Wextra -ggdb $(USEGL)

