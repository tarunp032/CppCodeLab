#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstdlib>
#include <ctime>
using namespace std;

class RandomizedCollection {
private:
    vector<int> elements;
    unordered_map<int, unordered_set<int>> indexMap;
    
public:
    RandomizedCollection() {
        srand(time(0));
    }
    
    bool insert(int val) {
        bool doesNotExist = indexMap[val].empty();
        elements.push_back(val);
        indexMap[val].insert(elements.size() - 1);
        return doesNotExist;
    }
    
    bool remove(int val) {
        if (indexMap[val].empty()) return false;
        
        int idxToRemove = *indexMap[val].begin();
        int lastElement = elements.back();
        
        elements[idxToRemove] = lastElement;
        indexMap[lastElement].insert(idxToRemove);
        indexMap[lastElement].erase(elements.size() - 1);
        
        elements.pop_back();
        indexMap[val].erase(idxToRemove);
        
        if (indexMap[val].empty()) {
            indexMap.erase(val);
        }
        
        return true;
    }
    
    int getRandom() {
        return elements[rand() % elements.size()];
    }
};

int main() {
    RandomizedCollection collection;
    collection.insert(1);
    collection.insert(1);
    collection.insert(2);
    cout << "Random element: " << collection.getRandom() << endl;
    collection.remove(1);
    cout << "Random element after removal: " << collection.getRandom() << endl;
    return 0;
}