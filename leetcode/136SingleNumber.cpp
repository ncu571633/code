/*
   given an array of integers, every element appears twice except for one. Find that single one.
 */

class Solution {
	public:
		int singleNumber(vector<int>& nums) {
			std::map<int, bool> temp;
			for(size_t i = 0; i<nums.size(); i++)
			{
				if(!temp.count(nums[i]))
				{
					temp.insert(std::make_pair(nums[i], 0)); 
				} else {
					temp[nums[i]] = 1;
				}
			}
			for(std::map<int, bool>::iterator i = temp.begin(); i!=temp.end(); i++)
			{
				if(!(i->second))
					return i->first;
			}
			return 0;
		}
}

/*

   */


/*
XOR is commutative and associative (so the order in which it's done is irrelevant).
a number XORed with itself will always be zero.
zero XORed with a number will be that number
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int temp = 0;
        for(int i=0; i<nums.size(); i++)
            temp ^= nums[i];
        return temp;
    }
};