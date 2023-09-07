#include <iostream>
#include <string>
#include <vector>
#include <queue>
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
//int solution(vector<vector<string>> clothes)
//{
//    int answer = 1;
//
//    unordered_map<string, int> umClothesMatch;
//    for (int i = 0; i < clothes.size(); ++i)
//    {
//        // clothes의 종류(처음이면 0, 처음이 아니면 기존 + 1)
//        ++umClothesMatch[clothes[i][1]];
//    }
//
//    for (auto Iter : umClothesMatch)
//    {
//        // 종류의 가짓수 전부 곱
//        // 안입는 경우 고려하여 + 1
//        answer *= (Iter.second + 1);
//    }
//
//    // 전부 안 입는 경우 제외해야 하므로 -1
//    answer -= 1;
//    return answer;
//}

// 기능개발
//vector<int> solution(vector<int> progresses, vector<int> speeds)
//{
//    vector<int> answer;
//    queue<int> qHandout;
//    int iDay = 0;
//    int iCheck = 0;
//    int iCount = 0;
//
//    // 남은 일자 계산
//    for (int i = 0; i < progresses.size(); ++i)
//    {
//        iDay = (100 - progresses[i]) / speeds[i];
//
//        if (0 != (100 - progresses[i]) % speeds[i])
//        {
//            ++iDay;
//        }
//
//        qHandout.push(iDay);
//    }
//
//    // 첫 배출 정보 및 수
//    iCheck = qHandout.front();
//    qHandout.pop();
//    ++iCount;
//
//    // 배출 카운트 및 검토
//    while (0 <= qHandout.size())
//    {
//        // 모든 배출일자가 빠지면 남은 카운트 추가
//        if (0 == qHandout.size())
//        {
//            answer.push_back(iCount);
//            break;
//        }
//        else if (iCheck >= qHandout.front())
//        {
//            ++iCount;
//            qHandout.pop();
//        }
//        else
//        {
//            answer.push_back(iCount);
//            iCheck = qHandout.front();
//            qHandout.pop();
//            iCount = 1;
//        }
//    }
//
//    return answer;
//}

// 프로세스
int solution(vector<int> priorities, int location)
{
    int answer = 1;
    int iIndex = 0;
    int iLocationIndex = location;

    // 중요도 순서 큐에 저장
    queue<int> qProcess;
    for (int i = 0; i < priorities.size(); ++i)
    {
        qProcess.push(priorities[i]);
    }

    // 중요도 순서 내림차순으로 정렬
    sort(priorities.begin(), priorities.end(), greater<>());

    while (true)
    {
        // 내림차순으로 정렬된 순서와 큐의 제일 앞에 있는 수 같은지 비교
        // 같지 않다면 빼서 뒤로 삽입
        // 위치도 같이 변경(위치인덱스가 0이라면 큐 사이즈의 -1 한만큼, 즉 제일 뒷 인덱스 번호 부여. 0이 아니라면 현재 인덱스에서 -1)
        if (priorities[iIndex] != qProcess.front())
        {
            qProcess.push(qProcess.front());
            qProcess.pop();
            iLocationIndex = 0 == iLocationIndex ? qProcess.size() - 1 : iLocationIndex - 1;
        }
        // 내림차순으로 정렬된 순서와 큐의 제일 앞에 있는 수가 같다면 내림차순 정렬에서 확인하는 인덱스 증가
        // 큐에서는 맨 앞 같은 수 제거
        // 프로세스 실행 카운트 증가(++answer)
        // 큐에서 제거하므로 위치 인덱스 또한 변형되므로 현재 위치 인덱스에서 -1
        // 위치 인덱스가 0이면 제일 앞이라는 뜻. 즉 알고 싶은 위치 인덱스의 나가는 순서에 해당되므로 반복을 멈추고 나감
        // 따라서 '큐에서 제거하므로~'의 주석에서 검토하는 것보다 앞의 위치에 있어 -1시키면 안되는 경우는 어쩌지? 라는 생각할 필요X
        else
        {
            if (0 == iLocationIndex)
            {
                break;
            }
            ++iIndex;
            qProcess.pop();
            --iLocationIndex;
            ++answer;
        }
    }

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
    /*solution({ {"yellow_hat", "headgear"} ,{"blue_sunglasses", "eyewear"},{"green_turban", "headgear"} });
    solution({ {"crow_mask", "face"} ,{"blue_sunglasses", "face"},{"smoky_makeup", "face"} });*/

    // 기능개발
    /*solution({ 93, 30, 55 }, { 1, 30, 5 });
    solution({ 95, 90, 99, 99, 80, 99 }, { 1, 1, 1, 1, 1, 1 });*/

    // 프로세스
    solution({ 2, 1, 3, 2 }, 2);
    solution({ 1, 1, 9, 1, 1, 1 }, 0);

    return 0;
}