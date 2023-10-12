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
// @lc code=end

