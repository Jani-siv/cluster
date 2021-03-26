CXX = g++
OBJS = main.cpp server.cpp clientClass.cpp menu.cpp
CXXFLAGS = -Wall 
CONF = -pthread

engine: $(OBJS)
				$(CXX) -o build/server $(OBJS) $(CXXFLAGS) $(CONF) 

main.cpp:server.h
server.cpp::server.h clientClass.h menu.h
clientClass.cpp:: clientClass.h
menu.cpp:: menu.h
clean:
		$(RM) game $(OBJS)
