
robo: robo.cpp robo.hpp
	g++ robo robo.cpp robo.hpp 

omni: omni.cpp omni.hpp
	g++ omni omni.cpp omni.hpp

robot: robot.cpp omni.o robo.o
	g++ -o robot robot.cpp omni.o robo.o

clean:
	rm -f robo.o
	rm -f omni.o
	rm -f robo.hpp.gch
	rm -f robot
