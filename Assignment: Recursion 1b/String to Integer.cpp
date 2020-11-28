/*
Write a recursive function to convert a given string into the number it represents. That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer.
Input format :
Numeric string S (string, Eg. "1234")
Output format :
Corresponding integer N (int, Eg. 1234)
Constraints :
0 <= |S| <= 9
where |S| represents length of string S.
Sample Input 1 :
1231
Sample Output 1 :
1231
Sample Input 2 :
12567
Sample Output 2 :
12567
*/


#include<cmath>
#include<cstring>
int helper(char input[], int n){
	if (n==1){
        return input[0] -'0';
    }
    else{
        return (10 * helper(input, n-1) + input[n-1] -'0');
    }
}


int stringToNumber(char input[]) {
    // Write your code here
    int len = strlen(input);
    return helper(input, len);
}

                                  /****  METHOD - 2  ****/
/*  
#include<cmath>
#include<cstring>


int stringToNumber(char input[]) {
    // Write your code here
    int len = strlen(input);
    if(len ==1){
        return input[0] - '0';
    }
    
    int smallAns = stringToNumber(input+1);
    int num = input[0] - '0';
    num = num * pow(10, len-1);
    return num + smallAns; 
}
*/

