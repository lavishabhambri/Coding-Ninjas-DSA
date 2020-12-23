/*
You have been given a random integer array/list(ARR) and a number X. Find and return the triplet(s) in the array/list which sum to X.
Note :
Given array/list can contain duplicate elements.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the first array/list.

Second line contains 'N' single space separated integers representing the elements in the array/list.

Third line contains an integer 'X'.
Output format :
For each test case, print the total number of triplets present in the array/list.

Output for every test case will be printed in a separate line.
Constraints :
1 <= t <= 10^2
0 <= N <= 10^3
0 <= X <= 10^9

Time Limit: 1 sec
Sample Input 1:
1
7
1 2 3 4 5 6 7 
12
Sample Output 1:
5
Sample Input 2:
2
7
1 2 3 4 5 6 7 
19
9
2 -5 8 -6 0 5 10 11 -3
10
Sample Output 2:
0
5


 Explanation for Input 2:
Since there doesn't exist any triplet with sum equal to 19 for the first query, we print 0.

For the second query, we have 5 triplets in total that sum up to 10. They are, (2, 8, 0), (2, 11, -3), (-5, 5, 10), (8, 5, -3) and (-6, 5, 11)
*/

#include <bits/stdc++.h>

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    
    
    // Create temp arrays
    int L[n1], R[n2];
 
    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    // Merge the temp arrays back into arr[l..r]
 
    // Initial index of first subarray
    int i = 0;
 
    // Initial index of second subarray
    int j = 0;
 
    // Initial index of merged subarray
    int k = l;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int arr[],int l,int r){
    if(l>=r){
        return;//returns recursively
    }
    int m = (l+r-1)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}
 


int pairSum(int *arr, int i,int j, int num)
{
	//Write your code here
    //Sorting the array
    //mergeSort(arr,i,j);
    
    //int i=0,j=n-1,
    int count=0;
    //int counts[n];
//     unordered_map<int, int> counts;
//     for(int i=0;i<j;i++){
//     	counts[arr[i]]++;   
//     }
    
    while(i<j){
        if(arr[i]+arr[j] == num){
            if(arr[i] == arr[j]){
                int h = (j-i);
                count += (h*(h+1))/2;
                return count;
            }else {
                int a=1,b=1;
        		while(arr[i]==arr[i+1]){
                    a++;
                    i++;
                }
                while(arr[j]==arr[j-1]){
                    b++;
                    j--;
                }
                count+= a*b;
                i++;
                j--;
            }
        }
        else if(arr[i]+arr[j]<num){
            i++;
        }else{
            j--;
        }
        
    }
    return count;
    
}


int tripletSum(int *arr, int n, int num)
{
    mergeSort(arr, 0,n-1);
    int ans = 0;
    for(int i=0; i<n; i++){
        ans += pairSum(arr, i+1, n-1, num-arr[i]);
    }
    
    return ans;
}

