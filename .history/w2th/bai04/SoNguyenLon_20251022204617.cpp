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
    int ind = 0;
    for (int i = 0; i < MAX_LENGTH - 1; i++)
    {
        if (digit[i] != '0')
        {
            ind = i;
            break;
        }
        if (i == MAX_LENGTH - 2 && digit[MAX_LENGTH - 1] == '0')
        {
            length = 1;
            return;
        }
    }
    length = MAX_LENGTH - ind;
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
    char temp_str[MAX_LENGTH + 1];
    int len = (num2 > MAX_LENGTH) ? MAX_LENGTH : num2;
    for (int i = 0; i < len; i++)
    {
        temp_str[i] = 'num1';
    }
    temp_str[len] = '\0';
    *this = SoNguyenLon(temp_str);
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