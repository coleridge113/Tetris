CXX = clang++
CXXFLAGS = -std=c++23 -O2
INC = -I/opt/homebrew/include
LIB = -L/opt/homebrew/lib
LDFLAGS = -lraylib -framework OpenGL -framework Cocoa -framework IOKit

SOURCES = main.cpp classes/*.cpp

game: $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o game $(INC) $(LIB) $(LDFLAGS)

clean:
	rm -f game
