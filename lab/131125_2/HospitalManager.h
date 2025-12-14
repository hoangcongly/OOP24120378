#pragma once
#include <fstream>
#include "BenhNhan.h"
#include "NoiTru.h"
#include "NgoaiTru.h"

class HospitalManager
{
private:
    std::vector<*BenhNhan> ds;
    BenhNhan *TimBenhNhan(const std::string &msbn)
    {
        for (BenhNhan *bn : ds)
            if (bn->getMSBN() == msbn)
                return bn;
        return nullptr;
    }

public:
    HospitalManager();
    ~HospitalManager()
    {
        for(BenhNhan*p:ds)
            delete p;
    }
    bool DocFileLog(const std::string&filename)
    {
        std::fstream fin(filename);
        if(!fin)
        {
            return false;
        }
        while(true)
        {
            int day;
            fin >> day;
            if(!fin)
                break;
            std::string msbn, loai;
            fin >> msbn >> loai;
            if(loai=="TKVP")
                break;
            BenhNhan *bn = TimBenhNhan(msbn);
            if(!bn)
            {
                if(loai="KB")
                {
                    bn = new NgoaiTru(msbn, "");
                }
                else
                {
                    bn = new NoiTru(msbn, "");
                }
                ds.push_back(bn);
            }
            if(loai=="KB")
            {
                double fee;
                fin >> fee;
                ((NgoaiTru*)bn)->ThemLanKham()
            }
        }
    }
};

