class AllOne
{
public:
    unordered_map<string, int> keys;
    set<pair<int, string> > setMap;

    AllOne()
    {
        keys = unordered_map<string, int>();
        setMap = set<pair<int, string> >();
    }

    void inc(std::string key)
    {
        int temp = keys[key];
        if (temp > 0)
            setMap.erase({temp, key});
        keys[key]++;
        setMap.insert({temp + 1, key});
    }

    void dec(std::string key)
    {
        int temp = keys[key];
        setMap.erase({temp, key});
        keys[key]--;
        if (temp > 1)
            setMap.insert({temp - 1, key});
    }

    std::string getMaxKey()
    {
        if (setMap.size() == 0)
            return "";
        auto it = *setMap.rbegin();

        return it.second;
    }

    std::string getMinKey()
    {
        if (setMap.size() == 0)
            return "";
        auto it = *setMap.begin();
        return it.second;
    }
};