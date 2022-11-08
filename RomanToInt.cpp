#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int romanToInt(string s)
{
    unordered_map<char,int>m({{'I',1},{'V',5},{'X',10},{'L', 50},{'C',100},{'D',500},{'M',1000}});
    int r = s.length() - 1;
    int l = r - 1;
    int sum = m[s[r]];

    while(r >= 0)
    {
        if (m[s[r]] <= m[s[l]]) sum += m[s[l]];
        else sum -= m[s[l]];
        l--;
        r--;
    }

    return sum;
}

int main()
{
    cout << romanToInt("XIX") << endl;
    cout << romanToInt("MMXIV") << endl;
}