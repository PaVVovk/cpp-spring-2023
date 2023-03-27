#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

struct Students{
    std::string name;
    int score;
};

int main(){
    int N = 10;
    Students* st = new Students[N];
    for (int i = 0; i < N; i++){
        cin >> st[i].name >> st[i].score;
    }
    int M = 0;
    cin >> M;
    for (int i = 0; i < N; i++){
        if (st[i].score >= M){
            cout << st[i].name << ' ';
        }
    }
    cout << endl;
    delete [] st;
    return 0;
}