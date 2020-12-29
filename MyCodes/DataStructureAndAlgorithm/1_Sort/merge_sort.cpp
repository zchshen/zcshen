/*
 * @Autor: zcshen
 * @Date: 2020-12-28 15:04:13
 * @Description: 二路归并排序
 */

#include <vector>
#include "common_function.h"

using namespace std;
using namespace zcshen;

// [lo, hi) = [lo, mid) + [mid, hi)
template < typename T >
void Merge(vector< T >& elements, int lo, int mid, int hi) {
    int len_b = mid - lo;
    vector< T > elements_b;

    // 初始化B
    for (int i = lo; i < mid; i++) {
        elements_b.push_back(elements[i]);
    }

    // 主体
    for (int rank_b = 0, rank_c = mid, rank_a = lo; (rank_b < len_b) || (rank_c < hi);) {
        if ((rank_b < len_b) && ((rank_c >= hi) || (elements_b[rank_b] <= elements[rank_c]))) {
            elements[rank_a++] = elements_b[rank_b++];
        }

        if ((rank_c < hi) && ((rank_b >= len_b) || (elements_b[rank_b] > elements[rank_c]))) {
            elements[rank_a++] = elements[rank_c++];
        }
    }

    //elements_b.swap(vector< T >());
}

// [lo, hi)
template < typename T >
void MergeSort(vector< T >& elements, int lo, int hi) {
    if ((hi - lo) < 2) {
        return;
    }

    int mid = lo + ((hi - lo) >> 1);
    // [lo, mid)
    MergeSort(elements, lo, mid);
    // [mid, hi)
    MergeSort(elements, mid, hi);
    // 归并
    Merge(elements, lo, mid, hi);
}

int main(int argc, char** argv) {
    vector< int > vec1;
    MergeSort(vec1, 0, vec1.size());
    ShowElememts(vec1);

    vector< int > vec2 = { 1 };
    MergeSort(vec2, 0, vec2.size());
    ShowElememts(vec2);

    vector< int > vec3 = { 1, 2, 3, 4, 5 };
    MergeSort(vec3, 0, vec3.size());
    ShowElememts(vec3);

    vector< int > vec4 = { 5, 4, 3, 2, 1 };
    MergeSort(vec4, 0, vec4.size());
    ShowElememts(vec4);

    vector< int > vec5 = { 1, 2, 3, 4, 2, 1, 3, 4, 5, 6, 7 };
    MergeSort(vec5, 0, vec5.size());
    ShowElememts(vec5);

    return 0;
}
