class Solution
{
public:
    vector<int> par;
    void initPar()
    {
        for (int i = 0; i < par.size(); i++)
            par[i] = i;
        return;
    }

    int findPar(int x)
    {
        if (par[x] == x)
            return x;
        return par[x] = findPar(par[x]);
    }

    int findMST(vector<pair<int, int>> &weights, vector<vector<int>> &edges, int avoid)
    {
        int res = 0;

        for (auto w : weights)
        {
            if (w.second == avoid)
                continue;
            int parX = findPar(edges[w.second][0]);
            int parY = findPar(edges[w.second][1]);

            if (parX == parY)
                continue;
            par[parY] = parX;
            res += w.first;
        }

        return res;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges)
    {
        vector<pair<int, int>> weights;
        int minCost = 0;

        par.resize(n);

        for (int i = 0; i < edges.size(); i++)
            weights.push_back({edges[i][2], i});

        std::sort(weights.begin(), weights.end());

        initPar();
        minCost = findMST(weights, edges, -1);
        vector<vector<int>> res(2);

        for (auto w : weights)
        {
            initPar();
            int temp = findMST(weights, edges, w.second);
            if (findPar(edges[w.second][0]) != findPar(edges[w.second][1]) || temp > minCost)
            {
                res[0].push_back(w.second);
                continue;
            }

            initPar();
            par[edges[w.second][0]] = edges[w.second][1];
            temp = w.first;
            temp += findMST(weights, edges, w.second);
            if (temp == minCost)
                res[1].push_back(w.second);
        }

        return res;
    }
};