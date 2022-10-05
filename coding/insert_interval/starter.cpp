class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
         vector<vector<int>> output;
        if(intervals.size()==0){//edge case1
            output.push_back(newInterval);
        return output;
        }
        int flag=1;
        for (int i=0;i<intervals.size();i++){
            if(intervals[i][0]>newInterval[0]){
                intervals.insert(intervals.begin() + i,newInterval);
                flag=0;
            break;
            }
        }
        if (flag==1)//edge case2
            intervals.push_back(newInterval);
        
        output.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(output.back()[1]>=intervals[i][0])
                output.back()[1]=max(output.back()[1],intervals[i][1]);
            else
                output.push_back(intervals[i]);
        }
        return output;
    }
};
s
