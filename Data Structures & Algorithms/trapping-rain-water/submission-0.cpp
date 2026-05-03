class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> height_l(height.size(), 0), height_r(height.size(), 0);
        int l=0, r=height.size()-1, ans=0;
        cout<<"height_l"<<endl;
        for (int i = 0; i<height.size()-1; i++) {
            height_l[i] = ans;
            if (height[i] > ans) ans = height[i];
            cout<<height_l[i]<<" ";
        }
        ans = 0;
        cout<<"\nheight_r"<<endl;
        for (int i=height.size()-1; i>=0; i--) {
            height_r[i] = ans;
            if (height[i] > ans) ans = height[i];
            cout<<height_r[i]<<" ";
        }
        ans = 0;
        for (int i=0; i<height.size()-1; i++) 
            if ((min(height_r[i], height_l[i]) - height[i]) > 0)
                ans+=(min(height_r[i], height_l[i]) - height[i]);
        
        return ans;
    }
};
