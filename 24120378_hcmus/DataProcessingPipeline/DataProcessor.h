#ifndef _DATAPROCESSOR_H
#define _DATAPROCESSOR_H

#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <map>
#include <mutex>
#include <fstream>
#include <algorithm>

using namespace std;

class DataProcessor
{
private:
    static DataProcessor* _instance;
    static mutex _mtx;

    map<string, function<void(vector<int>&)>> filters;
    vector<string> chain;
    vector<vector<int>> history;

    DataProcessor();
    DataProcessor(const DataProcessor&) = delete;
    DataProcessor& operator=(const DataProcessor&) = delete;

    void saveHistory(const vector<int>& data);

public:
    static DataProcessor* getInstance();

    // Filters
    void registerFilter(const string& name, function<void(vector<int>&)> func);
    void removeFilter(const string& name);
    void listFilters() const;

    // Chain
    void addToChain(const string& filterName);
    void removeFromChain(const string& filterName);
    void clearChain();
    void listChain() const;

    // Processing
    void process(vector<int>& data);
    void undo(vector<int>& data);

    // Config
    void saveConfig(const string& filename) const;
    void loadConfig(const string& filename);
};

#endif
