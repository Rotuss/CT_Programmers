#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// 달리기 경주
vector<string> solution(vector<string> players, vector<string> callings)
{
    vector<string> answer;

    // 9~13번 시간 초과
    /*vector<string>& answer = players;
    
    for (int i = 0; i < callings.size(); ++i)
    {
        int temp = find(players.begin(), players.end(), callings[i]) - players.begin();

        swap(players[temp], players[temp - 1]);
    }*/

    map<int, string> mapRank;
    map<string, int> mapName;
    int rank = 1;

    for (auto& name : players)
    {
        // 순위, 선수이름
        mapRank[rank] = name;
        // 선수이름, 순위
        mapName[name] = rank;
        ++rank;
    }

    for (int i = 0; i < callings.size(); ++i)
    {
        // 호출된 선수의 순위
        int rank_check = mapName[callings[i]];
        // 호출된 선수의 앞 선수 이름
        string name_front = mapRank[rank_check - 1];
        
        // [순위,이름] => [호출된 선수의 하나 앞 순위,호출된 선수]
        mapRank[rank_check - 1] = callings[i];
        // [순위,이름] => [호출된 선수의 순위, 호출된 선수의 앞 선수 이름]
        mapRank[rank_check] = name_front;

        // [이름,순위] => [호출된 선수의 이름, 호출된 선수의 하나 앞 순위]
        mapName[callings[i]] = rank_check - 1;
        // [이름,순위] => [호출된 선수의 앞 선수 이름, 호출된 선수의 순위]
        mapName[name_front] = rank_check;
    }

    for (int i = 0; i < mapRank.size(); ++i)
    {
        // 순위별 선수이름 삽입
        answer.push_back(mapRank[i]);
    }

    return answer;
}

int main(void)
{
    solution({ "mumu", "soe", "poe", "kai", "mine" }, { "kai", "kai", "mine", "mine" });

    return 0;
}