#include <iostream>
#include <string>
#include <queue>
#include <map>

using namespace std;

string opa(const string& in) {
    string out = string(8, '\0');
    out[0] = in[2];
    out[1] = in[3];
    out[2] = in[0];
    out[3] = in[1];
    out[4] = in[6];
    out[5] = in[7];
    out[6] = in[4];
    out[7] = in[5];
    return out;
}

string opb(const string& in) {
    string out = string(8, '\0');
    out[0] = in[1];
    out[1] = in[2];
    out[2] = in[3];
    out[3] = in[0];
    out[4] = in[5];
    out[5] = in[6];
    out[6] = in[7];
    out[7] = in[4];
    return out;
}

string opc(const string& in) {
    string out = string(8, '\0');
    out[0] = in[0];
    out[1] = in[2];
    out[2] = in[6];
    out[3] = in[3];
    out[4] = in[4];
    out[5] = in[1];
    out[6] = in[5];
    out[7] = in[7];
    return out;
}


int main() {
    int lim;

    map<string, string> m;
    queue<string> q;

    string org = "12345678";
    q.push(org);
    m[org] = "";

    while (cin >> lim && lim != -1) {
        string target;
        for (char tmp, i = '0'; i != '8'; i++) {
            cin >> tmp;
            target += tmp;
        }

        bool ok = false;

        if (m.find(target) != m.end() && m[target].length() <= lim) {
            cout << m[target].length() << ' ' << m[target] << endl;
            ok = true;
            continue;
        }

        if (m.find(target) == m.end()) {
            while (!q.empty() && !ok && m[q.back()].length() <= lim) {
                string cur = q.front();
                q.pop();

                string state[3] = {opa(cur), opb(cur), opc(cur)};
                string ops[3] = {m[cur] + "A", m[cur] + "B", m[cur] + "C"};

                for (int i = 0; i != 3; i++) {
                    if (m.find(state[i]) == m.end()) {
                        m[state[i]] = ops[i];
                        q.push(state[i]);
                    }

                    if (state[i] == target) {
                        cout << m[target].length() << ' ' << m[target] << endl;
                        ok = true;
                        break;
                    }
                }
            }
        }

        if (!ok) {
            cout << -1 << endl;
        }
    }
    return 0;
}
