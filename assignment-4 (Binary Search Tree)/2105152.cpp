#include"2105152.h"

using namespace std;

template <typename T>
BSTnode<T>::BSTnode(){
    key=0;
}

template <typename T>
BSTnode<T>* BSTnode<T>::tree(T& key) {
    BSTnode<T>* n = new BSTnode<T>;
    n->key = key;
    n->left = NULL;
    n->right = NULL;
    return n;
}

template <typename T>
BSTnode<T>* BSTnode<T>::insert(BSTnode<T>* root,T& key) {
    if (root == NULL) {
        root = tree(key);
    } else if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}

template <typename T>
BSTnode<T>* BSTnode<T>::find(BSTnode<T>* n) {
    BSTnode<T>* curr = n;
    while (curr && curr->left != NULL) {
        curr = curr->left;
    }
    return curr;
}

template <typename T>
BSTnode<T>* BSTnode<T>:: deleteN(BSTnode<T>* root,T& key) {
    if (root == NULL) {
        return root;
    } else if (key < root->key) {
        root->left = deleteN(root->left, key);
    } else if (key > root->key) {
        root->right = deleteN(root->right, key);
    } else {
        if (root->left == NULL && root->right ==NULL) {
            delete root;
            root = NULL;
        } else if (root->left == NULL) {
            BSTnode<T>* temp = root;
            root = root->right;
            delete temp;
        } else if (root->right == NULL) {
            BSTnode<T>* temp = root;
            root = root->left;
            delete temp;
        } else {
            BSTnode<T>* temp2= find(root->right);
            root->key = temp2->key;
            root->right = deleteN(root->right, temp2->key);
        }
    }
    return root;
}

template <typename T>
bool BSTnode<T>:: search(BSTnode<T>* root,T& key) {
    if (root == NULL) {
        return false;
    } else if (root->key == key) {
        return true;
    } else if (key < root->key) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

template <typename T>
void BSTnode<T>::display(BSTnode<T>* root, ofstream& print) {
    if (root == NULL) {
        return;
    }
    print << root->key;
    if (root->left != NULL || root->right != NULL) {
        print << "(";
        display(root->left, print);
        print << ",";
        display(root->right, print);
        print << ")";
    }
}


template <typename T>
void BSTnode<T>::inorder(BSTnode<T>* root, ofstream& print) {
    if (root != NULL) {
    inorder(root->left,print);
    print << root->key << " ";
    inorder(root->right,print);
    }
    return;
}

template <typename T>
void BSTnode<T>::preorder(BSTnode<T>* root, ofstream& print) {
    if (root != NULL) {    
    print << root->key <<" ";
    preorder(root->left, print);
    preorder(root->right,print);
    }
    return;
}

template <typename T>
void BSTnode<T>::postorder(BSTnode<T>* root, ofstream& print) {
    if (root != NULL) {
     postorder(root->left, print);
    postorder(root->right, print);
    print << root->key <<" ";
    }
    return;
}
