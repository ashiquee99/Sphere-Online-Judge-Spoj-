#include <bits/stdc++.h>
using namespace std;
typedef                long long int ll;
#define                MX 1000007
#define                FAST_IO ios_base::sync_with_stdio(false),cin.tie(NULL)
#define                exit() return 0;

using namespace std;

int f[MX];//the failure array
void failure_function(string& pattern)
{
    f[0] = 0;
    int i = 1, j = 0, len_p = pattern.size();

    while (i<len_p)
    {
        if (pattern[i] == pattern[j])
        {
            j++;
            f[i] = j;
            i++;
        }
        else
        {
            if (j>0)//here j is non zero
            {
                j = f[j - 1];
            }
            else
            {
                f[i] = 0;
                i++;
            }
        }

    }
    return;
}

void KMP_match(string& txt, string& pattern)
{
    int i = 0, j = 0, ret = -1;
    int len_t = txt.size(), len_p = pattern.size();
    vector <int> v;
    bool flag = false;
    while (i < len_t)
    {
        if (txt[i] == pattern[j])
        {
            i++;
            j++;
            if (j == len_p)
            {
                flag = true;
                ret = i - len_p;
                v.push_back(ret);
                j = f[j - 1];
            }
        }
        else
        {
            if (j)
            {
                j = f[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
    if(flag)
    {
        cout<<v.size()<<endl;
        for(int i = 0; i<v.size(); i++)
        {
            cout<<v[i]+1<<" ";
        }
        cout<<endl;
    }
    else
    {
        cout<<"Not Found"<<endl;
    }
}
int main()
{
    int T;
    cin>>T;
    for(int i = 1; i<=T; i++)
    {
        string A, B;
        cin>>A;
        cin>>B;
        failure_function(B);
        KMP_match(A, B);
    }
    return 0;
}
