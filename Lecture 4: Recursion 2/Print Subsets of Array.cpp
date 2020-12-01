/*
Given an integer array (of length n), find and print all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important. Just print the subsets in different lines.
Input format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)
Constraints :
1 <= n <= 15
Sample Input:
3
15 20 12
Sample Output:
[] (this just represents an empty array, don't worry about the square brackets)
12 
20 
20 12 
15 
15 12 
15 20 
15 20 12
*/

void helper(int input[], int n, int output[], int m){
    if(n==0){
        for(int i=0; i<m;i++){
            cout<<output[i]<<" ";
        }
        cout<<endl;
        return;
    }
    
    //including the element
    int newOutput[m+1];
    for(int i=0; i<m;i++){
        newOutput[i] = output[i];
    }
    newOutput[m] = input[0];
    helper(input+1, n-1, newOutput, m+1);
    
    //excluding the element
    helper(input+1, n-1, output, m);
}


void printSubsetsOfArray(int input[], int size) {
	// Write your code here
    int output[15];
    helper(input, size, output, 0);
	    
}

