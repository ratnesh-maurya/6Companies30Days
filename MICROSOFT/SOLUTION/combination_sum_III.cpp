class Solution {
public:
    void solve(int st,int k,int n,vector<int> &temp,vector<vector<int>> &ans)
    {
        if(k<=0)
        {
            if(n==0) ans.push_back(temp);
            return;
        }
        
        for(int i=st;i<=9;i++)    
        {
            temp.push_back(i);
            solve(i+1,k-1,n-i,temp,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(1,k,n,temp,ans);
        return ans;
    }
};