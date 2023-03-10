#ifndef BINARY_H
#define BINARY_H
#include <string>
#include <sstream>

template <class T>
struct binaryNode
{
    T *data;
    binaryNode<T> *lTree;
    binaryNode<T> *rTree;
    ~binaryNode() { delete data; };
};

template <class T>
class binaryTree
{
public:
    const binaryTree<T> &operator=(const binaryTree<T> &otherTree);
    binaryTree(const binaryTree<T> &otherTree);
    binaryTree();
    void destroyTree();
    std::string inorderTraversal() const;
    std::string preorderTraversal() const;
    std::string postorderTraversal() const;

protected:
    binaryNode<T> *root;

private:
    void copyTree(binaryNode<T> *&copiedTreeRoot, binaryNode<T> *otherTreeRoot);
    void destroy(binaryNode<T> *&p);
    void inorder(binaryNode<T> *p, std::ostringstream &out) const;
    void preorder(binaryNode<T> *p, std::ostringstream &out) const;
    void postorder(binaryNode<T> *p, std::ostringstream &out) const;
}

template <class T>
const binaryTree<T> &binaryTree<T>::operator=(const binaryTree<T> &otherTree)
{
    if (this != &otherTree)
    {
        if (root != nullptr)
            destroy(root);
        if (otherTree.root == nullptr)
            root = nullptr;
        else
            copyTree(root, otherTree.root);
    }
    return *this;
}

template <class T>
binaryTree<T>::binaryTree(const binaryTree<T> &otherTree)
{
    if (otherTree.root == nullptr)
        root = nullptr;
    else
        copyTree(root, otherTree.root);
}

template <class T>
binaryTree<T>::binaryTree()
{
    root = nullptr;
}

template <class T>
void binaryTree<T>::destroyTree()
{
    destroy(root);
}

template <class T>
std::string binaryTree<T>::inorderTraversal() const
{
    std::ostringstream out;
    inorder(root, out);
    return out.str();
}
template <class T>
std::string binaryTree<T>::preorderTraversal() const
{
    std::ostringstream out;
    preorder(root, out);
    return out.str();
}
template <class T>
std::string binaryTree<T>::postorderTraversal() const
{
    std::ostringstream out;
    postorder(root, out);
    return out.str();
}

template <class T>
void binaryTree<T>::copyTree(binaryNode<T> *&copiedTreeRoot, binaryNode<T> *otherTreeRoot)
{
    if (otherTreeRoot == nullptr)
        copiedTreeRoot = nullptr;
    else
    {
        copiedTreeRoot = new binaryNode<T>;
        copiedTreeRoot->data = new T(otherTreeRoot->data);
        copyTree(copiedTreeRoot->lTree, otherTreeRoot->lTree);
        copyTree(copiedTreeRoot->rTree, otherTreeRoot->rTree);
    }
}
template <class T>
void binaryTree<T>::destroy(binaryNode<T> *&p)
{
    if (p != nullptr)
    {
        destroy(p->lTree);
        destroy(p->rTree);
        delete p;
        p = nullptr;
    }
}
template <class T>
void binaryTree<T>::inorder(binaryNode<T> *p, std::ostringstream &out) const
{
    inorder(p->lTree);
    out << *(p->data) << "\n\n";
    inorder(p->rTree);
}
template <class T>
void binaryTree<T>::preorder(binaryNode<T> *p, std::ostringstream &out) const
{
    out << *(p->data) << "\n\n";
    preorder(p->lTree);
    preorder(p->rTree);
}
template <class T>
void binaryTree<T>::postorder(binaryNode<T> *p, std::ostringstream &out) const
{
    postorder(p->lTree);
    postorder(p->rTree);
    out << *(p->data) << "\n\n";
}
#endif