#include <iostream>
#include <string>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;

struct Node{
    char key;
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

char pop(Node* &head){
    char key;
    Node* tmp = head;
    head = head->next;
    key = tmp->key;
    delete tmp;
    return key;
}

int main(){
    Node* oper = nullptr;
    int n = 0;
    int* numb = nullptr;
    int cnt = 0;
    
    std::string line;
    std::string full;
    std::getline(std::cin, full);
    full.push_back(' ');
    std::istringstream ss(full);
    std::getline(ss, line, ' ');
    
    while (line != "stop"){
        if (line == "+"){
            push_front(oper, '+');
            n++;
        } else if (line == "*"){
            push_front(oper, '*');
            n++;
        } else {
            if (numb == nullptr){
                numb = new int[n+1];
            }
            numb[cnt] = std::stoi(line);
            cnt++;
        }
        std::getline(ss, line, ' ');
    }

    int value = numb[0];
    cnt = 1;
    char op;
    while (oper != nullptr){
        op = pop(oper);
        if (op == '+'){
            value += numb[cnt];
        } else if (op == '*'){
            value *= numb[cnt];
        }
        cnt++;
    }
    cout << value << endl;
    delete [] numb;
    return 0;
}