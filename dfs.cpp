#include <iostream>
#include <stack>
using namespace std;

const int num_nodes = 5;
bool visited[num_nodes] = {false};
int graph[num_nodes][num_nodes] = {
    {0, 0, 1, 0, 1},
    {0, 0, 0, 0, 1},
    {1, 0, 0, 1, 1},
    {0, 0, 1, 0, 1},
    {1, 1, 1, 1, 0}
};

void dfs(int start_node){
    stack<int> stack;
    stack.push(start_node);
    visited[start_node] = true;

    cout<< "Depth First Traversal: ";
    while(!stack.empty()){
        int current_node = stack.top();
        stack.pop();
        cout<< current_node << " ";

        for(int neighbor = 0; neighbor < num_nodes; ++neighbor){
            if(graph[current_node][neighbor] && !visited[neighbor]){
                stack.push(neighbor);
                visited[neighbor] = true; // Mark neighbor as visited
            }
        }
    }
    cout<< endl;
}

int main(){
    int start_node ;
    cout<< "Enter the starting node (index from 0 to "<< num_nodes - 1 <<"): " ;
    cin>>start_node;
    if(start_node<0 || start_node>=num_nodes){
        cout<<"Invalid Starting Node!\n";
        return 1;
    }
    dfs(start_node);
    return 0;
}
