import java.io.StringBufferInputStream;
import java.util.Arrays;
import java.util.Collection;
import java.util.stream.Collectors;

public class SoNguyenLon {
    private String digit;

    public SoNguyenLon() {
        this.digit = "0";
    }

    public SoNguyenLon(String str) {
        if (str == null || str.isEmpty() || str.matches("\\d+")) {
            this.digit = "0";
        } else {
            this.digit = str.replaceFirst("^0(?!$)", "");
            if (this.digit.isEmpty()) {
                this.digit = "0";
            }
        }
    }

    public SoNguyenLon(int num1, int num2) {
        if (num1 < 0 || num1 > 9) {
            this.digit = "0";
        }
        if (num2 <= 0) {
            this.digit = "0";
        } else {
            char digit = (char) (num1 + '0');
            char[] chars = new char[num2];
            Arrays.fill(chars, digit);
            this.digit = new String(chars).replaceFirst("^0(?!$)", "");
            if (this.digit.isEmpty()) {
                this.digit = "0";
            }
        }
    }

    public int compare(SoNguyenLon other) {
        if (this.digit.length() > other.digit.length())
            return 1;
        if (this.digit.length() < other.digit.length())
            return -1;
        return this.digit.compareTo(other.digit);
    }

    public SoNguyenLon cong(SoNguyenLon other) {
        String s1 = this.digit;
        String s2 = other.digit;

        String rs1 = new StringBuilder(s1).reverse().toString();
        String rs2 = new StringBuilder(s2).reverse().toString();

        StringBuilder result = new StringBuilder();
        int carry = 0;
        int n = Math.max(s1.length(), s2.length());
        for (int i = 0; i < n || carry != 0; i++) {
            int digit1 = (i < rs1.length()) ? (rs1.charAt(i) - '0') : 0;
            int digit2 = (i < rs2.length()) ? (rs2.charAt(i) - '0') : 0;
            int sum = digit1 + digit2 + carry;
            result.append(sum % 10);
            carry = sum / 10;
        }
        return new SoNguyenLon(result.reverse().toString());
    }

    public SoNguyenLon cong(long num) {
        SoNguyenLon snl_num = new SoNguyenLon(String.valueOf(num));
        return this.cong(snl_num);
    }

    public SoNguyenLon tru(SoNguyenLon other) {
        if (this.compare(other) < 0) {
            return new SoNguyenLon("0");
        }
        String s1 = this.digit;
        String s2 = other.digit;

        String rs1 = new StringBuilder(s1).reverse().toString();
        String rs2 = new StringBuilder(s2).reverse().toString();

        StringBuilder result = new StringBuilder();
        int borrow = 0;
        int n = s1.length();
        for (int i = 0; i < n; i++) {
            int digit1 = rs1.charAt(i) - '0';
            int digit2 = (i < rs2.length()) ? (rs2.charAt(i) - '0') : 0;

            int diff = digit1 - digit2 - borrow;

            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            result.append(diff);
        }
        return new SoNguyenLon(result.reverse().toString());
    }

    public static SoNguyenLon hieuVoiHangSo(long num, SoNguyenLon snl) {
        SoNguyenLon num_snl = new SoNguyenLon(String.valueOf(num));
        return num_snl.tru(snl);
    }

    public String in() {
        return this.digit;
    }

    @Override
    public String toString() {
        return this.digit;
    }
}

public class SoNguyenLon1 {

    // Hàm main là điểm bắt đầu thực thi của chương trình Java
    public static void main(String[] args) {

        System.out.println("--- Kiem tra lop SoNguyenLon ---");

        // 1. Kiem tra constructor khong tham so
        SoNguyenLon soA = new SoNguyenLon();
        System.out.println("So A (mac dinh): " + soA.toString()); // Ket qua mong doi: 0

        // 2. Kiem tra constructor co tham so (so lon hop le)
        String soLonStr = "9876543210987654321012345";
        SoNguyenLon soB = new SoNguyenLon(soLonStr);
        System.out.println("So B (tu chuoi): " + soB.toString());

        // 3. Kiem tra constructor voi so 0 vo nghia o dau
        String soThua0 = "00012345";
        SoNguyenLon soC = new SoNguyenLon(soThua0);
        System.out.println("So C (thua so 0): " + soC.toString()); // Ket qua mong doi: 12345 (sau khi chuan hoa)

        // 4. Kiem tra constructor voi gia tri 0
        String chiLa0 = "000";
        SoNguyenLon soD = new SoNguyenLon(chiLa0);
        System.out.println("So D (chi la 0): " + soD.toString()); // Ket qua mong doi: 0 (sau khi chuan hoa)

        // 5. Kiem tra constructor voi chuoi rong (phu thuoc vao cach xu ly trong
        // constructor)
        // Note: Trong code sua, neu chuoi rong/null, no se tra ve "0"
        SoNguyenLon soE = new SoNguyenLon("");
        System.out.println("So E (chuoi rong): " + soE.toString()); // Ket qua mong doi: 0
    }
}