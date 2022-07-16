#include<iostream>
using namespace std;

int count(int n){
    // Base Case
    if(n == 0){
        return 0;
    }

    // recursive call
    int smallAns = count(n / 10);

    // calculation
    return smallAns + 1;
}

int main(){
    int n;
    cin >> n;
  
    cout << count(n) << endl;
}