#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
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
//int solution(vector<int> people, int limit) {
//    int answer = 0;
//
//    // ���� �ջ� 100 �������θ� ������ �߸��� ����
//    //for (int i = 0; i < people.size(); ++i)
//    //{
//    //    for (int j = i + 1; j < people.size(); ++j)
//    //    {
//    //        if (limit >= people[i] + people[j])
//    //        {
//    //            people.erase(people.begin() + j);
//    //            break;
//    //        }
//    //    }
//    //    ++answer;
//    //}
//
//    sort(people.begin(), people.end());
//
//    vector<int>::iterator Iter_begin = people.begin();
//    vector<int>::iterator Iter_end = people.end() - 1;
//    while (Iter_begin <= Iter_end)
//    {
//        if (limit >= *Iter_begin + *Iter_end)
//        {
//            ++Iter_begin;
//        }
//        --Iter_end;
//        ++answer;
//    }
//
//    return answer;
//}

// �ǻ�
//int solution(vector<vector<string>> clothes)
//{
//    int answer = 1;
//
//    unordered_map<string, int> umClothesMatch;
//    for (int i = 0; i < clothes.size(); ++i)
//    {
//        // clothes�� ����(ó���̸� 0, ó���� �ƴϸ� ���� + 1)
//        ++umClothesMatch[clothes[i][1]];
//    }
//
//    for (auto Iter : umClothesMatch)
//    {
//        // ������ ������ ���� ��
//        // ���Դ� ��� ����Ͽ� + 1
//        answer *= (Iter.second + 1);
//    }
//
//    // ���� �� �Դ� ��� �����ؾ� �ϹǷ� -1
//    answer -= 1;
//    return answer;
//}

// ��ɰ���
vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    queue<int> qHandout;
    int iDay = 0;
    int iCheck = 0;
    int iCount = 0;

    // ���� ���� ���
    for (int i = 0; i < progresses.size(); ++i)
    {
        iDay = (100 - progresses[i]) / speeds[i];

        if (0 != (100 - progresses[i]) % speeds[i])
        {
            ++iDay;
        }

        qHandout.push(iDay);
    }

    // ù ���� ���� �� ��
    iCheck = qHandout.front();
    qHandout.pop();
    ++iCount;

    // ���� ī��Ʈ �� ����
    while (0 <= qHandout.size())
    {
        // ��� �������ڰ� ������ ���� ī��Ʈ �߰�
        if (0 == qHandout.size())
        {
            answer.push_back(iCount);
            break;
        }
        else if (iCheck >= qHandout.front())
        {
            ++iCount;
            qHandout.pop();
        }
        else
        {
            answer.push_back(iCount);
            iCheck = qHandout.front();
            qHandout.pop();
            iCount = 1;
        }
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
    /*solution({ 70, 50, 80, 50 }, 100);
    solution({ 70, 80, 50 }, 100);*/

    // �ǻ�
    /*solution({ {"yellow_hat", "headgear"} ,{"blue_sunglasses", "eyewear"},{"green_turban", "headgear"} });
    solution({ {"crow_mask", "face"} ,{"blue_sunglasses", "face"},{"smoky_makeup", "face"} });*/

    // ��ɰ���
    solution({ 93, 30, 55 }, { 1, 30, 5 });
    solution({ 95, 90, 99, 99, 80, 99 }, { 1, 1, 1, 1, 1, 1 });

    return 0;
}