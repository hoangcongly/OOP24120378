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
// void DataProcessor:: removeFilter(const string&name)
// {
//     filters.erase(name);
// }
void DataProcessor:: listFilters() const 
{
    cout << "Available filters: " << endl;
    for(const auto&kv: filters)
    {
        cout << " - " << kv.first << endl;
    }
}
void DataProcessor:: addToChain(const string&filterName)
{
    if(filters.find(filterName)!= filters.end())
    {
        chain.push_back(filterName);
    }
}
void DataProcessor:: removeFilter(const string&filterName)
{
    chain.erase(remove(chain.begin(), chain.end(), filterName), chain.end());
}
void DataProcessor:: clearChain()
{
    chain.clear();
}
void DataProcessor:: listChain() const
{
    cout << "Current processing chain: " << endl;
    for(const auto& filterName: chain)
    {
        cout << " - " << filterName << endl;
    }
}
void DataProcessor:: process(vector<int>&data)
{
    saveHistory(data);
    for(const auto&filterName: chain)
    {
        filters[filterName](data);
    }
}
void DataProcessor:: undo(vector<int>&data)
{
    if(!history.empty())
    {
        data=history.back();
        history.pop_back();
    }
}
void DataProcessor:: saveConfig(const string&fileName) const
{
    ofstream file(fileName);
    for(const auto&kv: chain)
    {
        file << kv << endl;
    }
}
void DataProcessor:: loadConfig(const string&fileName)
{
    ifstream file(fileName);
    string line;
    chain.clear();
    while(getline(file, line))
    {
        if(filters.find(line)!= filters.end())
        {
            chain.push_back(line);
        }
    }
}