#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <numeric>

using namespace std;

// Type alias for the graph structure: device name -> list of connected devices
using Graph = map<string, vector<string>>;

/**
 * @brief Recursively finds and counts all paths from a start node to a target node.
 * @param graph The adjacency list representing the device connections.
 * @param current_node The device name currently being visited.
 * @param target_node The final device name for this segment.
 * @param current_paths_count The reference to accumulate the count of paths found.
 */
void countPaths(const Graph& graph, const string& current_node, const string& target_node, long long& current_paths_count) {
    // 1. Base Case: Target node reached
    if (current_node == target_node) {
        current_paths_count++;
        return;
    }

    // 2. Recursive Step: Explore neighbors
    // Check if the current node has outputs defined in the graph
    if (graph.count(current_node)) {
        // Iterate over all devices connected to the current node's outputs
        for (const string& neighbor : graph.at(current_node)) {
            // Recursive call to continue the search from the neighbor
            countPaths(graph, neighbor, target_node, current_paths_count);
        }
    }
    // Note: No need for a 'visited' set and backtracking if the graph is a DAG, 
    // which is implied by the problem ("data only ever flows... it can't flow backwards").
}


/**
 * @brief Parses the input file and builds the graph structure.
 */
void parseInput(const string& filename, Graph& graph) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        exit(1);
    }

    string line;
    while (getline(file, line)) {
        size_t colon_pos = line.find(':');
        if (colon_pos == string::npos) continue;

        string device = line.substr(0, colon_pos);
        device.erase(remove_if(device.begin(), device.end(), ::isspace), device.end());

        string outputs_str = line.substr(colon_pos + 1);
        stringstream ss(outputs_str);
        string output_device;
        vector<string> connections;

        while (ss >> output_device) {
            connections.push_back(output_device);
        }

        graph[device] = connections;
    }

    file.close();
}


/**
 * @brief Calculates the number of paths for a sequence of segments.
 *
 * Example: For segments {"svr", "dac", "fft", "out"}, it computes:
 * (Paths svr->dac) * (Paths dac->fft) * (Paths fft->out)
 *
 * @param graph The device connection graph.
 * @param segments A vector of device names defining the sequential path.
 * @return The total number of unique paths following this segment order.
 */
long long calculateSegmentedPaths(const Graph& graph, const vector<string>& segments) {
    if (segments.size() < 2) return 0;

    // The result is the product of the number of paths in each segment
    long long total_paths = 1;

    // Iterate through the path segments (e.g., svr->dac, dac->fft, fft->out)
    for (size_t i = 0; i < segments.size() - 1; ++i) {
        const string& start_node = segments[i];
        const string& end_node = segments[i+1];
        
        long long segment_paths_count = 0;
        
        // Find paths for this segment
        // The `countPaths` function is initialized to 0 and updates the count by reference
        countPaths(graph, start_node, end_node, segment_paths_count);

        // If even one segment has 0 paths, the entire sequence has 0 paths
        if (segment_paths_count == 0) {
            return 0;
        }

        // Multiply the current total by the number of paths in the new segment
        // This is valid because paths in a DAG are independent in terms of counting.
        total_paths *= segment_paths_count;

        cout << "  - Paths from " << start_node << " to " << end_node << ": " << segment_paths_count << endl;
    }

    return total_paths;
}


int main() {
    // --- Configuration ---
    const string INPUT_FILE = "input.txt";
    const string START_NODE = "svr";
    const string END_NODE = "out";
    const string MIDDLE_NODE_1 = "dac"; // Digital-to-analog converter
    const string MIDDLE_NODE_2 = "fft"; // Fast Fourier Transform
    // ---------------------
    
    // 1. Parse the input and build the graph
    Graph device_graph;
    parseInput(INPUT_FILE, device_graph);

    long long total_required_paths = 0;

    // 2. Scenario 1: Path must follow S -> A -> B -> E (svr -> dac -> fft -> out)
    vector<string> sequence_1 = {START_NODE, MIDDLE_NODE_1, MIDDLE_NODE_2, END_NODE};
    cout << "### Calculating Sequence 1: " << START_NODE << " -> " << MIDDLE_NODE_1 << " -> " << MIDDLE_NODE_2 << " -> " << END_NODE << " ###" << endl;
    long long paths_s1 = calculateSegmentedPaths(device_graph, sequence_1);
    cout << "Total paths for Sequence 1: " << paths_s1 << endl;
    total_required_paths += paths_s1;
    
    cout << endl;

    // 3. Scenario 2: Path must follow S -> B -> A -> E (svr -> fft -> dac -> out)
    vector<string> sequence_2 = {START_NODE, MIDDLE_NODE_2, MIDDLE_NODE_1, END_NODE};
    cout << "### Calculating Sequence 2: " << START_NODE << " -> " << MIDDLE_NODE_2 << " -> " << MIDDLE_NODE_1 << " -> " << END_NODE << " ###" << endl;
    long long paths_s2 = calculateSegmentedPaths(device_graph, sequence_2);
    cout << "Total paths for Sequence 2: " << paths_s2 << endl;
    total_required_paths += paths_s2;


    // 4. Output the final result
    cout << "\n--- Final Result ---" << endl;
    cout << "Total number of paths from '" << START_NODE << "' to '" << END_NODE << "' that visit both '" << MIDDLE_NODE_1 << "' and '" << MIDDLE_NODE_2 << "': " << total_required_paths << endl;
    cout << "--------------------" << endl;

    return 0;
}