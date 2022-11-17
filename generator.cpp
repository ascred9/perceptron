#include <fstream>
#include <iomanip>
#include <random>

const int Nevents = 1e3;

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> norm(.0, 1e-2);
    std::uniform_real_distribution<> dist(-3., 3.);

    std::ofstream fout("cos.txt");
    for (int i = 0; i < Nevents; ++i)
    {
        double x = dist(gen);
        double y = cos(x) + norm(gen);
        fout << std::setprecision(9) << x << " " << y << std::endl;
    }
    fout.close();

    return 1;
}