/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        if(x == 0){
            return 0;
        }
        if(x == 1){
            return 1;
        }
        while (left < right){
            int half = left + (right - left) / 2;
            if(half <= x / half && (half+1) > x / (half + 1)){//除法防止超过范围
                return half;
            }else if(half > x / half){
                right = half - 1;
            }else{
                left = half + 1;//给边界一个增加的值防止陷入死循环
            }
        }
        return left;
    }
};
// @lc code=end

