#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct Node{
    char key = 0;
    Node* next = nullptr;
};

void push_front(Node* &head, char new_key){
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

void pop(Node* &head){
    if (head == nullptr){
        return;
    }
    Node* tmp = head;
    head = head->next;
    delete tmp;
}

void destroy_list(Node* &head_ref){
    Node* tmp_ptr = head_ref;
    while (head_ref != nullptr){
        head_ref = tmp_ptr->next;
        delete tmp_ptr;
        tmp_ptr = head_ref;
    }
}

void check_brackets(){
    char tmp;
    Node* head = nullptr;
    tmp = std::getchar();
    while ((tmp != '\0') && (tmp != '\n')){
        if (tmp == '('){
            push_front(head, tmp);
        } else if (tmp == ')'){
            if (head == nullptr){
                 cout << "NO" << endl;
                 return;
            } else {
                pop(head);
            }
        }
        tmp = std::getchar();
    }
    if (head == nullptr){
        cout << "YES" << endl;
    } else {
    cout << "NO" << endl;
    }
    destroy_list(head);
}

int main(){
    check_brackets();
    return 0;
}