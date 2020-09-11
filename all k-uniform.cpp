
#include<bits/stdc++.h>
using namespace std;

vector< vector<long> > v;
long n,m,k,cnt=0,a[250][250]={0},c[250];
vector<long> g[250];

void generate(long x,stack<long> s)
{
    if(x==n*k+1)
    {   
        cnt++;
        vector<long> p;
        while(!s.empty())
        {
            p.push_back(s.top());
            s.pop();
        }
        v.push_back(p);
        return;
    }
    for(long i=1;i<=n;i++)
    {
         if(c[i]>0)
            {
                s.push(i);
                c[i]--;
                generate(x+1,s);
                c[i]++;
                s.pop();
            }
    }
    return;
}

int main()
{   
    long i,j,l;
    cin>>n>>m>>k;
    for(i=1;i<=m;i++)
        {
            cin>>j>>l;
            g[j].push_back(k);
            g[k].push_back(j);
            a[j][k]=1;a[k][j]=1;
        }
    for(i=1;i<=n;i++)
        c[i]=k;
    stack<long> s;
    generate(1,s);
    for(i=0;i<cnt;i++)
    {
        if(v[i].size()!=0)
        for(j=0;j<v[i].size();j++)
        {
            cout<<v[i][j];
        }
        cout<<endl;
    }
    cout<<"over "<<cnt;
}
