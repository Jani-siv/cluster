CXX = clang++
OBJS = main.cpp server.cpp clientClass.cpp menu.cpp
CXXFLAGS = -Wall 
CONF = -pthread -lsupc++

engine: $(OBJS)
				$(CXX) -o build/server $(OBJS) $(CXXFLAGS) $(CONF) 

main.cpp:server.h
server.cpp::server.h clientClass.h menu.h
clientClass.cpp:: clientClass.h
menu.cpp:: menu.h clientClass.h
clean:
		$(RM) game $(OBJS)
