CXX = g++
CXXFLAGS = -std=c++11 -Wall --coverage
LDFLAGS = --coverage

SRCS = main.cpp Items.cpp library.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = library_app

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET) *.gcda *.gcno *.info -r out

coverage: all
	./$(TARGET)
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory out
