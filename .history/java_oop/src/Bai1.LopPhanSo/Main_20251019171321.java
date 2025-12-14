//package Bai1.LopPhanSo;

import java.util.Scanner;

class PhanSo {
    private long tu, mau;

    public PhanSo(long tu, long mau) {
        this.tu = tu;
        this.mau = mau;
    }

    private long gcd(long a, long b) {
        while (b != 0) {
            long r = a % b;
            a = b;
            b = r;
        }
        return a;
    }

    public void rutGon() {
        long ucln = gcd(tu, mau);
        this.tu = this.tu / ucln;
        this.mau = this.mau / ucln;
    }

    @Override
    public String toString() {
        return this.tu + "/" + this.mau;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long tu = sc.nextLong();
        long mau = sc.nextLong();
        PhanSo p = new PhanSo(tu, mau);
        p.rutGon();
        System.out.println(p);
    }
}
