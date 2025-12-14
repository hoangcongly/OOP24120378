#include "Student.h" // Chỉ cần include file của lớp con

int main()
{
    std::cout << "================================================" << std::endl;
    std::cout << "## 1. KIEM TRA HAM DUNG MAC DINH (Person() / Student()) ##" << std::endl;
    std::cout << "================================================" << std::endl;

    // Kiểm tra Student()
    Student s_default;
    std::cout << "--- Hien thi Sinh vien mac dinh (s_default): ---" << std::endl;
    s_default.display();

    std::cout << "\n--- Them diem vao s_default: ---" << std::endl;
    s_default.addGrade(8);
    s_default.addGrade(7);
    s_default.display();

    // Kiểm tra Person()
    Person p_default;
    std::cout << "\n--- Hien thi Person mac dinh (p_default): ---" << std::endl;
    p_default.display();

    std::cout << "\n================================================" << std::endl;
    std::cout << "## 2. KIEM TRA HAM DUNG CO THAM SO (Student(name, cap)) ##" << std::endl;
    std::cout << "================================================" << std::endl;

    // Tạo sinh viên có tên, dung lượng mảng điểm là 5
    Student s1("Hoang Cong Ly", 5);
    s1.addGrade(10);
    s1.addGrade(9);
    s1.addGrade(8);

    std::cout << "--- Hien thi s1 (Hoang Cong Ly): ---" << std::endl;
    s1.display();

    std::cout << "\n--- Kiem tra dung luong mang diem (them 3 diem vao s1): ---" << std::endl;
    s1.addGrade(7);
    s1.addGrade(6);
    s1.addGrade(5); // <-- Diem nay se bi tu choi (vi dung luong chi la 5)
    s1.display();   // Mảng điểm vẫn chỉ có 5 điểm

    std::cout << "\n================================================" << std::endl;
    std::cout << "## 3. KIEM TRA HAM DUNG SAO CHEP (Copy Constructor) ##" << std::endl;
    std::cout << "================================================" << std::endl;

    // Tạo s2 là bản sao của s1
    Student s2 = s1; // Hoặc Student s2(s1);

    std::cout << "--- Hien thi s2 (ngay sau khi sao chep tu s1): ---" << std::endl;
    s2.display();

    std::cout << "\n--- Thay doi s2 (doi ten va them diem): ---" << std::endl;
    // (Lưu ý: s2 cũng đầy, nên addGrade sẽ thất bại, nhưng setName thì thành công)
    s2.setName("Student Copy");
    s2.addGrade(4); // Sẽ báo lỗi

    std::cout << "\n--- Hien thi lai s1 (PHAI KHONG DOI): ---" << std::endl;
    s1.display(); // Phải là "Hoang Cong Ly" (chứng tỏ deep copy)

    std::cout << "\n--- Hien thi lai s2 (PHAI THAY DOI TEN): ---" << std::endl;
    s2.display(); // Phải là "Student Copy"

    std::cout << "\n================================================" << std::endl;
    std::cout << "## 4. KIEM TRA TOAN TU GAN (Assignment Operator) ##" << std::endl;
    std::cout << "================================================" << std::endl;

    // Tạo s3 (dùng hàm dựng mặc định)
    Student s3;
    std::cout << "--- Hien thi s3 (truoc khi gan): ---" << std::endl;
    s3.display();

    std::cout << "\n--- Thuc hien phep gan 's3 = s1' ---" << std::endl;
    s3 = s1; // Gọi operator=

    std::cout << "\n--- Hien thi s3 (ngay sau khi gan): ---" << std::endl;
    s3.display(); // Phải giống hệt s1

    std::cout << "\n--- Thay doi s3 (doi ten): ---" << std::endl;
    s3.setName("Assigned Student");

    std::cout << "\n--- Hien thi lai s1 (PHAI KHONG DOI): ---" << std::endl;
    s1.display(); // Phải là "Hoang Cong Ly" (chứng tỏ deep copy)

    std::cout << "\n--- Hien thi lai s3 (PHAI THAY DOI TEN): ---" << std::endl;
    s3.display(); // Phải là "Assigned Student"

    std::cout << "\n================================================" << std::endl;
    std::cout << "## 5. KIEM TRA TINH DA HINH (Polymorphism) ##" << std::endl;
    std::cout << "================================================" << std::endl;

    // Dùng con trỏ LỚP CHA trỏ đến đối tượng LỚP CON
    Person *p_ptr = new Student("Poly Morph", 4);

    // Không thể gọi p_ptr->addGrade(10); vì Person không có hàm này
    // Chúng ta phải test các hàm virtual

    std::cout << "--- Goi 'p_ptr->display()' (Kiem tra virtual display): ---" << std::endl;
    // Phải gọi display() của Student (in cả tên, điểm, GPA)
    // Nếu display() không virtual, nó sẽ chỉ gọi display() của Person (chỉ in tên)
    p_ptr->display();

    std::cout << "\n--- Goi 'delete p_ptr' (Kiem tra virtual destructor): ---" << std::endl;
    // Phải gọi ~Student() trước, rồi mới gọi ~Person()
    // Nếu ~Person() không virtual, chỉ có ~Person() được gọi
    // -> Gây rò rỉ bộ nhớ (memory leak) cho 'grades'
    delete p_ptr;

    std::cout << "--- Da xoa p_ptr thanh cong ---" << std::endl;

    return 0;
}