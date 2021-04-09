CXX = clang++
OBJS = main.cpp server.cpp clientClass.cpp menu.cpp clientContainer.cpp neural/neural.cpp neural/input.cpp neural/layer.cpp neural/filehandle.cpp
CXXFLAGS = -Wall 
CONF = -pthread -lsupc++

engine: $(OBJS)
				$(CXX) -o build/server $(OBJS) $(CXXFLAGS) $(CONF) 

main.cpp:server.h
server.cpp::server.h clientClass.h menu.h clientContainer.h
clientClass.cpp:: clientClass.h
menu.cpp:: menu.h clientClass.h neural/neural.h
clientContainer.cpp:: clientContainer.h
neural/neural.cpp:: neural/neural.h neural/input.h neural/layer.h
neural/input.cpp:: neural/input.h
neural/layer.cpp:: neural/layer.h neural/input.h neural/filehandle.h
neural/filehandle.cpp:: neural/filehandle.h
clean:
		$(RM) game $(OBJS)
