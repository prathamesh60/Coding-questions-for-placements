#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the realEstateBroker function below.
 */
bool rule(pair<pair<int,int>,int> x,pair<pair<int,int>,int> y)
{
    if(x.first.second==y.first.second)
    {
        return (x.second<y.second);
    }
    return (x.first.second<y.first.second);
}
int realEstateBroker(vector<vector<int>> clients, vector<vector<int>> houses) {
    vector<pair<pair<int,int>,int>> A;
    int i;
    for(i=0;i<clients.size();i++)
     {
        A.push_back(make_pair(make_pair(clients[i][0],clients[i][1]),1));
     }
    for(i=0;i<houses.size();i++)
     {
        A.push_back(make_pair(make_pair(houses[i][0],houses[i][1]),0));
     }
    sort(A.begin(),A.end(),rule);
    int count=0;
    set<int> s;
    for(i=0;i<A.size();i++)
    {
        pair<pair<int,int>,int> p=A[i];
        if(p.second==0)
         {
             s.insert(p.first.first);
         }
        else
         {
             auto it=s.upper_bound(p.first.first);
             if(it!=s.end())
              {
                  count++;
                  s.erase(it);
              }
         }
    }
    return count;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int>> clients(n);
    for (int clients_row_itr = 0; clients_row_itr < n; clients_row_itr++) {
        clients[clients_row_itr].resize(2);

        for (int clients_column_itr = 0; clients_column_itr < 2; clients_column_itr++) {
            cin >> clients[clients_row_itr][clients_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<vector<int>> houses(m);
    for (int houses_row_itr = 0; houses_row_itr < m; houses_row_itr++) {
        houses[houses_row_itr].resize(2);

        for (int houses_column_itr = 0; houses_column_itr < 2; houses_column_itr++) {
            cin >> houses[houses_row_itr][houses_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = realEstateBroker(clients, houses);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
