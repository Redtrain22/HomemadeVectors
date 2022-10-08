CXX := g++
CXXFLAGS := -g -std=c++17 -O0
INCFLAGS := -Iinclude

SRCDIR := ./src
OBJDIR := ./obj
TARGETDIR := ./bin
TARGET := $(notdir $(CURDIR))

SRC := $(wildcard $(SRCDIR)/*.cpp)
OBJ := $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRC))

.PHONY: clean

all: create $(TARGETDIR)/$(TARGET)

$(TARGETDIR)/$(TARGET): $(OBJ)
	$(CXX) -o $@ $^ $(INCFLAGS) $(CXXFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) -c $< -o $@ $(INCFLAGS) $(CXXFLAGS)

create:
	mkdir -p $(OBJDIR)
	mkdir -p $(TARGETDIR)

clean:
	rm -rf $(OBJDIR)
	rm -rf $(TARGETDIR)