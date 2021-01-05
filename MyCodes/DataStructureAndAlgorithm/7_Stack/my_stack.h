/*
 * @Autor: zcshen
 * @Date: 2021-01-04 15:44:36
 * @Description: 分别通过向量和链表实现 栈 结构
 */

#ifndef ZCSHEN_STACK_H
#define ZCSHEN_STACK_H

#include "my_vector.h"

namespace zcshen {

template < typename T >
class Stack : public Vector< T > {
  public:
    void Push(const T& e) {
        this->Insert(this->Size(), e);
    }

    T Pop() {
        return this->Remove(this->Size() -1);
    }

    T& top() {
        return (*this[this->Size() - 1]);
    }
};

}  // namespace zcshen

#endif