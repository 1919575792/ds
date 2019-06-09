#include <iostream>
using namespace std;
int main() {
    string a,b;
    cin>>a>>b;
    int len1 = a.size(),len2 = b.size();
    int sum[10000]={0,};
    int i=0,j=0;
    for(i=0;i<len1;i++){
        for(j=0;j<len2;j++){
            sum[i+j] += (a[len1-i-1]-'0') * (b[len2-j-1]-'0');  //相乘
        }
    }
    for(int k=0;k<j+i;k++){
        sum[k+1] += sum[k]/10;  //  取十位
        sum[k] =sum[k]-(sum[k]/10)*10;
    } // 进位
    int k=i+j;
    while(k>=0){
        if(sum[k]!=0){
            cout<<sum[k];
        }
        k--;
    }  //输出
}   //正确版

  //   好像不太对啊 。。
  /*测试数据 1234567891011121314151617181920
            2019181716151413121110987654321
            输出      249281691287726668779424983772975935133869549611317632
            正确输出   2492816912877266687794240983772975935013386905490061131076320*/