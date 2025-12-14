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

}
