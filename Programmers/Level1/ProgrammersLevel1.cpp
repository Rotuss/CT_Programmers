#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// �޸��� ����
vector<string> solution(vector<string> players, vector<string> callings)
{
    vector<string> answer;

    // 9~13�� �ð� �ʰ�
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
        // ����, �����̸�
        mapRank[rank] = name;
        // �����̸�, ����
        mapName[name] = rank;
        ++rank;
    }

    for (int i = 0; i < callings.size(); ++i)
    {
        // ȣ��� ������ ����
        int rank_check = mapName[callings[i]];
        // ȣ��� ������ �� ���� �̸�
        string name_front = mapRank[rank_check - 1];
        
        // [����,�̸�] => [ȣ��� ������ �ϳ� �� ����,ȣ��� ����]
        mapRank[rank_check - 1] = callings[i];
        // [����,�̸�] => [ȣ��� ������ ����, ȣ��� ������ �� ���� �̸�]
        mapRank[rank_check] = name_front;

        // [�̸�,����] => [ȣ��� ������ �̸�, ȣ��� ������ �ϳ� �� ����]
        mapName[callings[i]] = rank_check - 1;
        // [�̸�,����] => [ȣ��� ������ �� ���� �̸�, ȣ��� ������ ����]
        mapName[name_front] = rank_check;
    }

    for (int i = 0; i < mapRank.size(); ++i)
    {
        // ������ �����̸� ����
        answer.push_back(mapRank[i]);
    }

    return answer;
}

int main(void)
{
    solution({ "mumu", "soe", "poe", "kai", "mine" }, { "kai", "kai", "mine", "mine" });

    return 0;
}