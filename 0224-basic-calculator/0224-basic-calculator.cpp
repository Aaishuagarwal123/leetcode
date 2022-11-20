class Solution {
public:
    int calculate(string s) {
        int n=s.length();
      int ans=0;
      int sign=1;
      int num=0;
      stack<int>st;
     for(int i=0;i<n;i++)
        {
            if(isdigit(s[i]))
            {
              num=0;
                  while(i<n && isdigit(s[i]))
                {
                    num = num*10 + (s[i] -'0');
                    i++;
                }
              i--;
                ans+=num*sign;
            }
            
            else if(s[i] == '+')
            {
                sign=1;
            }
            else if (s[i] == '-')
            {
                sign=-1;
            }
            else if (s[i] == '(')
            {
                st.push(ans);
                st.push(sign);
                ans=0;
                sign=1;
            }
            else if(s[i] == ')')
            {
              ans=ans*st.top();
                st.pop();
               ans+= st.top();
                st.pop();
               
            }
        }
      return ans;
    }
};