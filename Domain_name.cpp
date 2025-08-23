#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

bool is_valid_fqdn(const string &domain) {
    int n = domain.size();
    if (n > 253) return false;

    // Split by '.'
    vector<string> labels;
    size_t start = 0, end;
    while ((end = domain.find('.', start)) != string::npos) {
        labels.push_back(domain.substr(start, end - start));
        start = end + 1;
    }
    labels.push_back(domain.substr(start));

    if (labels.size() < 2) return false; // At least one above TLD

    // TLD checks
    string tld = labels.back();
    if (tld.size() < 2 || tld.size() > 63) return false;
    for (char c : tld) {
        if (!islower(c)) return false; // must be lowercase a-z only
    }

    // Labels checks
    for (size_t i = 0; i < labels.size() - 1; ++i) {
        const string &label = labels[i];
        int len = label.size();
        if (len < 1 || len > 63) return false;
        if (label.front() == '-' || label.back() == '-') return false;
        for (char c : label) {
            if (!isalnum(c) && c != '-') return false; // Only [a-zA-Z0-9-]
            if (c == '_') return false;
        }
    }

    return true;
}

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string domain;
        getline(cin, domain);

        // Convert TLD to lowercase
        size_t last_dot = domain.rfind('.');
        if (last_dot != string::npos) {
            for (size_t i = last_dot + 1; i < domain.size(); ++i) {
                domain[i] = tolower(domain[i]);
            }
        }

        cout << (is_valid_fqdn(domain) ? "true" : "false") << endl;
    }
    return 0;
}
