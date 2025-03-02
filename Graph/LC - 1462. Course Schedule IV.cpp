/*
1. create an adjacency list "graph" for graphical representation
2. create an inDgree vector to keep track of node's indegree. Reduce indegre every time u process a node. add node to queue if indegree==0
i.e. not a prerequisite to any cource
3. keep updating memset : isPrequisite[course_a][cource_b] a we process the node by looking at the adjacency list of node with no prerequistie.
4. we maintain a queue for these node with indegree==0 and perform BFS(i.e. while(!queue.empty())
*/
class Solution {
public:
    // This method determines if the second course in each query is a prerequisite of the first.
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) 
    {
        // Create a 2D array to mark prerequisites.
        bool isPrerequisite[numCourses][numCourses];
        memset(isPrerequisite, false, sizeof(isPrerequisite));
      
        // Adjacency list for graph representation.
        vector<int> graph[numCourses];
      
        // Array to track the number of incoming edges for each course.
        vector<int> inDegree(numCourses, 0);
      
        // Build the graph and update in-degrees.
        for (auto &prerequisite : prerequisites) 
        {
            int course_a=prerequisite[0];
            int course_b=prerequisite[1];
            graph[course_a].push_back(course_b);//course_a is prerequisite if course_b
            ++inDegree[course_b];//therefore indegree of course b will increase
        }
      
        // Queue for BFS.
        queue<int> courseQueue;
      
        // Add courses with no prerequisites to the queue.
        for (int i = 0; i < numCourses; ++i) 
        {
            if (inDegree[i] == 0) 
            {
                courseQueue.push(i);
            }
        }
      
        // Process courses using BFS.
        while (!courseQueue.empty()) 
        {
            int current = courseQueue.front();
            courseQueue.pop();

            for (int adjacentCourse : graph[current]) 
            {
                // Mark current as a direct prerequisite of adjacentCourse.
                isPrerequisite[current][adjacentCourse] = true;
              
                // Mark all the prerequisites of current as prerequisites of adjacentCourse as well.
                for (int k = 0; k < numCourses; k++) 
                {
                    //If k is a prerequisite of current, then k is also a prerequisite of adjacentCourse.
                    isPrerequisite[k][adjacentCourse] |= isPrerequisite[k][current];
                }
              
                // If the adjacentCourse has no other prerequisites, add it to the queue.
                if (--inDegree[adjacentCourse] == 0) //Every time you process a course, you reduce the in-degree of its adjacent courses.
                {
                    courseQueue.push(adjacentCourse);//If a course has no more prerequisites (inDegree[adjacentCourse] == 0), it is ready to be processed and pushed into the queue.

                }
            }
        }
      
        // Now check the queries against the prerequisites map.
        vector<bool> results;
        for (const auto& query : queries) 
        {
            results.push_back(isPrerequisite[query[0]][query[1]]);
        }
      
        return results;
    }
};
