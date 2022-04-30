#include <bits/stdc++.h>

using namespace std;

// This function checks if all the files can be opened or not.
// Returns TRUE if the file can be opened.
bool check_file(ifstream &fin, ofstream &fout, ofstream &temp)
{
    if (fin.fail() || fout.fail() || temp.fail())
    {
        cout << "Failed to create a file.";
        return false;
    }
    return true;
}

// Adds the name of the gates at the 1st row.
void shift_old_to_new(ofstream &fout, ifstream &temp)
{
    temp.seekg(0, ios::beg);
    string line;
    fout << "\n";

    while (getline(temp, line))
    {
        if (line.size() == 0)
            continue;

        fout << line << "\n";
    }
}

// Adds the initial lines of the output files.
void add_initial_lines(ofstream &fout)
{
    fout << "Printing the Flip Flop Values in Tablular Form.\n";
    fout << "The first row represents the names of all the gates.\n";
    fout << "The first column represents the cycle number.\n\n";
}

int main(int argc, char *argv[])
{
    string file_name = argv[1];
    ifstream fin(file_name + ".txt");

    ofstream temp("Temp.txt");

    ofstream fout("Table_" + file_name + ".txt");

    if (!check_file(fin, fout, temp))
        return 0;
    
    string line;
    int ignore = 4; // Initial lines to be skipped.
    int cur_cycle = 0;

    add_initial_lines(fout);

    while (getline(fin, line))
    {
        if (ignore) // Skipping initial lines.
        {
            ignore--;
            continue;
        }

        if (line.size() == 0)
            continue;

        istringstream iss(line);

        int num;
        string type;
        iss >> type >> num;

        if (type == "Cycle")
            temp << "\n", cur_cycle = num;
        else
        {
            if (cur_cycle == 0)
                fout << type << " ";
            temp << num << "\t";
        }
    }
    temp.close();

    ifstream temp1("Temp.txt");
    shift_old_to_new(fout, temp1);

    fin.close();
    fout.close();
    temp1.close();
    remove("Temp.txt");

    return 0;
}