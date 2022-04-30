#include <iostream>
#include <fstream>

using namespace std;

void generate_path(string bench_name, string type, int start, int end, int start_input, int end_input)
{
    ofstream fout("Scripts_" + type + "_to_table_" + bench_name + ".sh");
    fout << "#!/bin/bash\n\n";

    for (int cur_input = start_input; cur_input <= end_input; cur_input++)
    {
        for (int i = start; i <= end; i++)
            fout << "`./table " + type + "_" + bench_name + "_trojan" + to_string(i) + "_I" + to_string(cur_input) + "`\n";
    }
}

int main()
{
    string bench_name, type; // Type = ff values / output values
    int start, end;
    int start_input, end_input;

    cin >> bench_name >> type >> start >> end >> start_input >> end_input;

    generate_path(bench_name, type, start, end, start_input, end_input);
    return 0;
}