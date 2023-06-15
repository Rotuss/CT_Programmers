#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

// 짝지어 제거하기
int solution(string s)
{
    int answer = -1;
    stack<char> stackchar;
    
    for (int i = 0; i < s.size(); ++i)
    {
        if (true != stackchar.empty() && s[i] == stackchar.top())
        {
            stackchar.pop();
        }
        else
        {
            stackchar.push(s[i]);
        }
    }
    
    // 짝지어 제거 모두 성공 1, 실패 0
    return answer = stackchar.empty();
}

int main(void)
{
    // 짝지어 제거하기
    solution("baabaa");
    solution("cdcd");

    return 0;
}