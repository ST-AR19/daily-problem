/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 0;
        int right = num / 2;
        if(num == 1) return true;
        if(num == 0) return false;
        while (left <= right){
            int mid = left + (right - left) / 2;
            if(mid < num / (mid * 1.0)){
                left = mid + 1;
            }else if(mid > num / (mid * 1.0)){//乘以1.0和直接将mid改为float的区别在于
                right = mid - 1;              //直接改float也会改变mid计算出来的值，比如出现mid=0.5的情况
                                              //此时计算机的误差可能会带来误判
            }else{
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

