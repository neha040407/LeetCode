class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;

        for (int student : students) {
            q.push(student);
        }

        int sandwich = 0;
        int rotation = 0;

        while (!q.empty()) {
            
            if (q.front() == sandwiches[sandwich]) {
                q.pop();
                sandwich++;
                rotation = 0;
            }
            else {
                q.push(q.front());
                q.pop();
                rotation++;
            }

            if (rotation == q.size()) {
                break;
            }
        }

        return q.size();
    }
};