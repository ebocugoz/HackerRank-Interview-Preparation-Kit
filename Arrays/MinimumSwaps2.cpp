

//Question: https://www.hackerrank.com/challenges/minimum-swaps-2/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the minimumSwaps function below.
int minimumSwaps(vector<int> arr) {
    vector<int> sorted = arr;
    sort(sorted.begin(),sorted.end());
    int minSwap=0;
    
    int diff = sorted[0]-1;
    
    for(int i=0;i<arr.size();i++)
    {
        arr[i] = arr[i]-diff;
    }
    
    for(int i=0;i<arr.size()-1;i++)
    {
       if(arr[i]!=i+1)
        {
           
           int temp = arr[i];
           cout<<arr[i]<<"'s position is "<< i <<endl;
           cout<<arr[i]<<"'s new position is "<< arr[i]-1 <<endl;
           cout<<"There was a "<< arr[arr[i]-1]<<" at "<< arr[i]-1<<endl;
           arr[i] = arr[temp-1];
           
           arr[temp-1] = temp;
           cout<<arr[i]<<"'s new position is "<< i <<endl;
           cout<<arr[i]<<endl;
           
           minSwap++;
           i--;
       }
    }
    
    
    return (minSwap);

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int res = minimumSwaps(arr);

    fout << res << "\n";

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

