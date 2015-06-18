/* INCOMPLETE */
/*
Write a function:

    int solution(vector<int> &A);

that, given a non-empty zero-indexed array A of N integers, returns the minimal positive integer that does not occur in A.

For example, given:

  A[0] = 1
  A[1] = 3
  A[2] = 6
  A[3] = 4
  A[4] = 1
  A[5] = 2

the function should return 5.

Assume that:

        N is an integer within the range [1..100,000];
        each element of array A is an integer within the range [−2,147,483,648..2,147,483,647].

Complexity:

        expected worst-case time complexity is O(N);
        expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).

Elements of input arrays can be modified.
Copyright 2009–2015 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/

#include <vector>
#include <set>

int solution(vector<int> &A) {
    set<int> nums;
    for(int ii = 0; ii < A.size(); ii++) {
        nums.insert(A[ii]);
    }

    set<int>::iterator iter;
    int prev = 0;
    int missing = 0;
    for(iter = nums.begin(); iter != nums.end(); iter++) {
        if(*iter > 0 && *iter-prev > 1) {
            for(int jj = prev+1; jj < *iter; jj++) {
                if(jj > 0) {
                    missing = jj;
                    break;
                }
            }
        }
        prev = *iter;
    }
    if(missing == 0) {
        do {
            missing = prev+1;
            prev++;
        }while(missing <= 0);
    }
    return missing;
}
