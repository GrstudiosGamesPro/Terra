# Variables
CXX = g++
CXXFLAGS = -g --std=c++17 -Wall -DGLM_ENABLE_EXPERIMENTAL #-DNDEBUG
INCLUDE_DIR = -I../vendor/include -I../vendor/include/origami-math/include
LIB_DIR = -L../vendor/libs
SRC_DIR = ../src
VENDOR_DIR = ../vendor/libs

SOURCES = $(wildcard $(SRC_DIR)/*.cpp $(SRC_DIR)/game/*.cpp $(SRC_DIR)/graphics/*.cpp $(SRC_DIR)/components/*.cpp $(SRC_DIR)/scenes/*.cpp $(SRC_DIR)/UPhysics/core/*.cpp $(SRC_DIR)/UPhysics/core/body/*.cpp)

GLAD_SOURCE = $(VENDOR_DIR)/glad.c

TARGET = Terra

LIBS = -lassimp -lglfw3dll -lglm

all: $(TARGET)

$(TARGET): $(SOURCES) $(GLAD_SOURCE)
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIR) $(LIB_DIR) $(SOURCES) $(GLAD_SOURCE) -o $(TARGET) $(LIBS)

clean:
	rm -f *.o

.PHONY: all clean