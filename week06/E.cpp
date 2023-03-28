#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct Line{
    int x1;
    int x2;
};

Line get_line(){
    Line line;
    cin >> line.x1 >> line.x2;
    if (line.x1 > line.x2){
        int tmp = line.x1;
        line.x1 = line.x2;
        line.x2 = tmp;
    }
    return line;
}

void common_dot(Line* lines, int len){
    int min_right = lines[0].x2;
    int max_left = lines[0].x1;
    for (int i = 1; i < len; i++){
        if (lines[i].x2 < min_right){
            min_right = lines[i].x2;
        }
        if (lines[i].x1 > max_left){
            max_left = lines[i].x1;
        }
    }
    if (max_left <= min_right){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main(){
    int N = 0;
    cin >> N;
    Line* lines = new Line[N];
    for (int i = 0; i < N; i++){
        lines[i] = get_line();
    }
    common_dot(lines, N);
    delete [] lines;
    return 0;
}