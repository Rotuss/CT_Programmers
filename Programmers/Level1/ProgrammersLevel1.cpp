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
vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo)
{
    vector<int> answer;
    map<string, int> mapPoint;

    for (int i = 0; i < name.size(); ++i)
    {
        mapPoint[name[i]] = yearning[i];
    }

    for (int i = 0; i < photo.size(); ++i)
    {
        int iTotal = 0;

        for (int j = 0; j < photo[i].size(); ++j)
        {
            iTotal += mapPoint[photo[i][j]];
        }

        answer.push_back(iTotal);
    }
    return answer;
}

int main(void)
{
    // 달리기 경주
    // solution({ "mumu", "soe", "poe", "kai", "mine" }, { "kai", "kai", "mine", "mine" });

    // 추억 점수
    solution({ "may", "kein", "kain", "radi" }, { 5, 10, 1, 3 }, { { "may", "kein", "kain", "radi" }, { "may", "kein", "brin", "deny" }, { "kon", "kain", "may", "coni" } });
    solution({ "kali", "mari", "don" }, { 11, 1, 55 }, { { "kali", "mari", "don" }, { "pony", "tom", "teddy" }, { "con", "mona", "don" } });
    solution({ "may", "kein", "kain", "radi" }, { 5, 10, 1, 3 }, { { "may" }, { "kein", "deny", "may" }, { "kon", "coni" } });

    return 0;
}