/*
 * @Autor: zcshen
 * @Date: 2020-12-27 13:45:43
 * @Description: 二分查找
 */

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

// 在有序向量A的[lo,hi)区间内查找元素e - 普通二分法
template <typename T>
int BinSearchA(T* vec, const T& e, int lo, int hi) {
    if (nullptr == vec) {
        return -1;
    }

    while (lo < hi) {
        int mid = lo + ((hi - lo) >> 1);
        if (e < vec[mid]) {
            hi = mid;
        }
        else if (vec[mid] < e) {
            lo = mid + 1;
        }
        else {
            return mid;
        }
    }

    return -1;
}

// 有序向量A的[lo, hi)区间中查找元素e, 改进版本B
template < typename T >
int BinSearchB(T* vec, const T& e, int lo, int hi) {
    while (1 < hi - lo) {
        int mid = lo + ((hi - lo) >> 1);
        (e < vec[mid]) ? hi = mid : lo = mid;
    }

    return (vec[lo] == e) ? lo : -1;
}

// 有序向量A的[lo, hi)区间中查找元素e, 改进版本C
template<typename T>
int BinSearchC(T* vec, const T& e, int lo, int hi) {
    while (lo < hi) {
        int mid = lo + ((hi - lo) >> 1);
        (e < vec[mid]) ? hi = mid : lo = mid + 1;
    }

    // 由上层算法判断是否查找成功, 如果没找到, 返回不大于e的最后一个元素
    return --lo;
}

int main(int argc, char** argv) {
    int array[] = { 1, 2, 3, 4, 5, 6, 6, 7, 7 };
    int e = 10; 
    size_t size = sizeof(array)/sizeof(array[0]);

    cout << "PositionA: " << BinSearchA<int>(array, e, 0, size) << endl;
    cout << "PositionB: " << BinSearchB<int>(array, e, 0, size) << endl;
    cout << "PositionC: " << BinSearchC<int>(array, e, 0, size) << endl;

    return 0;
}