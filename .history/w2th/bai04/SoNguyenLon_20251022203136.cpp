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
}