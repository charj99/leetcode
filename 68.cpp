#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        vector<string> wordsInLine;
        int lengthOfWords = 0;
        for (int i = 0; i < words.size(); i++) {
            if (canAppend(lengthOfWords, wordsInLine.size(), words[i].length(), maxWidth)) {
                wordsInLine.push_back(words[i]);
                lengthOfWords += words[i].length();
            }
            else {
                result.push_back(catWords(wordsInLine, lengthOfWords, maxWidth));
                wordsInLine.clear();
                wordsInLine.push_back(words[i]);
                lengthOfWords = words[i].length();
            }

        }
        result.push_back(catWordsForLastLine(wordsInLine, maxWidth));
        return result;
    }
private:
    bool canAppend(int lengthOfWords, int wordsNum, int wordLength, int maxWidth) {
        if (!wordsNum)
            return wordLength <= maxWidth;
        else return lengthOfWords + wordsNum + wordLength  <= maxWidth;
    }
    string buildSpaces(int n) {
        string result;
        for (int i = 0; i < n; i++)
            result += " ";
        return result;
    }
    string catWords(vector<string>& wordsInLine, int lengthOfWords, int maxWidth ) {
        int wordsNum = wordsInLine.size();
        int spaces = maxWidth - lengthOfWords;
        string result;
        if (wordsNum == 1) {
            result = wordsInLine[0] + buildSpaces(spaces);
        } else {
            int averageSpace = spaces / (wordsNum - 1);
            int moreSpace = spaces % (wordsNum - 1);
            string averageSpaceStr = buildSpaces(averageSpace);
            for (int i = 0; i < wordsNum; i++) {
                if (i < moreSpace)
                    result += wordsInLine[i] + averageSpaceStr + " ";
                else if (i == wordsNum - 1)
                    result += wordsInLine[i];
                else result += wordsInLine[i] + averageSpaceStr;
            }
        }
        return result;
    }
    string catWordsForLastLine(vector<string>& wordsInLine, int maxWidth) {
        string result;
        for (int i = 0; i < wordsInLine.size(); i++) {
            if (i != wordsInLine.size() - 1)
                result += wordsInLine[i] + " ";
            else result += wordsInLine[i];
        }
        return result + buildSpaces(maxWidth - result.length());
    }
};

int main() {
    int maxWidth;
    cin >> maxWidth;
    string word;
    vector<string> words;
    while (cin >> word) {
        words.push_back(word);
    }

    Solution* solution = new Solution();
    vector<string> result = solution->fullJustify(words, maxWidth);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    system("pause");
    return 0;
}