/*
Sort an array A using Merge Sort.
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
2 1 5 2 3
Sample Output 2 :
1 2 2 3 5
*/

void merge(int input[], int si, int ei){
    int i=si, j=((si+ei)/2)+1, k=0;
    int mid = (si+ei)/2;
    int out[ei-si+1];
    while(i<=mid && j<=ei){
        if(input[i] <= input[j]){
            out[k] = input[i];
            i++;
            k++;
        }
        else{
            out[k] = input[j];
            k++; 
            j++;
        }
    }
    while(i<=mid){
        out[k] = input[i];
        i++;
        k++;
    }
    while(j<=ei){
        out[k] = input[j];
        k++; 
        j++;
    }
    k=0;
    for(int i=si; i<=ei; i++){ //now copy the elements to original I/P array.
        input[i] = out[k];
        k++;
    }
    
}

void helper(int input[], int si, int ei){
    
	if(si>=ei){
        return;
    }        
    int mid=(si+ei)/2;
    helper(input, si, mid);
    helper(input, mid+1, ei);
    
    merge(input, si, ei);
    
}

void mergeSort(int input[], int size){
	// Write your code here
    helper(input, 0, size-1);
    
}    
