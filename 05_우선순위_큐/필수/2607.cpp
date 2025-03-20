#include <iostream>
#include <map>
#include <cmath>

using namespace std;

// 비슷한 단어인지 판단하는 함수
bool isSimilar(map<char, int> &first_word, map<char, int> &new_words){
    int length_diff = first_word.size() - new_words.size();
    int word_diff = 0;
    if(abs(length_diff) > 2){
        return false;
    }
    for(auto iter : first_word){
        if(new_words.count(iter.first) == 0){
            word_diff += iter.second;
        }
        else{
            word_diff += abs(new_words[iter.first] - iter.second);
        }
    }
    // 새로운 단어에만 있는 글자 추가하기
    for(auto iter : new_words){
        if(first_word.count(iter.first) == 0){
            word_diff += iter.second;
        }
    }
    // word_diff의 개수대로 분기
    if(word_diff > 2){
        return false;
    }
    if(word_diff == 2){
        // 두 글자 다 새로운 단어라면 치환한 게 아니므로
        if(abs(length_diff) == 2){
            return false;
        }
        return true;
    }
    // 한 글자 더하거나 뺀 경우나 같은 구성인 경우
    if(word_diff < 2){
        return true;
    }
}

int countWords(int n){
    string word;
    int count = 0;
    cin >> word;

    map<char, int> first_word;

    for(int i = 0; i < word.length(); i++){
        first_word[word[i]]++;
    }

    for(int i = 0; i < n - 1; i++){
        string new_word;
        cin >> new_word;
        
        map<char, int> new_words;
        for(int j = 0; j < new_word.length(); j++){
            new_words[new_word[j]]++;
        }
        // 비교
        int length = word.length() - new_word.length();
        // 단어 길이가 2이상 차이 나면 안되므로
        if(isSimilar(first_word, new_words) && abs(length) < 2){
            count++;
        }
    }
    return count;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    
    // 입력
    cin >> n;

    // 계산
    int result = countWords(n);

    // 출력
    cout << result;

    return 0;
}