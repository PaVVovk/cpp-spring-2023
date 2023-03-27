#include <iostream>

using std::cout;
using std::cin;
using std::endl;

struct Road{
    int x1;
    int y1;
    int x2;
    int y2;
};

Road get_road(){
    Road road;
    cin >> road.x1 >> road.y1 
        >> road.x2 >> road.y2;
    return road;
}

bool proj_check(Road r_1, Road r_2){
    bool flag_x = false;
    if ((std::max(r_1.x1, r_1.x2) >= std::min(r_2.x1, r_2.x2)) 
        and (std::max(r_2.x1, r_2.x2) >= std::min(r_1.x1, r_1.x2))){
            flag_x = true;
        }
    bool flag_y = false;
    if ((std::max(r_1.y1, r_1.y2) >= std::min(r_2.y1, r_2.y2)) 
        and (std::max(r_2.y1, r_2.y2) >= std::min(r_1.y1, r_1.y2))){
            flag_y = true;
        }
    return (flag_x and flag_y);
}

bool dot_pos(Road c_road, Road road){
    int A = road.y1 - road.y2;
    int B = road.x2 - road.x1;
    int C = - A*road.x1 - B*road.y1;
    int dot1 = A*c_road.x1 + B*c_road.y1 + C;
    int dot2 = A*c_road.x2 + B*c_road.y2 + C;
    if ((dot1 == 0) and (dot2 == 0)){
        return proj_check(c_road, road);
    } else if (dot1*dot2 <= 0){
        return true;
    }
    return false;
}

void cross(Road road1, Road road2){
//Чтобы понять, пересекаются ли отрезки, нужно проверить, лежат ли
//точки каждого отрезка по одну или по разные стороны от другого
//(отдельный случай - когда отрезки лежат на одной прямой). 
//Для этого надо подставить их в уравнение прямой, на которой лежит
//отрезок, и сравнить знаки.
    bool num1 = dot_pos(road1, road2);
    bool num2 = dot_pos(road2, road1);
    if (num1 and num2){
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}


int main(){
    Road road1 = get_road();
    Road road2 = get_road();
    cross(road1, road2);    
    return 0;
}