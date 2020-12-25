/*
 * @Autor: zcshen
 * @Date: 2020-12-24 14:55:45
 * @Description:  向量基本操作
 */

#ifndef ZCSHEN_VECTOR_H
#define ZCSHEN_VECTOR_H

#include <stdint.h>
#include <iostream>

namespace zcshen {
/**
 * @brief: 秩
 */
typedef int Rank;

/**
 * @brief: 默认大小
 */
#define DEFAULT_CAPACITY 10

template < typename T >
class Vector {
  public:
    Vector() {
    }

    Vector(int c) {
        _element = new T[_capacity = c];
        _size = 0;
    }

    // 数组区间复制
    Vector(const T* V, Rank lo, Rank hi) {
        CopyFrom(V, lo, hi);
    }

    // 向量区间复制
    Vector(const Vector< T >& V, Rank lo, Rank hi) {
        CopyFrom(V._element, lo, hi);
    }

    // 向量整体复制
    Vector(const Vector< T >& V) {
        CopyFrom(V._element, 0, V._size);
    }

    ~Vector() {
        delete[] _element;
    }

  protected:
  private:
    void CopyFrom(const T* V, Rank lo, Rank hi);
    void Expand();

  private:
    Rank _size{ 0 };
    int _capacity{ DEFAULT_CAPACITY };
    T* _element{ nullptr };
};

template < typename T >
void Vector< T >::CopyFrom(const T* V, Rank lo, Rank hi) {
    // 两倍的方式申请空间
    _element = new T[_capacity = 2 * (hi - lo)];
    _size = 0;

    // 拷贝数据
    while (lo < hi) {
        _element[_size++] = V[lo++];
    }
}

template<typename T>
void Vector<T>::Expand() {
  if (_size < _capacity) {
    // 无需扩容
    return;
  }

  _capacity = (_capacity < DEFAULT_CAPACITY) ? DEFAULT_CAPACITY : _capacity;

  T* old_element = _element;
  // 加倍式扩容
  _element = new T[_capacity <<= 1];

  for (int i = 0; i<_size; i++) {
    // 拷贝元素
    _element[i] = old_element[i];
  }

  delete[] old_element;
}

}  // namespace zcshen

#endif  // end of ZCSHEN_VECTOR_H