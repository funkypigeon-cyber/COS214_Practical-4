CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic
INCLUDES = -Isrc/shared -Isrc/caitlin -Isrc/musa -Isrc/rochaan

TARGET = taskforge

SOURCES = src/shared/main.cpp \
          $(wildcard src/caitlin/*.cpp) \
          $(wildcard src/musa/*.cpp) \
          $(wildcard src/rochaan/*.cpp)

OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJECTS) $(TARGET)

rebuild: clean all

.PHONY: all run clean rebuild