#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<pair<int, int>, int> data_dict;

    for (int i = 0; i < n; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            int a, b;
            cin >> a >> b;

            bool add_element = true;
            vector<std::pair<int, int> > keys_to_delete;

            for (const auto& item : data_dict) {
                int x = item.first.first;
                int y = item.first.second;

                if (x <= a && y <= b) {
                    keys_to_delete.push_back(item.first);
                } else if (x >= a && y >= b) {
                    add_element = false;
                }
            }

            for (const auto& key : keys_to_delete) {
                data_dict.erase(key);
            }

            if (add_element) {
                data_dict[make_pair(a, b)] = 0;
            }

        } else if (type == 2) {
            cout << data_dict.size() << endl;
        }
    }

    return 0;
}
