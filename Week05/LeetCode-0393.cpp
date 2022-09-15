class Solution
{
public:
    bool validUtf8(vector<int> &data)
    {
        int n = data.size();
        int i = 0;
        while (i < n)
        {
            int cnt = 0;
            if ((data[i] & 0x80) == 0)
            {
                i++;
                continue;
            }
            if ((data[i] & 0xE0) == 0xC0)
                cnt = 1;
            else if ((data[i] & 0xF0) == 0xE0)
                cnt = 2;
            else if ((data[i] & 0xF8) == 0xF0)
                cnt = 3;
            else
                return false;
            i++;
            while (cnt--)
            {
                if (i >= n || (data[i] & 0xC0) != 0x80)
                    return false;
                i++;
            }
        }
        return true;
    }
};