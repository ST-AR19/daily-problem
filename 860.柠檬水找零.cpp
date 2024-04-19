/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cnt5=0;
        int cnt10=0;
        for(int i = 0; i < bills.size(); i++){
            if(bills[i] == 5) cnt5++;
            if(bills[i] == 10){
                if(cnt5 < 1) return false;
                cnt10++;
                cnt5--;
            }
            if(bills[i] == 20){
                if(cnt5 < 1 || cnt10 < 1 && cnt5 < 3)  return false;
                if(cnt10 > 0) {
                    cnt10--;
                    cnt5--;
                }else{
                    cnt5 -= 3;
                }
            }
        }
        return true;
    }
};
// @lc code=end

