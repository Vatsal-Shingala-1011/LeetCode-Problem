//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    long long int largestPrimeFactor(int N){
        int n=N;
        for(int i=2;i<=n;i++){
            if(i>N) return N;
            while(N%i==0){
                if(N==i) return N;
                N=N/i;
                // cout<<N<<" ";
            }
        }
        // cout<<N<<" **";
        return n;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends