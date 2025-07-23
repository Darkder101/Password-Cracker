CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude
SRC = src/main.cpp src/attacks/brute_force.cpp src/attacks/dictionary_attack.cpp
OUT = pwcrackr
LIBS = -lssl -lcrypto

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT) $(LIBS)

clean:
	rm -f $(OUT)
