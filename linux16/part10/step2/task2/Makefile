CX = g++
CXFLAGS = -g -Wall
OBJS = main.o
TARGET = main

$(TARGET): $(OBJS)
	$(CX) $(CXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp GClass.hpp
	$(CX) $(CXFLAGS) -c main.cpp

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJS)
