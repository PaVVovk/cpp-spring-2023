#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

struct Atom{
    std::string name;
    int A = 0;
    int Z = 0;
};

struct React{
    std::string name;
    std::string reac;
};

void react(Atom* atoms, int a_len, React r){
    int i = 0;
    while ((i < a_len) and (r.name != atoms[i].name)){
        i++;
    }
    if (i == a_len){
        cout << "NO DATA ";
        return;
    }
    Atom* new_atom = new Atom;
    if (r.reac == "alpha"){
        new_atom->A = atoms[i].A - 4;
        new_atom->Z = atoms[i].Z - 2;
    } else if (r.reac == "beta+"){
        new_atom->A = atoms[i].A;
        new_atom->Z = atoms[i].Z - 1;
    } else if (r.reac == "beta-"){
        new_atom->A = atoms[i].A;
        new_atom->Z = atoms[i].Z + 1;
    }
    i = 0;
    while ((i < a_len) and not((new_atom->A == atoms[i].A) and (new_atom->Z == atoms[i].Z))){
        i++;
    }
    if (i == a_len){
        cout << "NO DATA ";
    } else {
        cout << atoms[i].name << ' ';
    }
    delete new_atom;
}

int main(){
    int N = 0;
    cin >> N;
    Atom* atoms = new Atom[N];
    for (int i = 0; i < N; i++){
        cin >> atoms[i].name >> atoms[i].A >> atoms[i].Z;
    }
    
    int M = 0;
    cin >> M;
    React* rect = new React[M];
    for (int i = 0; i < M; i++){
        cin >> rect[i].name >> rect[i].reac;
    }
    for (int i = 0; i < M; i++){
        react(atoms, N, rect[i]);
    }

    delete [] atoms;
    delete [] rect;
    return 0;
}