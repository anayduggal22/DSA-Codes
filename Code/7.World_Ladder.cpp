// Word Ladder I [ Brute Force BFS using Vector ]

// First, we store all words from wordList into a vector and also create a visited array.
// We start from the beginWord and try to reach the endWord.
// We use BFS because we need the shortest transformation sequence.
// Instead of queue, we use a vector and a front pointer to simulate queue.
// For each word, we try to change every character from 'a' to 'z'
// and check if the new word exists in the wordList and is not visited.
// If the new word matches endWord, we return the length + 1.
// Otherwise, we push the new word into the vector and continue.
// If we cannot reach endWord, we return 0.

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {

        vector<int> visited(wordList.size(), 0);
        
        vector<string> q; // Acting like a queue

        q.push_back(beginWord);
        int front = 0; // acting like front of queue

        int length = 1;

        while (front < q.size()) // Till queue is not empty
        {
            // For each level
            int size = q.size() - front;

            for (int i = 0; i < size; i++)
            {
                // Poping each word from front
                string word = q[front];
                front++;

                // For each words lenght
                for (int j = 0; j < word.length(); j++)
                {
                    char original = word[j]; // Storing that index char

                    // checking that word with different characters
                    for (char ch = 'a'; ch <= 'z'; ch++)
                    {
                        word[j] = ch;

                        if (word == endWord)
                        {
                            return length + 1;
                        }

                        // Check in wordList
                        for (int k = 0; k < wordList.size(); k++)
                        {
                            if (visited[k] == 0 && wordList[k] == word)
                            {
                                visited[k] = 1;
                                q.push_back(wordList[k]);
                            }
                        }
                    }

                    word[j] = original;
                }
            }
            // Btw while and for loop, incrementing for each level
            length++;
        }

        return 0;
    }
};


int main()
{
    Solution obj;

    string beginWord = "hit";
    string endWord = "cog";

    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    int result = obj.ladderLength(beginWord, endWord, wordList);

    cout << "Shortest transformation length: " << result;

    return 0;
}