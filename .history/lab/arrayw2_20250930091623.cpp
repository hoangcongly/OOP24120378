#include "arrayw2.h"

CIntArray:: CIntArray()
{
    m_Length=0;
    m_Array=nullptr;
}
CIntArray:: CIntArray(const CIntArray& other)
{
    m_Length= other.m_Length;
    if(m_Length>0)
    {
        m_Array= new int[m_Length];
        for(int i=0; i<m_Length; i++)
        {
            m_Array[i]= other.m_Array[i];
        }
    }
    else m_Array=nullptr;
}
CIntArray:: CIntArray(int*arr, int length)
{
    m_Length=length;
    m_Array= new int[m_Length];
    for(int i=0; i< m_Length; i++)
    {
        m_Array[i]= arr[i];
    }
}
CIntArray:: ~CIntArray()
{
    delete[] m_Array;
}
void CIntArray:: InputArray()
{
    cout << "Nhap so phan tu: ";
    cin >> m_Length;
    m_Array = new int[m_Length];
    for (int i = 0; i < m_Length; i++) {
        m_Array[i] = rand() % 100; // random 0..99
    }
}
void CIntArray::OutputArray() {
    cout << "Mang: ";
    for (int i = 0; i < m_Length; i++) {
        cout << m_Array[i] << " ";
    }
    cout << endl;
}
CIntArray CIntArray:: Remove()
{
    for(int i=0; i< m_Length; i++)
    {
        for(int j=i+1; j<m_Length;)
        {
            if(m_Array[i]==m_Array[j])
            {
                Remove(j);
            }
            else j++;
        }
    }
    return *this;
}
CIntArray CIntArray:: Remove(int index)
{
    if(index<0|| index>=m_Length) return *this;
    for(int i=index; i<m_Length-1;i++)
    {
        m_Array[i]=m_Array[i+1];
    }
    m_Length--;
    return*this;
}
CIntArray CIntArray:: Remove(int k, int n)
{
    // 5 2 5 .3 5 2 5. 2 4 1: k=3, n=4: xoa 4 phan tu tu vi tri so 3
    if(k<0|| k+n>m_Length) return*this;
    for(int i=k; i<m_Length-n; i++)
    {
        m_Array[i]=m_Array[i+n];
    }
    m_Length-=n;
    return *this;
}
CIntArray CIntArray:: Replace(int oldval, int newval)
{
    for(int i=0; i<m_Length; i++)
    {
        if(m_Array[i]==oldval) m_Array[i]= newval;
    }
    return *this;
}
CIntArray CIntArray:: AddHead(int val)
{
    int* tmp= new int[m_Length+1];
    tmp[0]= val;
    for(int i=0; i<m_Length; i++)
    {
        tmp[i+1]= m_Array[i];
    }
    delete[] m_Array;
    m_Array=tmp;
    m_Length++;
    return *this;
}
CIntArray CIntArray:: AddTail(int val)
{
    int*tmp= new int[m_Length+1];
    for(int i=0; i< m_Length; i++)
    {
        tmp[i]= m_Array[i];
    }
    tmp[m_Length]=val;
    delete[] m_Array;
    m_Array=tmp;
    m_Length++;
    return*this;
}
CIntArray CIntArray:: Insert(int val, int k)
{
    if(k<0|| k>m_Length) return*this;
    int *tmp= new int[m_Length+1];
    for(int i=0; i<k; i++)
    {
        tmp[i]= m_Array[i];
    }
    tmp[k]= val;
    for(int i=k; i<m_Length; i++)
    {
        tmp[i+1] = m_Array[i];   
    }
    delete[] m_Array;
    m_Array=tmp;
    m_Length++;
    return*this;
}
int CIntArray:: Max()
{
    int mx= m_Array[0];
    for(int i=1; i<m_Length; i++)
    {
        if(m_Array[i]>mx) mx= m_Array[i];
    }
    return mx;
}
int CIntArray:: Min()
{
    int mn= m_Array[0];
    for(int i=1; i< m_Length; i++)
    {
        if(m_Array[i]< mn) mn= m_Array[i];
    }
    return mn;
}
CIntArray CIntArray::Ascending()
{
    sort(m_Array, m_Array + m_Length);
    return *this;
}
CIntArray CIntArray::Descending() {
    sort(m_Array, m_Array + m_Length, greater<int>());
    return *this;
}
bool CIntArray:: IsSymmetry()
{
    // 5 2 4 3 4 2 5 
    for(int i=0; i<m_Length/2; i++)
    {
        if(m_Array[i]!=m_Array[m_Length-i-1]) return false;
    }
    return true;
}
CIntArray CIntArray:: MoveForward()
{
    return MoveForward(1);
}
CIntArray CIntArray:: MoveForward(int n)
{
    // 4 5 6 7 2 3 --> 6 7 2 3 4 5 --> 2 3 4 5 6 7 
    // x x 4 5 6 7 
    n%= m_Length;
    int *tmp= new int[m_Length];
    for(int i=0; i< m_Length; i++)
    {
        tmp[i]= m_Array[(i+n)%m_Length];
    }
    delete[] m_Array;
    m_Array=tmp;
    return*this;
}
CIntArray CIntArray:: MoveBehind()
{
    return MoveBehind(1);
}
CIntArray CIntArray:: MoveBehind(int n)
{
    n%= m_Length;
    int*tmp= new int[m_Length];
    for(int i=0; i< m_Length; i++)
    {
        tmp[(i + n) % m_Length] = m_Array[i];
    }
    delete[] m_Array;
    m_Array= tmp;
    return*this;
}
CIntArray CIntArray:: Invert()
{
    for (int i = 0; i < m_Length / 2; i++) {
        swap(m_Array[i], m_Array[m_Length - 1 - i]);
    }
    return *this;
}
int CIntArray::Appearance(int val) {
    int cnt = 0;
    for (int i = 0; i < m_Length; i++) if (m_Array[i] == val) cnt++;
    return cnt;
}