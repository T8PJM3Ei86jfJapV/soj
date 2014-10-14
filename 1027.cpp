#include <iostream>
#include <string>
#include <map>

using namespace std;

struct Poster
{
    string id, ip;
};

int main() {
    int n;
    Poster poster[20];
    while (cin >> n && n) {
        for (int i = 0; i < n; i++) {
            cin >> poster[i].id >> poster[i].ip;
        }

        map<string, string> m;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (poster[i].ip == poster[j].ip) {
                    m[poster[i].id] = poster[j].id;
                    break;
                }
            }
        }

        for (map<string, string>::iterator it = m.begin(); it != m.end(); it++) {
            cout << it->second << " is the MaJia of " << it->first << endl;
        }
        cout << endl;
    }
    return 0;
}