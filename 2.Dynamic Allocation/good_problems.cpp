// Problem 1
#include <iostream>
using namespace std;

void func(int p){
    cout << p << " ";
}

int main(){
    int i = 10;
    int &p = i;
    func(p++);      //💡 i (or p) is passed to func, then incremented. 
    cout << i;
}