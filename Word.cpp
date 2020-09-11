#include<bits/stdc++.h>
using namespace std;

vector< vector<long> > v;
long n,m,k,cnt=0,a[250][250]={0},c[250];
vector<long> g[250];

bool wordcheck(stack<long> s)
{
    vector<long> p,u,unique;
    while(!s.empty())
    {
        p.push_back(s.top());
        u.push_back(s.top());
        s.pop();
    }
    sort(u.begin(),u.end());
    unique.push_back(u[0]);
    for(long i=1;i<u.size();i++)
    {
        if(u[i]!=u[i-1])
            unique.push_back(u[i]);
    }
    bool check=true;
    for(long i=1;i<=n;i++)
    {
        for(long j=i+1;j<=n;j++)
        {
            if(a[i][j]==1)
            {
                vector<long> fresh;
                for(long z=0;z<p.size();z++)
                {
                    if(p[z]==i || p[z]==j)
                        fresh.push_back(p[z]);
                }
                for(long z=1;z<fresh.size();z++)
                {
                    if(fresh[z]==fresh[z-1])
                        check=false;
                }
            }
            else
            {
                vector<long> fresh;
                for(long z=0;z<p.size();z++)
                {
                    if(p[z]==i || p[z]==j)
                        fresh.push_back(p[z]);
                }
                for(long z=2;z<fresh.size();z++)
                {
                    if(fresh[z]==fresh[z-2] && fresh[z-1]!=fresh[z-2])
                        check=false;
                }
            }
        }
    }
    return check;
}

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
                if(wordcheck(s))
                {          
                    c[i]--;
                    generate(x+1,s);
                    c[i]++;
                }
                s.pop();
            }
    }
    return;
}


int main()
{
    long i,j,l;
    //Enter number of nodes,edges and K denoting K-uniform words
    cin>>n>>m>>k;
    for(i=0;i<m;i++)
    {
        //Enter the edges
        cin>>j>>l;
        g[j].push_back(l);
        g[l].push_back(j);
        a[j][l]=1;a[l][j]=1;
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
    return 0;
}
