/*Given a matrix of integers A of size N x M in which each row is sorted.

Find an return the overall median of the matrix A.

Note: No extra memory is allowed.

Note: Rows are numbered from top to bottom and columns are numbered from left to right.



Input Format

The first and only argument given is the integer matrix A.
Output Format

Return the overall median of the matrix A.
Constraints

1 <= N, M <= 10^5
1 <= N*M  <= 10^6
1 <= A[i] <= 10^9
N*M is odd
For Example

Input 1:
    A = [   [1, 3, 5],
            [2, 6, 9],
            [3, 6, 9]   ]
Output 1:
    5
Explanation 1:
    A = [1, 2, 3, 3, 5, 6, 6, 9, 9]
    Median is 5. So, we return 5.

Input 2:
    A = [   [5, 17, 100]    ]
Output 2:
    17 */
    
    
    
    int Solution::findMedian(vector<vector<int> > &A) {
   
       int n=A.size();
       int c=A[0].size();
         int mi=INT_MAX;
         int mx=INT_MIN;
         
         for(int i=0;i<n;i++)
         {
              mi=min(A[i][0],mi);
              mx=max(A[i][c-1],mx);
         }
         int md=(n*c+1)/2 ;
         while(mi<mx)
        {
              int mid=(mi+mx)/2;
              
              
              int cnt=0;
              
              for(int i=0;i<n;i++)
              {
                   cnt+=upper_bound(A[i].begin(),A[i].end(),mid)-A[i].begin();
              }
              
              if(cnt<md)
              {
                  mi=mid+1;
              }
              else
              {
                  mx=mid;
              }
        }
        
        return mi;
    
    
    
}

    
