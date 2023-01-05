const int N = 1e5;
const int offset = 4e4;
class Solution {
public:
    // left ---> st to mid
    // right ---> mid + 1 to end
    vector<int>tree;
    long long func(int curr, int st, int ed, int qst, int qed)
    {
        if(st >= qst and ed <= qed) return tree[curr];
        if(st > qed or ed < qst) return 0;

        int mid = st + (ed - st) / 2;
        return 0LL + func(2*curr, st, mid, qst, qed) + func(2*curr+1, mid + 1, ed, qst, qed);
    }
    void query(int st, int ed, int curr, int target)
    {
        if(st == ed)
        {
            tree[curr] ++;
            return;
        }
        int mid = st + (ed - st) / 2;
        if(target <= mid) query(st, mid, 2*curr, target);
        else query(mid+1, ed, 2*curr+1, target);
        tree[curr] = tree[2*curr] + tree[2*curr+1]; 
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        long long ans = 0LL;
        tree.resize(4*N+5);

        int n = nums1.size();
        for(int j=0;j<n;++j)
        {
            long long maxx = 0LL + nums1[j] - nums2[j] + diff + offset;
            ans = ans + 0LL + func(1, 1, N, 1, maxx);
            maxx = maxx - diff;
            query(1, N, 1, maxx);
        }
        return ans;
    }
};