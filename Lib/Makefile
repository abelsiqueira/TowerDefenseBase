CXX = g++
CXXFLAGS = -Wall -Wextra -ggdb 
ROOTDIR = ..
I = -I$(ROOTDIR)/Include -I$(ROOTDIR)/Vectors/Include

TOWERS = Light_Tower.o Tower.o
ENEMIES = Skeleton.o Enemy.o
PROJECTILES = Light_Projectile.o Projectile.o
INTERFACE = Interface.o

GRAPHICOBJ = AllegroDraw.o
GRAPHIC_LIB = -lallegro_ttf -lallegro_font -lallegro_primitives -lallegro \
							-lallegro_audio -lallegro_acodec -lallegro_image \
							-D'GraphicLibrary=ALLEGRO'

OBJS = $(TOWERS) $(ENEMIES) $(PROJECTILES) $(GRAPHICOBJ) $(INTERFACE)

all: $(OBJS)
	g++ ../main.cpp $(OBJS) $(GRAPHIC_LIB) -o test $(I) $(CXXFLAGS)

%.o: ../Src/%.cpp
	$(CXX) -c -o $@ $< $(I) $(GRAPHIC_LIB) $(CXXFLAGS)

clean:
	rm -f test
	rm -f *.o
