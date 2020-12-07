CC = g++
CXXFLAGS = -Wall -g -D__LINUX__

INCLUDES =
LDADD =

TARGET = BubbleSortForce
all:$(TARGET)

OBJS = bubble_sort_force.o

$(TARGET):$(OBJS)
	$(CC) $(CXXFLAGS) -fPIC -o $(TARGET) $(OBJS) $(LDADD)

.cpp.o:
	$(CC) $(CXXFLAGS) $(INCLUDES) -fPIC -c $<

.PHONY:clean
clean:
	rm -fr *.o $(TARGET)

	

