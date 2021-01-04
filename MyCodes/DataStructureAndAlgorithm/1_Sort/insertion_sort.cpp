/*
 * @Autor: zcshen
 * @Date: 2021-01-04 15:07:03
 * @Description: 链表的插入排序 - 消耗取决与逆序对的数量， input sensitive 
 */

#include "my_list.h"

using namespace zcshen;

int main(int argc, char** argv) {
    List<int> *inserted_list = new List<int>();
    inserted_list->InsertLast(0);
    inserted_list->InsertLast(0);
    inserted_list->InsertLast(3);
    inserted_list->InsertLast(1);
    inserted_list->InsertLast(5);
    inserted_list->InsertLast(4);
    inserted_list->InsertLast(8);

    inserted_list->Print();
    inserted_list->InsertionSort(inserted_list->First(), inserted_list->Size());
    inserted_list->Print();

    return 0;
}
