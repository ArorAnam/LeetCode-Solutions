class Solution {
    //Could do if nums[i]<= 0 or nums[i] > nums.size() disregarder
    //          else add to temp[nums[i]] = true;
    // Then return the first temp[i] which doesn't exists
public:
    int firstMissingPositive(vector<int>& nums) {
        // No numbers so return
        if(nums.size() == 0){
            return 1;
        }
        std::set<int> sort;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                sort.insert(nums[i]);
            }
        }

        //No positive so return
        if(sort.size() == 0){
            return 1;
        }

        std::set<int>::iterator itter=sort.begin();
        int prev = *itter;
        itter ++;

        // Smallest isn't 1 so return
        if(prev > 1){
            return 1;
        }

        for(std::set<int>::iterator it = itter; it!=sort.end(); ++it){
            if(*it != prev + 1){
                return prev + 1;
            }
            prev = *it;
        }


        return prev+1;
    }
};
