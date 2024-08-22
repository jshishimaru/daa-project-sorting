#include <iostream>
#include <ctime>
#include <fstream>
#include <vector>
#include "sortings.h"

using namespace std;

double time_sorting( int *a , int n , void (*sort)( int *a , int n)){
    clock_t start = clock();
    sort(a,n);
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}


int main(){

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    int *a = new int[n];
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int *b = new int[n];

    copy(a,a+n,b);

    double time = time_sorting(b,n,sort1);
    cout << "Time of sorting 1: " << time << "s" << endl;

    copy(a,a+n,b);

    time = time_sorting(b,n,sort2);
    cout << "Time of sorting 2: " << time << "s" << endl;

    copy(a,a+n,b);

    time = time_sorting(b,n,sort3);
    cout << "Time of sorting 3: " << time << "s" << endl;

    copy(a,a+n,b);

    time = time_sorting(b,n,sort4);
    cout << "Time of sorting 4: " << time << "s" << endl;

    copy(a,a+n,b);

    time = time_sorting(b,n,sort5);
    cout << "Time of sorting 5: " << time << "s" << endl;

}