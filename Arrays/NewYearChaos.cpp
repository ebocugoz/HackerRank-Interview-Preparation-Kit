//Question : https://www.hackerrank.com/challenges/new-year-chaos/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

void printVector(vector<int> q)
{
    
}

// Complete the minimumBribes function below.
void minimumBribes(vector<int> q) {
    vector<int> bribes(q.size()+1,0)  ;
    bool ordered = false;
while(!ordered)
{  
    ordered = true;
    for(int i = 0;i<q.size()-1;i++)
    { //cout<<q[i]<<" "<<q[i+1]<<" ";        
       if(q[i]>q[i+1]&&bribes[q[i]]<2)
       {
          // cout<<q[i]<<" is bribing who has "<<bribes[q[i]]<<" time bribed  "<<endl;
             bribes[q[i]]++;
           int temp = q[i];
           q[i]=q[i+1];
           q[i+1]=temp;
        
           
           
           ordered = false;
          
       }
        else if(q[i]>q[i+1]&&bribes[q[i]]==2)
        {
            cout<<"Too chaotic"<<endl;
            return;
        }
            
        
    }
}
    int totalbribes = 0;
    for(int i=0;i<q.size()+1;i++)
    {
        totalbribes += bribes[i];
    }
    cout<<totalbribes<<endl;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string q_temp_temp;
        getline(cin, q_temp_temp);

        vector<string> q_temp = split_string(q_temp_temp);

        vector<int> q(n);

        for (int i = 0; i < n; i++) {
            int q_item = stoi(q_temp[i]);

            q[i] = q_item;
        }

        minimumBribes(q);
    }

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
