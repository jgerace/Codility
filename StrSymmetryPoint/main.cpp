/*
Write a function:

    int solution(string &S);

that, given a string S, returns the index (counting from 0) of a character such that the part of the string to the left of that character is a reversal of the part of the string to its right. The function should return −1 if no such index exists.

Note: reversing an empty string (i.e. a string whose length is zero) gives an empty string.

For example, given a string:

"racecar"

the function should return 3, because the substring to the left of the character "e" at index 3 is "rac", and the one to the right is "car".

Given a string:

"x"

the function should return 0, because both substrings are empty.

Assume that:

        the length of S is within the range [0..2,000,000].

Complexity:

        expected worst-case time complexity is O(length(S));
        expected worst-case space complexity is O(1) (not counting the storage required for input arguments).

Copyright 2009–2015 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
*/

int solution(string &S) {
    int len = S.length();
    int idx = -1;
    int ii = 0, jj = len-1;
    for(; ii <= jj; ii++, jj--) {
        if(ii == jj) {
            idx = ii;
            break;
        }
        else if(S[ii] != S[jj] || jj < ii) {
            return -1;
        }
    }
    return idx;
}
