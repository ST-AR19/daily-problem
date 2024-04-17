/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int preDiff = 0;
        int curDiff = 0;
        int result = 1;
        //对于当前差值的计算是采用i+1和i的差值，所以对于nums元素的遍历要少一个
        for(int i = 0; i < nums.size() - 1; i++){
            curDiff = nums[i+1] - nums[i];
            if(preDiff <= 0 && curDiff > 0 || preDiff >= 0 && curDiff < 0){
                result++;
                preDiff = curDiff;
            }
        }
        return result;
    }
};
// @lc code=end

