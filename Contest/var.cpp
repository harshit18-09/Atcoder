// Author: Harshit_1809
#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, m;
    cin>>n>>k>>m;

    map<int, vector<int>> mp;

    for(int i=0; i<n; i++){
        int c, v;
        cin>>c>>v;
        mp[c].push_back(v);
    }

    vector<int> taken, extras;

    for(auto &x : mp){
        vector<int> &v = x.second;

        sort(v.begin(), v.end(), greater<int>());

        taken.push_back(v[0]);

        for(int i=1; i<v.size(); i++){
            extras.push_back(v[i]);
        }
    }

    sort(taken.begin(), taken.end(), greater<int>());
    sort(extras.begin(), extras.end(), greater<int>());

    int ans = 0;

    for(int i=0; i<m; i++){
        ans += taken[i];
    }

    vector<int> rem;

    for(int i=m; i<taken.size(); i++){
        rem.push_back(taken[i]);
    }

    for(auto x : extras){
        rem.push_back(x);
    }

    sort(rem.begin(), rem.end(), greater<int>());

    for(int i=0; i<k-m; i++){
        ans += rem[i];
    }

    cout<<ans;

    return 0;
}