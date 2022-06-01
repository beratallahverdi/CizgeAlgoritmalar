class Solution
{
public:
    bool isPathCrossing(const string &path)
    {
        std::set<std::pair<int, int>> positions;
        std::pair<int, int> current(0, 0);
        positions.insert(current);

        for (const char &c : path)
        {
            switch (c)
            {
            case 'N':
                current.first++;
                break;
            case 'S':
                current.first--;
                break;
            case 'E':
                current.second++;
                break;
            case 'W':
                current.second--;
                break;
            }
            if (positions.find(current) != positions.end())
                return true;

            positions.insert(current);
        }
        return false;
    }
};