/*
Given a string, compute recursively a new string where all 'x' chars have been removed.
Input format :
String S
Output format :
Modified String
Constraints :
1 <= |S| <= 10^3
where |S| represents the length of string S. 
Sample Input 1 :
xaxb
Sample Output 1:
ab
Sample Input 2 :
abc
Sample Output 2:
abc
Sample Input 3 :
xx
Sample Output 3:
*/


// Change in the given string itself. So no need to return or print anything

#include<cstring>
void removeX(char input[]) {
    // Write your code here
    
	int len=strlen(input);
    if(len==0)
        return ;
    
    removeX(input+1);
    
    if(input[0]=='x')
    {
        for(int i=0;i<=len;i++) // for indexing 
        {
         input[i]=input[i+1];   
        }
    }    
}
