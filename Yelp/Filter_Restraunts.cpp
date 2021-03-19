class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        
        auto logicEnd = partition(restaurants.begin(), restaurants.end(), 
                  [&](const auto& a)
                  {
                      if(veganFriendly && a[2] == false) return false;
                      if(a[3] > maxPrice) return false;
                      if(a[4] > maxDistance) return false;
                      return true;
                  });
        
        
        sort(restaurants.begin(), logicEnd,
            [&](const auto& a, const auto& b)
             {
                 if(a[1] == b[1]) return a[0] > b[0];
                 return a[1] > b[1];
             });
        
        vector<int> ans;
        for(auto it = restaurants.begin(); it != logicEnd; ++it)
        {
            ans.push_back((*it)[0]);
        }
        return ans;
    }
};