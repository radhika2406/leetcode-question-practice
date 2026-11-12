/*242. VALID ANAGRAM

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

Example 1:

Input: s = "anagram", t = "nagaram"

Output: true*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()){
            return false;
        }
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        return (s==t);
    }
};
