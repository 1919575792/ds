#include<iostream>
using namespace std;
typedef struct node{
    int arc[100][100];
    int x;
}G;

G Create(int n)
{
    G g;
    g.x=n;
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin>>g.arc[i][j];
        }
    }
    return g;
}
int visit[100];

void DFS(G g,int v)
{
    int i;
    for(i=0;i<g.x;i++){
        if(visit[i]==0 && g.arc[v][i]==1){
            visit[i]=1;
            DFS(g,i);
        }
    }
}
void TDFS(G g)
{
    int i,sum=0;
    for(i=0;i<g.x;i++){
        if(visit[i]==0){
            visit[i]=1;
            DFS(g,i);
            sum++;
            }
    }
    cout<<sum;
}
int main()
{
    int n;
    cin>>n;
    G g=Create(n);
    TDFS(g);
    return 0;
}
