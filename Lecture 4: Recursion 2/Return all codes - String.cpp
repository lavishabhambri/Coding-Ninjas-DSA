/*
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. And input string does not contain 0s.
Input format :
A numeric string
Constraints :
1 <= Length of String S <= 10
Sample Input:
1123
Sample Output:
aabc
kbc
alc
aaw
kw
*/

#include <string.h>
using namespace std;

int asciiToInt(char a){
    return a-'0';
}

char intToAscii(int k){
    return 'a'+k-1;
}

int getCodes(string input, string output[10000]) {
    if(input.size()==0){
        return 0;
    }
    
    if(input.size()==1)
    {
        output[0]= intToAscii(asciiToInt(input[0]));   
        return 1;
    }
   
    if(input[0] =='0'){
        return 0;
    }
    
    string output1[10000], output2[10000];
    //char k1 = 'a'+(input[0]-'0')-1;
    int s1 = getCodes(input.substr(1), output1);
    int x=asciiToInt(input[0])*10+asciiToInt(input[1]);
    int s2=0;
    if(x<=26){
        s2 = getCodes(input.substr(2), output2);
    }  
    
    //merging both arrays into 1 output array
	int row=0;
    for(int i=0;i<s1;i++){
        output[row] = intToAscii(asciiToInt(input[0])) + output1[i];
        row++;
    }
      
    if(x<=26){
        if(s2==0){
            output[row] = intToAscii(x);
        	row++;
        }
        else{
        	for(int i=0;i<s2;i++){
        		output[row] = intToAscii(x) + output2[i];
    			row++;
    		}    
        }
    }    
    return row;
}
