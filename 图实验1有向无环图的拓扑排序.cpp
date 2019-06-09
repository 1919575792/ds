#include <iostream>
#include<stack>
using namespace std;

typedef struct{
    int vertex[100]; //顶点
    int arcs[100][100]; //矩阵
    int n;   // 顶点个数
}AdjMatrix;  // 创建矩阵的数据结构

int FindID(AdjMatrix G,int n){  //n 顶点
    int id=0;
    for(int i=0;i<G.n;i++){
        if(G.arcs[i][n] == 1)
            id ++;
    }
    return id;
}

void TopoSort(AdjMatrix g){
    stack<int> S;
    int p[100] = {-1,},t=0;
    int indegree[g.n];
    int i=0,count=0,k=0,f=0;
    for(i = 0;i<g.n;++i){
        indegree[i]=FindID(g,i);
    }
    for(i = 0;i<=g.n;i++){
        if(!indegree[i]) {S.push(i);
            p[t++] =i;}
    }
    count = 0;   // 对输出顶点计数
    while(!S.empty()){
        i = S.top();
        cout<<i<<' ';
        S.pop();
        ++count;
        for(k = 0;k<g.n;k++){
            if(g.arcs[i][k] ==1){
                g.arcs[i][k] =0;
                indegree[k]-=1;
            }
        }
        for (int l = 0; l < g.n; ++l) {
            if(indegree[l] == 0 ){
                for (int j = 0; j < t; ++j) {
                    if(l == p[j]) f=1;
                }
                if(f==0){
                    S.push(l);p[t++] =l;}
            }    f = 0;
    }}
    if(count < g.n)  cout<<"ERROR";

}

int main()
{
    AdjMatrix a;
    int n=0;
    cin>>n;a.n=n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a.arcs[i][j];
        }
        a.vertex[i] = i;
    }

    TopoSort(a);
}