/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow1 = head;//判断是否有环
        ListNode* slow2 = head;//找到环的入口
        //后一个条件是为了排除只有一个头结点的情况
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow1 = slow1->next;
            if(fast == slow1) break;
        }
        //后一个条件在这也是为了排除只有头结点的情况
        //因为前面有可能在next的位置跳出循环，此时fast可能还不是空值
        if(fast == nullptr || fast->next == nullptr) return NULL;
        while(slow1 != slow2){
            slow1 = slow1->next;
            slow2 = slow2->next;
        }
        return slow1;
    }
};
// @lc code=end

