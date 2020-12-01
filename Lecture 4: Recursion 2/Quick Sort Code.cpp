/*
Sort an array A using Quick Sort.
Change in the input array itself. So no need to return or print anything.


Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)
Output format :
Array elements in increasing order (separated by space)
Constraints :
1 <= n <= 10^3
Sample Input 1 :
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8
Sample Input 2 :
5
1 5 2 7 3
Sample Output 2 :
1 2 3 5 7
*/

int partition(int input[], int si, int ei){
    int x = input[si], c=0;
    for(int i=si;i<=ei;i++){
        if(input[i]<x){
            c++;
        }
    }
    //place the element x to its correct position while swaping
    int temp = input[si];
    input[si] = input[si+c];
    input[si+c] = temp;
    int pivot_index = si+c;
    int i=si, j=ei;
    while(i < pivot_index && j > pivot_index){
        if(input[i] <input[pivot_index]){
            i++;
        }
        else if(input[j]>=input[pivot_index]){
            j--;
        }
        else{
            temp = input[i];
            input[i] = input[j];
            input[j] = temp;
            //i++;
            //j--;
        }
    }
    return pivot_index;
    
}

void helper(int input[], int si, int ei){
    //base case
    if(si>=ei){
        return;
    }
    
    int c = partition(input, si, ei);
    helper(input, si, c-1);
    helper(input, c+1, ei);
}

void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */
    helper(input, 0, size-1);

}
