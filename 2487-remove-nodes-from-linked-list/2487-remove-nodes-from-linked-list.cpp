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
    ListNode* removeNodes(ListNode* head) {
        ListNode* temp=head;
      long long n=0;
      while(temp)
      {
        n++;
        temp=temp->next;
      }
      temp=head;
      vector<int>v(n); int i=0;
      while(temp)
      {
        v[i]=temp->val;i++;
        temp=temp->next;
      }
      stack<int>st;
      vector<int>ans;
      for(int i=n-1;i>=0;i--)
      {
        if(st.empty())
        {
          ans.push_back(v[i]);
          st.push(v[i]);
        }
        else
        {
          if(st.top()<=v[i])
          {ans.push_back(v[i]);
           st.push(v[i]);}
        }
      }
      reverse(ans.begin(),ans.end());
      ListNode* head1=new ListNode(0);
      temp=head1;
      for(auto x:ans)
      {
        temp->next=new ListNode(x);
        temp=temp->next;
      }
      return head1->next;
    }
};