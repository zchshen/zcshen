/*
 * @Autor: zcshen
 * @Date: 2020-12-28 13:32:12
 * @Description: 气泡排序 - 改进版本, 避免对有序子序列重复遍历
 */

#include "common_function.h"
#include <vector>

using namespace std;
using namespace zcshen;

template < typename T >
int Bubble(vector< T >& elements, int lo, int hi) {
    int last_swap = lo;
    while (++lo < hi) {
        if (elements[lo - 1] > elements[lo]) {
            // 存在逆序对
            //swap(elements[lo], elements[lo - 1]);
            T temp = elements[lo - 1];
            elements[lo - 1] = elements[lo];
            elements[lo] = temp;
            last_swap = lo;
        }
    }

    return last_swap;
}

// [lo, hi)
template < typename T >
void BubbleSort(vector< T >& elements, int lo, int hi) {
    while (lo < hi) {
        hi = Bubble(elements, lo, hi);
    }
}

int main(int argc, char** argv) {
    vector< int > vec1;
    BubbleSort(vec1, 0, vec1.size());
    ShowElememts(vec1);

    vector< int > vec2 = { 1 };
    BubbleSort(vec2, 0, vec2.size());
    ShowElememts(vec2);

    vector< int > vec3 = { 1, 2, 3, 4, 5 };
    BubbleSort(vec3, 0, vec3.size());
    ShowElememts(vec3);

    vector< int > vec4 = { 5, 4, 3, 2, 1 };
    BubbleSort(vec4, 0, vec4.size());
    ShowElememts(vec4);

    vector< int > vec5 = { 1, 2, 3, 4, 2, 1, 3, 4, 5, 6, 7 };
    BubbleSort(vec5, 0, vec5.size());
    ShowElememts(vec5);

    return 0;
}
