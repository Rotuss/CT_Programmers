#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// �޸��� ����
//vector<string> solution(vector<string> players, vector<string> callings)
//{
//    vector<string> answer;
//
//    // 9~13�� �ð� �ʰ�
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
//        // ����, �����̸�
//        mapRank[rank] = name;
//        // �����̸�, ����
//        mapName[name] = rank;
//        ++rank;
//    }
//
//    for (int i = 0; i < callings.size(); ++i)
//    {
//        // ȣ��� ������ ����
//        int rank_check = mapName[callings[i]];
//        // ȣ��� ������ �� ���� �̸�
//        string name_front = mapRank[rank_check - 1];
//        
//        // [����,�̸�] => [ȣ��� ������ �ϳ� �� ����,ȣ��� ����]
//        mapRank[rank_check - 1] = callings[i];
//        // [����,�̸�] => [ȣ��� ������ ����, ȣ��� ������ �� ���� �̸�]
//        mapRank[rank_check] = name_front;
//
//        // [�̸�,����] => [ȣ��� ������ �̸�, ȣ��� ������ �ϳ� �� ����]
//        mapName[callings[i]] = rank_check - 1;
//        // [�̸�,����] => [ȣ��� ������ �� ���� �̸�, ȣ��� ������ ����]
//        mapName[name_front] = rank_check;
//    }
//
//    for (int i = 0; i < mapRank.size(); ++i)
//    {
//        // ������ �����̸� ����
//        answer.push_back(mapRank[i]);
//    }
//
//    return answer;
//}

// �߾� ����
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
    // �޸��� ����
    // solution({ "mumu", "soe", "poe", "kai", "mine" }, { "kai", "kai", "mine", "mine" });

    // �߾� ����
    solution({ "may", "kein", "kain", "radi" }, { 5, 10, 1, 3 }, { { "may", "kein", "kain", "radi" }, { "may", "kein", "brin", "deny" }, { "kon", "kain", "may", "coni" } });
    solution({ "kali", "mari", "don" }, { 11, 1, 55 }, { { "kali", "mari", "don" }, { "pony", "tom", "teddy" }, { "con", "mona", "don" } });
    solution({ "may", "kein", "kain", "radi" }, { 5, 10, 1, 3 }, { { "may" }, { "kein", "deny", "may" }, { "kon", "coni" } });

    return 0;
}