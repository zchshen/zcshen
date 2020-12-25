/*
 * @Autor: zcshen
 * @Date: 2020-12-20 13:10:30
 * @Description: 查找数组中最大的两个元素(top2问题)
 */

#include <iostream>
#include "common_function.h"

using namespace std;
using namespace zcshen;

static const int kArrayLen = 6;

// Array[0, hi)
// 迭代方法1: 比较次数 2n - 3
void Top2(const int (&input)[kArrayLen], int lo, int hi, int& top1, int& top2) {
    // 第一次遍历, 获取最大值
    top1 = lo;
    for (int i = lo + 1; i < hi; i++) {
        if (input[top1] < input[i]) {
            top1 = i;
        }
    }

    // 获取区间[lo, top1)中的最大值
    top2 = (top1 == lo ? lo + 1 : lo);
    for (int i = top2 + 1; i < top1; i++) {
        if (input[top2] < input[i]) {
            top2 = i;
        }
    }

    // 获取区间[top1+1, hi)中的最大值, 并与[lo, top1)中最大值比较, 取较大的那个作为 top2
    for (int i = top1 + 1; i < hi; i++) {
        if (input[top2] < input[i]) {
            top2 = i;
        }
    }
}

// 改进1
// 迭代方法2: 比较次数, 最好: 1+(n-2)*1 = n-1, 最坏: 1+ (n-2)*2 = 2n-3
void Top2Pro1(const int (&input)[kArrayLen], int lo, int hi, int& top1, int& top2) {
    if (input[top1 = lo] < input[top2 = lo + 1]) {
        swap(top1, top2);
    }

    for (auto i = lo + 2; i < hi; i++) {
        if (input[top2] < input[i]) {
            if (input[top1] < input[top2 = i]) {
                swap(top1, top2);
            }
        }
    }
}

// 改进2
// 递归+分治: T(n) <= 5n/3 -2， 没搞懂怎么得来
void Top2Pro2(const int (&input)[kArrayLen], int lo, int hi, int& top1, int& top2) {
    // 退化情况
    if (lo + 2 == hi) {
        if (input[top1 = lo] < input[top2 = lo + 1]) {
            swap(top1, top2);
        }

        return;
    }

    if (lo + 3 == hi) {
        if (input[top1 = lo] < input[top2 = lo + 1]) {
            swap(top1, top2);
        }

        if (input[top2] < input[lo + 2]) {
            if (input[top1] < input[top2 = lo + 2]) {
                swap(top1, top2);
            }
        }

        return;
    }

    int mi = (lo + hi) >> 1;

    int top1_l = 0, top2_l = 0;
    Top2Pro2(input, lo, mi, top1_l, top2_l);
    int top1_r = 0, top2_r = 0;
    Top2Pro2(input, mi, hi, top1_r, top2_r);

    if (input[top1_l] > input[top1_r]) {
        top1 = top1_l;
        top2 = (input[top2_l] > input[top1_r] ? top2_l : top1_r);
    }
    else {
        top1 = top1_r;
        top2 = (input[top1_l] > input[top2_r] ? top1_l : top2_r);
    }
}

int main(int argc, char** argv) {
    // 输入
    int input[kArrayLen] = { 0 };
    for (auto i = 0; i < kArrayLen; i++) {
        cin >> input[i];
    }

    cout << "Input: ";
    ShowElememts(input);

    int top1 = 0;
    int top2 = 0;
    Top2(input, 0, kArrayLen, top1, top2);
    cout << "TOP2: "
         << "top1 = " << input[top1] << " top2 = " << input[top2] << endl;

    top1 = 0;
    top2 = 0;
    Top2Pro1(input, 0, kArrayLen, top1, top2);
    cout << "TOP2PRO1: "
         << "top1 = " << input[top1] << " top2 = " << input[top2] << endl;

    top1 = 0;
    top2 = 0;
    Top2Pro2(input, 0, kArrayLen, top1, top2);
    cout << "TOP2PRO2: "
         << "top1 = " << input[top1] << " top2 = " << input[top2] << endl;

    return 0;
}