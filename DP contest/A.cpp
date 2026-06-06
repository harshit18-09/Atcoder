// Author: Harshit_1809
#include<bits/stdc++.h>
using namespace std;

#define int long long

signed get(vector<int>& arr, int i, vector<int>& dp){
    if(i == arr.size()-1) return 0;
    if(dp[i] != -1) return dp[i];

    int c1 = (i+1 < arr.size()) ? abs(arr[i]-arr[i+1]) + get(arr, i+1, dp) : LLONG_MAX;
    int c2 = (i+2 < arr.size()) ? abs(arr[i]-arr[i+2]) + get(arr, i+2, dp) : LLONG_MAX;
    return dp[i] = min(c1, c2);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> dp(n+1, -1);
    cout<<get(arr, 0, dp);
    return 0;
}