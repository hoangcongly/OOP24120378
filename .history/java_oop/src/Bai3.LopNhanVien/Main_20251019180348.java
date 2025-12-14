import java.util.Scanner;

class NhanVien {
    private String ma, ten, sex, ngaySinh, diaChi, MST, hd;

    public NhanVien(String ma, String ten, String sex, String ngaySinh, String diaChi, String MST, String hd) {
        this.ma = ma;
        this.ten = ten;
        this.sex = sex;
        this.ngaySinh = ngaySinh;
        this.diaChi = diaChi;
        this.MST = MST;
        this.hd = hd;
    }

    private String ChuanHoaNgay(String ngay) {
        StringBuilder sb = new StringBuilder(ngay);
        if (sb.charAt(1) == '/') {
            sb.insert(0, "0");
        }
        if (sb.charAt(4) == '/') {
            sb.insert(3, "0");
        }
        return sb.toString();
    }

    public void ChuanHoa() {
        String[] a = ten.trim().split("\\s+");// Tach ten thanh cac mang tu
        String name = "";
        for (String x : a) {
            name += Character.toUpperCase(x.charAt(0));
            for (int i = 1; i < x.length(); i++) {
                name += Character.toLowerCase(x.charAt(i));
            }
            name += " ";
        }
        this.ten = name.trim();
        ngaySinh = ChuanHoaNgay(this.ngaySinh);
        this.hd = ChuanHoaNgay(this.hd);
    }

    @Override
    public String toString() {
        return ma + " " + ten + " " + sex + " " + ngaySinh + " " + diaChi + " " + MST + " " + hd;
    }
}

public class Main {
    public static void main(String[] aStrings) {

    }
}