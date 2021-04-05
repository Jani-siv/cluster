CXX = clang++
OBJS = main.cpp server.cpp clientClass.cpp menu.cpp clientContainer.cpp neural.cpp
CXXFLAGS = -Wall 
CONF = -pthread -lsupc++

engine: $(OBJS)
				$(CXX) -o build/server $(OBJS) $(CXXFLAGS) $(CONF) 

main.cpp:server.h
server.cpp::server.h clientClass.h menu.h clientContainer.h
clientClass.cpp:: clientClass.h
menu.cpp:: menu.h clientClass.h neural.h
clientContainer.cpp:: clientContainer.h
neural.cpp:: neural.h
clean:
		$(RM) game $(OBJS)
