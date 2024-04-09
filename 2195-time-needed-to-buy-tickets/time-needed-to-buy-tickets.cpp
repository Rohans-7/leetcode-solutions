class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int>q;

        int times=0;

        for(int i=0; i<tickets.size(); ++i){
            q.push(i);
        }

        while(true){
            if(tickets[k]==0){
                break;
            }

            int curr=q.front();

            tickets[curr]--;
            times++;
            q.pop();

            if(tickets[curr]!=0){
                q.push(curr);
            }
        }

        return times;
    }
};