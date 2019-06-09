#include <iostream>
#include  <time.h>
#include<cstdlib>
using namespace std;

// bubble sort
void bubbleSort(int *a,int n){
    for (int i = n; i >1 ; i--) {
        int f=0;
        for(int j = 1; j < i; j++){
            if(a[j]>a[j+1]){
                f = a[j];
                a[j] = a[j+1];
                a[j+1] = f;
                f = 1;
            }
        }
        if(!f) break;
    }
    /*  for (int i = 0;i<n ; ++i) {
          cout<<a[i+1]<<' ';
      }*/
}

void Shakersort(int *a,int n)
{
    int left = 1, right = n, f = 1;
    int i;
    while (left < right)
    {
        for (i = left; i < right; i++)
        {
            if (a[i] > a[i+1])
            {   int t = a[i];
                a[i] = a[i+1];
                a[i+1] = t;
                f = i;
            }
        }
        right = f;
        for (i = right-1; i >= left; i--)
        {
            if (a[i] > a[i+1])
            {
                int t = a[i];
                a[i] = a[i+1];
                a[i+1] = t;
                f = i + 1;
            }
        }
        left = f;
    }
    /*for (int i = 0;i<n ; ++i)
        cout<<a[i+1]<<' ';*/
}

int QKpass(int *a,int low,int high){
    int x = a[low];
    while(low <high){
        while(low<high && a[high] > x)
            high --;
        if(low < high) {a[low] = a[high];low ++;}
        while(low<high && a[low] < x)
            low ++;
        if(low < high) {a[high] = a[low];high --;}
    }
    a[low] = x;
    return low;
}

void QS(int *a, int low, int high){
    int pos;
    if(low < high){
        pos = QKpass(a,low,high);
        QS(a,low,pos-1);
        QS(a,pos+1,high);
    }

}

int main() {

    int a[10000]={1},n = 10000;
    for (int i = 1;i<=10000; ++i) {
        a[i] = rand();
    }


    clock_t start1 = clock();
    bubbleSort(a,n);
    clock_t end1 = clock();
    cout<<endl<<"冒泡： "<<end1-start1<<"ms"<<endl;

    clock_t start2 = clock();
    Shakersort(a,n);
    clock_t end2 = clock();
    cout<<endl<<"双向冒泡： "<<end2-start2<<"ms"<<endl;


    clock_t start3 = clock();
    QS(a,1,n);
    clock_t end3 = clock();
    /*for (int i = 0;i< n ; ++i)
        cout<<a[i+1]<<' ';*/
    cout<<endl<<"快速排序： "<<end3-start3<<"ms"<<endl;

}



