#include <iostream>
#include <cstring>
using namespace std;
#define max  999

typedef struct{
    int vexnum;
    int arcs[1000][1000];
}AdjMatrix;
int member(int n,int *s){
    int len = 0;
    while(s[len]!=-1){
        if(n == s[len]) return 1;
        len ++;
        }
    return 0;
} //判断n是否在s中，若是则返回1
void DIJ(AdjMatrix g,int v0,int *dist){

    int s[100],t=0,v=-1;   //s存储已经找到最短路径的点
    memset(s,-1,400);  //初始化
    s[t++] = v0;   // 起点已经是最短路径

    for (int i  = 0; i < g.vexnum; i++) {
        int min=999;
        for (int j = 0; j < g.vexnum; ++j) {

            if(member(j,s) == 0) //j没有被访问过
                if(dist[j]<min){
                    min = dist[j]; v = j;
                }}
        s[t++] = v; //将v加入s
        for (int k = 0; k <g.vexnum; ++k) { //更新dist
            if(member(k,s)==0 && (min+g.arcs[v][k])<dist[k])
                dist[k] = min+g.arcs[v][k];
        }
    }
    //将找到的最短路径输出
    for (int l = 0; l < g.vexnum; ++l) {
        if(l!=v0){
            if(dist[l] != 999)
                cout<<dist[l]<<' ';
            else
                cout<<-1<<' ';
        }
    }
}

int main(){
    int dist[99];
    int n,s;AdjMatrix g;
    cin>>n>>s;  //n为元素个数 ，s为原点
    g.vexnum = n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin>>g.arcs[i][j];
            if(g.arcs[i][j] ==0)
                g.arcs[i][j] = max;
        }
    }//创建图  读入数据

    for (int i = 0; i < g.vexnum; ++i) {
            dist[i] = g.arcs[s][i];//  对dist 赋值 初始化
    }
    DIJ(g,s,dist);


}