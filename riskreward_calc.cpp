#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

class riskreward_calc {
public:
    double rr_calc(double rr, double width) {
        double amt = width / (1 / rr + 1);
        return amt;
    }

    static std::string formatNumberWithLeadingZeros(double number, int length) {
        std::stringstream ss;
        ss << std::fixed << std::setprecision(2) << number;
        std::string numberStr = ss.str();

        int zerosNeeded = length - numberStr.length();
        std::string zeros(zerosNeeded, '0');
        return zeros + numberStr;
    }

    void pnt(double a[], int size) {
        std::cout << std::endl;
        for (int i = 0; i < size; i++) {
            std::cout << a[i] << " | ";
        }
        std::cout << std::endl;
    }

    void maain(double pr1) {
        pr = pr1;

        for (int i = 0; i < 5; i++)
            amtt[i] = pr - 200 * i;
        pnt(amtt, 5);

        std::cout << std::endl;
        double rr = 0.45;
        double width = 200;

        int k = 2;
        for (int i = 100; i <= 1500; i += 200)
            prt(i, k);
        std::cout << std::endl;
        for (int i = 200; i <= 1200; i += 200)
            prt(i, k);
        std::cout << std::endl;
    }

    void prt(int i, int k) {
        std::cout << i << "\t" << std::endl;
        if (k == 2)
            j = 0.10;
        else
            j = 0.50;
        while (j <= 2.5 * k) {
            double rr = j;
            double width = i;
            double amt1 = rr_calc(rr, width);
            double amt2 = width - amt1;
            double amt3 = amt1 / 2.0;
            double amt4 = width - amt3;
            std::string amt_s1 = formatNumberWithLeadingZeros(amt1, 6);
            std::string amt_s2 = formatNumberWithLeadingZeros(amt2, 6);
            std::string amt_s3 = formatNumberWithLeadingZeros(amt3, 6);
            std::string amt_s4 = formatNumberWithLeadingZeros(amt4, 6);
            if (j <= 1)
                std::cout << std::fixed << std::setprecision(2) << "(" << j << ", " << 1 / j << ":1), " << amt_s1 << ", " << amt_s2 << "| " << amt_s3 << " " << amt_s4;
            else
                std::cout << std::fixed << std::setprecision(2) << "(" << j << ", " << 1 / j << ":1), " << amt_s1 << ", " << amt_s2 << "| " << amt_s3 << " " << amt_s4;

            for (int i1 = 0; i1 < 5; i1++) {
                double brk1 = amtt[i1] - std::stod(amt_s1);
                double brk2 = amtt[i1] + std::stod(amt_s1);
                double dist = pr - brk1;
                double dist1 = brk2 - brk1;
                std::cout << std::fixed << std::setprecision(2) << "( " << amtt[i1] << " " << brk1 << " " << brk2 << " " << dist << " " << dist1 << ") ";
            }

            std::cout << std::endl;
            if (j < 1)
                j += 0.10;
            else
                j += 0.40;
        }
        std::cout << std::endl;
    }

private:
    double pr = 0;
    double j = 0.10;
    double amtt[5];
};

// Main function should be outside the class
int main(int argc, char* argv[]) {
    double prr = 66200;
    riskreward_calc ob;
    ob.maain(prr);
    return 0;
}
