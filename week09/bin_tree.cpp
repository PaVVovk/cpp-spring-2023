#include <iostream>
#include <iomanip>

using std::endl;
using std::cout;
using std::cin;

enum colors{black, red};

struct Node{
    int value = 0;
    Node* left = nullptr;
    Node* right = nullptr;

    //Я РУССКИЙ
    //Я ИДУ ДО КОНЦА
    //Я РУССКИЙ
    //МОЯ КРОВЬ ОТ ОТЦААА
    Node* parent = nullptr;
    bool color = black;
};

Node* create_node(int value=0){
    Node* node = new Node{};
    node->value = value;
    return node;
}

Node* grandpa(Node* node){
    if ((node != nullptr) && (node->parent != nullptr)){
        return node->parent->parent;
    }
    return nullptr;
}

Node* uncle(Node* node){
    Node* grand = grandpa(node);
    if (grand != nullptr){
        if (grand->left != node->parent){
            return grand->left;
        }
        return grand->right;
    }
    return nullptr;
}

bool is_left(Node* child){
    if (child->parent == nullptr){
        return false;
    }
    return (child->parent->left == child);
}

void rotate_left(Node* n){
    Node* pivot = n->right;
    pivot->parent = n->parent; /* при этом, возможно, pivot становится корнем дерева */
    if (pivot->parent != nullptr) {
        if (n->parent->left == n)
            n->parent->left = pivot;
        else
            n->parent->right = pivot;
    }		
	
    n->right = pivot->left;
    if (pivot->left != nullptr)
        pivot->left->parent = n;

    n->parent = pivot;
    pivot->left = n;
}

void rotate_right(Node* n){
    Node* pivot = n->left;
    pivot->parent = n->parent; /* при этом, возможно, pivot становится корнем дерева */
    if (n->parent != nullptr) {
        if (n->parent->left==n)
            n->parent->left = pivot;
        else
            n->parent->right = pivot;
    }		
	
    n->left = pivot->right;
    if (pivot->right != nullptr)
        pivot->right->parent = n;

    n->parent = pivot;
    pivot->right = n;
}

void change_color(Node* &leaf){
    leaf->color = red;
    if (leaf->parent == nullptr){
        leaf->color = black;
        return;
    }
    if ((leaf->parent->color == red) && ((uncle(leaf) != nullptr) && (uncle(leaf)->color == red))){
        leaf->parent->color = black;
        uncle(leaf)->color = black;
        change_color(leaf->parent->parent);
        return;
    }
    if ((leaf->parent->color == red) && ((uncle(leaf) == nullptr) or (uncle(leaf)->color == black))
        && (is_left(leaf) != is_left(leaf->parent))){
        if (is_left(leaf)){
            rotate_right(leaf->parent);
            leaf = leaf->right;
        } else {
            rotate_left(leaf->parent);
            leaf = leaf->left;
        }
    }
    if ((leaf->parent->color == red) && ((uncle(leaf) == nullptr) or (uncle(leaf)->color == black))
        && (is_left(leaf) == is_left(leaf->parent))){
            leaf->parent->color = black;
            grandpa(leaf)->color = red;
            if (is_left(leaf)){
                rotate_right(leaf->parent->parent);
            } else {
                rotate_left(leaf->parent->parent);
            }
    }
}

void print_tree(Node* tree, int padding = 0) {//Функция вывода данных узла
    if (tree != nullptr) {
        cout << std::setw(padding) << ' ' << std::setw(0) << " ["<< tree->value << "] " << endl;
        padding += 2;
        print_tree(tree->left, padding); //левое поддерево
        print_tree(tree->right, padding); //правое поддерево
    }
}

Node* head_found(Node* p)
{
    while (p->parent != nullptr)
        p = p->parent;
    return p;
}

void insert(Node* &tree, int value){
    Node* leaf = create_node(value);
    if (tree == nullptr){
        tree = leaf;
        return;
    }
    Node* tmp = tree;
    Node* parent = nullptr;
    while (tmp != nullptr){
        parent = tmp;
        if (value < tmp->value){
            tmp = tmp->left;
        } else {
            tmp = tmp->right;
        }
    }
    leaf->parent = parent;
    if (value < parent->value){
        parent->left = leaf;
    } else {
        parent->right = leaf;
    }
    change_color(leaf);
    tree = head_found(tree);
}

int min_tree(Node* tree){
    if (tree == nullptr){
        return 0;
    }
    while (tree->left != nullptr){
        tree = tree->left;
    }
    return tree->value;
}

int max_tree(Node* tree){
    if (tree == nullptr){
        return 0;
    }
    while (tree->right != nullptr){
        tree = tree->right;
    }
    return tree->value;
}

int tree_height(Node* tree){
    int h = 0;
    while (tree != nullptr){
        if (tree->color == black){
            h++;
        }
        tree = tree->left;
    }
    return h;
}

int main(){
    Node* tree = nullptr;
    for (int i = 0; i < 12; i++){
        insert(tree, i);
    }
    print_tree(tree);
    return 0;
}