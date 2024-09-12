/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;//慢指针
        for(int fast = 0; fast < nums.size() ; fast++){//使用<= num.size()-1时可能会造成数组的越界
            if(nums[fast] != val){
                nums[slow++] = nums[fast];
            }
        }
        return slow;
    }
};
// @lc code=end

