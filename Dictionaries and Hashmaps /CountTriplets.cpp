// Question : https://www.hackerrank.com/challenges/count-triplets-1/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=dictionaries-hashmaps

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the countTriplets function below.


long countTriplets(vector<long> arr, long r) {
    
    
   
    map<long,long> mapCount,leftMapCount;
    
    
    for(long i=0;i<arr.size();i++)
    {
        mapCount[arr[i]]++;
    }
         leftMapCount[arr[0]]++;
        mapCount[arr[0]]--;
    long possibru = 0;  
    for(long i=1;i<arr.size();i++)
    {
        long currPossibru = 0;
        
        mapCount[arr[i]]--;
        cout<<"Current Num= "<<arr[i]<<endl;
     if(arr[i]%r==0)
     {
         if(leftMapCount.count(arr[i]/r) >0 &&mapCount.count(arr[i]*r) >0)
         {
             currPossibru =  leftMapCount[arr[i]/r]* mapCount[arr[i]*r];
             possibru += currPossibru;
         }
     }
        leftMapCount[arr[i]]++;
        
    }
    
return possibru;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nr_temp;
    getline(cin, nr_temp);

    vector<string> nr = split(rtrim(nr_temp));

    int n = stoi(nr[0]);

    long r = stol(nr[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<long> arr(n);

    for (int i = 0; i < n; i++) {
        long arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    long ans = countTriplets(arr, r);

    fout << ans << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

