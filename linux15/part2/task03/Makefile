CX = g++
CXFLAGS = -g -Wall
OBJS = shape.o main.o
TARGET = main

$(TARGET): $(OBJS)
	$(CX) $(CXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp shape.hpp
	$(CX) $(CXFLAGS) -c main.cpp

shape.o: shape.cpp shape.hpp
	$(CX) $(CXFLAGS) -c shape.cpp

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJS)
