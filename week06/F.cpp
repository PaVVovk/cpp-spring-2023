#include <iostream>

using std::cout;
using std::cin;
using std::endl;

enum Status {
    CNT = 100,
    OK = 200,
    CRT = 201,
    ACC = 202,
    BRQ = 400,
    UNA = 401,
    NF = 404,
    MNA = 405,
    ISE = 500,
    NI = 501,
    BGA = 502,
};

void print_error(int st){
    switch (st){
        case CNT:
            cout << "Continue" << endl;
            break;
        case OK:
            cout << "OK" << endl;
            break;
        case CRT:
            cout << "Created" << endl;
            break;
        case ACC:
            cout << "Accepted" << endl;
            break;
        case BRQ:
            cout << "Bad Request" << endl;
            break;
        case UNA:
            cout << "Unauthorized" << endl;
            break;
        case NF:
            cout << "Not Found" << endl;
            break;
        case MNA:
            cout << "Method Not Allowed" << endl;
            break;
        case ISE:
            cout << "Internal Server Error" << endl;
            break;
        case NI:
            cout << "Not Implemented" << endl;
            break;
        case BGA:
            cout << "Bad Gateaway" << endl;
            break;        
    }
}

void resize(int* &arr, int &len, int new_len){
    int* new_arr = new int[new_len];
    for (int i = 0; i < len; i++){
        new_arr[i] = arr[i];
    }
    delete [] arr;
    arr = new_arr;
    len = new_len;
}

int main(){
    int* arr = new int[1];
    int len = 0;
    int elem = 0;
    cin >> elem;
    while (elem != 0){
        resize(arr, len, len+1);
        arr[len-1] = elem;
        cin >> elem;
    }
    for (int i = 0; i < len; i++){
        print_error(arr[i]);
    }
    delete [] arr;
    return 0;
}