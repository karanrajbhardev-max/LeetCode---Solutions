class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        stringstream s1(version1), s2(version2);
        string temp;

        while (getline(s1, temp, '.'))
            v1.push_back(stoi(temp));
        while (getline(s2, temp, '.'))
            v2.push_back(stoi(temp));

        int n = max(v1.size(), v2.size());
        while (v1.size() < n)
            v1.push_back(0);
        while (v2.size() < n)
            v2.push_back(0);

        for (int i = 0; i < n; i++) {
            if (v1[i] < v2[i])
                return -1;
            if (v1[i] > v2[i])
                return 1;
        }

        return 0;
    }
};