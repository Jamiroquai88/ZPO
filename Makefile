CP=g++
CPFLAGS=-std=c++11 -pthread -pedantic -Wall -O3 -g
CPP_FILES := $(wildcard *.cpp)
OBJ_FILES := $(CPP_FILES:.cpp=.o)

all: detect-text

detect-text: $(OBJ_FILES)
	$(CP) $(CPFLAGS) $^ -o $@ -lm

%.o:%.cpp
	$(CP) $(CPFLAGS) -c $< -o $@ -I/usr/local/include -L/usr/local/lib64 -lm

clean:
	$(RM) detect-text $(OBJ_FILES) *.h.gch
