# array(c++11)

># 与vector比较
1. constructor、destructor、operator= 都是 implicit
2. capacity: 无resize、shrink_to_fit、capacity、reserve 方法
3. modifiers: 除swap外，不支持其他方法修改容器内容
4. observers: 无 get_allocator