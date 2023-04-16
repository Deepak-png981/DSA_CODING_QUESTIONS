//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
    //Memoization ka function
    // int minS(int n , vector<int>&ans){
    //     if(n == 1){
    //         ans[n] = 0;
    //         return 0;
    //     }
    //     if(ans[n-1] == -1){
    //         ans[n-1] = minS(n-1 , ans);
    //     }
    //     int y = INT_MAX , z = INT_MAX;
    //     if(n % 2 == 0){
    //         if(ans[n/2] == -1){
    //             ans[n/2] = minS(n/2 , ans);
    //         }
    //         y = ans[n/2];
    //     }
    //     if(n % 3 == 0){
    //         if(ans[n/3] == -1){
    //             ans[n/3] = minS(n/3 , ans);
    //         }
    //         z = ans[n/3];
    //     }
    //     ans[n] = 1 + min(ans[n-1] , min( y , z));
    //     return ans[n];
    // }
	public:
	int minSteps(int n) 
	{ 
	    
	   // //basic recursion approach
	   // int a = INT_MAX , b = INT_MAX , c = INT_MAX;
	   // if( n == 1)
	   //     return 0;
	   // if(n % 2 == 0){
	   //     a = 1 + minSteps(n / 2);
	   // }
	   // if(n % 3 == 0)
	   //     b = 1 + minSteps(n/3);
	   // c = 1 + minSteps(n-1);
	   // return min( a , min( b , c));
	   
	   //MEMOIZATION USE
	   //vector<int>ans(n+1 ,-1);
	   //return minS(n , ans);
	   
	   //DP use kerke dikhayenge ab ishme
	   vector<int>dp(n + 1 , INT_MAX);
	   dp[0] = 0;
	   dp[1] = 0;
	   for(int i = 2; i<=n; i++){
	       if(i%2 == 0){
	           dp[i]  = 1 + min(dp[i/2] , dp[i-1]);
	       }
	       if(i%3 == 0){
	           dp[i] = 1 + min(dp[i/3] , dp[i-1]);
	       }
	       else{
	           dp[i] = min(dp[i] , 1 + dp[i-1]);
	       }
	   }
	   return dp[n];
	   
	   
	    
	} 
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.minSteps(n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends