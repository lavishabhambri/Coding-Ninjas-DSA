/*
Given an array of length N and an integer x, you need to find all the indexes where x is present in the input array. Save all the indexes in an array (in increasing order).
Do this recursively. Indexing in the array starts from 0.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x
Output Format :
indexes where x is present in the array (separated by space)
Constraints :
1 <= N <= 10^3
Sample Input :
5
9 8 10 8 8
8
Sample Output :
1 3 4
*/


int allIndexes(int input[], int size, int x, int output[]) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Save all the indexes in the output array passed and return the size of output array.
     Taking input and printing output is handled automatically.
  */
    
    if(size == 0){
        return 0;
    }
    int ans = allIndexes(input, size-1, x, output);
    if(input[size-1] == x){
        output[ans] = size-1;
        ans+=1;
    }
    return ans;

}


                      /**********     APPROACH - 2   ***********/
/*
int allIndexes(int input[], int size, int x, int output[]) {
  
    if(size == 0){
        return 0;
    }
    
    int ans = allIndexes(input+1, size-1, x, output);
    
    //updation of each value by 1.
    for(int i=ans-1; i>=0; i--){
        output[i] += 1;
    }
    
    if(input[0] == x){
        for(int i=ans-1; i>=0; i--){
        	output[i+1] = output[i];  //shifting elements to right by 1.
        }    
        
        output[0] = 0;
        ans+=1;
    }
    return ans;    
}

*/
