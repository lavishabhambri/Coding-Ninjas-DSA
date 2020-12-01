/*
Given an array A of size n and an integer K, return all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important.
Input format :
Line 1 : Integer n, Size of input array
Line 2 : Array elements separated by space
Line 3 : K 
Constraints :
1 <= n <= 20
Sample Input :
9 
5 12 3 17 1 18 15 3 17 
6
Sample Output :
3 3
5 1
*/

/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 3, 4, 2} and K = 5, then output array should contain
	{{2, 1, 4},	// Length of this subset is 2
	{2, 3, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/

int subsetSumToK(int input[], int n, int output[][50], int k) {
    // Write your code here
    if(n==0){
    	if(k==0){  
            //we found 1 valid subset
        	output[0][0] = 0;
        	return 1;
        }else{
            //no valid subset is found
            return 0;
        }
    }
    int o1[1000][50];
    int o2[1000][50];
    //Including the 0th element of input.
    int s1 = subsetSumToK(input+1, n-1, o1, k-input[0]);
    
    int row=0;
    for(int i=0;i<s1;i++){
        output[row][0] = o1[i][0] + 1; //storing size
        output[row][1] = input[0];  //storing the input[0] at 1st index of output.
        for(int j=1;j<=o1[i][0];j++){   //copying the rest elements from index=2.
            output[row][j+1] = o1[i][j];
        }
        row++;
    }
    
    int s2 = subsetSumToK(input+1, n-1, o2, k);
    for(int i=0;i<s2;i++){
        for(int j=0;j<=o2[i][0];j++){
            output[row][j] = o2[i][j];
        }
        row++;
    }
    
    return row;    
}
