#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

struct Node{
    std::string key;
    Node* next = nullptr;
};

void destroy_list(Node* &head_ref){
    if (head_ref == nullptr){
        return;
    }
    Node* tmp_ptr = head_ref;
    Node* tmp_ptr2 = tmp_ptr;
    while (tmp_ptr->next != head_ref){
        tmp_ptr2 = tmp_ptr;
        tmp_ptr = tmp_ptr->next;
        delete tmp_ptr2;
    }
    delete tmp_ptr;
}

void push_back_cycle(Node* &head, std::string new_key){
    if (head == nullptr){
        head = new Node;
        head->key = new_key;
        head->next = head;
        return;
    }
    Node* current = head;
    while (current->next != head){
        current = current->next;
    }
    current->next = new Node;
    current->next->next = head;
    current->next->key = new_key;
}

Node* read_list(Node* head=nullptr){
    std::string tmp;
    int len = 0;
    cin >> len;
    while (len > 0){
        cin >> tmp;
        push_back_cycle(head, tmp);
        len--;
    }
    return head;
}

std::string remove_k(Node*& head_ref, int k){
    Node* tmp =  head_ref;
    if (tmp == tmp->next){
        std::string nm = tmp->next->key;
        return nm;
    }
    for (int i = 0; i < k-2; i++){
        tmp = tmp->next;
    }
    head_ref = tmp->next->next;
    std::string nm = tmp->next->key;
    delete tmp->next;
    tmp->next = head_ref;
    return nm;
}

int flav(Node* &head, int k, std::string name){
    int step = 1;
    std::string nm = remove_k(head, k);
    while (nm != name){
        nm = remove_k(head, k);
        step++;
    }
    return step;
}

int main(){
    Node* head = read_list();
    int k = 0;
    cin >> k;
    std::string imposter;
    cin >> imposter;
    cout << flav(head, k, imposter) << endl;
    destroy_list(head);
    return 0;
}