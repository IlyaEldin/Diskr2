#include <stdio.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;
const int maxn = 100;
const int maxn_n = maxn * (maxn - 1) / 2;
int p[4][maxn_n];
int Mark[maxn];
int k,i,t,m,n;
void Change_Mark(int l,int m,int n)
{

    int i,t;
    if (m<l) {
        t=l;
        l=m;
        m=t;
    }
    for(int i=1; i<=n; i++) {
        if (Mark[i]==m) {
            Mark[i]=l;
        }
    }

}
int main()
{
    cout<<"Введите через пробел кол-во вершин и кол-во ребер"<<endl;
    cin>>n>>m;
    cout<<"Введите "<< m <<" раз через пробел номер одной и второй вершины ребра и вес этого ребра"<<endl;
    for(int i=1; i<=m; i++) {
        cin>>p[1][i]>>p[2][i]>>p[3][i];
    }
    for(int i=1; i<m; i++) {
        for(int t=(i+1); t<=m; t++) {
            if (p[3][i] > p[3][t]) {
                k = p[1][i];
                p[1][i] = p[1][t];
                p[1][t] = k;
                k= p[2][i];
                p[2][i] = p[2][t];
                p[2][t] = k;
                k = p[3][i];
                p[3][i] = p[3][t];
                p[3][t] = k;
            }

        }
    }
    for(int i=1; i<=n; i++) {
        Mark[i]=i;
    }
    k = 0;
    t = m;
    while (k < (n - 1)) {
        i=1;
        while ((i<=t)&&(Mark[p[1][i]]==Mark[p[2][i]])&&(p[1][i]))
        i++;
            k++;
        if ((p[1][i] * p[2][i]) != 0) {
            cout<<p[1][i]<<" "<<p[2][i]<<endl;
            Change_Mark(Mark[p[1][i]], Mark[p[2][i]], n);
        }




    }
    cout<<endl;
    cout<<"Полученые пары чисел - есть вершины ребер, входящих в кратчайший остов графа"<<endl;
    return 0;
}
