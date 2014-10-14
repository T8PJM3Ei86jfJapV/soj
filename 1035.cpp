#include <iostream>
#include <string>

using namespace std;

int main() {
    int cases;
    cin >> cases;
    while (cases--) {
        int n; // n: the number of single strands
        cin >> n;
        string strand[100];
        for (int i = 0; i < n; i++) {
            cin >> strand[i];
        }

        int pairs = 0; // pairs: number of double strands that can be formed
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int len1 = strand[i].length();
                int len2 = strand[j].length();
                if (len1 == len2 && len1 != 0) { // important: len != 0
                    bool matched = true;
                    for (int k = 0; k < len1; k++) {
                    /*
                        'A'+'T'=149, 149%11=6
                        'A'+'C'=132, 132%11=0
                        'A'+'G'=136, 136%11=4
                        'T'+'C'=151, 151%11=8
                        'T'+'G'=155, 155%11=1
                        'C'+'G'=138, 138%11=6
                    */
                        if ((strand[i][k]+strand[j][k]) % 11 != 6) {
                            matched = false;
                            break;
                        }
                    }
                    if (matched) {
                        strand[j].clear();
                        pairs++;
                        break;
                    }
                }
            }
        }
        cout << pairs << endl;
    }
    return 0;
}