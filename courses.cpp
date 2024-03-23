//name abdi teshome
#include <iostream>
#include <vector>

using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses, vector<int>());
    vector<int> indegree(numCourses, 0);
    
    // Build the graph and calculate the in-degree of each course
    for(auto pre : prerequisites) {
        int course = pre[0];
        int prerequisite = pre[1];
        graph[prerequisite].push_back(course);
        indegree[course]++;
    }
    
    // Topological sorting using Kahn's algorithm
    vector<int> queue;
    for(int i = 0; i < numCourses; i++) {
        if(indegree[i] == 0)
            queue.push_back(i);
    }
    
    int count = 0;
    while(!queue.empty()) {
        int curr = queue.front();
        queue.erase(queue.begin());
        count++;
        
        for(auto next : graph[curr]) {
            if(--indegree[next] == 0)
                queue.push_back(next);
        }
    }
    
    return count == numCourses;
}

int main() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;
    
    int numPrerequisites;
    cout << "Enter the number of prerequisites: ";
    cin >> numPrerequisites;
    
    vector<vector<int>> prerequisites(numPrerequisites, vector<int>(2));
    cout << "Enter the prerequisite courses (in the format 'course prerequisite'):\n";
    for(int i = 0; i < numPrerequisites; i++) {
        cin >> prerequisites[i][0] >> prerequisites[i][1];
    }
    
    bool isPossible = canFinish(numCourses, prerequisites);
    cout << (isPossible ? "Possible to finish all courses." : "Not possible to finish all courses.") << endl;
    
    return 0;
}

