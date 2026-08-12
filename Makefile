CXX = clang++

CXXFLAGS = -shared -fPIC -std=c++17 -I./include
#CXXFLAGS = -shared -fPIC -std=c++17 $(CXXFLAG_1) $(CXXFLAG_LIB_1)

TARGET = libsample.so
all: $(TARGET)

$(TARGET): sample.o
	$(CXX) $(CXXFLAGS) sample.o -o $(TARGET)

sample.o: sample.cpp
	$(CXX) $(CXXFLAGS) -c sample.cpp

clean:
	rm *.o $(TARGET)
