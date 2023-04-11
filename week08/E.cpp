#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct Node{
    char key = 0;
    Node* next = nullptr;
};

enum brackets{
    round = 0,
    figure = 1,
    square = 2,
    triang = 3,
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

int br_type(char sym){
    if ((sym == ')') or ((sym == '('))){
        return round;
    }
    if ((sym == '>') or ((sym == '<'))){
        return triang;
    }
    if ((sym == '}') or ((sym == '{'))){
        return figure;
    }
    if ((sym == ']') or ((sym == '['))){
        return square;
    }
    return -1; //чтобы не было warning-а о потенциальном возвращении пустоты
}

bool left_br(char sym){
    return ((sym == '(') or (sym == '<')
    or (sym == '{') or (sym == '['));
}

bool right_br(char sym){
    return ((sym == ')') or (sym == '>')
    or (sym == '}') or (sym == ']'));
}
//2 функции - для защиты от появления нескобочных символов в строке

void check_brackets(){
    char tmp;
    Node* head = nullptr;
    tmp = std::getchar();
    while ((tmp != '\0') && (tmp != '\n')){
        if (left_br(tmp)){
            push_front(head, tmp);
        } else if (right_br(tmp)){
            if ((head == nullptr) or (br_type(tmp) != br_type(head->key))){
                cout << "NO" << endl;
                destroy_list(head);
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