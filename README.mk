Tower Defense Base
==================

This project serve as a base for tower defense games. I programmed it
so it would be easy to change the graphic library used. However, so
far, only Allegro is usable.

Install
-------

In this version, Allegro 5 is needed. You must download and install it
from

www.allegro.cc/files/

You must add the path to the library and the header to the compiler. 
You can do that with the following lines in your .bashrc

export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:/usr/local/lib"
export CPLUS_INCLUDE_PATH="$CPLUS_INCLUDE_PATH:/usr/local/include/allegro5"

Alternatively, you can add paths to these places in Lib/Makefile.

You will also need the Vectors library I made, that can be
downloaded with

git clone https://github.com/abelsiqueira/Vectors.git

After downloading, adjust the path to Vectors in Lib/Makefile

Now, enter

$ make

If you change something, you may have to clean before you can remake. You can do a 

$ make clean all

to remake completely.

After compiled, you can run the project with

$ Lib/test

