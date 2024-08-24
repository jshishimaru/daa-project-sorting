#include <iostream>
#include <ctime>
#include <fstream>
#include <vector>
#include <algorithm>
#include "sortings.h"

using namespace std;

double time_sorting( int *a , int n , void (*sort)( int *a , int n)){
    clock_t start = clock();

    int *b = new int[n];
    for( int i=0 ; i<5 ; ++i){
    
        copy(a,a+n,b);
        sort(b,n);
    
    }
    clock_t end = clock();
    return (double)(end - start) / (CLOCKS_PER_SEC * (double)5);
}

typedef void (*sort_function)(int *a, int n);

int main(){

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; // number of input arrays
    cin>>t;

    int n;
    cin >> n;

    int *a = new int[n];

    sort_function sort_functions[] = {sort1,sort2,sort3,sort4,sort5};

    // first test with randomized input array
    cout << "For Randomized input array" << endl << endl;
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector <pair <double,pair<sort_function,int>>> times;

    double time = time_sorting(a,n,sort_functions[0]);
    times.push_back({time,{sort_functions[0] , 1 } });

    time = time_sorting(a,n,sort_functions[1]);
    times.push_back({time,{sort_functions[1] , 2 } });

    time = time_sorting(a,n,sort_functions[2]);
    times.push_back({time,{sort_functions[2] , 3 } });

    time = time_sorting(a,n,sort_functions[3]);
    times.push_back({time,{sort_functions[3] , 4 } });

    time = time_sorting(a,n,sort_functions[4]);
    times.push_back({time,{sort_functions[4] , 5 } });

    sort(times.begin(),times.end());

    vector <pair<double,pair<sort_function,int>>> nlogn_alogrithms;
    nlogn_alogrithms.push_back(times[0]);
    nlogn_alogrithms.push_back(times[1]);

    vector <pair<double,pair<sort_function,int>>> linear_alogrithms;
    linear_alogrithms.push_back(times[2]);
    linear_alogrithms.push_back(times[3]);
    linear_alogrithms.push_back(times[4]);

    for( auto p : nlogn_alogrithms ){
        cout << "Algorithm " << p.second.second << " took " << p.first << " seconds on avg and is a nlogn algorithm" << endl;
    }
    for( auto p : linear_alogrithms ){
        cout << "Algorithm " << p.second.second << " took " << p.first << " seconds on avg and is a linear algorithm" << endl;
    }
    cout << endl << endl;

    // second test with sorted input array
    // with sorted array we can diffrentiate bw merge sort and quick sort

    cout << "For Sorted input array" << endl << endl;

    for(int i = 0; i < n; i++){
        cin>>a[i];
    }

    times.clear();

    time = time_sorting(a,n,nlogn_alogrithms[0].second.first);
    times.push_back({time,nlogn_alogrithms[0].second });

    time = time_sorting(a,n,nlogn_alogrithms[1].second.first);
    times.push_back({time,nlogn_alogrithms[1].second });

    sort(times.begin(),times.end());

    cout << "Algorithm " << times[0].second.second << " took " << times[0].first << " seconds on avg and is a merge sort" << endl;
    cout << "Algorithm " << times[1].second.second << " took " << times[1].first << " seconds on avg and is a quick sort" << endl;

    times.clear();
    time = time_sorting(a,n,linear_alogrithms[0].second.first);
    times.push_back({time,linear_alogrithms[0].second });

    time = time_sorting(a,n,linear_alogrithms[1].second.first);
    times.push_back({time,linear_alogrithms[1].second });

    time = time_sorting(a,n,linear_alogrithms[2].second.first);
    times.push_back({time,linear_alogrithms[2].second });

    sort(times.begin(),times.end());

    cout << "Algorithm " << times[2].second.second << " took " << times[2].first << " seconds on avg and is a selection sort" << endl;
    for(auto x : linear_alogrithms){
        if( x.second.second == times[2].second.second ){
                    linear_alogrithms.erase(find(linear_alogrithms.begin(),linear_alogrithms.end(),x));       
        }
    }
    cout << endl << endl;

    times.clear();

    //operating on partial sorted array
    cout << "For Partially Sorted input array" << endl << endl;
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }

    time = time_sorting(a,n,linear_alogrithms[0].second.first);
    times.push_back({time,linear_alogrithms[0].second });

    time = time_sorting(a,n,linear_alogrithms[1].second.first);
    times.push_back({time,linear_alogrithms[1].second });

    sort(times.begin(),times.end());

    cout << "Algorithm " << times[0].second.second << " took " << times[0].first << " seconds on avg and is a insertion sort" << endl;
    cout << "Algorithm " << times[1].second.second << " took " << times[1].first << " seconds on avg and is a bubble sort" << endl;

}