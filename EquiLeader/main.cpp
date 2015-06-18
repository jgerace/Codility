/*
A non-empty zero-indexed array A consisting of N integers is given.

The leader of this array is the value that occurs in more than half of the elements of A.

An equi leader is an index S such that 0 ≤ S < N − 1 and two sequences A[0], A[1], ..., A[S] and A[S + 1], A[S + 2], ..., A[N − 1] have leaders of the same value.

For example, given array A such that:

    A[0] = 4
    A[1] = 3
    A[2] = 4
    A[3] = 4
    A[4] = 4
    A[5] = 2

we can find two equi leaders:

        0, because sequences: (4) and (3, 4, 4, 4, 2) have the same leader, whose value is 4.
        2, because sequences: (4, 3, 4) and (4, 4, 2) have the same leader, whose value is 4.

The goal is to count the number of equi leaders.

Write a function:

    int solution(vector<int> &A);

that, given a non-empty zero-indexed array A consisting of N integers, returns the number of equi leaders.

For example, given:

    A[0] = 4
    A[1] = 3
    A[2] = 4
    A[3] = 4
    A[4] = 4
    A[5] = 2

the function should return 2, as explained above.

Assume that:

        N is an integer within the range [1..100,000];
        each element of array A is an integer within the range [−1,000,000,000..1,000,000,000].

Complexity:

        expected worst-case time complexity is O(N);
        expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).

Elements of input arrays can be modified.
Copyright 2009–2015 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/

#include <climits>

int getLeader(vector<int> &A, int begin, int end);

int solution(vector<int> &A) {
    int count = 0;
    for(int ii = 0; ii < A.size()-1; ii++) {
        int L1 = getLeader(A, 0, ii+1);
        int L2 = getLeader(A, ii+1, A.size());
        if(L1 != INT_MIN && L2 != INT_MIN && L1 == L2) {
            count++;
        }
    }
    return count;
}

int getLeader(vector<int> &A, int begin, int end) {
    int size = 0;
    int value = INT_MIN;
    for(int ii = begin; ii < end; ii++) {
        if(size == 0) {
            size++;
            value = A[ii];
        }
        else {
            if(value != A[ii]) {
                size--;
            }
            else {
                size++;
            }
        }
    }
    int candidate = INT_MIN;
    if(size > 0) {
        candidate = value;
    }
    int count = 0;
    for(int ii = begin; ii < end; ii++) {
        if(A[ii] == candidate) {
            count++;
        }
    }
    int leader = INT_MIN;
    if(count > (end - begin)/2) {
        leader = candidate;
    }
    return leader;
}
