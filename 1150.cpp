#include <iostream>
#include <string>
#include <list>

using namespace std;

class Puzzle {
    public:
        Puzzle(string state);
        string get_state();
        string get_ops();
        Puzzle A();
        Puzzle B();
        Puzzle C();
        bool operator==(const Puzzle& other);
    private:
        Puzzle(string state, string ops);
        string state;
        string ops;
        void swap(int i, int j);
};

Puzzle::Puzzle(string s) {
    state = s;
    ops = "";
}

Puzzle::Puzzle(string s, string o) {
    state = s;
    ops = o;
}

string Puzzle::get_state() {
    return state;
}

string Puzzle::get_ops() {
    return ops;
}

void Puzzle::swap(int i, int j) {
    char tmp = state[i];
    state[i] = state[j];
    state[j] = tmp;
}

Puzzle Puzzle::A() {
    Puzzle result = Puzzle(state, ops + "A");
    for (int i = 0; i != 4; i++) {
        result.swap(i, i + 4);
    }
    return result;
}

Puzzle Puzzle::B() {
    Puzzle result = Puzzle(state, ops + "B");
    for (int i = 0; i != 3; i++) {
        result.swap(3 - i, 2 - i);
        result.swap(7 - i, 6 - i);
    }
    return result;
}

Puzzle Puzzle::C() {
    Puzzle result = Puzzle(state, ops + "C");
    result.swap(1, 5);
    result.swap(2, 6);
    result.swap(2, 5);
    return result;
}

bool Puzzle::operator==(const Puzzle& other) {
    return state == other.state;
}

int main() {
    int limit;
    while (cin >> limit && limit != -1) {
        char input[8];
        for (int i = 0; i != 8; i++) {
            cin >> input[i]; 
        }
        Puzzle target = Puzzle(string(input));

        list<Puzzle> nodes = list<Puzzle>();
        Puzzle org = Puzzle("12348765");
        nodes.push_back(org);

        bool ok = false;
        if (org == target) {
            ok = true;
        }

        list<Puzzle>::iterator it = nodes.begin();
        while (nodes.back().get_ops().length() <= limit && it != nodes.end() && !ok) {
            Puzzle puzzles[3] = {it->A(), it->B(), it->C() };

            for (int i = 0; i != 3; i++) {
                nodes.push_back(puzzles[i]);
                if (puzzles[i] == target) {
                    ok = true;
                    break;
                }
            }

            it++;
        }

        if (ok) {
            cout << nodes.back().get_ops().length() << ' ' << nodes.back().get_ops() << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}