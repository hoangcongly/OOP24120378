#include "libraryw7.h"

void showMenu()
{
    std::cout << "\n================ MENU ================" <<std::endl;
    std::cout << "1. Hien thi danh sach hien tai" << std::endl;
    std::cout << "2. Xuat danh sach ra file OUTPUT.TXT" << std::endl;
    std::cout << "3. Xoa mot tai lieu theo ID" << std::endl;
    std::cout << "4. Sap xep tai lieu theo nam" << std::endl;
    std::cout << "5. Tim kiem tai lieu theo ten tac gia" << std::endl;
    std::cout << "6. Loc tai lieu theo loai" << std::endl;
    std::cout << "0. Thoat chuong trinh" << std::endl;
    std::cout << "======================================" << std::endl;
    std::cout << "Lua chon cua ban: ";
}
int main()
{
    CLibrary myLibrary;
    myLibrary.Input("input07.txt");
    int choice;
    do
    {
        showMenu();
        std:: cin>> choice;
        switch (choice)
        {
            case 1:
            std::cout << "\n--- DANH SACH TAI LIEU HIEN TAI ---" << std::endl;
            break;
        case 2:
            myLibrary.Output("OUTPUT.TXT");
            break;
        case 3:
            myLibrary.Delete();
            break;
        case 4:
            myLibrary.SortYear();
            break;
        case 5:
            myLibrary.SearchByAuthor();
            break;
        case 6:
            myLibrary.FilterByType();
            break;
        case 0:
            std::cout << "Thoat chuong trinh." << std::endl;
            break;
        default:
            std::cout << "Lua chon khong hop le. Vui long chon lai." << std::endl;
            break;
        }
    } while (choice!=0);
    return 0;
}