#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cctype>

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
//vector<int> solution(string today, vector<string> terms, vector<string> privacies)
//{
//    vector<int> answer;
//    // ��� ���� ����
//    map<char, int> m_termtype;
//
//    // ���� ��¥
//    int Ytoday = stoi(today.substr(0, 4));
//    int Mtoday = stoi(today.substr(5, 2));
//    int Dtoday = stoi(today.substr(8, 2));
//
//    // ��� ��ȿ�Ⱓ ���
//    for (int i = 0; i < terms.size(); ++i)
//    {
//        m_termtype.insert(make_pair(terms[i][0], stoi(terms[i].substr(2, terms[i].size()))));
//    }
//
//    for (int i = 0; i < privacies.size(); ++i)
//    {
//        // ��� ���� ��¥
//        int Yterm = stoi(privacies[i].substr(0, 4));
//        int Mterm = stoi(privacies[i].substr(5, 2));
//        int Dterm = stoi(privacies[i].substr(8, 2));
//
//        // ��� ���� �Ⱓ
//        int month = m_termtype[privacies[i][11]];
//        while (true)
//        {
//            if (0 == month)
//            {
//                break;
//            }
//            else if (1 == month)
//            {
//                Dterm += 27;
//            }
//            else if(1 < month)
//            {
//                Dterm += 28;
//            }
//
//            if (Dterm > 28)
//            {
//                Dterm -= 28;
//                ++Mterm;
//            }
//            if (Mterm > 12)
//            {
//                Mterm -= 12;
//                ++Yterm;
//            }
//            --month;
//        }
//
//        // �ı� �Ǻ�
//        if (Ytoday > Yterm)
//        {
//            answer.push_back(i + 1);
//        }
//        else if (Ytoday == Yterm && Mtoday > Mterm)
//        {
//            answer.push_back(i + 1);
//        }
//        else if (Ytoday == Yterm && Mtoday == Mterm && Dtoday > Dterm)
//        {
//            answer.push_back(i + 1);
//        }
//
//    }
//
//    return answer;
//}

// �������� ���� ��ȿ�Ⱓ 2.
//vector<int> solution(string today, vector<string> terms, vector<string> privacies)
//{
//    vector<int> answer;
//    // ��� ���� ���� Ȯ�ο�
//    vector<int> v_termcheck;
//    // ��� ���� ����
//    map<char, int> m_termtype;
//
//    // ���� ��¥
//    int Ytoday = stoi(today.substr(0, 4));
//    int Mtoday = stoi(today.substr(5, 2));
//    int Dtoday = stoi(today.substr(8, 2));
//    int Ttoday = Ytoday * 12 * 28 + (Mtoday - 1) * 28 + Dtoday;
//
//    // ��� ��ȿ�Ⱓ ���
//    for (int i = 0; i < terms.size(); ++i)
//    {
//        m_termtype.insert(make_pair(terms[i][0], stoi(terms[i].substr(2, terms[i].size()))));
//    }
//
//    for (int i = 0; i < privacies.size(); ++i)
//    {
//        // ��� ���� ��¥
//        int Yterm = stoi(privacies[i].substr(0, 4));
//        int Mterm = stoi(privacies[i].substr(5, 2));
//        int Dterm = stoi(privacies[i].substr(8, 2));
//        int month = m_termtype[privacies[i][11]];
//
//        // ��� ���� �Ⱓ ����
//        int termend = Yterm * 12 * 28 + (Mterm - 1) * 28 + Dterm + (month * 28 - 1);
//        v_termcheck.push_back(termend);
//
//    }
//
//    // �ı� �Ǻ�
//    for (int i = 0; i < v_termcheck.size(); ++i)
//    {
//        // ���� ��¥�� ���� �Ⱓ���� ū ��� �ı�
//        if (Ttoday > v_termcheck[i])
//        {
//            answer.push_back(i + 1);
//        }
//    }
//
//    return answer;
//}

// ���� ���� �˻��ϱ�
//string solution(vector<string> survey, vector<int> choices)
//{
//    string answer = "";
//    map<char, int> m_Type = { {'R',0}, {'T',0},
//                            {'C',0}, {'F',0},
//                            {'J',0}, {'M',0},
//                            {'A',0}, {'N',0} };
//
//    // 1)�ſ� ���� 3, 2)���� 2, 3)�ణ ���� 1, 4)�𸣰��� 0, 5)�ణ ���� 1, 6)���� 2, 7)�ſ� ���� 3
//    for (int i = 0; i < survey.size(); ++i)
//    {
//        switch (choices[i])
//        {
//        // case 1~3�� ������ ���� ���� �߰�
//        case 1:
//        {
//            m_Type[survey[i][0]] += 3;
//        }
//            break;
//        case 2:
//        {
//            m_Type[survey[i][0]] += 2;
//        }
//            break;
//        case 3:
//        {
//            m_Type[survey[i][0]] += 1;
//        }
//            break;
//        // case 5~7�� ������ ���� ���� �߰�
//        case 5:
//        {
//            m_Type[survey[i][1]] += 1;
//        }
//            break;
//        case 6:
//        {
//            m_Type[survey[i][1]] += 2;
//        }
//            break;
//        case 7:
//        {
//            m_Type[survey[i][1]] += 3;
//        }
//            break;
//        default:
//            break;
//        }
//    }
//
//    // Ÿ�Ժ� �� �� Ÿ�� ����
//    m_Type['R'] >= m_Type['T'] ? answer.push_back('R') : answer.push_back('T');
//    m_Type['C'] >= m_Type['F'] ? answer.push_back('C') : answer.push_back('F');
//    m_Type['J'] >= m_Type['M'] ? answer.push_back('J') : answer.push_back('M');
//    m_Type['A'] >= m_Type['N'] ? answer.push_back('A') : answer.push_back('N');
//
//    return answer;
//}

// �Ű� ��� �ޱ�(����)
//vector<int> solution(vector<string> id_list, vector<string> report, int k)
//{
//    vector<int> answer;
//    // ����, �Ű� ��
//    unordered_map<string, int> um_Reportcount;
//    // �Ű���� ����, �Ű��� ����
//    unordered_map<string, unordered_set<string>> um_Reportlist;
//
//    string s_Reportname;
//    string s_Reportedname;
//
//    for (int i = 0; i < id_list.size(); ++i)
//    {
//        // ����id ����Ʈ
//        um_Reportcount.insert(make_pair(id_list[i], 0));
//    }
//
//    for (int i = 0; i < report.size(); ++i)
//    {
//        int blank = report[i].find(" ");
//
//        // �Ű���, �ǽŰ��� �ľ�
//        s_Reportname = report[i].substr(0, blank);
//        s_Reportedname = report[i].substr(blank + 1, report[i].size());
//
//        um_Reportlist[s_Reportedname].insert(s_Reportname);
//    }
//
//    for (auto listcount : um_Reportlist)
//    {
//        // k�� �̻� �Ű���� ���� ����id �� �Ű� ��
//        if (k <= listcount.second.size())
//        {
//            for (auto count : listcount.second)
//            {
//                um_Reportcount[count] += 1;
//            }
//        }
//    }
//    
//    for (auto i : um_Reportcount)
//    {
//        answer.push_back(i.second);
//    }
//
//    return answer;
//}

// �Ű� ��� �ޱ�(����)
//vector<int> solution(vector<string> id_list, vector<string> report, int k) {
//    vector<int> answer(id_list.size());
//    // ����, �Ű� ��
//    unordered_map<string, int> um_Reportcount;
//    // �Ű���� ����, �Ű��� ����
//    unordered_map<string, unordered_set<string>> um_Reportlist;
//
//    string s_Reportname;
//    string s_Reportedname;
//
//    for (int i = 0; i < id_list.size(); ++i)
//    {
//        // ����id ����Ʈ ���ؽ��� ���
//        um_Reportcount.insert(make_pair(id_list[i], i));
//    }
//
//    for (int i = 0; i < report.size(); ++i)
//    {
//        int blank = report[i].find(" ");
//
//        // �Ű���, �ǽŰ��� �ľ�
//        s_Reportname = report[i].substr(0, blank);
//        s_Reportedname = report[i].substr(blank + 1, report[i].size());
//
//        um_Reportlist[s_Reportedname].insert(s_Reportname);
//    }
//
//    for (auto listcount : um_Reportlist)
//    {
//        // k�� �̻� �Ű���� ���� ����id �� �Ű� ��
//        if (k <= listcount.second.size())
//        {
//            for (auto count : listcount.second)
//            {
//                ++answer[um_Reportcount[count]];
//            }
//        }
//    }
//
//    return answer;
//}

// �ű� ���̵� ��õ
string solution(string new_id)
{
    string answer = new_id;
    
    // 1) �빮�� -> �ҹ���
    for (int i = 0; i < answer.size(); ++i)
    {
        answer[i] = tolower(answer[i]);
    }
    // 2) �ҹ���, ����, -, _, .�� ������ ��� ���� ����
    for (int i = 0; i < answer.size(); )
    {
        if (0 == islower(answer[i]) && 0 == isdigit(answer[i]) && answer[i] != '-' && answer[i] != '_' && answer[i] != '.')
        {
            answer.erase(i,1);
        }
        else
        {
            ++i;
        }
    }
    // 3) .�� 2�� �̻� ���ӵ� �κ��� . 1���� �����ϰ� ġȯ
    size_t ddot_pos = 0;
    while (string::npos != (ddot_pos = answer.find("..")))
    {
        answer.replace(ddot_pos, 2, ".");
    }
    // 4) .�� ó�� Ȥ�� �������� ��ġ�ϸ� ����
    if ('.' == answer.front())
    {
        answer.erase(0, 1);
    }
    if (0 != answer.size() && '.' == answer.back())
    {
        answer.pop_back();
    }
    // 5) �� ���ڿ��� ��� "a" ����
    if (true == answer.empty())
    {
        answer += 'a';
    }
    // 6) ���ڿ��� ���̰� 16�� �̻��� ��� ù 15�� ���ڸ� ������ ������ ���ڿ� ����
    if (16 <= answer.size())
    {
        answer.erase(15);
        // 6')���� �� .�� �������� ��ġ�Ѵٸ� �������� ��ġ�� . ����
        if ('.' == answer.back())
        {
            answer.pop_back();
        }
    }
    // 7) ���ڿ��� ���̰� 2�� ������ ��� ������ ���ڸ� ���̰� 3�� �� ������ �ݺ��Ͽ� ���� ����
    if (2 >= answer.size())
    {
        for (size_t i = answer.size(); i < 3; ++i)
        {
            answer += answer.back();
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
    /*solution("2022.05.19", { "A 6", "B 12", "C 3" }, { "2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C" });
    solution("2020.01.01", { "Z 3", "D 5" }, { "2019.01.01 D", "2019.11.15 Z", "2019.08.02 D", "2019.07.01 D", "2018.12.28 Z" });*/

    // ���� ���� �˻��ϱ�
    /*solution({ "AN", "CF", "MJ", "RT", "NA" }, { 5, 3, 2, 7, 5 });
    solution({ "TR", "RT", "TR" }, { 7, 1, 3 });*/

    // �Ű� ��� �ޱ�
    /*solution({ "muzi", "frodo", "apeach", "neo" }, { "muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi" }, 2);
    solution({ "con", "ryan" }, { "ryan con", "ryan con", "ryan con", "ryan con" }, 3);*/

    // �ű� ���̵� ��õ
    solution("...!@BaT#*..y.abcdefghijklm");
    solution("z-+.^.");
    solution("=.=");
    solution("123_.def");
    solution("abcdefghijklmn.p");

    return 0;
}