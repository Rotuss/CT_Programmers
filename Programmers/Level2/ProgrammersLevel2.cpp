#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

// ¦���� �����ϱ�
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
    
    // ¦���� ���� ��� ���� 1, ���� 0
    return answer = stackchar.empty();
}

int main(void)
{
    // ¦���� �����ϱ�
    solution("baabaa");
    solution("cdcd");

    return 0;
}