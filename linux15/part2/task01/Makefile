CX = g++
CXFLAGS = -g -Wall
OBJS = TV.o main.o
TARGET = main

$(TARGET): $(OBJS)
	$(CX) $(CXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp TV.hpp
	$(CX) $(CXFLAGS) -c main.cpp

TV.o: TV.cpp TV.hpp
	$(CX) $(CXFLAGS) -c TV.cpp

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJS)
