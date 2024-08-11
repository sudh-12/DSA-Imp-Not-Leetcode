// You are given a binary string A(i.e. with characters 0 and 1) consisting of characters A1, A2, ..., AN. In a single operation, you can choose two indices L and R such that 1 ≤ L ≤ R ≤ N and flip the characters AL, AL+1, ..., AR. By flipping, we mean change character 0 to 1 and vice-versa.

// Your aim is to perform ATMOST one operation such that in final string number of 1s is maximised.

// If you don't want to perform the operation, return an empty array. Else, return an array consisting of two elements denoting L and R. If there are multiple solutions, return the lexicographically smallest pair of L and R.

// NOTE: Pair (a, b) is lexicographically smaller than pair (c, d) if a < c or, if a == c and b < d.

// Problem Constraints
// 1 <= size of string <= 100000

// Input Format
// First and only argument is a string A.

// Output Format
// Return an array of integers denoting the answer.

// Example Input
// Input 1:
// A = "010"

// Input 2:
// A = "111"

// Example Output
// Output 1:
// [1, 1]

// Output 2:
// []

vector<int> Solution::flip(string A) {
    int n=A.size();
   int mxsum=INT_MIN, cur_sum=0;
   int left=0,right=0;
   int curr_left=0;
   
   for(int i=0; i<n; ++i){
       cur_sum+=(A[i]=='0'?1:-1);
       if(cur_sum>mxsum){
           mxsum=cur_sum;
           right=i;
           left=curr_left;
       }
       if(cur_sum<0)
       {
           cur_sum=0;
           curr_left=i+1;
       }
   }
   
   //if no 0 is present in the array or string
   if(mxsum<0)
   return {};
   //for left and right index of sub array 1 based indexing
   return {left+1,right+1};
   //this ques can be modified to for total number of flip
  return  (right-left+1)-mxsum;
}

