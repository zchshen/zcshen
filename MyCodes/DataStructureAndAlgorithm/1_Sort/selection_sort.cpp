/*
 * @Autor: zcshen
 * @Date: 2020-12-30 15:09:24
 * @Description: 选择排序
 */

#include "my_list.h"

using namespace zcshen;

int main(int argc, char** argv) {
    // 创建链表
    List<int> *test_list = new List<int>();
    test_list->InsertLast(5);
    test_list->InsertLast(3);
    test_list->InsertLast(6);
    test_list->InsertLast(7);
    test_list->Print();

    // 排序
    test_list->SelectionSort(test_list->First(), test_list->Size());
    test_list->Print();

    return 0;
}