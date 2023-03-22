#include <iostream>

using std::endl;
using std::cout;
using std::cin;

int main(){
    short int* ptr = nullptr;
    ptr = new short int[10];
    for (short int i = 0; i < 10; i++){
        ptr[i] = i;
        cout << &ptr[i] << ' ';
    }
    cout << endl;
    for (short int i = 0; i < 10; i++){
        cout << *(ptr+i) << ' ';
    }
    cout << endl;
    for (short int i = 0; i < 10; i++){
        if (i%2 == 0){
            *(ptr+i) *= *(ptr+i);
        }
        cout << *(ptr+i) << ' ';
    }
    cout << endl;
    delete [] ptr;
    return 0;
}

//Лекция началась. Один студент опоздал. 
//Лектор: 
//- Почему вы опоздали? 
//- Я участвовал в соревнованиях по ралли. 
//Через некоторое время заходит ещё один студент. 
//Профессор спрашивает: 
//- Вы тоже с ралли? 
//Студент обалдело: 
//- Нет, я код без delete [] ptr писал...
//Ну и отчислили студента.