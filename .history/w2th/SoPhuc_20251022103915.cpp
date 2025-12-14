#include "SoPhuc.h"

SoPhuc::SoPhuc()
{
    thuc = ao = 0;
    sl++;
    ssl++;
}
SoPhuc::SoPhuc(const int &th, const int &a)
{
    thuc = th;
    ao = a;
    sl++;
    ssl++;
}
SoPhuc::SoPhuc(const SoPhuc &sp)
{
    thuc = sp.thuc;
    ao = sp.ao;
    sl++;
    ssl++;
}
SoPhuc::~SoPhuc()
{
    sl--;
    ssl--;
}
SoPhuc SoPhuc::Cong(const SoPhuc &sp)
{
    SoPhuc kq(*this);
    kq.thuc += sp.thuc;
    kq.ao += sp.ao;
    return kq;
}
int SoPhuc::SoLuongSP()
{
    return sl;
}
int SoPhuc::SSoLuongSP()
{
    return ssl;
}
int SoPhuc::ssl = 0;