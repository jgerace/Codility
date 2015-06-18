#include <iostream>
/*
You are given integers K, M and a non-empty zero-indexed array A consisting of N integers. Every element of the array is not greater than M.

You should divide this array into K blocks of consecutive elements. The size of the block is any integer between 0 and N. Every element of the array should belong to some block.

The sum of the block from X to Y equals A[X] + A[X + 1] + ... + A[Y]. The sum of empty block equals 0.

The large sum is the maximal sum of any block.

For example, you are given integers K = 3, M = 5 and array A such that:

  A[0] = 2
  A[1] = 1
  A[2] = 5
  A[3] = 1
  A[4] = 2
  A[5] = 2
  A[6] = 2

The array can be divided, for example, into the following blocks:

        [2, 1, 5, 1, 2, 2, 2], [], [] with a large sum of 15;
        [2], [1, 5, 1, 2], [2, 2] with a large sum of 9;
        [2, 1, 5], [], [1, 2, 2, 2] with a large sum of 8;
        [2, 1], [5, 1], [2, 2, 2] with a large sum of 6.

The goal is to minimize the large sum. In the above example, 6 is the minimal large sum.

Write a function:

    int solution(int K, int M, vector<int> &A);

that, given integers K, M and a non-empty zero-indexed array A consisting of N integers, returns the minimal large sum.

For example, given K = 3, M = 5 and array A such that:

  A[0] = 2
  A[1] = 1
  A[2] = 5
  A[3] = 1
  A[4] = 2
  A[5] = 2
  A[6] = 2

the function should return 6, as explained above.

Assume that:

        N and K are integers within the range [1..100,000];
        M is an integer within the range [0..10,000];
        each element of array A is an integer within the range [0..M].

Complexity:

        expected worst-case time complexity is O(N*log(N+M));
        expected worst-case space complexity is O(1), beyond input storage (not counting the storage required for input arguments).

Elements of input arrays can be modified.
Copyright 2009�2015 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/
using namespace std;
int getMinBlockSize(vector<int> &A, int K, int ignore);
bool isValidBlockSize(vector<int> &A, int K, int blockSize);

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

int solution(int K, int M, vector<int> &A) {
    return getMinBlockSize(A, K, M);
}

int getMinBlockSize(vector<int> &A, int K, int ignore) {
    int max = 0;
    int sum = 0;
    for(int ii = 0; ii < A.size(); ii++) {
        if(A[ii] > max) {
            max = A[ii];
        }
        sum += A[ii];
    }
    int lowerBound = max;
    int upperBound = sum;
    while(lowerBound <= upperBound) {
        int size = (upperBound + lowerBound) / 2;
        if(isValidBlockSize(A, K, size)) {
            upperBound = size - 1;
        }
        else {
            lowerBound = size + 1;
        }
    }

    return lowerBound;
}

bool isValidBlockSize(vector<int> &A, int K, int blockSize) {
    int block = 1;
    int sum = 0;
    for(int ii = 0; ii < A.size(); ii++) {
        if(sum + A[ii] > blockSize) {
            sum = A[ii];
            block++;
        }
        else {
            sum += A[ii];
        }

        if(block > K) {
            return false;
        }
    }
    return true;
}

