#include <stdio.h>
#include <bits/stdc++.h>
#include <chrono>
#include <cstdlib>
#include <string.h>
using namespace std;
using namespace chrono;

int find_lowest_missing_pos(int arr[], int size) {
    int tmp_arr[size];

    for (int i = 0; i < size; i++) {
        tmp_arr[i] = arr[i];
    }

    int i = 0;
    while (i < size) {
        int num = tmp_arr[i];

        if (num < 0 || num > size) {
            i++;
            continue;
        }
        else if (num == i + 1) {
            i++;
            continue;
        }
        else if (num < i + 1) {
            int tmp_num = tmp_arr[num - 1];
            tmp_arr[num - 1] = num;
            tmp_arr[i] = tmp_num;

            i++;
            continue;
        }
        else {
            int tmp_num = tmp_arr[num - 1];
            tmp_arr[num - 1] = num;
            tmp_arr[i] = tmp_num;
        }
    }

    for (int i = 0; i < size; i++) {
        if (tmp_arr[i] != i + 1) {
            return i + 1;
        }
    }

    return size + 1;
}

int main() {
    int test[4] = {3, 4, -1, 1};
    int size = sizeof(test) / sizeof(test[0]);

    cout << find_lowest_missing_pos(test, size) << "\n";
}
