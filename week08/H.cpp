#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct Node{
    char key;
    Node* next = nullptr;
};

enum operators{
    bracket = 0,
    add = 1,
    mult = 2,
    un_minus = 3,
    failure = 4,
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

char pop(Node* &head){
    char curr = head->key;
    Node* tmp = head;
    head = head->next;
    delete tmp;
    return curr;
}

bool is_digit(char sym){
    if ((sym == '(') or (sym == ')') or
        (sym == '+') or (sym == '-') or
        (sym == '*') or (sym == '/')){
            return false;
        }
    return true;
}

int priority(char op){
    if ((op == '(') or (op == ')')){
        return bracket;
    }
    if ((op == '+') or (op == '-')){
        return add;
    }
    if ((op == '*') or (op == '/')){
        return mult;
    }
    if (op == '~'){
        return un_minus;
    }
    return failure;
}

int main(){
    Node* oper = nullptr;
    char tmp = std::getchar();
    char prev_tmp;
    while ((tmp != '\n') and (tmp != '\0')){
        if (is_digit(tmp)){
            cout << tmp << ' ';
        }
        else {
            if ((tmp == '-') and ((oper == nullptr) or 
            ((oper->key != ')') and (not is_digit(prev_tmp))))){
                tmp = '~';
            }
            char curr;
            while ((oper != nullptr) and (priority(oper->key) >= priority(tmp))
                    and (priority(tmp) > 0)){
                curr = pop(oper);
                cout << curr << ' ';
            }
            if (tmp == ')'){
                curr = pop(oper);
                while (curr != '('){
                    cout << curr << ' ';
                    curr = pop(oper);
                }
            } else {
                push_front(oper, tmp);
            }
        }
        prev_tmp = tmp;
        tmp = std::getchar();
    }
    while (oper != nullptr){
        tmp = pop(oper);
        cout << tmp;
        if (oper != nullptr){
            cout << ' ';
        }
    }
    cout << endl;
    return 0;
}