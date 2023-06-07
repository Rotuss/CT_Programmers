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
//// �����̵�
//int MoveEast(vector<string> park, int X, int Y, int n)
//{
//    // ���� ��Ż��
//    if (Y + n >= park[0].size())
//    {
//        return 0;
//    }
//
//    // 'X' ������ ��
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
//// �����̵�
//int MoveWest(vector<string> park, int X, int Y, int n)
//{
//    // ���� ��Ż��
//    if (Y - n < 0)
//    {
//        return 0;
//    }
//
//    // 'X' ������ ��
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
//// �����̵�
//int MoveSouth(vector<string> park, int X, int Y, int n)
//{
//    // ���� ��Ż��
//    if (X + n >= park.size())
//    {
//        return 0;
//    }
//
//    // 'X' ������ ��
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
//// �����̵�
//int MoveNorth(vector<string> park, int X, int Y, int n)
//{
//    // ���� ��Ż��
//    if (X - n < 0)
//    {
//        return 0;
//    }
//
//    // 'X' ������ ��
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
//    // park�� ���� ���� Ž�� ����
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
//    // routes ���鹮�ڷ� �̵� ����� �̵��� �� �ľ�
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

// �������� ���� ��ȿ�Ⱓ 1.
vector<int> solution(string today, vector<string> terms, vector<string> privacies)
{
    vector<int> answer;
    // ��� ���� ����
    map<char, int> m_termtype;

    // ���� ��¥
    int Ytoday = stoi(today.substr(0, 4));
    int Mtoday = stoi(today.substr(5, 2));
    int Dtoday = stoi(today.substr(8, 2));

    // ��� ��ȿ�Ⱓ ���
    for (int i = 0; i < terms.size(); ++i)
    {
        m_termtype.insert(make_pair(terms[i][0], stoi(terms[i].substr(2, terms[i].size()))));
    }

    for (int i = 0; i < privacies.size(); ++i)
    {
        // ��� ���� ��¥
        int Yterm = stoi(privacies[i].substr(0, 4));
        int Mterm = stoi(privacies[i].substr(5, 2));
        int Dterm = stoi(privacies[i].substr(8, 2));

        // ��� ���� �Ⱓ
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

        // �ı� �Ǻ�
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

// �������� ���� ��ȿ�Ⱓ 2.
vector<int> solution(string today, vector<string> terms, vector<string> privacies)
{
    vector<int> answer;
    // ��� ���� ���� Ȯ�ο�
    vector<int> v_termcheck;
    // ��� ���� ����
    map<char, int> m_termtype;

    // ���� ��¥
    int Ytoday = stoi(today.substr(0, 4));
    int Mtoday = stoi(today.substr(5, 2));
    int Dtoday = stoi(today.substr(8, 2));
    int Ttoday = Ytoday * 12 * 28 + (Mtoday - 1) * 28 + Dtoday;

    // ��� ��ȿ�Ⱓ ���
    for (int i = 0; i < terms.size(); ++i)
    {
        m_termtype.insert(make_pair(terms[i][0], stoi(terms[i].substr(2, terms[i].size()))));
    }

    for (int i = 0; i < privacies.size(); ++i)
    {
        // ��� ���� ��¥
        int Yterm = stoi(privacies[i].substr(0, 4));
        int Mterm = stoi(privacies[i].substr(5, 2));
        int Dterm = stoi(privacies[i].substr(8, 2));
        int month = m_termtype[privacies[i][11]];

        // ��� ���� �Ⱓ ����
        int termend = Yterm * 12 * 28 + (Mterm - 1) * 28 + Dterm + (month * 28 - 1);
        v_termcheck.push_back(termend);

    }

    // �ı� �Ǻ�
    for (int i = 0; i < v_termcheck.size(); ++i)
    {
        // ���� ��¥�� ���� �Ⱓ���� ū ��� �ı�
        if (Ttoday > v_termcheck[i])
        {
            answer.push_back(i + 1);
        }
    }

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
    /*solution({ "SOO","OOO","OOO" }, { "E 2","S 2","W 1" });
    solution({ "SOO","OXX","OOO" }, { "E 2","S 2","W 1" });
    solution({ "OSO","OOO","OXO","OOO" }, { "E 2","S 3","W 1" });*/

    // �������� ���� ��ȿ�Ⱓ
    solution("2022.05.19", { "A 6", "B 12", "C 3" }, { "2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C" });
    solution("2020.01.01", { "Z 3", "D 5" }, { "2019.01.01 D", "2019.11.15 Z", "2019.08.02 D", "2019.07.01 D", "2018.12.28 Z" });

    return 0;
}