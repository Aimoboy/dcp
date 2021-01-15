#include <stdio.h>
#include <bits/stdc++.h>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace chrono;

void product_array(int input[], int output[], int size) {
    int all_sum = 1;

    for (int i = 0; i < size; i++) {
        all_sum *= input[i];
    }

    for (int i = 0; i < size; i++) {
        output[i] = int(all_sum / input[i]);
    }
}

void product_array_no_divide(int input[], int output[], int size) {
    int left_product[size];
    int right_product[size];
    left_product[0] = input[0];
    right_product[size - 1] = input[size - 1];

    for (int i = 1; i < size; i++) {
        left_product[i] = left_product[i - 1] * input[i];
    }

    for (int i = size - 2; i >= 0; i--) {
        right_product[i] = right_product[i + 1] * input[i];
    }

    output[0] = right_product[1];
    output[size - 1] = left_product[size - 2];
    for (int i = 1; i < size - 1; i++) {
        output[i] = left_product[i - 1] * right_product[i + 1];
    }
}

void product_array_force(int input[], int output[], int size) {
    for (int i = 0; i < size; i++) {
        int product = 1;
        for (int j = 0; j < i; j++) {
            product *= input[j];
        }
        for (int j = i + 1; j < size; j++) {
            product *= input[j];
        }

        output[i] = product;
    }
}

int main() {
    int test[100000];
    int size = sizeof(test) / sizeof(test[0]);

    for (int i = 0; i < size; i++) {
        test[i] = (rand() % 10000) + 1;
    }

    int result[size];

    auto start1 = high_resolution_clock::now();
    product_array(test, result, size);
    auto stop1 = high_resolution_clock::now();

    auto start2 = high_resolution_clock::now();
    product_array_no_divide(test, result, size);
    auto stop2 = high_resolution_clock::now();

    auto start3 = high_resolution_clock::now();
    product_array_force(test, result, size);
    auto stop3 = high_resolution_clock::now();

    auto duration1 = duration_cast<milliseconds>(stop1 - start1);
    auto duration2 = duration_cast<milliseconds>(stop2 - start2);
    auto duration3 = duration_cast<milliseconds>(stop3 - start3);

    cout << "Time 1: " << duration1.count() << " milliseconds\n";
    cout << "Time 2: " << duration2.count() << " milliseconds\n";
    cout << "Time 3: " << duration3.count() << " milliseconds\n";
}
