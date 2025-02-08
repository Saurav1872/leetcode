class NumberContainers {
public:
    map<int, int> indexToNumberMap;

    map<int, std::set<int>> numberToIndicesMap;

    NumberContainers() {}

    void change(int index, int number) {
        auto it = indexToNumberMap.find(index);
        if (it != indexToNumberMap.end()) {
            numberToIndicesMap[it->second].erase(index);
            it->second = number;
        } else {
            indexToNumberMap[index] = number;
        }
        numberToIndicesMap[number].insert(index);
    }

    int find(int number) {
        auto it = numberToIndicesMap.find(number);
        return (it == numberToIndicesMap.end() || it->second.empty()) ? -1 : *it->second.begin();
    }
};