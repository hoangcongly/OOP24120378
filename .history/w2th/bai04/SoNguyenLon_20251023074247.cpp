#include "SoNguyenLon.h"

SoNguyenLon *SoNguyenLon::DS_SNL[MAX_SNL] = {nullptr};
int SoNguyenLon::DS_size = 0;

void SoNguyenLon::init_zero()
{
    for (int i = 0; i < MAX_LENGTH; i++)
    {
        digit[i] = '0';
    }
    length = 1;
}
void SoNguyenLon::trimLeadingZeros()
{
    int first_digit_index = 0;
    for (int i = 0; i < MAX_LENGTH; i++)
    {
        if (digit[i] != '0')
        {
            first_digit_index = i;
            break;
        }
    }
    if (digit[first_digit_index] == '0')
    {
        length = 1;
    }
    else
    {
        length = MAX_LENGTH - first_digit_index;
    }
}
int SoNguyenLon::compare(const SoNguyenLon &other)
{
    if (length > other.length)
        return 1;
    if (length < other.length)
        return -1;
    int start = MAX_LENGTH - length;
    for (int i = start; i < MAX_LENGTH; i++)
    {
        if (digit[i] > other.digit[i])
            return 1;
        if (digit[i] < other.digit[i])
            return -1;
    }
    return 0;
}
SoNguyenLon::SoNguyenLon()
{
    init_zero();
    if (DS_size < MAX_SNL)
    {
        DS_SNL[DS_size] = this;
        DS_size++;
    }
}
SoNguyenLon::SoNguyenLon(const char *str)
{
    init_zero();
    int len = strlen(str);
    length = min(len, MAX_LENGTH);
    for (int i = 0; i < length; i++)
    {
        digit[MAX_LENGTH - i - 1] = str[len - i - 1];
    }
    trimLeadingZeros();
    if (DS_size < MAX_SNL)
    {
        DS_SNL[DS_size] = this;
        DS_size++;
    }
}
SoNguyenLon::SoNguyenLon(int num1, int num2)
{

    init_zero();
    int len = (num2 > MAX_LENGTH) ? MAX_LENGTH : num2;
    int start = MAX_LENGTH - len;
    for (int i = start; i < MAX_LENGTH; i++)
    {
        this->digit[i] = num1 + '0';
    }
    this->length = len;
    trimLeadingZeros();
    if (DS_size < MAX_SNL)
    {
        DS_SNL[DS_size] = this;
        DS_size++;
    }
}
SoNguyenLon::~SoNguyenLon()
{
    for (int i = 0; i < DS_size; i++)
    {
        if (DS_SNL[i] == this)
        {
            for (int j = i; j < DS_size - 1; ++j)
            {
                DS_SNL[j] = DS_SNL[j + 1];
            }
            DS_SNL[--DS_size] = nullptr;
            return;
        }
    }
}
SoNguyenLon SoNguyenLon::Cong(const SoNguyenLon &other)
{
    SoNguyenLon result;
    int carry = 0;
    int maxlen = max(this->length, other.length);
    for (int i = 0; i < maxlen; i++)
    {
        int idx = MAX_LENGTH - 1 - i;
        int digit1 = 0;
        if (idx < this->length)
        {
            digit1 = this->digit[idx] - '0';
        }
        int digit2 = 0;
        if (idx < other.length)
        {
            digit2 = other.digit[idx] - '0';
        }
        int sum = digit1 + digit2 + carry;
        int result_digit = sum % 10;
        carry = sum / 10;
        result.digit[i] = result_digit + '0';
        if (i >= maxlen && carry == 0)
            break;
    }
    result.trimLeadingZeros();
    return result;
}
SoNguyenLon SoNguyenLon::Tru(const SoNguyenLon &other)
{
    if (this->compare(other))
        return SoNguyenLon("0");
    SoNguyenLon result;
    int borrow = 0;
    for (int i = 0; i < this->length; i++)
    {
        int idx = MAX_LENGTH - i - 1;
        int digit1 = this->digit[idx] - '0';
        int digit2 = 0;
        if (i < other.length)
        {
            digit2 = other.digit[idx] - '0';
        }
        int dif = digit1 - digit2 - borrow;
        if (dif < 0)
        {
            dif += 10;
            borrow = 1;
        }
        else
            borrow = 0;
        result.digit[i] = dif + '0';
    }
    result.trimLeadingZeros();
    return result;
}
void SoNguyenLon::LongLongToChar(long long num, char *str)
{
    if (num < 0)
        num = -num;
    if (num == 0)
    {
        str[0] = '0';
        str[1] = '\0';
        return;
    }
    char temp_result[100];
    int i = 0;
    long long temp = num;
    while (temp > 0)
    {
        temp_result[i++] = (temp % 10) + '0';
        temp /= 10;
    }
    int len = i;
    for (int j = 0; j < len; j++)
    {
        str[j] = temp_result[len - 1 - j];
    }
    str[j] = '\0';
}
SoNguyenLon SoNguyenLon::HieuVoiHangSo(const long long &num, const SoNguyenLon &snl)
{
    char num_str[100];
}