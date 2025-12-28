#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

// Type alias for the graph structure: device name -> list of connected devices
using Graph = map<string, vector<string>>;

// Global counter for the total number of paths found
long long total_paths = 0;

/**
 * @brief Recursively finds all paths from the current node to the target node.
 * * Uses Depth-First Search (DFS) to explore all possible paths.
 * * @param graph The adjacency list representing the device connections.
 * @param current_node The device name currently being visited.
 * @param target_node The final device name (out in this problem).
 * @param current_path The list of nodes in the path built so far.
 */
void findAllPaths(const Graph& graph, const string& current_node, const string& target_node, vector<string>& current_path) {
    // Add the current node to the path
    current_path.push_back(current_node);

    // 1. Base Case: Target node reached
    if (current_node == target_node) {
        // We found a complete path from 'you' to 'out'
        total_paths++;
        
        // --- Optional: Print the path found ---
        // cout << "Path " << total_paths << ": ";
        // for (size_t i = 0; i < current_path.size(); ++i) {
        //     cout << current_path[i] << (i == current_path.size() - 1 ? "" : " -> ");
        // }
        // cout << endl;
        // -------------------------------------

        // Backtrack: Remove the target node before returning
        current_path.pop_back();
        return;
    }

    // 2. Recursive Step: Explore neighbors
    // Check if the current node has outputs defined in the graph
    if (graph.count(current_node)) {
        // Iterate over all devices connected to the current node's outputs
        for (const string& neighbor : graph.at(current_node)) {
            // Recursive call to continue the search from the neighbor
            findAllPaths(graph, neighbor, target_node, current_path);
        }
    }

    // 3. Backtrack: Remove the current node from the path when all its branches are explored
    current_path.pop_back();
}


/**
 * @brief Parses the input file and builds the graph structure.
 * * @param filename The name of the input file (e.g., "input.txt").
 * @param graph The map to store the device connections (adjacency list).
 */
void parseInput(const string& filename, Graph& graph) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        exit(1);
    }

    string line;
    while (getline(file, line)) {
        // Format is: device: output1 output2 output3...

        // Find the position of the colon
        size_t colon_pos = line.find(':');
        if (colon_pos == string::npos) continue; // Skip malformed lines

        // Extract the device name (key)
        string device = line.substr(0, colon_pos);
        // Trim leading/trailing whitespace from the device name
        // (Though usually not needed for this type of input)
        device.erase(remove_if(device.begin(), device.end(), ::isspace), device.end());

        // Extract the list of outputs (value)
        string outputs_str = line.substr(colon_pos + 1);
        
        stringstream ss(outputs_str);
        string output_device;
        vector<string> connections;

        // Read all output device names from the stringstream
        while (ss >> output_device) {
            connections.push_back(output_device);
        }

        // Store the connections in the graph
        graph[device] = connections;
    }

    file.close();
}


int main() {
    // --- Configuration ---
    const string INPUT_FILE = "input.txt"; // Ensure your input data is in this file
    const string START_NODE = "you";
    const string END_NODE = "out";
    // ---------------------
    
    // 1. Parse the input and build the graph
    Graph device_graph;
    parseInput(INPUT_FILE, device_graph);

    // 2. Perform the path-finding search
    vector<string> path_in_progress; // Stores the nodes of the path being explored
    
    cout << "Starting search for paths from " << START_NODE << " to " << END_NODE << "..." << endl;

    // Check if the starting node exists in the graph
    if (device_graph.count(START_NODE) || START_NODE == END_NODE) {
        findAllPaths(device_graph, START_NODE, END_NODE, path_in_progress);
    } else {
        cout << "Error: Starting device '" << START_NODE << "' not found in the input." << endl;
    }

    // 3. Output the final result
    cout << "\n--- Result ---" << endl;
    cout << "Total number of paths from '" << START_NODE << "' to '" << END_NODE << "': " << total_paths << endl;
    cout << "--------------" << endl;

    return 0;
}