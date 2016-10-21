Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.

Example:

n = 15,

Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]


class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> v;
        for(int i=1; i<=n; i++) {
            string s;
            if(i%3==0)
                s = string("Fizz");
            if(i%5==0)
                s = s + string("Buzz");
            if(i%3 && i%5) 
                s = to_string(i);
            v.push_back(s);
        }
        return v;
    }
};
