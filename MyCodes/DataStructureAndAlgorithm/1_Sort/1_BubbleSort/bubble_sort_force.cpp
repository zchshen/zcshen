/*
 * @Autor: zcshen
 * @Date: 2020-12-06 15:33:37
 * @Description: 冒泡排序-暴力解法
 */

#include <iostream>
#include <stdio.h>

static const uint8_t kMAX_INPUT = 100;

// 冒泡排序-暴力解法，逐趟扫描
// 有序：任意相邻元素均有序
// 无序：总有一对无序
void BubbleSort(int array[], int n) {
    for (bool sorted = false; (sorted = !sorted); n--) {
        for (int i = 1; i < n; i++) {
            if (array[i - 1] > array[i]) {
                // 逆序, 交换相邻元素
                std::swap(array[i - 1], array[i]);
                sorted = false;
            }
        }
    }
}

// 打印序列内容
void ShowArray(int array[], int n) {
    for (auto i = 0; i < n; i++) {
        std::cout << array[i] << " ";
    }

    std::cout << std::endl;
}

int main(int argc, char* argv[]) {
    // 存放待排序的无序数组
    int disorder_vector[kMAX_INPUT] = { 0 };

    int size = 0;

    std::cout << "Input the vector size: ";
    scanf("%d", &size);

    (size <= 0 || size > kMAX_INPUT) ?
        std::cout << "The vector size is too large!" << std::endl :
        std::cout << "Count is: " << size << std::endl;

    std::cout << "Enter the elements: " << std::endl;
    for (auto i = 0; i < size; i++) {
        scanf("%d", &disorder_vector[i]);
    }

    std::cout << "Before sort: ";
    ShowArray(disorder_vector, size);

    // 排序
    BubbleSort(disorder_vector, size);

    std::cout << "After sort: ";
    ShowArray(disorder_vector, size);

    return 0;
}
