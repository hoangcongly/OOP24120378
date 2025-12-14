import java.util.Scanner;

class SinhVien {
    private String ten, ngaySinh;
    private double d1, d2, d3;

    public SinhVien(String ten, String ngaySinh, double d1, double d2, double d3) {
        this.ten = ten;
        this.ngaySinh = ngaySinh;
        this.d1 = d1;
        this.d2 = d2;
        this.d3 = d3;
    }

    public void InThongTin() {
        double tongdiem = d1 + d2 + d3;
        System.out.println(ten + " " + ngaySinh + " " + String.format("%.1f", tongdiem));
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String ten = sc.nextLine();
        String ngaySinh = sc.nextLine();
        double diem1 = sc.nextDouble();
        double diem2 = sc.nextDouble();
        double diem3 = sc.nextDouble();

        SinhVien s = new SinhVien(ten, ngaySinh, diem1, diem2, diem3);
        s.InThongTin();
    }
}