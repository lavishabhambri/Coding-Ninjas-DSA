/*
Check whether a given String S is a palindrome using recursion. Return true or false.
Input Format :
String S
Output Format :
'true' or 'false'
Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.
Sample Input 1 :
racecar
Sample Output 1:
true
Sample Input 2 :
ninja
Sample Output 2:
false
*/


#include<cstring>
bool helper(char input[], int start,int end){
    if(start==end){
        return true;
    }
    //int start=0, end = len-1;
    if(input[start] != input[end]){
        return false;
    }
	
    if(start<end+1){
    	return helper(input, start+1, end-1);
    } 
    return true;
}

bool checkPalindrome(char input[]) {
    // Write your code here
    int len = strlen(input);
    if(len == 0 || len == 1){
        return true;
    }
    
    return helper(input, 0, len-1);

}
