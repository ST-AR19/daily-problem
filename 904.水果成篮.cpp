/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */

// @lc code=start
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int first = 0,second = 0;
        int result = 0;
        for(int end = 0;end < fruits.size();end++){
            if(fruits[end] != fruits[first] 
                && fruits[first] == fruits[second]){//只有一个种类的时候加入第二个种类
                second = end;
            }else if(fruits[end] != fruits[first] 
                    && fruits[end] != fruits[second]
                    && fruits[first] != fruits[second]){//出现第三个种类的情况
                        first = second;
                        second = end;
                        int temp = first;
                        for(; temp < second; temp++){//确保当前窗口只有两个元素
                            if(fruits[temp] != fruits[first]
                                && fruits[temp] != fruits[second]){
                                    first = temp;
                                }
                        }
            }
            result = result > end - first ? result : end - first;
        }
        return result+1;
    }
};
/*
优化版本*/
/*class Solution {
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> cnt;//设置一个哈希表，一个代表种类，一个代表数量
        int left = 0, ans = 0;
        for(int right = 0; right < n; ++right){
            ++cnt[fruits[right]];//向哈希表中插入值
            while (cnt.size()>2){//当哈希表中的种类大于2的时候，维护当前的窗口
                auto it = cnt.find(fruits[left]);
                --it->second;
                if(it->second == 0){//不断查找直到将原本窗口中的一个种类完全删干净
                    cnt.erase(it);
                }
                ++left;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
}*/
// @lc code=end

