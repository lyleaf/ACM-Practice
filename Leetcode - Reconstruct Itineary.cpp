class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        int n = tickets.size();
        map<string,priority_queue<string, vector<string>, std::greater<string>>> mm;
        map<string,int> outwards;//Number of out going cities.
        for (int i=0;i<n;i++){
            mm[tickets[i].first].push(tickets[i].second);
            outwards[tickets[i].first]+=1;
        }
        vector<string> r;
        stack<string> s;
        s.push("JFK");

        
        while(!s.empty()){
            while(mm[s.top()].size()!=0){
                string temp = mm[s.top()].top();
                mm[s.top()].pop();
                s.push(temp);
            }
            r.push_back(s.top());
            //cout << s.top();
            s.pop();
        }
        
        reverse(r.begin(),r.end());
        return r;
    }
}; 
