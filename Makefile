CXX = g++
CXXFLAGS = -Wall -Iinclude `pkg-config --cflags opencv4`
LDFLAGS = `pkg-config --libs opencv4`
SRC = src/Jogo.cpp src/DetectorFace.cpp src/Comida.cpp src/Utils.cpp main.cpp
EXEC = jogo-serpente

all: $(EXEC)

$(EXEC): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(EXEC)
