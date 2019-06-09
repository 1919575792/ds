#include <iostream>
using namespace std;
typedef struct{
    int row,col;
    int e;
}node;
typedef struct{
    node data[12500] ;//最多存储
    int m,n,len;
}matrix;

void inputmatrix(matrix *A,int r,int c){
    int i=1,j=0;
    while(i<=r*c){
        int e; cin>>e;
        if(e!=0){
            A->data[j].e = e;
            if(i%c != 0){
                A->data[j].row = i/c+1;
                A->data[j].col = i%c;
                j++;
            }
            else{
            A->data[j].row = i/c;
            A->data[j].col = c;
            j++;}
        }i++; A->len = j;

    }
}

void outputmatrix(matrix B,int r,int c){   //交换后A中的 rc 为B中的cr
    int t = 0;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(B.data[t].col==j && B.data[t].row == i){
                cout<<B.data[t].e<<' ';
                t++;
            }
            else{
                cout<<0<<' ';
            }
        }
        cout<<endl;
    }
} //  这里好乱   我自己已经晕了 。。。   回头在理一遍

void FastTransposeMatrix(matrix A,matrix *B){
    int i,j,k;
    B->len = A.len;
    B->n = A.m;
    B->m = A.n;
    if(B->len > 0){
        j =0;
        for(k=1;k<=A.n+1;k++)
            for(i=0;i<A.len;i++)
                if(A.data[i].col == k){
                    B->data[j].row =A.data[i].col;
                    B->data[j].col = A.data[i].row;
                    B->data[j].e = A.data[i].e;
                    j++;
                }

    }
}

int main(){
    matrix A,B;
    int r = 0,c = 0;
    cin>>r>>c;
    A.m = r; A.n= c;
    inputmatrix(&A,r,c);
    FastTransposeMatrix(A,&B);
    outputmatrix(B,c,r);
}