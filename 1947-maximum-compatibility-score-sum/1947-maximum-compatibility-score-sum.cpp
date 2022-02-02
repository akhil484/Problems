class Solution {
public:
    int score(vector<int> student, vector<int> mentor)
    {
        int score=0;
        for(int i=0;i<student.size();i++)
            score+=student[i]==mentor[i];
        return score;
    }
    
    int makeCombinations(vector<vector<int>>& students, vector<vector<int>>& mentors, int i, int mask)
    {
        if(i==students.size())
            return 0;
        int ans=0;
        for(int j=0;j<mentors.size();j++)
        {
            if(!((mask>>j)&1))
            {
                int new_mask=(mask|(1<<j));
                ans = max(ans,score(students[i],mentors[j])+makeCombinations(students,mentors,i+1,new_mask));
            }
        }
        return ans;
    }
    
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        return makeCombinations(students, mentors, 0, 0);
    }
};