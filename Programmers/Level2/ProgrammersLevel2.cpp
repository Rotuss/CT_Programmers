#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

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

// 구명보트
//int solution(vector<int> people, int limit) {
//    int answer = 0;
//
//    // 무게 합산 100 기준으로만 생각한 잘못된 오류
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

// 의상
int solution(vector<vector<string>> clothes)
{
    int answer = 1;

    unordered_map<string, int> umClothesMatch;
    for (int i = 0; i < clothes.size(); ++i)
    {
        // clothes의 종류(처음이면 0, 처음이 아니면 기존 + 1)
        ++umClothesMatch[clothes[i][1]];
    }

    for (auto Iter : umClothesMatch)
    {
        // 종류의 가짓수 전부 곱
        // 안입는 경우 고려하여 + 1
        answer *= (Iter.second + 1);
    }

    // 전부 안 입는 경우 제외해야 하므로 -1
    answer -= 1;
    return answer;
}

int main(void)
{
    // 짝지어 제거하기
    /*solution("baabaa");
    solution("cdcd");*/

    // 카펫
    /*solution(10, 2);
    solution(8, 1);
    solution(24, 24);*/

    // 구명보트
    /*solution({ 70, 50, 80, 50 }, 100);
    solution({ 70, 80, 50 }, 100);*/

    // 의상
    solution({ {"yellow_hat", "headgear"} ,{"blue_sunglasses", "eyewear"},{"green_turban", "headgear"} });
    solution({ {"crow_mask", "face"} ,{"blue_sunglasses", "face"},{"smoky_makeup", "face"} });

    return 0;
}