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

