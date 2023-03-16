# include <iostream>
# include <fstream>
# include <chrono>
# include <random>

using std::endl;
using std::cout;
using std::cin;

int swaps = 0;

void swap(int& lha, int& rha){
    int tmp = lha;
    lha = rha;
    rha = tmp;
    swaps++;
}

void record(double time, int N){
    std::ofstream out("data_time.txt", std::ios::app);
    if (out.is_open())
    {
        out << N << " " << time << "\n";
    }
    out.close();
}

void record(int sw, int N){
    std::ofstream out("data_swap.txt", std::ios::app);
    if (out.is_open())
    {
        out << N << " " << sw << "\n";
    }
    out.close();
}

void step_check(int* arr, int len, int step){
    for (int i = 0; i < len - step; i+=step){
        if (arr[i] > arr[i+step]){
            swap(arr[i], arr[i+step]);
        }
    }
}

void brush_sort(int* arr, int len, int step){
    while (step > 0){
        step_check(arr, len, step);
        step /= 2;
    }
}

int main(){
    double time1 = 0;
    unsigned seed = 1001;
    int s_count = 250;
    for (int m = 10; m<5500; m += 100){
        time1 = 0;
        int* a = new int[m];

        std::default_random_engine rng(seed);
        std::uniform_int_distribution<unsigned> dstr(0, m);

        for (int i = 0; i < m; i++){
            a[i] = dstr(rng);
        }

        for(int i = 0; i < s_count; i++){
            auto begin = std::chrono::steady_clock::now();
            brush_sort(a, m, m-1);
            auto end = std::chrono::steady_clock::now();
  
            auto time_span = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
            time1 += time_span.count();
            }

        record(time1/s_count, m);
        record(swaps/s_count, m);
        swaps = 0;
        delete [] a;
    }

    return 0;
}
