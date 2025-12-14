#include <iostream>
#include "Report.h" // Chỉ cần include file cuối cùng

int main()
{
    std::cout << "================================================" << std::endl;
    std::cout << "## 1. KIEM TRA HAM DUNG MAC DINH (Report()) ##" << std::endl;
    std::cout << "================================================" << std::endl;

    Report r_default;
    r_default.display();

    std::cout << "\n================================================" << std::endl;
    std::cout << "## 2. KIEM TRA HAM DUNG CO THAM SO ##" << std::endl;
    std::cout << "================================================" << std::endl;

    Report r1("Quarterly Results", "Hoang Cong Ly", "Sales are up 20%.");
    r1.display();

    std::cout << "\n================================================" << std::endl;
    std::cout << "## 3. KIEM TRA HAM DUNG SAO CHEP ##" << std::endl;
    std::cout << "================================================" << std::endl;

    Report r2 = r1; // Gọi hàm dựng sao chép
    r2.setContent("Sales are up 50% due to new strategy.");

    std::cout << "\n--- Hien thi r1 (Phai khong doi) ---" << std::endl;
    r1.display();

    std::cout << "\n--- Hien thi r2 (Phai thay doi content) ---" << std::endl;
    r2.display();

    std::cout << "\n================================================" << std::endl;
    std::cout << "## 4. KIEM TRA TOAN TU GAN ##" << std::endl;
    std::cout << "================================================" << std::endl;

    Report r3; // Gọi hàm dựng mặc định
    std::cout << "\n--- Hien thi r3 (Truoc khi gan) ---" << std::endl;
    r3.display();

    r3 = r1; // Gọi toán tử gán
    r3.setContent("Sales are flat.");

    std::cout << "\n--- Hien thi r1 (Phai khong doi) ---" << std::endl;
    r1.display();

    std::cout << "\n--- Hien thi r3 (Phai thay doi content) ---" << std::endl;
    r3.display();

    std::cout << "\n================================================" << std::endl;
    std::cout << "## 5. KIEM TRA DA HINH (Polymorphism) ##" << std::endl;
    std::cout << "================================================" << std::endl;

    Document *docPtr = new Report("Annual Review", "CEO", "A great year.");

    docPtr->display(); // Phải gọi Report::display()

    delete docPtr; // Phải gọi ~Report() rồi mới đến ~Document()
    std::cout << "--- Da xoa docPtr ---" << std::endl;

    return 0;
}