class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    static bool cmp(pair<int, int> &a, pair<int, int> &b) {
        if(a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    }
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        vector<pair<int, int>> meetings;
        
        for(int i = 0; i < start.size(); i++) {
            meetings.push_back({start[i], end[i]});
        }
        
        sort(meetings.begin(), meetings.end(), cmp);
        
        int cnt = 1;
        int endtime = meetings[0].second;
        for(int i = 1; i < start.size(); i++) {
            if(meetings[i].first > endtime) {
                cnt++;
                endtime = meetings[i].second;
            }
        }
        return cnt;
    }
};