TARGET=testenum

SRCS=testenum.cpp

OBJS=$(SRCS:.cpp=.o)

CXXFLAGS=-g -Wall -fPIC -O2
#CXXFLAGS+=-save-temps

all: $(TARGET)

$(OBJS): days.h numbers.h fruits.h enumstr.h Makefile

#%.o: %.cpp
.cpp.o: $(SRCS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CXX) -s -o $@ $^

clean:
	rm -f $(OBJS) $(SRCS:.cpp=.ii) $(SRCS:.cpp=.s)

distclean: clean
	rm -f $(TARGET)
