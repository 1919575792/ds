#include<iostream>
#include <cstring>
using namespace std;

struct ArcNode
{
    int to, dur, no;	//边指向顶点、权重、活动序号
    ArcNode *next;
};
int n, m;				//顶点个数、边数
ArcNode *List1[1000];	//每个顶点的边链表表头指针（出边表）
ArcNode *List2[1000];	//每个顶点的边链表表头指针（入边表）
int indegree[1000];		//各顶点的入度
int outdegree[1000];		//各顶点的出度
int Ve[1000];			//各事件的最早可能开始时间
int Vl[1000];			//各事件的最迟允许开始时间
int e[1000];			//各活动的最早可能开始时间
int L[1000];			//各活动的最迟允许开始时间
void CriticalPath()		//求关键路径
{
    //拓扑排序求Ve
    int i, j, k;
    int top1 = -1;
    ArcNode *temp1;
    memset(Ve, 0, sizeof(Ve));
    for(i = 0; i < n; i++)
        if(indegree[i] == 0) { indegree[i] = top1; top1 = i; }
    for(i = 0; i < n; i++)
    {
            j = top1; top1 = indegree[top1];
            temp1 = List1[j];
            while(temp1 != NULL)
            {
                k = temp1->to;
                if(--indegree[k] == 0) { indegree[k] = top1; top1 = k; }
                if(Ve[j]+temp1->dur > Ve[k]) Ve[k] = Ve[j] + temp1->dur;
                temp1 = temp1->next;
            }
    }
    //拓扑排序求Vl
    int top2 = -1;
    ArcNode *temp2;
    for(i = 0; i < n; i++)
    {
        Vl[i] = Ve[n-1];
        if(outdegree[i] == 0) { outdegree[i] = top2; top2 = i; }
    }
    for(i = 0; i < n; i++)
    {
        j = top2; top2 = outdegree[top2];
        temp2 = List2[j];
        while(temp2 != NULL)
        {
            k = temp2->to;
            if(--outdegree[k] == 0) { outdegree[k] = top2; top2 = k; }
            if(Vl[j]-temp2->dur < Vl[k]) Vl[k] = Vl[j] - temp2->dur;
            temp2 = temp2->next;
        }
    }
    //求e[k]和L[k]
    memset(e, 0, sizeof(e)); memset(L, 0, sizeof(L));
    for(i = 0; i < n; i++)
    {
        temp1 = List1[i];
        while(temp1 != NULL)
        {
            j = temp1->to; k = temp1->no;
            e[k] = Ve[i]; L[k] = Vl[j] - temp1->dur;
            if(e[k] == L[k]) cout<<i<<' '<<j<<endl;
            temp1 = temp1->next;
        }
    }
}
int main()
{
    int i, u, v, w;	//循环变量、边的起点和终点
    cin>>n>>m;	//读入顶点个数和边数
    ArcNode *temp1, *temp2;
    for(i = 0; i < m; i++)
    {
        cin>>u>>v>>w;	//读入边的起点和终点
        indegree[v]++;
        temp1 = new ArcNode;			//邻接表
        temp1->to = v; temp1->dur = w;
        temp1->no = i + 1; temp1->next = NULL;
        if(List1[u] == NULL) List1[u] = temp1;
        else { temp1->next = List1[u]; List1[u] = temp1; }
        outdegree[u]++;
        temp2 = new ArcNode;			//逆邻接表
        temp2->to = u; temp2->dur = w;
        temp2->no = i + 1; temp2->next = NULL;
        if(List2[v] == NULL) List2[v] = temp2;
        else { temp2->next = List2[v]; List2[v] = temp2; }
    }
    CriticalPath();
}
