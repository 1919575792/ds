#include <iostream>

using namespace std;

/* 堆排序思路
 * 1. 构造大顶堆(升序排序)
 * 2.堆顶与末尾元素交换，将最大元素沉到最后
 * 去掉最大元素重建大顶堆
 * 反复 */

void sift(int a[], int low, int high) {
    // 调整堆的函数 ，low 为根节点
    int f,i;
    for(f = low, i = 2*low+1;i<=high;i=i*2+1 ){ //f为被调整节点，low从0开始
        //先判断左右孩子的大小
        if(i<high && a[i]<a[i+1])  //  如果右孩子比左孩子大 i<high 很重要
            i++;
        if(a[f]>a[i]) // 不用调整
            break;

        int z = a[f];
        a[f] = a[i];
        a[i] = z;
        f = i;  //调整，i成为新的节点
    }
}

void crt_heap(int a[], int n) {  // 初始创建堆的函数,倒着创建
    for (int i = n-2 / 2; i >= 0; --i) {
        sift(a, i, n-1);
    }
}

void HeapSort(int a[], int n) {
    int f;
    crt_heap(a, n);
    for (int k = 0; k < n; ++k )
        cout << a[k] << ' ';
    cout << endl;
    for (int i = n-1; i > 0; --i) {
        f = a[0];
        a[0] = a[i];
        a[i] = f;
        sift(a, 0, i - 1);
        for (int k = 0; k < n; ++k )
            cout << a[k] << ' ';
        cout << endl;
    }
}

int main() {
    int a[10000] , n = 0;

    cin>>a[0];
    for (int i = 0; a[i] != 0; ++i) {
        cin >> a[i + 1];
        n = i;
    }
    HeapSort(a, n+1);
}

