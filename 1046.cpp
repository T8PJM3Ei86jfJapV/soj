#include <iostream>
#include <vector>
#include <algorithm>

struct Period {
    Period(int s, int e, double a) : start(s), end(e), avg(a) {}

    int start, end;
    double avg;

    friend bool operator < (const Period &a, const Period &b) {
        if (a.avg == b.avg) {
            return a.end-a.start != b.end-b.start ?
                a.end-a.start > b.end-b.start : a.end < b.end;
        }
        return a.avg > b.avg;
    }
};

int main(int argc, char* argv[]) {
    int loops;
    std::cin >> loops;
    for (int run = 1; run <= loops; run++) {
        int total, req, min;
        std::vector<Period> periods = std::vector<Period>();
        std::vector<int> sum = std::vector<int>();
        sum.push_back(0);

        std::cin >> total >> req >> min;
        for (int num, i = 0; i < total; i++) {
            std::cin >> num;
            sum.push_back(sum.back() + num);
        }

        for (int start = 1; start + min - 1 <= total; start++) {
            for (int end = start + min - 1; end <= total; end++) {
                double avg = (double)(sum[end] - sum[start - 1]) / (end - start + 1);
                periods.push_back(Period(start, end, avg));
            }
        }

        std::sort(periods.begin(), periods.end());

        std::cout << "Result for run " << run << ':' << std::endl;
        for (int i = 0; i < req && i < periods.size(); i++) {
            std::cout << periods[i].start << '-' << periods[i].end << std::endl;
        }
    }
    return 0;
}