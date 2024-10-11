traffic: main.o trafficLight.o time.o
	g++ -Wall -g main.o  trafficLight.o time.o -o traffic

main.o: main.cpp trafficLight.h time.h
	g++ -Wall -g -c main.cpp

traffic.o: trafficLight.cpp trafficLight.h
	g++ -Wall -g -c trafficLight.cpp

time.o: time.cpp trafficLight.h time.h
	g++ -Wall -g -c time.cpp

clean:
	rm -f *.o traffic
