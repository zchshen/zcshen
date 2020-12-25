/*
 * @Autor: zcshen
 * @Date: 2020-12-20 08:30:26
 * @Description:  数组倒置 -递归与迭代版本
 */

#include <iostream>
#include "common_function.h"

using namespace std;
using namespace zcshen;

static const uint8_t kArrayLen = 10;

// 递归版本
template<typename T>
void RecursionReverse(T& input, int lo, int hi) {
    if (lo < hi) {
        swap(input[lo], input[hi]);
        RecursionReverse(input, lo+1, hi-1);
    }
}

// 迭代版本
template<typename T>
void IterationReverse(T& input, int lo, int hi) {
    while (lo < hi) {
        swap(input[lo++], input[hi--]);
    }
}

int main(int argc, char** argv) {
    // 输入
    int test_array[kArrayLen] = { 0 };
    for (auto i = 0; i < kArrayLen; i++) {
        cin >> test_array[i];
    }

    // 倒置前
    cout << "Origin: " << endl;
    ShowElememts(test_array);

    // 递归版本
    RecursionReverse(test_array, 0, kArrayLen-1);
    // 递归执行后
    cout << "Recursion: " << endl;
    ShowElememts(test_array);

    // 迭代版本
    IterationReverse(test_array, 0, kArrayLen-1);
    // 迭代执行后
    cout << "Iteration: " << endl;
    ShowElememts(test_array);

    return 0;
}
