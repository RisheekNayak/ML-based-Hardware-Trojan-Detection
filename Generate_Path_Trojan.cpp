#include <iostream>
#include <fstream>

using namespace std;

void generate_path(string bench_name, int trojan_number_start, int trojan_number_end, int input_start, int input_end)
{
    string too_add_in_path = bench_name + "_trojan";
    string file_name = "Scripts.sh";
    ofstream fout(file_name);
    fout << "#!/bin/bash\n\n";

    for (int current_input = input_start; current_input <= input_end; current_input++)
    {
        for (int i = trojan_number_start; i <= trojan_number_end; i++)
        {
            string cur = too_add_in_path + to_string(i);
            fout << "`./Binod_sim1 " + cur + ".bench 10000 dummy.txt ff_values_" + cur + "_I" + to_string(current_input) + ".txt output_values_" + cur + "_I" + to_string(current_input) + ".txt Input" + to_string(current_input) + ".txt" + " 0`\n";
        }
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
        int start, end, input_start, input_end;

        cin >> name_of_file >> start >> end >> input_start >> input_end;

        generate_path(name_of_file, start, end, input_start, input_end);
    }

    return 0;
}