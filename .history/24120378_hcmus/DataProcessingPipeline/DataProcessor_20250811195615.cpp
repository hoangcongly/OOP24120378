#include "DataProcessor.h"

DataProcessor* DataProcessor::_instance=nullptr;
mutex DataProcessor::_mtx;

DataProcessor::DataProcessor(){};
DataProcessor* DataProcessor:: getInstance()
{
    lock_guard<mutex> lock(_mtx);
    if(_instance==nullptr)
    {
        _instance=new DataProcessor();
    }
    return _instance;
}
void DataProcessor::saveHistory(const vector<int>&data)
{
    history.push_back(data);
}
void DataProcessor:: registerFilter(const string&name, function<void(vector<int>&)> func)
{
    filters[name] = func;
}
void DataProcessor:: removeFilter(const string&name)
{
    
}