#include<iostream>
#include <malloc.h>
#include <cstring>
using namespace std;

typedef struct{
    int weight;
    int parent;
    int LChild;
    int RChild;
}HTNode,HuffmanTree[100000];
typedef char* HuffmanCode[100000];
void select(HuffmanTree ht,int i,int* s1,int* s2){
    int n=1;
    HTNode temp = ht[0];

    for(int m = 1;m <= i;m++){
        if(ht[m].parent==0 && ht[m].weight<temp.weight) {*s1 = m;
        temp = ht[m];
        }
    }

    int j=1;
    while(ht[j].parent != 0 || j==*s1)    j++;
    temp = ht[0];
    for(int k = 1;k <= i;k++){
        if(ht[k].parent==0 && ht[k].weight<temp.weight && k!=*s1) {*s2 = k;
        temp = ht[k];
        }
    }
}

void CrtHuffmanTree(HuffmanTree ht,int w[],int n){
    ht[0].weight = 10000;
    ht[0].parent = 0;
    ht[0].LChild = 0;
    ht[0].RChild = 0;
    for(int i = 1;i <= n;i++){
        ht[i].weight = w[i];
        ht[i].parent = 0;
        ht[i].LChild = 0;
        ht[i].RChild = 0;
    }
    int m=2*n-1;
    for(int i = n+1;i <= m;i++){
        ht[i].weight = 0;
        ht[i].LChild = 0;
        ht[i].RChild = 0;
        ht[i].parent = 0;
    }
    int s1,s2;
    for(int i = n+1;i <= m;i++){
    select(ht,i-1,&s1,&s2);
    ht[i].weight = ht[s1].weight+ht[s2].weight;
    ht[s1].parent = i; ht[s2].parent = i;
    ht[i].LChild = s1; ht[i].RChild = s2;
    }
}

void CRThuffmanCode(HuffmanTree ht,HuffmanCode hc,int n ){
    char *cd;int start,c,p;
    cd = (char *)malloc(n * sizeof(char));
    cd[n-1]='\0';
    for(int i =1;i<=n;i++){
        start = n-1;
        c=i;p=ht[i].parent;
        while(p!=0){
            --start;
            if(ht[p].LChild==c) cd[start]='0';
            else cd[start]='1';
            c=p;p=ht[p].parent;
        }
        hc[i]=(char*)malloc((n-start)*sizeof(char));
        strcpy(hc[i],&cd[start]);
    }
    free(cd);
}
int main(){
    int num[100],i=0,n;
    HuffmanTree ht;
    cin>>n;
    while(i++ < n)
        cin>>num[i];
    CrtHuffmanTree(ht,num,n);
    HuffmanCode Hc;
    CRThuffmanCode(ht,Hc,n);
    for(int i =0;i<n;++i){
        cout<<Hc[i+1]<<endl;
    }

}



