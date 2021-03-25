CXX = g++
OBJS = main.cpp server.cpp
CXXFLAGS = -Wall 
CONF = `sdl2-config --cflags --libs`

engine: $(OBJS)
				$(CXX) -o build/server $(OBJS) $(CXXFLAGS) $(CONF) 

main.cpp:server.h
server.cpp::server.h

clean:
		$(RM) game $(OBJS)
