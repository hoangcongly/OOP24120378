#include "DataProcessor.h"

int main()
{
    auto dp= DataProcessor::getInstance();
    dp->registerFilter("SortAsc",[](vector<int>&data)
    {
        sort(data.begin(), data.end());
    });
        dp->registerFilter("SortDesc", [](vector<int>& v) {
        sort(v.begin(), v.end(), greater<int>());
    });

    dp->registerFilter("RemoveNegative", [](vector<int>& v) {
        v.erase(remove_if(v.begin(), v.end(), [](int x) { return x < 0; }), v.end());
    });
    dp->registerFilter("RemoveDuplicates", [](vector<int>& v) {
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
    });
    dp->addToChain("RemoveDuplicates");
    dp->addToChain("RemoveNegative");
    dp->addToChain("SortAsc");
    dp->addToChain("SortDesc");
     vector<int> data = {3, -5, 7, 1, -2, 10};

    cout << "Original data: ";
    for (int x : data) cout << x << " ";
    cout << "\n";
    dp->process(data);
     cout << "Processed data: ";
    for (int x : data) cout << x << " ";
    cout << "\n";
     dp->undo(data);
    cout << "After undo: ";
    for (int x : data) cout << x << " ";
    cout << "\n";
    dp->listFilters();
    
    return 0;
}