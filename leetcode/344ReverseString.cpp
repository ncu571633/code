/*
Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh". 
*/

class Solution {
	public:
		string reverseString(string s) {
			for(int i=0, j=s.length()-1; i<j; i++, j--)
			{
				char a = s[i];
				s[i] = s[j];
				s[j] = a;
			}
			return s;
		}
}
