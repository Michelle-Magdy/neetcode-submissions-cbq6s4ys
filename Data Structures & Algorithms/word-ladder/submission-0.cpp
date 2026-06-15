#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Put all words in a set for O(1) lookups
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        
        // If the endWord isn't even in the list, no sequence exists
        if (wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }

        queue<string> q;
        q.push(beginWord);
        
        int levels = 1; // Start counting level from 1 (the beginWord itself)

        while (!q.empty()) {
            int size = q.size();
            
            // Process all words at the current level
            for (int i = 0; i < size; i++) {
                string currWord = q.front();
                q.pop();

                // Target found!
                if (currWord == endWord) {
                    return levels;
                }

                // Try changing each character of the word from 'a' to 'z'
                for (int j = 0; j < currWord.size(); j++) {
                    char originalChar = currWord[j];

                    for (char c = 'a'; c <= 'z'; c++) {
                        currWord[j] = c;

                        // If this newly formed word is in our set
                        if (wordSet.find(currWord) != wordSet.end()) {
                            q.push(currWord);
                            // Remove it from the set so it acts as "visited"
                            wordSet.erase(currWord);
                        }
                    }
                    // Restore the original character for the next position loop
                    currWord[j] = originalChar;
                }
            }
            levels++; // Increment level after exploring all neighbors at this depth
        }

        return 0; // Return 0 if no ladder is found
    }
};