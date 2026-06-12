// Author: Harshit_1809
#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr(n), brr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        cin >> brr[i];
    }

    for(int i=0; i<n; i++){
        if(brr[arr[i]-1] != i+1){
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}