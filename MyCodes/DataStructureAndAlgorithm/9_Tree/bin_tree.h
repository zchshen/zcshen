/*
 * @Autor: zcshen
 * @Date: 2021-01-10 05:48:21
 * @Description: 二叉树实现
 */

#ifndef ZCSHEN_BIN_NODE_H
#define ZCSHEN_BIN_NODE_H

#include <stdint.h>
#include <algorithm>
#include <iostream>

using namespace std;

namespace zcshen {

#define BinNodePosition(T) BinNode< T >*

template < typename T >
struct BinNode {
    BinNode() {
    }

    explicit BinNode(const T& e) : data(e), parent(nullptr), lchild(nullptr), rchild(nullptr) {
    }

    BinNode(const T& e, BinNodePosition(T) p) : data(e), parent(p), lchild(nullptr), rchild(nullptr) {
    }

    // 子树规模
    int Size() const;

    // 作为左孩子插入
    BinNodePosition(T) InsertAsLChild(const T& e);
    // 作为右孩子插入
    BinNodePosition(T) InsertAsRChild(const T& e);

    // 当前节点的直接后继
    BinNodePosition(T) Succ() {
        BinNodePosition(T) node = this;
        while (NULL != node->lchild) {
            node = node->lchild;
        }

        return node;
    }

    //子树层次遍历
    template < typename VST >
    void TraveLevel(VST&);

    //子树先序遍历
    template < typename VST >
    void TravePre(VST&) {
    }

    //子树中序遍历
    template < typename VST >
    void TraveIn(VST&) {
    }

    //子树后续遍历
    template < typename VST >
    void TravePost(VST&) {
    }

    BinNodePosition(T) parent;
    BinNodePosition(T) lchild;
    BinNodePosition(T) rchild;

    T data;

    int height;
};

template < typename T >
int BinNode< T >::Size() const {
    // 节点自身
    int size = 1;

    size += (nullptr == lchild ? 0 : lchild->Size());
    size += (nullptr == rchild ? 0 : rchild->Size());

    return size;
}

template < typename T >
BinNodePosition(T) BinNode< T >::InsertAsLChild(const T& e) {
    return lchild = new BinNode< T >(e, this);
}

template < typename T >
BinNodePosition(T) BinNode< T >::InsertAsRChild(const T& e) {
    return rchild = new BinNode< T >(e, this);
}

#define Stature(p) ((p) ? (p)->height : -1)

template < typename T >
class BinTree {
  public:
    BinTree() : _size(0), _root(nullptr) {
    }

    int Size() const {
        return _size;
    }

    bool Empty() const {
        return !_root;
    }

    BinNodePosition(T) Root() const {
        return _root;
    }

  protected:
    // 规模
    int _size;
    // 根节点
    BinNodePosition(T) _root;

    // 更新节点的高度
    virtual int UpdateHeight(BinNodePosition(T) x);
    // 更新节点及其祖先的高度
    void UpdateHeightAbove(BinNodePosition(T) x);

    // 作为左孩子插入
    BinNodePosition(T) InsertAsLChild(BinNodePosition(T) x, const T& e);
    // 作为有孩子插入
    BinNodePosition(T) InsertAsRChild(BinNodePosition(T) x, const T& e);

  private:
};

template < typename T >
int BinTree< T >::UpdateHeight(BinNodePosition(T) x) {
    return (x->height = 1 + (Stature(x->lchild) > Stature(x->rchild)) ? Stature(x->lchild) : Stature(x->rchild));
}

template < typename T >
void BinTree< T >::UpdateHeightAbove(BinNodePosition(T) x) {
    while (x) {
        int old_height = x->height;
        UpdateHeigth(x);
        if (old_height == x->height) {
            // 高度未变, 终止
            return;
        }

        x = x->parent;
    }
}

template < typename T >
BinNodePosition(T) BinTree< T >::InsertAsLChild(BinNodePosition(T) x, const T& e) {
    ++_size;
    x->InsertAsLChild(e);
    UpdateHeightAbove(x);

    return x->lchild;
}

template < typename T >
BinNodePosition(T) BinTree< T >::InsertAsRChild(BinNodePosition(T) x, const T& e) {
    ++_size;
    x->InsertAsRChild(e);
    UpdateHeightAbove(x);

    return x->rchild;
}

template < typename T >
class TreeVisit {
  public:
    TreeVisit() {
    }

    ~TreeVisit() {
    }

    void operator()(const T& e) {
        cout << "Node data is: " << e << endl;
    }
};

}  // namespace zcshen
#endif
