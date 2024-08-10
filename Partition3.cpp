// Problem Description

// You are given a 1D integer array B containing A integers.

// Count the number of ways to split all the elements of the array into 3 contiguous parts so that the sum of elements in each part is the same.

// Such that : sum(B[1],..B[i]) = sum(B[i+1],...B[j]) = sum(B[j+1],...B[n]) 


// Problem Constraints
// 1 <= A <= 105
// -109 <= B[i] <= 109


// Input Format
// First argument is an integer A.
// Second argument is an 1D integer array B of size A.

// Output Format
// Return a single integer denoting the number of ways to split the array B into three parts with the same sum.

// Example Input
// Input 1:

//  A = 5
//  B = [1, 2, 3, 0, 3]
// Input 2:

//  A = 4
//  B = [0, 1, -1, 0]

// Example Output
// Output 1:
//  2

// Output 2:
//  1

int Solution::solve(int A, vector<int> &B) {
   int tot=0;
    for(auto x:B)
    tot+=x;
    
    
    if(tot%3)
    return 0;
    int sum=0;
    int ans=0;
    int cnt=0;
    
    for(int i=0; i<A-1; ++i){
        sum+=B[i];
        if(sum==2*(tot/3))
        ans+=cnt;
        
        if(sum==tot/3){
            cnt+=1;
        }
        
    }
    
    return ans;
}

