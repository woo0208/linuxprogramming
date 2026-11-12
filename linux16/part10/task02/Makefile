CX = g++
CXFLAGS = -g -Wall
OBJS = main.o Circle.o
TARGET = main

$(TARGET): $(OBJS)
	$(CX) $(CXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp
	$(CX) $(CXFLAGS) -c main.cpp

circle.o: Circle.cpp Circle.hpp
	$(CX) $(CXFLAGS) -c Circle.cpp


.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJS)
