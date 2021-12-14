#include <iostream>
#include "Header.h"


void menu();

int main()
{
    List<int>* Pointer1 = nullptr;
    List<double>* Pointer2 = nullptr;
    std::cout << "With who you need to work?(int=0, double!=0)";
    int a;
    std::cin >> a;
    std::cout << "Enter count:";
    int cnt;
    std::cin >> cnt;
    if (a == 0)
    {
        int inum;
        std::cout << "Add elems:";
        int icnt = cnt;
        while (icnt--)
        {
            std::cin >> inum;

            Pointer1->addToTail(Pointer1, inum);
        }
        std::cout << "\nInt:";
        Pointer1->print(Pointer1);
        std::cout << '\n';
        int ch = -1;
        do {
            menu();
            std::cin >> ch;
            switch (ch) {
            case 1:
            {
                int i, n;
                std::cout << "Write start position and size:";
                std::cin >> i >> n;
                int* arr = new int[n];
                std::cout << "Write elements:";
                for (int i = 0; i < n; i++)
                    std::cin >> arr[i];
                Pointer1->GroupAddIterative(Pointer1, i, i + n - 1, arr);
                delete[] arr;
            }break;
            case 2:
            {
                int i, n;
                std::cout << "Write start position and size:";
                std::cin >> i >> n;
                Pointer1->GroupDeleteIterative(Pointer1, i, i + n - 1);
            }break;
            case 3:
            {
                int i, n;
                std::cout << "Write start position and size:";
                std::cin >> i >> n;
                int* arr = new int[n];
                std::cout << "Write elements:";
                for (int i = 0; i < n; i++)
                    std::cin >> arr[i];
                Pointer1->GroupChageIterative(Pointer1, i, i + n - 1, arr);
                delete[] arr;
            }break;
            case 4:
            {
                int num;
                std::cout << "Write num:";
                std::cin >> num;
                bool flag = Pointer1->isElemInList(Pointer1, num);
                if (flag)
                    std::cout << "Yes\n";
                else
                    std::cout << "No\n";
            }break;
            case 5:
            {
                int n;
                std::cout << "Write size num:";
                std::cin >> n;
                int* arr = new int[n];
                std::cout << "Write elements:";
                for (int i = 0; i < n; i++)
                    std::cin >> arr[i];
                bool flag = Pointer1->FindGroupElementIterative(Pointer1, arr, n);
                delete[] arr;
                if (flag)
                    std::cout << "Yes\n";
                else
                    std::cout << "No\n";
            }break;
            case 6:
            {
                Pointer1->print(Pointer1);
            }break;
            case 7:
            {
                std::cout << "Exit!\n";
            }break;
            default:
            {
                std::cout << "No such choise!\n";
            }break;
            }
        } while (ch != 7);
    }
    else
    {
        int dcnt = cnt;
        double dnum;
        std::cout << "Add elems:";
        while (dcnt--)
        {
            std::cin >> dnum;

            Pointer2->addToTail(Pointer2, dnum);
        }

        std::cout << "\nDouble:";
        Pointer2->print(Pointer2);
        std::cout << '\n';
        int ch = -1;
        do {
            menu();
            std::cin >> ch;
            switch (ch) {
            case 1:
            {
                int i, n;
                std::cout << "Write start position and size:";
                std::cin >> i >> n;
                double* arr = new double[n];
                std::cout << "Write elements:";
                for (int i = 0; i < n; i++)
                    std::cin >> arr[i];
                Pointer2->GroupAddIterative(Pointer2, i, i + n - 1, arr);
                delete[] arr;
            }break;
            case 2:
            {
                int i, n;
                std::cout << "Write start position and size:";
                std::cin >> i >> n;
                Pointer2->GroupDeleteIterative(Pointer2, i, i + n - 1);
            }break;
            case 3:
            {
                int i, n;
                std::cout << "Write start position and size:";
                std::cin >> i >> n;
                double* arr = new double[n];
                std::cout << "Write elements:";
                for (int i = 0; i < n; i++)
                    std::cin >> arr[i];
                Pointer2->GroupChageIterative(Pointer2, i, i + n - 1, arr);
                delete[] arr;
            }break;
            case 4:
            {
                double num;
                std::cout << "Write num:";
                std::cin >> num;
                bool flag = Pointer2->isElemInList(Pointer2, num);
                if (flag)
                    std::cout << "Yes\n";
                else
                    std::cout << "No\n";
            }break;
            case 5:
            {
                int n;
                std::cout << "Write size num:";
                std::cin >> n;
                double* arr = new double[n];
                std::cout << "Write elements:";
                for (int i = 0; i < n; i++)
                    std::cin >> arr[i];
                bool flag = Pointer2->FindGroupElementIterative(Pointer2, arr, n);
                delete[] arr;
                if (flag)
                    std::cout << "Yes\n";
                else
                    std::cout << "No\n";
            }break;
            case 6:
            {
                Pointer2->print(Pointer2);
            }break;
            case 7:
            {
                std::cout << "Exit!\n";
            }break;
            default:
            {
                std::cout << "No such choise!\n";
            }break;
            }
        } while (ch != 7);
    }
    
    return 0;
}

void menu()
{
    std::cout << "Menu\n";
    std::cout << "1.Add Group\n";
    std::cout << "2.Delete Group\n";
    std::cout << "3.Change Group\n";
    std::cout << "4.Find one\n";
    std::cout << "5.Find Group\n";
    std::cout << "6.Print\n";
    std::cout << "7.Exit\n";
}