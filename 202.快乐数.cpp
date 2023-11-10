/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
public:
    int getSum(int n){
        int sum=0;
        while(n){
            sum += (n%10)*(n%10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> judge;
        int sum;
        while (true){
            sum = getSum(n);
            if(sum == 1) return true;
            //注意在unordered_set中使用find方法来判断该元素是否在集合中
            if(judge.find(sum) != judge.end()){
                return false;
            }else{
                //注意unordered_set中数据的插入方法是什么
                judge.insert(sum);
            }
            n = sum;
        }
        
    }
};
// @lc code=end

