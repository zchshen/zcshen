/*
 * @Autor: zcshen
 * @Date: 2020-12-29 15:18:24
 * @Description: 双向链表
 */

#ifndef ZCSHEN_LIST_H
#define ZCSHEN_LIST_H

#include <stdint.h>
#include <iostream>

using namespace std;

namespace zcshen {

#define Rank int

/**
 * @brief: 节点定义
 */

#define Position(T) ListNode< T >*

template < typename T >
struct ListNode {
    ListNode() {
    }

    ListNode(T e, Position(T) p, Position(T) s) : data(e), pred(p), succ(s) {
    }

    // 当前节点前插
    Position(T) InsertAsPred(const T& e);
    // 当前节点尾插
    Position(T) InsertAsSucc(const T& e);

    // 数据
    T data;
    // 前驱节点
    Position(T) pred;
    // 后继节点
    Position(T) succ;
};

template < typename T >
Position(T) ListNode< T >::InsertAsPred(const T& e) {
    ListNode* node = new ListNode(e, pred, this);
    pred->succ = node;
    pred = node;

    return node;
}

template < typename T >
Position(T) ListNode< T >::InsertAsSucc(const T& e) {
    ListNode* node = new ListNode(e, this, succ);
    succ->pred = node;
    succ = node;

    return node;
}

/**
 * @brief: 双向链表定义
 */
template < typename T >
class List {
  public:
    List() {
        Init();
    }

    ~List() {
        Clear();

        if (nullptr != _header) {
            delete _header;
        }

        if (nullptr != _trailer) {
            delete _trailer;
        }
    }

    inline Position(T) First() const {
        return _header->succ;
    }

    inline Position(T) Tail() const {
        return _trailer->pred;
    }

    inline int Size() const {
      return _size;
    }

    inline bool Empty() const {
        return !_size;
    }

    // 循秩访问
    T operator[](Rank r) const;

    // 在节点P的n个真前驱中查找元素e
    Position(T) Find(const T& e, int n, Position(T) p) const;

    // 对节点P进行前插
    Position(T) InsertBefore(Position(T) p, const T& e);
    // 对节点P进行后插
    Position(T) InsertAfter(Position(T) p, const T& e);
    // 链表尾插
    void InsertLast(const T& e);

    // 节点复制, 节点p后的n个节点到当前链表
    void CopyNodes(Position(T) p, int n);

    // 删除节点
    T Remove(Position(T) p);

    // 链表去重操作
    int Deduplicate();

    // 选择排序 - 对起始于P的连续n个元素进行选择排序
    void SelectionSort(Position(T) p, int n);
    Position(T) SelectMax(Position(T) p, int n);

    // 插入排序 - 对起始于p的连续n个元素进行插入排序
    void InsertionSort(Position(T) p, int n);

    // 有序链表的去重
    int Uniquify();

    // 有序列表查找, 返回不大于e的最后一个元素, 在p的n个真前缀中查找元素e
    Position(T) Search(const T& e, int n, Position(T) p);

    // 打印链表
    void Print();

  protected:
  private:
    // 创建链表时默认调用, 初始化头尾哨兵
    void Init();

    // 清空链表
    int Clear();

  private:
    // 规模
    int _size;
    // 头哨兵
    Position(T) _header;
    // 尾哨兵
    Position(T) _trailer;
};

template < typename T >
inline void List< T >::Init() {
    _header = new ListNode< T >();
    _trailer = new ListNode< T >();

    _header->pred = nullptr;
    _header->succ = _trailer;

    _trailer->pred = _header;
    _trailer->succ = nullptr;

    _size = 0;
}

template < typename T >
T List< T >::operator[](Rank r) const {
    Position(T) p = First();

    while (0 < r--) {
        p = p->succ;
    }

    return p->data;
}

template < typename T >
Position(T) List< T >::Find(const T& e, int n, Position(T) p) const {
    while (0 < n-- && nullptr != p) {
        p = p->succ;
        if (e == p->data) {
            return p;
        }
    }

    return nullptr;
}

template < typename T >
Position(T) List< T >::InsertBefore(Position(T) p, const T& e) {
    ++_size;
    return p->InsertAsPred(e);
}

template < typename T >
Position(T) List< T >::InsertAfter(Position(T) p, const T& e) {
    ++_size;
    return p->InsertAsSucc(e);
}

template < typename T >
void List< T >::CopyNodes(Position(T) p, int n) {
    // 创建空链表
    Init();

    while (n--) {
        InsertAsLast(p->data);
        p = p->succ;
    }
}

template < typename T >
void List< T >::InsertLast(const T& e) {
    InsertBefore(_trailer, e);
}

template < typename T >
T List< T >::Remove(Position(T) p) {
    T e = p->data;
    p->pred->succ = p->succ;
    p->succ->pred = p->pred;
    --_size;
    delete p;

    return e;
}

template < typename T >
int List< T >::Clear() {
    int old_size = _size;
    while (0 < _size) {
        Remove(_header->succ);
    }

    return old_size;
}

template < typename T >
void List< T >::Print() {
    Position(T) cur = _header;
    while (_trailer != (cur = cur->succ)) {
        cout << cur->data << " ";
    }
    cout << endl;
}

template < typename T >
int List< T >::Deduplicate() {
    if (_size < 2) {
        // 平凡链表无重复
        return 0;
    }

    int old_size = _size;
    Position(T) node = First();
    int pred_counter = 1;

    Position(T) find_node = nullptr;
    while (_trailer != (node = node->succ)) {
        find_node = Find(node->data, pred_counter, node);
        nullptr == find_node ? ++pred_counter : Remove(find_node);
    }

    return (old_size - _size);
}

template < typename T >
void List< T >::SelectionSort(Position(T) p, int n) {
    if (n < 2) {
        return;
    }

    Position(T) head = p->pred;
    Position(T) tail = p;

    for (int i = 0; i < n; ++i) {
        tail = tail->succ;
    }

    while (1 < n) {
        InsertBefore(tail, Remove(SelectMax(head->succ, n)));
        tail = tail->pred;
        --n;
    }
}

template < typename T >
Position(T) List< T >::SelectMax(Position(T) p, int n) {
    Position(T) max = p;
    for (Position(T) cur = p; 1 < n; --n) {
        if ((cur = cur->succ)->data >= max->data) {
            max = cur;
        }
    }

    return max;
}

template < typename T >
int List< T >::Uniquify() {
    if (_size < 2) {
        return 0;
    }

    int old_size = _size;

    Position(T) node1 = First();
    Position(T) node2 = nullptr;

    while (_trailer != (node2 = node1->succ)) {
        if (node1->data == node2->data) {
            Remove(node2);
        }
        else {
            node1 = node2;
        }
    }

    return old_size - _size;
}

template < typename T >
Position(T) List< T >::Search(const T& e, int n, Position(T) p) {
    while (0 <= n--) {
        if ((p = p->pred)->data <= e) {
            break;
        }
    }

    return p;
}

template < typename T >
void List< T >::InsertionSort(Position(T) p, int n) {
    if (nullptr == p) {
        return;
    }

    for (int r = 0; r < n; r++) {
        InsertAfter(Search(p->data, r, p), p->data);
        p = p->succ;
        Remove(p->pred);
    }
}

}  //  end of namespace zcshen

#endif  // end of ZCSHEN_LIST_H