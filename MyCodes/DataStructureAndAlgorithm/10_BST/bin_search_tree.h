/*
 * @Autor: zcshen
 * @Date: 2021-01-21 14:03:24
 * @Description: 二叉搜索树
 */

#ifndef ZCSHEN_BST_H
#define ZCSHEN_BST_H

#include "bin_tree.h"

namespace zcshen {

template < typename T >
class BST : public BinTree< T > {
  public:
    BST() {
    }
    ~BST() {
    }

    virtual BinNodePosition(T) & Search(const T& e);
    virtual BinNodePosition(T) Insert(const T& e);
    virtual bool Remove(const T& e);

  protected:
    // 命中节点的父节点
    BinNodePosition(T) _hot;

  private:
};

// 递归的方式进行查找
template < typename T >
static BinNodePosition(T) SearchIn(BinNodePosition(T) & v,  // 当前树根节点
    const T& e,                                             // 目标元素
    BinNodePosition(T) & hot                                // 记忆热点
) {
    if (NULL == v || e == v->data) {
        return v;
    }

    hot = v;
    return SearchIn((e < v->data ? v->lchild : v->rchild), e, hot);
}

template < typename T >
    BinNodePosition(T) & BST< T >::Search(const T& e) {
    return SearchIn(this->_root, e, _hot = NULL);
}

template < typename T >
BinNodePosition(T) BST< T >::Insert(const T& e) {
    BinNodePosition(T)& x = search(e);

    if (NULL == x) {  // 相同节点不重复插入
        x = new BinNode(e, _hot);
        _size++;
        UpdateHeightAbove(x);
    }

    return x;
}

template < typename T >
static BinNodePosition(T) RemoveAt(BinNodePosition(T) & x, BinNodePosition(T) & hot) {
    BinNodePosition(T) w = x;
    BinNodePosition(T) succ = NULL;

    if (NULL == x->lchild) {
        x = x->rchild;
        succ = x;
    }
    else if (NULL == x->rchild) {
        x = x->lchild;
        succ = x;
    }
    else {
        w = w->succ();
        swap(x->data, w->data);
        BinNodePosition(T) u = w->parent;
        succ = w->rchild;
        (u == x ? u->rchild : u->lchild)  = succ;
    }

    hot = w->parent;
    if (NULL == succ) {
        succ->parent = hot;
    }

    Release(w->data);
    Release(w);

    return succ;
}

template < typename T >
bool BST< T >::Remove(const T& e) {
    BinNodePosition(T)& x = search(e);
    if (NULL == x) {
        return false;
    }

    RemoveAt(x, _hot);
    _size--;
    UpdateHeightAbove(_hot);

    return x;
}

}  // namespace zcshen

#endif
