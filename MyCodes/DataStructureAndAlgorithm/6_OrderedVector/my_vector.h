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

    inline T& operator[](Rank r) const {
        return _element[r];
    }

    // 单元素插入
    Rank Insert(Rank r, const T& e);
    // 区间删除[lo, hi)
    int Remove(Rank lo, Rank hi);
    // 在[lo,hi)区间进行查找
    Rank Find(const T& e, Rank lo, Rank hi) const;
    // 单元素删除[r] = [r, r+1)
    T Remove(Rank r);
    // 删除重复元素
    int Deduplicate();

    // 遍历-函数指针
    void Traverse(void (*visit)(T&));
    // 遍历-函数对象
    template < typename VST >
    void Traverse(VST& visit);

    // 向量中逆序对个数
    int Disordered() const;

    // ------------------- 有序向量操作 ------------------------
    // 排序, 将无序向量转换为有序向量, 未实现
    void Ordered() {
    }
    // 唯一化
    int Uniquify();
    // 唯一化高效版本
    int Uniquify2();

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

template < typename T >
void Vector< T >::Expand() {
    if (_size < _capacity) {
        // 无需扩容
        return;
    }

    _capacity = (_capacity < DEFAULT_CAPACITY) ? DEFAULT_CAPACITY : _capacity;

    T* old_element = _element;
    // 加倍式扩容
    _element = new T[_capacity <<= 1];

    for (int i = 0; i < _size; i++) {
        // 拷贝元素
        _element[i] = old_element[i];
    }

    delete[] old_element;
}

template < typename T >
Rank Vector< T >::Insert(Rank r, const T& e) {
    Expand();
    // 移动元素
    for (int i = _size; i > r; i--) {
        _element[i] = _element[i - 1];
    }

    _element[r] = e;
    _size++;

    return r;
}

// [lo, hi)
template < typename T >
int Remove(Rank lo, Rank hi) {
    if (lo == hi) {
        return 0;
    }

    while (hi < _size) {
        _element[lo++] = _element[hi++];
    }

    _size = lo;

    return hi - lo;
}

// [lo, hi)
template < typename T >
Rank Vector< T >::Find(const T& e, Rank lo, Rank hi) const {
    while ((lo < hi--) && (e != _element[hi]))
        ;
    return hi;
}

template < typename T >
T Vector< T >::Remove(Rank r) {
    T e = _element[r];
    Remove(r, r + 1);

    return e;
}

template < typename T >
int Vector< T >::Deduplicate() {
    int old_size = _size;
    Rank i = 1;
    while (i < _size) {
        find(_element[i], 0, i) < 0 ? i++ : Remove(i);
    }

    return old_size - _size;
}

template < typename T >
void Vector< T >::Traverse(void (*visit)(T&)) {
    for (int i = 0; i < _size; i++) {
        visit(_element[i]);
    }
}

template < typename T >
template < typename VST >
void Vector< T >::Traverse(VST& visit) {
    for (int i = 0; i < _size; i++) {
        visit(_element[i]);
    }
}

template < typename T >
int Vector< T >::Disordered() const {
    int counter = 0;

    for (int i = 1; i < _size; i++) {
        if (_element[i - 1] > _element[i]) {
            n++;
        }
    }

    return n;
}

template < typename T >
int Vector< T >::Uniquify() {
    int old_size = _size;

    int i = 1;
    while (i < _size) {
        _element[i] == _element[i - 1] ? Remove(i) : i++;
    }

    return old_size - size;
}

template < typename T >
int Vector< T >::Uniquify2() {
    Rank p1 = 0;
    Rank p2 = 1;
    while (p2 < _size) {
        (_element[p2] != _element[p1]) ? _element[++p1] = _element[p2++] : p2++;
    }

    _size = ++p1;

    return p2 - p1;
}

}  // namespace zcshen

#endif  // end of ZCSHEN_VECTOR_H