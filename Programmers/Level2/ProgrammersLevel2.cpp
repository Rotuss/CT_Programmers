#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

// 짝지어 제거하기
//int solution(string s)
//{
//    int answer = -1;
//    stack<char> stackchar;
//    
//    for (int i = 0; i < s.size(); ++i)
//    {
//        if (true != stackchar.empty() && s[i] == stackchar.top())
//        {
//            stackchar.pop();
//        }
//        else
//        {
//            stackchar.push(s[i]);
//        }
//    }
//    
//    // 짝지어 제거 모두 성공 1, 실패 0
//    return answer = stackchar.empty();
//}

// 카펫
vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int iYX = 0;
    int iYY = 0;

    for (int i = 1; i < yellow; ++i)
    {
        if (0 == yellow % i)
        {
            iYX = yellow / i;
            iYY = i;

            if (brown == (iYX + 2) * 2 + iYY * 2)
                break;
        }
    }

    answer.push_back(iYX + 2);
    answer.push_back(iYY + 2);

    return answer;
}

int main(void)
{
    // 짝지어 제거하기
    /*solution("baabaa");
    solution("cdcd");*/

    // 카펫
    solution(10, 2);
    solution(8, 1);
    solution(24, 24);

    return 0;
}