#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <chrono>
#include <vector>
#include <time.h>
#include <immintrin.h>

#define HEUR 25
#define SIZE 2000 //not less than 10
int weights[SIZE][SIZE];
typedef std::chrono::steady_clock::time_point tp;



class Time {
public:
    static void show(tp t1, tp t2) { //time passed since t1
        //std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << '\t';
        //printf("nanoseconds \n");
        std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << '\t';
        printf("nanoseconds \n");
    }
    tp addPoint() {
        tp p = std::chrono::steady_clock::now();
        return p;
    }
};

void turn1(int t = 1) {
    for (auto i = 0; i < SIZE; i++)
        for (auto j = 0; j < SIZE; j++)
            if (weights[i][j] > t)
                weights[i][j] -= t;
}
void turn2(int t = 1) {
    for (auto i = 0; i < SIZE; i++)
        for (auto j = 0; j < SIZE; j++)
            weights[i][j] -= t*weights[i][j]>t;
}
int main() {
    Time time;
    int c = 0;
    for (auto i = 0; i < SIZE; i++)
        for (auto j = 0; j < SIZE; j++)
            weights[i][j] = rand() % 5000;
    auto t3 = time.addPoint();
    turn2(25);
    auto t4 = time.addPoint();
    auto t5 = time.addPoint();
    turn1(25);
    auto t6 = time.addPoint();
    time.show(t3, t4);
    time.show(t5, t6);
    return 0;

}