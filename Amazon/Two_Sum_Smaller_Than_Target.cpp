// "static void main" must be defined in a public class.


/*

Idea is to first sort both the input lists so that we can have a fixed structure to check. Its the same idea as that of TwoSum problem

Now keeping "i" fixed, we try to find the largest "j" ,such that the sumof these elements at i and j is <= target. 
If we find such elements, while keeping i fixed, we try to look for duplicate elements in list b that satisfy our propert , hence we do index--

Once we are done with all such pairs above, we increment i .

Since botht he lists are sorted in increasing order if a[i] + a[j] <= target then a[i+1] can never add up with b[j+1] to be <= target (since they will be bigger than i and j).
We use this property to increment i.
*/


typedef pair<int,int> _pair;
typedef vector<_pair> _list;

class Solution{
public:
  class compare{
  public:
    bool operator() (const _pair& a, const _pair& b){
      return a.second <= b.second; //CRITICAL: lists may contain duplicates <= is important
    }  
  };
  
  _list getPairs(_list& a, _list& b, int target)
  {
    sort(a.begin(), a.end(), compare());
    sort(b.begin(), b.end(), compare());
    int bestTillNow = INT_MIN;
      
    _list result;
      
    int a_pointer = 0;
    int b_pointer = b.size() - 1;
   
      while(a_pointer < a.size() && b_pointer >= 0){
        int sum = a[a_pointer].second + b[b_pointer].second;
        
        if(sum > target){
            b_pointer--;
        }else{
          if(sum >= bestTillNow){ //these makes sure we only check for values which are at least better than the besttillnow
            if(bestTillNow < sum){ 
              // Youll reset the result only if you found a better val.
              // The better val will always be <= target , so if the better val IS the target youll clear
              result.clear();
              bestTillNow = sum;
            }
            
            int tmp = b_pointer;
            while(tmp >= 0 && b[b_pointer].second == b[tmp].second){
              result.push_back({make_pair(a[a_pointer].first, b[tmp].first)});
              tmp--;
            }
          }
          a_pointer++;
        }//sum <= target
      } //while end
    
    return result ;
  }
    
  
  void printPairs(_list input){
    for(auto &i: input)
      cout << "Element ids : " << i.first << " and : " << i.second << " are the pairs " <<endl;
  }
};

int main(){
  _list a = {{1,2}, {2,4}, {3,6}};
  _list b = {{1,2}, {2,1}};
  
  _list c = {{1,3}, {2,5}, {3,7}, {4,10}};
  _list d = {{1,2}, {2,3}, {3,4}, {4,5}};

  _list e = {{1,8}, {2,7}, {3,14}};
  _list f = {{1,5}, {2,10}, {3,14}};
  
  _list g = {{1,8}, {2,15}, {3,9}};
  _list h = {{1,8}, {2,11}, {3,12}};
  
  _list i = {{1,8}, {2,15}, {3,9}};
  _list j = {{1,8}, {2,11}, {3,12}, {4,11}};

  Solution s;
  s.printPairs(s.getPairs(a,b,7));
  cout<<"=========" <<endl;
  s.printPairs(s.getPairs(c,d,10));
  cout<<"=========" <<endl;
  s.printPairs(s.getPairs(e,f,20));
  cout<<"=========" <<endl;
  s.printPairs(s.getPairs(g,h,20));
  cout<<"=========" <<endl;
  s.printPairs(s.getPairs(g,h,1));
  cout<<"=========" <<endl;
  s.printPairs(s.getPairs(i,j,20));
  return 0;
}