CC=/opt/rh/devtoolset-9/root/usr/bin/g++
CFLAGS=-std=c++17
TIMED=-DMEASURE

all: ans1# ans1-timed ans2 ans2-timed

ans1: ans1.cpp
	$(CC) $(CFLAGS) ans1.cpp -o ans1.out

clean:
	rm *.out

clean-timed-only:
	rm *.timed.out