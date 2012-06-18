CXX = g++
CXXFLAGS = -Wall -Wextra -ggdb
ROOTDIR = ..
I = -I$(ROOTDIR)/Include -I$(ROOTDIR)/../Vector2/Include

TOWERS = Light_Tower.o
ENEMIES = Skeleton.o
INTERFACE = Interface.o

GRAPHICOBJ = AllegroDraw.o
GRAPHIC_LIB = -lallegro_ttf -lallegro_font -lallegro_primitives -lallegro \
							-D'GraphicLibrary=ALLEGRO'

OBJS = $(TOWERS) $(ENEMIES) $(GRAPHICOBJ) $(INTERFACE)

all: clear $(OBJS)
	g++ ../main.cpp $(OBJS) $(GRAPHIC_LIB) -o test $(I) $(CXXFLAGS)

%.o: ../Src/%.cpp
	$(CXX) -c -o $@ $< $(I) $(GRAPHIC_LIB) $(CXXFLAGS)

clear:
	rm -f test
	rm -f *.o
