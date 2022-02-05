all: Collection-test.o Jeans_test.o Stress_ball_test.o Jeans.o Stress_ball.o
	g++ -std=c++11 -o test *.o
Collection-test.o: Collection-test.cpp Collection.h Stress_ball_test.h Jeans_test.h
	g++ -std=c++11 -c Collection-test.cpp
Jeans_test.o: Jeans_test.cpp Jeans.h Collection.h
	g++ -std=c++11 -c Jeans_test.cpp
Stress_ball_test.o: Stress_ball_test.cpp Stress_ball.h Collection.h
	g++ -std=c++11 -c Stress_ball_test.cpp
Jeans.o: Jeans.cpp Jeans.h
	g++ -std=c++11 -c Jeans.cpp
Stress_ball.o: Stress_ball.cpp Stress_ball.h
	g++ -std=c++11 -c Stress_ball.cpp
clean:
	rm test *.o
run: 
	./test