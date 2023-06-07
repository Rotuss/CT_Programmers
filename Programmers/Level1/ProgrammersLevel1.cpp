#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// 달리기 경주
//vector<string> solution(vector<string> players, vector<string> callings)
//{
//    vector<string> answer;
//
//    // 9~13번 시간 초과
//    /*vector<string>& answer = players;
//    
//    for (int i = 0; i < callings.size(); ++i)
//    {
//        int temp = find(players.begin(), players.end(), callings[i]) - players.begin();
//
//        swap(players[temp], players[temp - 1]);
//    }*/
//
//    map<int, string> mapRank;
//    map<string, int> mapName;
//    int rank = 1;
//
//    for (auto& name : players)
//    {
//        // 순위, 선수이름
//        mapRank[rank] = name;
//        // 선수이름, 순위
//        mapName[name] = rank;
//        ++rank;
//    }
//
//    for (int i = 0; i < callings.size(); ++i)
//    {
//        // 호출된 선수의 순위
//        int rank_check = mapName[callings[i]];
//        // 호출된 선수의 앞 선수 이름
//        string name_front = mapRank[rank_check - 1];
//        
//        // [순위,이름] => [호출된 선수의 하나 앞 순위,호출된 선수]
//        mapRank[rank_check - 1] = callings[i];
//        // [순위,이름] => [호출된 선수의 순위, 호출된 선수의 앞 선수 이름]
//        mapRank[rank_check] = name_front;
//
//        // [이름,순위] => [호출된 선수의 이름, 호출된 선수의 하나 앞 순위]
//        mapName[callings[i]] = rank_check - 1;
//        // [이름,순위] => [호출된 선수의 앞 선수 이름, 호출된 선수의 순위]
//        mapName[name_front] = rank_check;
//    }
//
//    for (int i = 0; i < mapRank.size(); ++i)
//    {
//        // 순위별 선수이름 삽입
//        answer.push_back(mapRank[i]);
//    }
//
//    return answer;
//}

// 추억 점수
//vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo)
//{
//    vector<int> answer;
//    map<string, int> mapPoint;
//
//    for (int i = 0; i < name.size(); ++i)
//    {
//        mapPoint[name[i]] = yearning[i];
//    }
//
//    for (int i = 0; i < photo.size(); ++i)
//    {
//        int iTotal = 0;
//
//        for (int j = 0; j < photo[i].size(); ++j)
//        {
//            iTotal += mapPoint[photo[i][j]];
//        }
//
//        answer.push_back(iTotal);
//    }
//
//    return answer;
//}

// 공원 산책
//// 동쪽이동
//int MoveEast(vector<string> park, int X, int Y, int n)
//{
//    // 범위 이탈시
//    if (Y + n >= park[0].size())
//    {
//        return 0;
//    }
//
//    // 'X' 만났을 때
//    for (int i = 0; i <= n; ++i)
//    {
//        if ('X' == park[X][Y + i])
//        {
//            return 0;
//        }
//    }
//
//    return n;
//}
//
//// 서쪽이동
//int MoveWest(vector<string> park, int X, int Y, int n)
//{
//    // 범위 이탈시
//    if (Y - n < 0)
//    {
//        return 0;
//    }
//
//    // 'X' 만났을 때
//    for (int i = 0; i <= n; ++i)
//    {
//        if ('X' == park[X][Y - i])
//        {
//            return 0;
//        }
//    }
//    
//    return n;
//}
//
//// 남쪽이동
//int MoveSouth(vector<string> park, int X, int Y, int n)
//{
//    // 범위 이탈시
//    if (X + n >= park.size())
//    {
//        return 0;
//    }
//
//    // 'X' 만났을 때
//    for (int i = 0; i <= n; ++i)
//    {
//        if ('X' == park[X + i][Y])
//        {
//            return 0;
//        }
//    }
//    
//    return n;
//}
//
//// 북쪽이동
//int MoveNorth(vector<string> park, int X, int Y, int n)
//{
//    // 범위 이탈시
//    if (X - n < 0)
//    {
//        return 0;
//    }
//
//    // 'X' 만났을 때
//    for (int i = 0; i <= n; ++i)
//    {
//        if ('X' == park[X - i][Y])
//        {
//            return 0;
//        }
//    }
//    
//    return n;
//}
//
//vector<int> solution(vector<string> park, vector<string> routes)
//{
//    vector<int> answer;
//    
//    // park에 대한 정보 탐색 저장
//    int i_Start_X = 0;
//    int i_Start_Y = 0;
//    int i_CurX = 0;
//    int i_CurY = 0;
//
//    int i_H = (int)park.size();
//    int i_W = (int)park[0].size();
//
//    for (int i = 0; i < i_H; ++i)
//    {
//        for (int j = 0; j < i_W; ++j)
//        {
//            if ('S' == park[i][j])
//            {
//                i_Start_X = i;
//                i_Start_Y = j;
//                break;
//            }
//        }
//    }
//
//    // routes 공백문자로 이동 방향과 이동할 수 파악
//    i_CurX = i_Start_X;
//    i_CurY = i_Start_Y;
//
//    for (int i = 0; i < routes.size(); ++i)
//    {
//        switch (routes[i][0])
//        {
//        case 'E':
//            i_CurY += MoveEast(park, i_CurX, i_CurY, routes[i][2] - '0');
//            break;
//        case 'W':
//            i_CurY -= MoveWest(park, i_CurX, i_CurY, routes[i][2] - '0');
//            break;
//        case 'S':
//            i_CurX += MoveSouth(park, i_CurX, i_CurY, routes[i][2] - '0');
//            break;
//        case 'N':
//            i_CurX -= MoveNorth(park, i_CurX, i_CurY, routes[i][2] - '0');
//            break;
//        default:
//            break;
//        }
//    }
//
//    answer.push_back(i_CurX);
//    answer.push_back(i_CurY);
//
//    return answer;
//}

// 개인정보 수집 유효기간 1.
vector<int> solution(string today, vector<string> terms, vector<string> privacies)
{
    vector<int> answer;
    // 약관 종류 관리
    map<char, int> m_termtype;

    // 오늘 날짜
    int Ytoday = stoi(today.substr(0, 4));
    int Mtoday = stoi(today.substr(5, 2));
    int Dtoday = stoi(today.substr(8, 2));

    // 약관 유효기간 등록
    for (int i = 0; i < terms.size(); ++i)
    {
        m_termtype.insert(make_pair(terms[i][0], stoi(terms[i].substr(2, terms[i].size()))));
    }

    for (int i = 0; i < privacies.size(); ++i)
    {
        // 약관 시작 날짜
        int Yterm = stoi(privacies[i].substr(0, 4));
        int Mterm = stoi(privacies[i].substr(5, 2));
        int Dterm = stoi(privacies[i].substr(8, 2));

        // 약관 종료 기간
        int month = m_termtype[privacies[i][11]];
        while (true)
        {
            if (0 == month)
            {
                break;
            }
            else if (1 == month)
            {
                Dterm += 27;
            }
            else if(1 < month)
            {
                Dterm += 28;
            }

            if (Dterm > 28)
            {
                Dterm -= 28;
                ++Mterm;
            }
            if (Mterm > 12)
            {
                Mterm -= 12;
                ++Yterm;
            }
            --month;
        }

        // 파기 판별
        if (Ytoday > Yterm)
        {
            answer.push_back(i + 1);
        }
        else if (Ytoday == Yterm && Mtoday > Mterm)
        {
            answer.push_back(i + 1);
        }
        else if (Ytoday == Yterm && Mtoday == Mterm && Dtoday > Dterm)
        {
            answer.push_back(i + 1);
        }

    }

    return answer;
}

// 개인정보 수집 유효기간 2.
vector<int> solution(string today, vector<string> terms, vector<string> privacies)
{
    vector<int> answer;
    // 약관 종료 최종 확인용
    vector<int> v_termcheck;
    // 약관 종류 관리
    map<char, int> m_termtype;

    // 오늘 날짜
    int Ytoday = stoi(today.substr(0, 4));
    int Mtoday = stoi(today.substr(5, 2));
    int Dtoday = stoi(today.substr(8, 2));
    int Ttoday = Ytoday * 12 * 28 + (Mtoday - 1) * 28 + Dtoday;

    // 약관 유효기간 등록
    for (int i = 0; i < terms.size(); ++i)
    {
        m_termtype.insert(make_pair(terms[i][0], stoi(terms[i].substr(2, terms[i].size()))));
    }

    for (int i = 0; i < privacies.size(); ++i)
    {
        // 약관 시작 날짜
        int Yterm = stoi(privacies[i].substr(0, 4));
        int Mterm = stoi(privacies[i].substr(5, 2));
        int Dterm = stoi(privacies[i].substr(8, 2));
        int month = m_termtype[privacies[i][11]];

        // 약관 종료 기간 연산
        int termend = Yterm * 12 * 28 + (Mterm - 1) * 28 + Dterm + (month * 28 - 1);
        v_termcheck.push_back(termend);

    }

    // 파기 판별
    for (int i = 0; i < v_termcheck.size(); ++i)
    {
        // 오늘 날짜가 종료 기간보다 큰 경우 파기
        if (Ttoday > v_termcheck[i])
        {
            answer.push_back(i + 1);
        }
    }

    return answer;
}

int main(void)
{
    // 달리기 경주
    // solution({ "mumu", "soe", "poe", "kai", "mine" }, { "kai", "kai", "mine", "mine" });

    // 추억 점수
    /*solution({ "may", "kein", "kain", "radi" }, { 5, 10, 1, 3 }, { { "may", "kein", "kain", "radi" }, { "may", "kein", "brin", "deny" }, { "kon", "kain", "may", "coni" } });
    solution({ "kali", "mari", "don" }, { 11, 1, 55 }, { { "kali", "mari", "don" }, { "pony", "tom", "teddy" }, { "con", "mona", "don" } });
    solution({ "may", "kein", "kain", "radi" }, { 5, 10, 1, 3 }, { { "may" }, { "kein", "deny", "may" }, { "kon", "coni" } });*/

    // 공원 산책
    /*solution({ "SOO","OOO","OOO" }, { "E 2","S 2","W 1" });
    solution({ "SOO","OXX","OOO" }, { "E 2","S 2","W 1" });
    solution({ "OSO","OOO","OXO","OOO" }, { "E 2","S 3","W 1" });*/

    // 개인정보 수집 유효기간
    solution("2022.05.19", { "A 6", "B 12", "C 3" }, { "2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C" });
    solution("2020.01.01", { "Z 3", "D 5" }, { "2019.01.01 D", "2019.11.15 Z", "2019.08.02 D", "2019.07.01 D", "2018.12.28 Z" });

    return 0;
}