#include<iostream>
using namespace std;
int main(){
    int testcase;
    cin>>testcase;
    while(testcase--){
        int n; cin>>n;
        int arr[n];
        for(int i = 0; i<n; i++){
            cin>>arr[i];
        }
        int count = 0;
        for(int i = 0; i<n; i++){
            if(arr[i] >= 10 and arr[i] <= 60)
            count++;
        }
        cout<<count<<endl;
    }
    return 0;
}