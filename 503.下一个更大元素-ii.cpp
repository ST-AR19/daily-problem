/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> result(nums.size(), -1);
        st.push(0);
        //我这里是直接转了两圈来解决循环数组的问题
        for(int i = 1; i < nums.size()*2; i++) {
            while(!st.empty() && nums[i%nums.size()] > nums[st.top()]) {
                result[st.top()] = nums[i%nums.size()];
                st.pop();
            }
            st.push(i%nums.size());
        }
        return result;
    }
};
// @lc code=end

