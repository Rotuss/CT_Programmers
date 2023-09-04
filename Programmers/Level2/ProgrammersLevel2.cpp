#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

// ¦���� �����ϱ�
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
//    // ¦���� ���� ��� ���� 1, ���� 0
//    return answer = stackchar.empty();
//}

// ī��
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
    // ¦���� �����ϱ�
    /*solution("baabaa");
    solution("cdcd");*/

    // ī��
    solution(10, 2);
    solution(8, 1);
    solution(24, 24);

    return 0;
}