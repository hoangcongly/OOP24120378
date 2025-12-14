#include <iostream>
#include "HistogramArray.h" // Chỉ cần include file của lớp con

int main()
{
    std::cout << "================================================" << std::endl;
    std::cout << "## 1. KIEM TRA HAM DUNG VA setValue ##" << std::endl;
    std::cout << "================================================" << std::endl;

    // Tạo mảng 10 phần tử, theo dõi giá trị từ 0-9
    HistogramArray hist1(10, 10);

    hist1.setValue(0, 1);
    hist1.setValue(1, 2);
    hist1.setValue(2, 1);
    hist1.setValue(3, 5);
    hist1.setValue(4, 9);
    hist1.setValue(5, 5);
    hist1.setValue(6, 1);

    // Giả sử display() đã được override để in cả mảng và histogram
    hist1.display();

    std::cout << "\n================================================" << std::endl;
    std::cout << "## 2. KIEM TRA HAM DUNG SAO CHEP (Copy Constructor) ##" << std::endl;
    std::cout << "================================================" << std::endl;

    // Tạo hist2 là bản sao của hist1
    HistogramArray hist2 = hist1; // Hoặc HistogramArray hist2(hist1);

    std::cout << "--- Hien thi hist2 (ngay sau khi sao chep): ---" << std::endl;
    hist2.display();

    std::cout << "\n--- Thay doi hist2 (them so 9): ---" << std::endl;
    hist2.setValue(7, 9); // Thay đổi hist2

    std::cout << "\n--- Hien thi lai hist1 (phai khong doi): ---" << std::endl;
    hist1.display(); // Phải giống hệt ban đầu

    std::cout << "\n--- Hien thi lai hist2 (phai thay doi): ---" << std::endl;
    hist2.display(); // Phải có thêm số 9

    std::cout << "\n================================================" << std::endl;
    std::cout << "## 3. KIEM TRA TOAN TU GAN (Assignment Operator) ##" << std::endl;
    std::cout << "================================================" << std::endl;

    // Tạo hist3 với kích thước khác
    HistogramArray hist3(5, 10);
    hist3.setValue(0, 8);
    hist3.setValue(1, 8);

    std::cout << "--- Hien thi hist3 (truoc khi gan): ---" << std::endl;
    hist3.display();

    std::cout << "\n--- Thuc hien phep gan 'hist3 = hist1' ---" << std::endl;
    hist3 = hist1; // Gọi operator=

    std::cout << "\n--- Hien thi hist3 (ngay sau khi gan): ---" << std::endl;
    hist3.display(); // Phải giống hệt hist1

    std::cout << "\n--- Thay doi hist3 (them so 0): ---" << std::endl;
    hist3.setValue(8, 0); // Thay đổi hist3

    std::cout << "\n--- Hien thi lai hist1 (phai khong doi): ---" << std::endl;
    hist1.display(); // Phải giống hệt ban đầu

    std::cout << "\n--- Hien thi lai hist3 (phai thay doi): ---" << std::endl;
    hist3.display(); // Phải có thêm số 0

    std::cout << "\n================================================" << std::endl;
    std::cout << "## 4. KIEM TRA TINH DA HINH (Polymorphism) ##" << std::endl;
    std::cout << "================================================" << std::endl;

    // Dùng con trỏ LỚP CHA trỏ đến đối tượng LỚP CON
    Array *ptr = new HistogramArray(7, 10);

    std::cout << "--- Da tao 'Array* ptr = new HistogramArray(7, 10)' ---" << std::endl;
    ptr->setValue(0, 5);
    ptr->setValue(1, 3);
    ptr->setValue(2, 5);

    std::cout << "\n--- Goi 'ptr->display()' (Kiem tra virtual display): ---" << std::endl;
    // Phải gọi display() của HistogramArray (in cả 2)
    // Nếu không virtual, nó sẽ chỉ gọi display() của Array (chỉ in mảng)
    ptr->display();

    std::cout << "\n--- Goi 'delete ptr' (Kiem tra virtual destructor): ---" << std::endl;
    // Nếu destructor không virtual, ~HistogramArray() sẽ không được gọi
    // -> Gây rò rỉ bộ nhớ (memory leak) cho 'histogram'
    delete ptr;

    std::cout << "--- Da xoa ptr thanh cong ---" << std::endl;

    return 0;
}