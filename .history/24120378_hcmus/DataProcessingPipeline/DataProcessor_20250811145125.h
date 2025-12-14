#ifndef _DATAPROCESSOR_H
#define _DATAPROCESSOR_H

#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <algorithm>
#include <mutex>
#include <type_traits>
#include <map>
#include <optional>

template<typename T>

class DataProcessor
{
private:
    static DataProcessor* _instance;
    static std::mutex _mtx;

    //Bo loc: Ten-> Ham xu li du lieu
    std::map<std:: string,std::function<void(std::vector<T>&)>> filters;
    //Chuoi filter hien tai
    std:: vector<std::string> chain;
    // Lich su du lieu
    std:: vector<std:: vector<T>> history;

    DataProcessor();
    DataProcessor(const DataProcessor&) = delete;
    DataProcessor& operator=(const DataProcessor&) =delete;

    void saveHistory(const std:: vector<T>&data);
public:
    // singleton access
    static DataProcessor<T>* getInstance();
    // filters Management
    void registerFilter(const std:: string&name, std:: function<void(std::vector<T>&)>func);
    void removeFilter(const std:: string&name);
    void listFilters() const;
    // Chain Management
    void addToChain(const std::string& filterName);
    void removeFromChain(const std::string&filterName);
    void clearChain();
    void listChain() const;
    //Processing
    void process(std::vector<T>&data);
    void undo(std::vector<T>&data);
    //Config
    void saveConfig(const std::string&filename) const;
    void loadConfig(const std::string&filename);

};

    template<typename T>
    DataProcessor<T>*DataProcessor<T>::_instance=nullptr;
    template<typename T>
    std:: mutex DataProcessor<T>::_mtx;
    #include "DataProcessor.tpp"

#endif