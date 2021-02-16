/*
    Given an integer array (of length n),
    find and return all the subsets of input array.

    NOTE: Do not store the empty subset
*/

#include <iostream>
using namespace std;

/***
    Save all the subsets in the given 2D output array.
    And return the number of subsets(i.e. number of rows filled in output)
    from the given function.

    In ith row of output array, 1st column contains length of the ith subset. And from 2nd column actual subset follows.
    For eg. Input : {1, 2}, then output should contain 
        {{0}, 		// Length of this subset is 0
        {1, 2},		// Length of this subset is 1
        {1, 1},		// Length of this subset is also 1
        {2, 1, 2}}	// Length of this subset is 2

    Don’t print the subsets, just save them in output.
***/

int subset(int input[], int n, int output[][20]) 
{
    // Base Case
    if (n == 1)
    {
        output[0][0] = 1;
        output[0][1] = input[0];
        return 1;
    }
    
    // Recursion
    int smallerOutput = subset(input+1, n-1, output);
    
    // Computation
    output[smallerOutput][0] = 1;
    output[smallerOutput][1] = input[0];
    
    for (int i = 0; i < smallerOutput; i++)
    {
        int length_set = output[i][0] + 1;
        output[i+smallerOutput+1][0] = length_set;
        for (int j = length_set; j > 1; j--)
        {
            output[i+smallerOutput+1][j] = output[i][j-1];
        }
        output[i+smallerOutput+1][1] = input[0];
    }    
    
    return 2*smallerOutput + 1;
}

int main() {
  int input[20],length, output[35000][20];
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  
  int size = subset(input, length, output);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}
