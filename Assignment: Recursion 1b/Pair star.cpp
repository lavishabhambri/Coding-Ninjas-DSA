/*
Given a string S, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".
Input format :
String S
Output format :
Modified string
Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.
Sample Input 1 :
hello
Sample Output 1:
hel*lo
Sample Input 2 :
aaaa
Sample Output 2 :
a*a*a*a
*/


// Change in the given string itself. So no need to return or print the changed string.
#include<cstring>
void pairStar(char input[]) {
    // Write your code here
    
	if(input[0] =='\0'){
        return;
    }
    pairStar(input+1);
    if(input[0] == input[1]){
        int len = strlen(input);
    	//input[len+2] = '\0';
        for(int i=len; i>=1; i--){ //shift all the characters including null character by 1 position to right whenever we get 2 characters at adjacent position.
            input[i+1] = input[i];
        }
        input[1] = '*';
    }
}
