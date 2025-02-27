#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void calc(stack<char> &s, vector<char> &result){
    string str;
    getline(cin, str);

    for(char ch : str){
        if(isalpha(ch)){
            result.push_back(ch);
        }
        else if(ch == '*' || ch == '/'){
            while(!s.empty() && s.top() != '+' && s.top() != '-' && s.top() != '(')
            {
                result.push_back(s.top());
                s.pop();
            }
            s.push(ch);
        }

        else if(ch == '+' || ch == '-'){
            while(!s.empty() && s.top() != '('){
                result.push_back(s.top());
                s.pop();
            }
            s.push(ch);
        }

        else if(ch == '('){
            s.push(ch);
        }
        
        else if(ch == ')'){
            while(!s.empty() && s.top() != '('){
                result.push_back(s.top());
                s.pop();
            }
            if (!s.empty()) s.pop();
        }
    }
    while(!s.empty()){
        result.push_back(s.top());
        s.pop();
    }

    for(auto iter : result){
        cout << iter;
    }
}

int main(){
    stack<char> s;
    vector<char> result;

    calc(s, result);
    return 0;
}