class Solution {
public:
    int evalRPN(vector<string>& t) {
        stack<long long int>s;
        for(int i=0;i<t.size();i++)
        { 
            if(t[i]!="+"&&t[i]!="-"&&t[i]!="*"&&t[i]!="/")
            {
                long long int k=stoll(t[i],0,10);
                s.push(k);
            }
            else
            {
                long long int a=s.top();
                s.pop();
                long long int b=s.top();
                s.pop();
                if(t[i]=="+")
                    s.push(a+b);
                else if(t[i]=="-")
                    s.push(b-a);
                else if(t[i]=="*")
                    s.push(a*b);
                else if(t[i]=="/")
                    s.push(b/a);
            }
        }
        return s.top();
    }
};