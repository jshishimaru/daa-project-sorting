#ifndef SORTINGS_H
#define SORTINGS_H

void sort1( int *a , int n ){ // selection sort 

    for( int i = 0 ; i < n ; i++ ){
        int min = i;
        for( int j = i+1 ; j < n ; j++ ){
            if( a[j] < a[min] ){
                min = j;
            }
        }
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }

}

void sort2( int *a , int n ){ // bubble sort

    for( int i = 0 ; i < n ; i++ ){
        for( int j = 0 ; j < n-i-1 ; j++ ){
            if( a[j] > a[j+1] ){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

}

void sort3( int *a , int n ){ // insertion sort

    for( int i = 1 ; i < n ; i++ ){
        int key = a[i];
        int j = i-1;
        while( j >= 0 && a[j] > key ){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }

}

void sort4( int *a , int n){ //merge sort 

    if( n > 1 ){
        int mid = n/2;
        int *left = new int[mid];
        int *right = new int[n-mid];
        for( int i = 0 ; i < mid ; i++ ){
            left[i] = a[i];
        }
        for( int i = mid ; i < n ; i++ ){
            right[i-mid] = a[i];
        }
        sort4( left , mid );
        sort4( right , n-mid );
        int i = 0 , j = 0 , k = 0;
        while( i < mid && j < n-mid ){
            if( left[i] < right[j] ){
                a[k] = left[i];
                i++;
            }
            else{
                a[k] = right[j];
                j++;
            }
            k++;
        }
        while( i < mid ){
            a[k] = left[i];
            i++;
            k++;
        }
        while( j < n-mid ){
            a[k] = right[j];
            j++;
            k++;
        }
        delete[] left;
        delete[] right;
    }

}

void sort5( int *a , int n ){ // quick sort with first element as pivot

    if( n > 1 ){
        int pivot = a[0];
        int i = 1;
        int j = n-1;
        while( i <= j ){
            while( i < n && a[i] <= pivot ){
                i++;
            }
            while( j > 0 && a[j] > pivot ){
                j--;
            }
            if( i < j ){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        int temp = a[0];
        a[0] = a[j];
        a[j] = temp;
        sort5( a , j );
        sort5( a+j+1 , n-j-1 );
    }

}
    
        

#endif