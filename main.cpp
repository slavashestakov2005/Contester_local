#include <iostream>
#include <clocale>
#include "comands.h"

using namespace std;

int main(int argc, char* argv[]){
    setlocale (LC_ALL,"rus");
    Commands::init(argv[0]);
    cout << "����� ���������� � ���������� ��� ������� ����������!" << endl;
    cout << "�������������� �������:" << endl;
    cout << "start\t\t- ��� ������� ����������." << endl;
    cout << "finish\t\t- ��� ���������� ����������." << endl;
    cout << "open\t\t- ��� �������� web �����." << endl;
    cout << "exit\t\t- ��� ������." << endl;
    cout << "cls\t\t- ��� ������� ������." << endl;
    cout << "help\t\t- ��� ������ ���� ���������." << endl;
    string s;
    do{
        cout << ">>> ";
        if (!getline(cin, s)) cin.clear();
    }while(Commands::run(s));
    return 0;
}
