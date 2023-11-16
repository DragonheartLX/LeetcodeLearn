/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* curNode = nullptr;

        bool sign = false;
        
        while (l1 != nullptr || l2 != nullptr)
        {
            int a = 0;
            int b = 0;

            if (l1 != nullptr)
            {
                a = l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr)
            {
                b = l2->val;
                l2 = l2->next;
            }
            
            int newVal = a + b + (sign ? 1 : 0);

            sign = false;

            if (newVal >= 10)
            {
                newVal = newVal % 10;
                sign = true;
            }
            

            if (curNode == nullptr)
                head = curNode = new ListNode(newVal);
            else
                curNode = curNode->next = new ListNode(newVal);

        }

        if (sign)
            curNode = curNode->next = new ListNode(1);
        
        return head;
    }
};
// @lc code=end

