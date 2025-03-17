#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    unordered_map<int, ListNode *> mp;
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        ListNode *tail = head;
        int sum = 0;
        while (tail != nullptr)
        {
            sum += tail->val;
            mp[sum] = tail;
            tail = tail->next;
        }
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        tail = dummy;
        int pref = 0;
        while (tail != nullptr)
        {
            pref += tail->val;
            if (mp.find(pref) != mp.end())
            {
                tail->next = mp[pref]->next;
                mp.erase(pref);
            }
            tail = tail->next;
        }
        return dummy->next;
    }
};