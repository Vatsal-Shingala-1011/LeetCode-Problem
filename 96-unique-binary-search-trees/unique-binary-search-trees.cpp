//// Time complexity:~O(n^n) //without memo 
//// Space complexity: O(n)O(n)O(n)

//// Time complexity: ~O(n*n)
//// Space complexity: O(n)+O(n)
class Solution {
public:
    int solve(int n,vector<int>& memo) { //memoization
        if(n <= 1) return 1;
        if(memo[n]!=-1) return memo[n];
        int ans=0;
        for(int i = 1; i <= n; i++){
            ans+= solve(i-1,memo) * solve(n-i,memo);
        }
        return memo[n]=ans;
    }
    int numTrees(int n) {//play with numbers not array //catalan numbers
        // int ans=0;
        vector<int> memo(n+1,-1);
        return solve(n,memo);
    }
};



//// Time complexity: ~O(n*n)
//// Space complexity: O(n)
// class Solution { 
// public: 
//     int numTrees(int n) {           //tabulation
//         vector<int>result(n+1,0);
//         result[1]=result[0]=1;
//         for(int i=2;i<=n;i++)
//         {
//             for(int j=0;j<i;j++)
//             {
//                 result[i]+=result[j]*result[i-j-1];
//             }
//         }
//         return result[n]; ]
//     }
// };



// Time complexity: ~O(n∗n)O(n*n)O(n∗n)
// Space complexity: O(n)O(n)O(n)
// class Solution {
// public:
//     long CalculateCoeff(int n,int k) //Function to calculate Ci(n.k)
//     {
//         long res=1;
//         if(k>n-k) k=n-k; //Since Ci(n,k)=Ci(n,n-k), property of binomial coefficients
//         for(int i=0;i<k;i++)
//         {
//             res*=(n-i);
//             res/=(i+1);
//         }
//         return res;
//     }
//     int numTrees(int n) {
//         return CalculateCoeff(2*n,n)/(n+1);
//     }
// };

// This method is not intuitive and requires Combinatorics as pre-requisite, but I am still presenting it here for your reference.
// I have used long double instead of long long in the code below because long long would lead to int division (kind of floor of what we need in the subsequent products) and thus will result into wrong answer. So, use long double instead to get the right division in subsequent products and thus the right answer. Finally, since the return type of func. is int, so the ans is type-casted by compiler to int:)
