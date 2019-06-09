//希尔排序，不稳定，又称缩小增量排序法
//待排序数列基本有序且较少时效率高
#include <iostream>
using namespace std;

void shellInsort(int a[],int n,int delta){   // delta 增量 , 对子序列进行直接插入排序
    int i,j;
    for(i = 1+delta; i<=n;i++){
        if(a[i] < a[i-delta]){  //如果后者大于前者则不用换
            a[0] = a[i];    // 在这里r[0]不是哨岗,只是当中间变量
            for(j = i-delta; j>0&&a[0]<a[j]; j-=delta)  //找到插入点
                a[j+delta] = a[j];
            a[j+delta] = a[0];
         }
    }
    for (int k = 1; k <=n ; ++k) {
        cout<<a[k]<<' ';
    }
    cout<<endl;
}

void shellSort(int a[],int n,int delta[],int nd){
    for(int i = 0; i < nd; ++i)
        shellInsort(a,n,delta[i]);    //对每个d
}
int main() {
    int a[100]={1},n,d[3];
    for(int i=0;a[i]!=0;i++){
        cin>>a[i+1];
        n=i;
    }
    for (int j = 0; j < 3; ++j) {
        cin>>d[j];
    }

    shellSort(a,n,d,3);

}
