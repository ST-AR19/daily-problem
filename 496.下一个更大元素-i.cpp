/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //暴力算法
        /*vector<int> ans(nums1.size(), -1);
        for(int i = 0; i < nums1.size(); i++) {
            for(int j = 0; j < nums2.size(); j++) {
                if(nums1[i] == nums2[j]) {
                    for(int k = j; k < nums2.size(); k++) {
                        if(nums2[k] > nums1[i]){
                            ans[i] = nums2[k];
                            break;
                        }
                    }
                    break;
                }
            }
        }
        return ans;*/
        //单调栈
        stack<int> st;
        vector<int> result(nums1.size(), -1);
        //预处理
        unordered_map<int, int> umap;
        for(int i = 0; i < nums1.size(); i++) umap[nums1[i]] = i;

        st.push(0);
        for(int i = 1; i < nums2.size(); i++) {
            //先确保找到了一个更大的数
            while(!st.empty() && nums2[i] > nums2[st.top()]){
                //再看原本比较的数是否是需要的数
                if (umap.count(nums2[st.top()]) > 0){
                    int index = umap[nums2[st.top()]];
                    result[index] = nums2[i];
                }
                st.pop();
            }
            st.push(i);
        }
        return result;
    }
};
// @lc code=end

