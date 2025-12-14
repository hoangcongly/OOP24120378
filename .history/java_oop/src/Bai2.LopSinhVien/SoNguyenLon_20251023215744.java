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

}
