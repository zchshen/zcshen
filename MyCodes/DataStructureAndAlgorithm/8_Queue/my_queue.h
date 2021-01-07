/*
 * @Autor: zcshen
 * @Date: 2021-01-07 15:23:18
 * @Description: 队列
 */

#ifndef ZCSHEN_QUEUE_H
#define ZCSHEN_QUEUE_H

#include <stdint.h>
#include "my_list.h"

namespace zcshen {

template < typename T >
class Queue : public List< T > {
  public:
    void Enqueue(const T& e) {
        this->InsertLast(e);
    }

    T Dequeue() {
        return this->Remove(this->First());
    }

    T& Front() {
        return this->First()->data;
    }

};

}  // namespace zcshen

#endif
