#include <iostream>

using std::endl;
using std::cout;
using std::cin;

struct Node{
    int key = 0;
    Node* next = nullptr;
};

void push_back(Node* &head, int new_key){
    if (head == nullptr){
        head = new Node;
        head->key = new_key;
        return;
    }
    Node* current = head;
    while (current->next != nullptr){
        current = current->next;
    }
    current->next = new Node;
    current->next->key = new_key;
}

void push_front(Node* &head, int new_key){
    if (head == nullptr){
        head = new Node;
        head->key = new_key;
        return;
    }
    Node* new_node = new Node;
    new_node->key = new_key;
    new_node->next = head;
    head = new_node;
}

void insert_after(Node*& prev_ref, int new_key){
    Node* new_node = new Node;
    if (prev_ref == nullptr){
        delete new_node;
        return;
    }
    new_node->key = new_key;
    new_node->next = prev_ref->next;
    prev_ref->next = new_node;
}

void destroy_list(Node* &head_ref){
    Node* tmp_ptr = head_ref;
    while (head_ref != nullptr){
        head_ref = tmp_ptr->next;
        delete tmp_ptr;
        tmp_ptr = head_ref;
    }
}

void print_list(Node* head_ref){
    while(head_ref != nullptr){
        cout << head_ref->key;
        if (head_ref->next != nullptr){
            cout << ' ';
        }
        head_ref = head_ref->next;
    }
    cout << endl;
}

Node* find(Node* head_ref, int key){
    while ((head_ref != nullptr) and (head_ref->key != key)){
        head_ref = head_ref->next;
    }
    return head_ref;
}

void remove_key(Node*& head_ref, int key){
    Node* tmp =  head_ref;
    if (tmp == nullptr){
        return;
    }
    if (tmp->key == key){
        delete head_ref;
        head_ref = tmp->next;
        return;
    }
    while ((tmp->next != nullptr) and (tmp->next->key != key)){
        tmp = tmp->next;
    }
    if (tmp->next != nullptr){
        Node* tmp2 = tmp->next;
        tmp->next = tmp2->next;
        delete tmp2;
    }
}

int main(){
    return 0;
}