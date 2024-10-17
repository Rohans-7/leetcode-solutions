class Solution {
public:
    int maximumSwap(int num) {
        string temp = to_string(num);
        int n = temp.size();

        vector<int> maxToRight(n);
        char mx=n-1;
        maxToRight[n-1]=mx;
        for(int i=n-2; i>=0; --i){
            int rightMaxInd=maxToRight[i+1];

            if(temp[i]>temp[rightMaxInd]){
                maxToRight[i]=i;
            }
            else{
                maxToRight[i]=rightMaxInd;
            }
        }

        for(int i = 0; i < n; ++i){
            if(temp[i]<temp[maxToRight[i]]){
                swap(temp[i],temp[maxToRight[i]]);
                break;
            }
        }


        return stoi(temp);
    }
};