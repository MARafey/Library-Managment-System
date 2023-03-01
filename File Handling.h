#pragma once
#include"Libraries.h"


template <typename T>
void write(string file_name, T obj)
{
    ofstream fout(file_name + ".dat", ios::binary | ios::app);
    fout.write((char*)&obj, sizeof(obj));
    fout.close();
}

template <typename T>
void read(string file_name)
{
    T temp;
    ifstream fin(file_name + ".dat", ios::binary);
    while (fin.read((char*)&temp, sizeof(temp)))
    {
        temp.display();
    }

    fin.close();
}

template <typename T>
void Update(string file_name, int name, string updated_name)
{
    fstream f(file_name + ".dat", ios::binary | ios::in | ios::out);
    T temp;
    while (f.read((char*)&temp, sizeof(temp)))
    {
        if (temp.name == name)
        {
            strcpy_s_s(temp.name, updated_name.c_str());
            int a = f.tellg();
            int size = sizeof(temp);
            f.seekp(a - size);
            f.write((char*)&temp, sizeof(temp));
            break;
        }
    }
}

template <class T>
void Delete(string file_name, string name) {
    T temp;
    T temp2;
    ifstream fin(file_name + ".dat", ios::binary);
    ofstream fout(file_name + "sample.dat", ios::binary | ios::app);
    while (fin.read((char*)&temp, sizeof(temp)))
    {
        if (name != temp.name)
        {
            fout.write((char*)&temp, sizeof(temp));
        }
    }
    fout.close();
    fin.close();
    string a = file_name + ".dat";
    string b = file_name + "sample.dat";
    remove(a.c_str());
    rename(b.c_str(), a.c_str());
}

template <typename T>
bool Search(string file_name, string gmail, string pass)
{
    T temp;
    ifstream fin(file_name + ".dat", ios::binary);
    while (fin.read((char*)&temp, sizeof(temp)))
    {
        if (temp.email == gmail)
        {
            if (temp.password == pass)
            {

                fin.close();
                return true;
            }
            else
            {
                cout << "Paswword is incorrect." << std::endl;
                return false;
            }
        }

    }
    fin.close();
    cout << "Email not found ." << std::endl;
    return false;
}
