/*
 * @Autor: zcshen
 * @Date: 2020-12-20 09:11:42
 * @Description: 每隔k个元素对数组进行倒置处理
 */

#include <iostream>
#include "CommonFunction.h"

using namespace std;
using namespace zcshen_common_function;

static const int kArrayLen = 10;

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

    int k = 0;
    cin >> k;
    cout << "K: " << k << endl;

    // 倒置前
    cout << "Origin: " << endl;
    ShowElememts(test_array);

    // 递归版本
    int lo = 0;
    int hi = lo + k - 1;
    while (hi < kArrayLen) {
        RecursionReverse(test_array, lo, hi);
        lo += k;
        hi = lo + k - 1;
    }
    // 递归执行后
    cout << "Recursion: " << endl;
    ShowElememts(test_array);

    // 迭代版本
    lo = 0;
    hi = lo + k - 1;
    while (hi < kArrayLen) {
        IterationReverse(test_array, lo, hi);
        lo += k;
        hi = lo + k - 1;
    }
    // 迭代执行后
    cout << "Iteration: " << endl;
    ShowElememts(test_array);

    return 0;
}
