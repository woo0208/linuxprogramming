CX = g++
CXFLAGS = -g -Wall
OBJS = main.o Student.o
TARGET = main

$(TARGET): $(OBJS)
	$(CX) $(CXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp
	$(CX) $(CXFLAGS) -c main.cpp

circle.o: Student.cpp Student.hpp
	$(CX) $(CXFLAGS) -c Student.cpp


.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJS)
