#include <bits/stdc++.h>

using namespace std;

bool generate_random_boolean()
{
    static auto gen = std::bind(std::uniform_int_distribution<>(0, 1), std::default_random_engine());
    return gen();
}

// Generates the input file consisting of random zeros and ones.
void generate_input_file(int rows, int cols, int number)
{
    ofstream fout("Input" + to_string(number) + ".txt");

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
            fout << generate_random_boolean();
        fout << "\n";
    }
    fout.close();
}

int main()
{
    int repeat = 1000;

    for (int i = 1; i <= repeat; i++)
    {
        int no_of_rows = 10001;      // cycles + 1 ie, 10001
        int no_of_cols = 35; // No of inputs

        srand(time(NULL));

        generate_input_file(no_of_rows, no_of_cols, i);
    }

    return 0;
}