#include <iostream>

using std::endl;
using std::cout;
using std::cin;

void subseq(int* seq, int len){
    int* d = new int[len]; 
    int* p = new int[len];
    int m_len = 0;
    int pos = 0;
    for (int i = 0; i < len; i++){
        d[i] = 1;
        p[i] = -1;
        for (int j = 0; j < i; j++){
            if (seq[j] < seq[i]){
                if (d[j] > d[i] - 1){
                    d[i] = d[j] + 1;
                    p[i] = j;
                }
            }
        }
        if (d[i] >= m_len){
            m_len = d[i];
            pos = i;
        }
    }
    while (pos != -1){
        cout << seq[pos] << ' ';
        pos = p[pos];
    }
    cout << m_len << endl;
    delete [] d;
    delete [] p;
}

int main(){
    int n = 0;
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    subseq(a, n);
    delete [] a;
    return 0;
}