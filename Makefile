CXX=g++
CXXFLAGS=-Wall -std=c++17
OBJS=main.o parser.o executor.o utils.o

mini_shell: $(OBJS)
	$(CXX) $(CXXFLAGS) -o mini_shell $(OBJS)

main.o: main.cpp parser.hpp executor.hpp utils.hpp
parser.o: parser.cpp parser.hpp
executor.o: executor.cpp executor.hpp utils.hpp
utils.o: utils.cpp utils.hpp

clean:
	rm -f *.o mini_shell
