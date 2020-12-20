/*
 * @Autor: zcshen
 * @Date: 2020-12-20 10:00:40
 * @Description: 数组求和
 */

#include <iostream>
#include "CommonFunction.h"

using namespace std;
using namespace zcshen_common_function;

static const uint8_t kArrayLen = 10;

// 减而治之
int SumDecrease(const int (&input)[kArrayLen], int lo, int hi) {
    cout << hi << endl;
    return ((lo == hi) ? input[lo] : SumDecrease(input, lo, hi-1) + input[hi]);
}

// 分而治之
int SumDivide(const int (&input)[kArrayLen], int lo, int hi) {
    if (lo == hi) return input[lo];
    int mi = (lo + hi) >> 1;
    return (SumDivide(input, lo, mi) + SumDivide(input, mi+1, hi));
}

int main(int argc, char** argv) {
    // 输入
    int input[kArrayLen] = { 0 };
    for (auto i = 0; i < kArrayLen; i++) {
        cin >> input[i];
    }

    cout << "Decrease sum: " << SumDecrease(input, 0, kArrayLen-1) << endl;
    cout << "Divide sum: " << SumDivide(input, 0, kArrayLen-1) << endl;
    return 0;
}
