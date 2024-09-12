/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start

class Solution {
public:
    //辅助实现小顶堆
    class temp {
    public: 
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs){
            return lhs.second > rhs.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        //统计元素的出现次数
        unordered_map<int, int> map;
        for(int i=0; i<nums.size(); i++){
            map[nums[i]]++;
        }
        //创建优先队列
        priority_queue<pair<int, int>, vector<pair<int, int>>, temp> result_heap;
        //维护优先队列，保证k个元素满足题目
        for(unordered_map<int, int>::iterator it=map.begin();it != map.end(); it++){
            result_heap.push(*it);
            if(result_heap.size()>k){
                result_heap.pop();
            }
        }
        //对小顶堆倒序输出结果
        vector<int> result(k);
        for(int i=k-1;i >= 0; i--){
            result[i] = result_heap.top().first;
            result_heap.pop();
        }
        return result;

    }
};
// @lc code=end

