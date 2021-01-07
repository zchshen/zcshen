/*
 * @Autor: zcshen
 * @Date: 2021-01-07 15:34:50
 * @Description: 测试自定义队列
 */

#include "my_queue.h"

using namespace std;
using namespace zcshen;

int main(int argc, char** argv) {
    Queue<int> my_queue;

    my_queue.Enqueue(1);
    cout << my_queue.Front() << endl;
    my_queue.Enqueue(2);
    cout << my_queue.Front() << endl;
    my_queue.Enqueue(4);
    my_queue.Dequeue();
    cout << my_queue.Front() << endl;
    my_queue.Enqueue(10);
    my_queue.Dequeue();
    cout << my_queue.Front() << endl;
    my_queue.Dequeue();
    cout << my_queue.Front() << endl;

    return 0;
}
