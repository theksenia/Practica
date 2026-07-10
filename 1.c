#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n, i, k, j;
    cin >> n;
    vector<int> a(n);
    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }
    sort(a.begin(), a.end());
 
    long ans = 0;
    for(i=0; i<n-2; i++)
    {
        k = i + 2; //индекс третьей по внличине палочки
        for(j = i+1; j< n-1; j++){
            while (k < n && a[i] + a[j] > a[k]) {  //пока третья не последняя и выполняется нераванство
                k++;
        }
        if(k>j){
            ans += (k-j-1); //подходят всем между j и k
        }
    }
    }
    cout<< ans << '\n';
    return 0;
}
