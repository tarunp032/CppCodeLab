#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string>

void alienOrder(const std::vector<std::string>& words) {
    std::unordered_map<char, std::unordered_set<char>> adjList;
    std::unordered_map<char, int> inDegree;
    
    for (const auto& word : words) {
        for (const auto& c : word) {
            inDegree[c] = 0;
        }
    }

    for (int i = 0; i < words.size() - 1; ++i) {
        std::string word1 = words[i];
        std::string word2 = words[i + 1];
        int len = std::min(word1.size(), word2.size());
        bool found = false;
        
        for (int j = 0; j < len; ++j) {
            if (word1[j] != word2[j]) {
                if (adjList[word1[j]].find(word2[j]) == adjList[word1[j]].end()) {
                    adjList[word1[j]].insert(word2[j]);
                    inDegree[word2[j]]++;
                }
                found = true;
                break;
            }
        }

        if (!found && word1.size() > word2.size()) {
            std::cout << "Invalid alien dictionary order." << std::endl;
            return;
        }
    }

    std::queue<char> q;
    for (const auto& entry : inDegree) {
        if (entry.second == 0) {
            q.push(entry.first);
        }
    }

    std::string result;
    while (!q.empty()) {
        char current = q.front();
        q.pop();
        result += current;

        for (const auto& neighbor : adjList[current]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    if (result.size() != inDegree.size()) {
        std::cout << "Cycle detected, invalid alien dictionary order." << std::endl;
    } else {
        std::cout << "Alien Dictionary Order: " << result << std::endl;
    }
}

int main() {
    std::vector<std::string> words = {"wrt", "wrf", "er", "ett", "rftt"};
    alienOrder(words);
    return 0;
}