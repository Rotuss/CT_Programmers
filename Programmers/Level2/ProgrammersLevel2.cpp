#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

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
//vector<int> solution(int brown, int yellow) {
//    vector<int> answer;
//    int iYX = 0;
//    int iYY = 0;
//
//    for (int i = 1; i < yellow; ++i)
//    {
//        if (0 == yellow % i)
//        {
//            iYX = yellow / i;
//            iYY = i;
//
//            if (brown == (iYX + 2) * 2 + iYY * 2)
//                break;
//        }
//    }
//
//    answer.push_back(iYX + 2);
//    answer.push_back(iYY + 2);
//
//    return answer;
//}

// ����Ʈ
int solution(vector<int> people, int limit) {
    int answer = 0;

    // ���� �ջ� 100 �������θ� ������ �߸��� ����
    //for (int i = 0; i < people.size(); ++i)
    //{
    //    for (int j = i + 1; j < people.size(); ++j)
    //    {
    //        if (limit >= people[i] + people[j])
    //        {
    //            people.erase(people.begin() + j);
    //            break;
    //        }
    //    }
    //    ++answer;
    //}

    sort(people.begin(), people.end());

    vector<int>::iterator Iter_begin = people.begin();
    vector<int>::iterator Iter_end = people.end() - 1;
    while (Iter_begin <= Iter_end)
    {
        if (limit >= *Iter_begin + *Iter_end)
        {
            ++Iter_begin;
        }
        --Iter_end;
        ++answer;
    }

    return answer;
}

int main(void)
{
    // ¦���� �����ϱ�
    /*solution("baabaa");
    solution("cdcd");*/

    // ī��
    /*solution(10, 2);
    solution(8, 1);
    solution(24, 24);*/

    // ����Ʈ
    solution({ 70, 50, 80, 50 }, 100);
    solution({ 70, 80, 50 }, 100);

    return 0;
}