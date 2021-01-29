CC=/opt/rh/devtoolset-9/root/usr/bin/g++
CFLAGS=-std=c++17
TIMED=-DMEASURE

all: ans1 ans1-timed ans2 ans2-timed

ans1: ans1.cpp
	$(CC) $(CFLAGS) ans1.cpp -o ans1.out

ans1-timed: ans1.cpp ../../Utils/timer.h ../../Utils/timer.cpp
	$(CC) $(CFLAGS) $(TIMED) ans1.cpp ../../Utils/timer.cpp -o ans1.timed.out

ans2: ans2.cpp
	$(CC) $(CFLAGS) ans2.cpp -o ans2.out

ans2-timed: ans2.cpp ../../Utils/timer.h ../../Utils/timer.cpp
	$(CC) $(CFLAGS) $(TIMED) ans2.cpp ../../Utils/timer.cpp -o ans2.timed.out

ans3: ans3.cpp
	$(CC) $(CFLAGS) ans3.cpp -o ans3.out
clean:
	rm *.out

clean-timed-only:
	rm *.timed.out