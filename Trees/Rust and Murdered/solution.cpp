#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the rustMurdered function below.
 */
void dfs(vector<int> roads[],int s,int visited[])
{
    visited[s]=1;
    int i;
    for(i=0;i<roads[s].size();i++)
     {  
         visited[roads[s][i]]=1;
     }
}
vector<int> rustMurderer(int n, vector<vector<int>> road,int s) {
    int i,j;
    vector<int>roads[n];
    for(i=0;i<road.size();i++)
     {  
        roads[road[i][0]-1].push_back(road[i][1]-1);
        roads[road[i][1]-1].push_back(road[i][0]-1);
     }
    for(i=0;i<n;i++)
     {
         sort(roads[i].begin(),roads[i].end());
         for(j=0;j<roads[i].size();j++)
          {
              cout<<roads[i][j]<<" ";
          }
          cout<<endl;
     }
    int visited[n];
    memset(visited,0,sizeof visited);
    dfs(roads,s-1,visited);
    queue<int> qu;
    int dist[n];
    memset(dist,0,sizeof dist);
    dist[s-1]=0;
    int count=1;
    for(i=0;i<n;i++)
    {
        visited[i]=(!visited[i]);
    }
    for(i=0;i<n;i++)
     {
        if(visited[i]!=0 && i!=s-1)
         {
           dist[i]=1;
           qu.push(i);
           count++;
         } 
     }
    visited[s-1]=1;
    while(count<n)
     {
         int x=qu.front();
         qu.pop();
         for(i=0;i<n;i++)
          {
             if(visited[i]==0)
              {
                  auto itr=lower_bound(roads[x].begin(),roads[x].end(),i);
                  if(itr==(roads[x].end()) || (*itr)!=i)
                   {
                       dist[i]=dist[x]+1;
                       count++;
                       qu.push(i);
                       visited[i]=1;

                   }
              }
          }
     }
     cout<<"Running"<<endl;
     vector<int> ans;
     for(i=0;i<n;i++)
      {
         if(i!=s-1)
          ans.push_back(dist[i]);
      }
  return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        int m = stoi(nm[1]);

        vector<vector<int>> roads(m);
        for (int roads_row_itr = 0; roads_row_itr < m; roads_row_itr++) {
            roads[roads_row_itr].resize(2);

            for (int roads_column_itr = 0; roads_column_itr < 2; roads_column_itr++) {
                cin >> roads[roads_row_itr][roads_column_itr];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int s;
        cin >> s;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<int> result = rustMurderer(n, roads,s);

        for (int result_itr = 0; result_itr < result.size(); result_itr++) {
            fout << result[result_itr];

            if (result_itr != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

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
