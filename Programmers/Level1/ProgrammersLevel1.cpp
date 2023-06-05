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

// ���� ��å

// �����̵�
int MoveEast(vector<string> park, int X, int Y, int n)
{
    // ���� ��Ż��
    if (Y + n >= park[0].size())
    {
        return 0;
    }

    // 'X' ������ ��
    for (int i = 0; i <= n; ++i)
    {
        if ('X' == park[X][Y + i])
        {
            return 0;
        }
    }

    return n;
}

// �����̵�
int MoveWest(vector<string> park, int X, int Y, int n)
{
    // ���� ��Ż��
    if (Y - n < 0)
    {
        return 0;
    }

    // 'X' ������ ��
    for (int i = 0; i <= n; ++i)
    {
        if ('X' == park[X][Y - i])
        {
            return 0;
        }
    }
    
    return n;
}

// �����̵�
int MoveSouth(vector<string> park, int X, int Y, int n)
{
    // ���� ��Ż��
    if (X + n >= park.size())
    {
        return 0;
    }

    // 'X' ������ ��
    for (int i = 0; i <= n; ++i)
    {
        if ('X' == park[X + i][Y])
        {
            return 0;
        }
    }
    
    return n;
}

// �����̵�
int MoveNorth(vector<string> park, int X, int Y, int n)
{
    // ���� ��Ż��
    if (X - n < 0)
    {
        return 0;
    }

    // 'X' ������ ��
    for (int i = 0; i <= n; ++i)
    {
        if ('X' == park[X - i][Y])
        {
            return 0;
        }
    }
    
    return n;
}

vector<int> solution(vector<string> park, vector<string> routes)
{
    vector<int> answer;
    
    // park�� ���� ���� Ž�� ����
    int i_Start_X = 0;
    int i_Start_Y = 0;
    int i_CurX = 0;
    int i_CurY = 0;

    int i_H = (int)park.size();
    int i_W = (int)park[0].size();

    for (int i = 0; i < i_H; ++i)
    {
        for (int j = 0; j < i_W; ++j)
        {
            if ('S' == park[i][j])
            {
                i_Start_X = i;
                i_Start_Y = j;
                break;
            }
        }
    }

    // routes ���鹮�ڷ� �̵� ����� �̵��� �� �ľ�
    i_CurX = i_Start_X;
    i_CurY = i_Start_Y;

    for (int i = 0; i < routes.size(); ++i)
    {
        switch (routes[i][0])
        {
        case 'E':
            i_CurY += MoveEast(park, i_CurX, i_CurY, routes[i][2] - '0');
            break;
        case 'W':
            i_CurY -= MoveWest(park, i_CurX, i_CurY, routes[i][2] - '0');
            break;
        case 'S':
            i_CurX += MoveSouth(park, i_CurX, i_CurY, routes[i][2] - '0');
            break;
        case 'N':
            i_CurX -= MoveNorth(park, i_CurX, i_CurY, routes[i][2] - '0');
            break;
        default:
            break;
        }
    }

    answer.push_back(i_CurX);
    answer.push_back(i_CurY);

    return answer;
}

int main(void)
{
    // �޸��� ����
    // solution({ "mumu", "soe", "poe", "kai", "mine" }, { "kai", "kai", "mine", "mine" });

    // �߾� ����
    /*solution({ "may", "kein", "kain", "radi" }, { 5, 10, 1, 3 }, { { "may", "kein", "kain", "radi" }, { "may", "kein", "brin", "deny" }, { "kon", "kain", "may", "coni" } });
    solution({ "kali", "mari", "don" }, { 11, 1, 55 }, { { "kali", "mari", "don" }, { "pony", "tom", "teddy" }, { "con", "mona", "don" } });
    solution({ "may", "kein", "kain", "radi" }, { 5, 10, 1, 3 }, { { "may" }, { "kein", "deny", "may" }, { "kon", "coni" } });*/

    // ���� ��å
    solution({ "SOO","OOO","OOO" }, { "E 2","S 2","W 1" });
    solution({ "SOO","OXX","OOO" }, { "E 2","S 2","W 1" });
    solution({ "OSO","OOO","OXO","OOO" }, { "E 2","S 3","W 1" });

    return 0;
}