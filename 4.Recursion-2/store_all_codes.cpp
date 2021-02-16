/*
    Assume that the value of a = 1, b = 2, c = 3, ... , z = 26.
    You are given a numeric string S.
    Write a program to return the list of all possible
    codes that can be generated from the given string.
*/

#include <iostream>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

int str2int(string s)
{
    int num = 0, j;
    for (int i = 0; i < s.size(); i++)
    {
        j = s[i] - '0';
        num = (num*10) + j;
    }
    
    return num;
}

char int2alphabet(int n)
{
    return (char)(n+96);
}

int getCodes(string input, string output[10000]) {
    
    // Base Cases
    if (input.size() == 0)
    {
        output[0] = "";
        return 1;
    }
    
    if (input.size() == 1)
    {
        output[0] = int2alphabet(str2int(input.substr(0,1)));
        return 1;
    }
    
    string sop1[10000];
    int smallerOutput1 = getCodes(input.substr(1), sop1);
    int smallerOutput2 = 0;
    
    for (int i = 0; i < smallerOutput1; i++)
    {
        output[i] = int2alphabet(str2int(input.substr(0,1))) + sop1[i];
    }
    
    int pairNumber = str2int(input.substr(0,2));
    
    if (pairNumber >= 10 && pairNumber <= 26)
    {
        string sop2[10000];    
    	smallerOutput2 = getCodes(input.substr(2), sop2);
    
        for (int i = 0; i < smallerOutput2; i++)
        {
            output[i+smallerOutput1] = int2alphabet(pairNumber) + sop2[i];
        }
    }
    
    return smallerOutput1 + smallerOutput2;
}

int main(){
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}
