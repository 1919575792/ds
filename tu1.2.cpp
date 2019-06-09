#include<iostream>
#include<algorithm>
using namespace std;
int f[300000];
typedef struct{
    int arc[100][100];
    int nv,ne;
}MGraph;

struct node
{
	int from,to,dis;

}edge[300000];

bool cmp(const node &a,const node &b)
{
	return a.dis<b.dis;
}

int parent(int x)
{
	if(f[x]!=x)
        return parent(f[x]);
	else
        return x;
}

void unionn(int x,int y)
{
	f[parent(y)]=parent(x);
}

int prim(MGraph g)
{
    int sum=0;
    int min,i,j,k;
    int lowcost[100];
    for(i=0;i<g.nv;i++){
        lowcost[i]=g.arc[0][i];
    }
    lowcost[0]=-1;
    for(i=0;i<g.nv;i++){
        min=233333333;
        k=-1;
        for(j=0; j<g.nv; j++){
            if(lowcost[j]>0 && min>lowcost[j]){
                min=lowcost[j];
                k=j;
            }}
        if(k!=-1){
            lowcost[k]=-1;
            sum+=min;
            for(j=0;j<g.nv;j++){
                if(lowcost[j]==0 || (g.arc[j][k]>0 && g.arc[j][k]<lowcost[j])){
                    lowcost[j]=g.arc[k][j];

                }}}}
    return sum;
}

int main()
{
    MGraph g;
    cin>>g.nv>>g.ne;
    int i,j,k,n;
    int kruskal_num=0;
    for(i=0;i<g.nv;i++){
        for(j=0;j<g.nv;j++){
            g.arc[i][j]=0;
        }
    }
    for(n=0;n<g.ne;n++){
        cin>>i>>j>>k;
        g.arc[i-1][j-1]=k;
        g.arc[j-1][i-1]=k;
        edge[n+1].from=i;
        edge[n+1].to=j;
        edge[n+1].dis=k;
    }
    cout<<prim(g)<<endl;  //prim


    k=0;
	for(i=1;i<=g.nv;i++) f[i]=i;
	sort(edge+1,edge+1+g.ne,cmp);
	for(i=1;i<=g.ne;i++)
	{
		if(k==g.nv-1) break;
		if(parent(edge[i].from)!=parent(edge[i].to))
		{
			unionn(edge[i].from,edge[i].to);
			kruskal_num+=edge[i].dis;
			k++;
		}}
	cout<<kruskal_num;   //kruskal
}
