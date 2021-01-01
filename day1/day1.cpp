#include <stdio.h>
#include <bits/stdc++.h>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace chrono;

bool sum_exist_force(int numbers[], int numbersLength, int sum) {
    for (int i = 0; i < numbersLength; i++) {
        for (int j = 0; j < numbersLength; j++) {
            if (i != j) {
                if (numbers[i] + numbers[j] == sum) {
                    return true;
                }
            }
        }
    }

    return false;
}

bool sum_exist(int numbers[], int numbersLength, int sum) {
    int numbers_copy[numbersLength];

    for (int i = 0; i < numbersLength; i++) {
        numbers_copy[i] = numbers[i];
    }

    sort(numbers_copy, numbers_copy + numbersLength);

    if (sum < numbers_copy[0]) {
        return 0;
    }

    int i = 0;
    int j = numbersLength - 1;

    while (true) {
        if (i == j) {
            return 0;
        }
        else if (numbers_copy[i] + numbers_copy[j] == sum) {
            return 1;
        }
        else if (numbers_copy[i] + numbers_copy[j] < sum) {
            i++;
        }
        else if (numbers_copy[i] + numbers_copy[j] > sum) {
            j--;
        }
    }
}

void test_func() {
    int iterations = 0;

    while (true) {
        int test[100];
        int test_length = 100;

        for (int i = 0; i < test_length; i++) {
            test[i] = rand() % 100;
        }

        int sum = rand() % 150;

        bool res1 = sum_exist_force(test, test_length, sum);
        bool res2 = sum_exist(test, test_length, sum);

        if (res1 != res2) {
            printf("Iteration %d failed\n", iterations);
            return;
        }
        printf("Iteration %d succeeded\n", iterations);

        iterations++;
    }
}

int main() {
    // int test[100000];
    // int testLength = sizeof(test)/sizeof(test[0]);
    // int sum = 19;

    // auto start1 = high_resolution_clock::now();
    // bool res1 = sum_exist_force(test, testLength, sum);
    // auto end1 = high_resolution_clock::now();
    // auto duration1 = duration_cast<milliseconds>(end1 - start1);

    // printf("Result 1: %d\n", res1);
    // cout << "Time 1: " << duration1.count() << " milliseconds\n";
    // cout << "\n";

    // auto start2 = high_resolution_clock::now();
    // bool res2 = sum_exist(test, testLength, sum);
    // auto end2 = high_resolution_clock::now();
    // auto duration2 = duration_cast<milliseconds>(end2 - start2);

    // printf("Result 2: %d\n", res2);
    // cout << "Time 2: " << duration2.count() << " milliseconds\n";

    test_func();
}
