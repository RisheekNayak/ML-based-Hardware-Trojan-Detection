#include <iostream>
#include <fstream>

using namespace std;

void generate_path(string bench_name, int start, int end)
{
    string too_add_in_path = bench_name;
    string file_name = "Scripts_" + too_add_in_path + ".sh";
    ofstream fout(file_name);
    fout << "#!/bin/bash\n\n";

    for (int i = start; i <= end; i++)
    {
        string cur = too_add_in_path + "_I" + to_string(i);
        fout << "`./Binod_sim1 " + bench_name + ".bench 10000 dummy.txt ff_values_" + cur + ".txt output_values_" + cur + ".txt Input" + to_string(i) + ".txt 0`\n";
    }
    fout.close();
}

int main()
{
    int number_of_files;
    cin >> number_of_files;
    cin.ignore();

    while (number_of_files--)
    {
        string name_of_file;
        int start, end;

        cin >> name_of_file >> start >> end;
        generate_path(name_of_file, start, end);
    }

    return 0;
}