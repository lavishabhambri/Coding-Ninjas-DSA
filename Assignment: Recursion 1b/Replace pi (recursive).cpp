/*
Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".
Sample Input 1 :
xpix
Sample Output :
x3.14x
Sample Input 2 :
pipi
Sample Output :
3.143.14
Sample Input 3 :
pip
Sample Output :
3.14p
*/


// Change in the given string itself. So no return or print anything
#include<cstring>
void replacePi(char input[]) {
	// Write your code here
    int len = strlen(input);
    if(len==0 || len==1){
        return;
    }
    
    replacePi(input+1);
    if(input[0] == 'p' && input[1] == 'i'){
        int count=0, i=0;
        
        while(input[i]!='\0'){   //loop to count characters in string
        	count++;
        	i++;
        }        
        for(int i=count+1; i>=2; i--){
            input[i+2] = input[i];
        }
        input[0] = '3';
        input[1] = '.';
        input[2] = '1';
        input[3] = '4';
    }
}

                              /***  METHOD - 2 ***/
/*                  
using namespace std;
#include<cstring>
void helper(char input[], int start){
    if(input[start] == '\0'){
        return;
    }
    helper(input, start+1);
    
    if(input[start] == 'p' && input[start+1]=='i'){
        for (int i = strlen(input); i >= start + 2; i--) {
            input[i + 2] = input[i];
        }
        
        input[start] = '3';
        input[start+1] = '.';
        input[start+2] = '1';
        input[start+3] = '4';
        
    }
}

void replacePi(char input[]) {
	// Write your code here
    helper(input, 0);
}

*/
