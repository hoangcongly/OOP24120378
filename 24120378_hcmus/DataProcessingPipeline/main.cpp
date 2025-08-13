#include "DataProcessor.h"

// Hiển thị vector gọn
void printVector(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i + 1 < v.size()) cout << ", ";
    }
    cout << "]\n";
}

// Đăng ký một số filter mặc định hữu ích
void registerBuiltInFilters(DataProcessor* dp) 
{
    dp->registerFilter("SortAsc", [](vector<int>& data) 
    {
        sort(data.begin(), data.end());
    });

    dp->registerFilter("SortDesc", [](vector<int>& data) 
    {
        sort(data.begin(), data.end(), greater<int>());
    });

    dp->registerFilter("RemoveNegative", [](vector<int>& data) 
    {
        data.erase(remove_if(data.begin(), data.end(), [](int x) 
        { return x < 0; }), data.end());
    });

    dp->registerFilter("RemoveDuplicates", [](vector<int>& data) 
    {
        sort(data.begin(), data.end());
        data.erase(unique(data.begin(), data.end()), data.end());
    });

    dp->registerFilter("MultiplyBy2", [](vector<int>& data) 
    {
        for (auto &x : data) x *= 2;
    });

    dp->registerFilter("Clamp0_100", [](vector<int>& data) 
    {
        for (auto &x : data) {
            if (x < 0) x = 0;
            if (x > 100) x = 100;
        }
    });
}

// Nhập dãy số từ dòng (khoảng trắng phân tách)
vector<int> inputVectorFromLine() 
{
    vector<int> v;
    cout << "Nhap cac so (cach nhau boi dau cach). Nhan Enter de ket thuc:\n";
    string line;
    getline(cin, line);
    if (line.empty()) { // nếu người dùng chỉ nhấn enter -> trả về rỗng
        return v;
    }
    istringstream iss(line);
    int x;
    while (iss >> x) v.push_back(x);
    return v;
}

// Tạo dữ liệu ngẫu nhiên
vector<int> generateRandomData(size_t n, int lo, int hi) {
    vector<int> v;
    v.reserve(n);
    static std::mt19937 rng(static_cast<unsigned>(time(nullptr)));
    std::uniform_int_distribution<int> dist(lo, hi);
    for (size_t i = 0; i < n; ++i) v.push_back(dist(rng));
    return v;
}

int main() {
    cout << "=== DataProcessor Demo (Professional CLI) ===\n\n";

    DataProcessor* dp = DataProcessor::getInstance();
    registerBuiltInFilters(dp);

    vector<int> data = {5, -3, 12, 5, 40, -10, 7}; // dữ liệu mẫu mặc định

    bool running = true;
    while (running) {
        cout << "\n--- Menu ---\n";
        cout << "1. Hien thi filters da dang ky\n";
        cout << "2. Hien thi chain hien tai\n";
        cout << "3. Them filter vao chain\n";
        cout << "4. Xoa filter khoi chain\n";
        cout << "5. Dang ky filter tuong dong (Multiply/Clamp)\n";
        cout << "6. Nhap du lieu (manually)\n";
        cout << "7. Tao du lieu ngau nhien\n";
        cout << "8. Hien thi du lieu hien tai\n";
        cout << "9. Chay process (ap dung chain)\n";
        cout << "10. Undo (phuc hoi trang thai truoc)\n";
        cout << "11. Luu chain vao file\n";
        cout << "12. Load chain tu file\n";
        cout << "13. Huy chain (clear)\n";
        cout << "14. Xoa dang ky mot filter (unregister)\n";
        cout << "0. Thoat\n";
        cout << "Lua chon: ";

        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            string dummy; getline(cin, dummy); // xoa dong
            cout << "Lua chon khong hop le. Thu lai.\n";
            continue;
        }
        string dummy; getline(cin, dummy); // clear rest of line

        switch (choice) {
            case 1:
                cout << "\n-- Registered filters --\n";
                dp->listFilters();
                break;

            case 2:
                cout << "\n-- Current chain --\n";
                dp->listChain();
                break;

            case 3: {
                cout << "Nhap ten filter muon them vao chain (chinh xac): ";
                string name;
                getline(cin, name);
                if (name.empty()) { cout << "Ten khong hop le.\n"; break; }
                dp->addToChain(name);
                cout << "Da them \"" << name << "\" vao chain.\n";
                break;
            }

            case 4: {
                cout << "Nhap ten filter muon xoa khoi chain: ";
                string name;
                getline(cin, name);
                if (name.empty()) { cout << "Ten khong hop le.\n"; break; }
                dp->removeFromChain(name);
                cout << "Da xoa \"" << name << "\" khoi chain (neu co).\n";
                break;
            }

            case 5: {
                cout << "Dang ky filter co tham so:\n";
                cout << " a) MultiplyBy <factor>\n b) Clamp <min> <max>\nLua chon (a/b): ";
                char c; cin >> c; getline(cin, dummy);
                if (c == 'a') 
                {
                    cout << "Nhap factor (so nguyen): ";
                    int factor; cin >> factor; getline(cin, dummy);
                    string name = "MultiplyBy_" + to_string(factor);
                    dp->registerFilter(name, [factor](vector<int>& arr) 
                    {
                        for (auto &x : arr) x *= factor;
                    });
                    cout << "Dang ky filter: " << name << "\n";
                } else if (c == 'b') 
                {
                    cout << "Nhap min va max (cach nhau boi khoang trang): ";
                    int lo, hi; cin >> lo >> hi; getline(cin, dummy);
                    string name = "Clamp_" + to_string(lo) + "_" + to_string(hi);
                    dp->registerFilter(name, [lo, hi](vector<int>& arr) {
                        for (auto &x : arr) 
                        {
                            if (x < lo) x = lo;
                            if (x > hi) x = hi;
                        }
                    });
                    cout << "Dang ky filter: " << name << "\n";
                } 
                else 
                {
                    cout << "Lua chon khong hop le.\n";
                }
                break;
            }

            case 6: {
                cout << "Nhap day so (dong, cac so cach nhau boi khoang trang). Nhap rieng dong de bo qua:\n";
                vector<int> v = inputVectorFromLine();
                if (!v.empty()) {
                    data = move(v);
                    cout << "Da cap nhat du lieu.\n";
                } else {
                    cout << "Khong co du lieu duoc nhap.\n";
                }
                break;
            }

            case 7: {
                cout << "Tao du lieu ngau nhien.\nNhap so phan tu, min, max: ";
                int n, lo, hi;
                if (!(cin >> n >> lo >> hi)) {
                    cin.clear();
                    getline(cin, dummy);
                    cout << "Nhap khong hop le.\n";
                } else {
                    getline(cin, dummy);
                    data = generateRandomData(static_cast<size_t>(n), lo, hi);
                    cout << "Du lieu ngau nhien da duoc tao.\n";
                }
                break;
            }

            case 8:
                cout << "Current data: ";
                printVector(data);
                break;

            case 9:
                if (dp->getInstance(), true) { /* ensure instance exists */ }
                cout << "Dang thuc hien process. (Luu history truoc khi ap dung)\n";
                dp->process(data);
                cout << "Sau khi process: ";
                printVector(data);
                break;

            case 10:
                cout << "Thuc hien UNDO...\n";
                dp->undo(data);
                cout << "Sau undo: ";
                printVector(data);
                break;

            case 11: {
                cout << "Nhap ten file de luu chain (vd: chain.txt): ";
                string fname; getline(cin, fname);
                if (fname.empty()) { cout << "Filename khong hop le.\n"; break; }
                dp->saveConfig(fname);
                cout << "Da luu chain vao " << fname << "\n";
                break;
            }

            case 12: {
                cout << "Nhap ten file de load chain: ";
                string fname; getline(cin, fname);
                if (fname.empty()) { cout << "Filename khong hop le.\n"; break; }
                dp->loadConfig(fname);
                cout << "Da load chain tu " << fname << " (chi them filter da dang ky)\n";
                break;
            }

            case 13:
                dp->clearChain();
                cout << "Da xoa toan bo chain.\n";
                break;

            case 14: {
                cout << "Nhap ten filter muon huy dang ky (registered filter): ";
                string name; getline(cin, name);
                if (name.empty()) { cout << "Ten khong hop le.\n"; break; }
                dp->removeFilter(name);
                cout << "Da huy dang ky filter (neu ton tai): " << name << "\n";
                break;
            }

            case 0:
                running = false;
                break;

            default:
                cout << "Lua chon khong hop le. Vui long chon lai.\n";
                break;
        }
    }

    cout << "Thoat chuong trinh. Tam biet!\n";
    return 0;
}
