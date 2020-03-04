#include <bits/stdc++.h>
using namespace std;
long long tb, tl, td;
class lib
{
public:
    long long score, total_books, total_capacity, sign_up_days, lib_id;
    set<pair<long long, long long>, greater<pair<long long, long long>>> books_id;
    float profit;
    void cal_score()
    {
        long long rem_days = td - sign_up_days;
        long long total_scan_books = rem_days * total_capacity;
        auto it = books_id.begin();
        while (total_scan_books && it != books_id.end())
        {
            score += (*it).first;
            total_scan_books--;
            it++;
        }
        profit = score / td;
    }
};
bool compare(const lib &a, const lib &b)
{
    return a.profit > b.profit;
}
int main()
{
    cin >> tb >> tl >> td;
    map<long long, long long> books_score;
    long long score;
    for (long long i = 0; i < tb; i++)
    {
        cin >> score;
        books_score[i] = score;
    }
    lib Library[tl];
    // long long lib_books, lib_days, lib_capacity;
    for (long long i = 0; i < tl; i++)
    {
        cin >> Library[i].total_books >> Library[i].sign_up_days >> Library[i].total_capacity;
        Library[i].lib_id = i;
        long long book_id;
        for (long long j = 0; j < Library[i].total_books; j++)
        {
            cin >> book_id;
            Library[i].books_id.insert(make_pair(books_score[book_id], book_id));
        }
        Library[i].cal_score();
    }
    sort(Library, Library + tl, compare);
    map<long long, bool> selected_books;
    // long long total_selected_lib = 0;
    long long total_days_copy = td;
    long long index = 0;
    vector<vector<long long>> ans;
    vector<long long> Lib_id;
    long long ans_ct = 0;
    while (total_days_copy && index < tl)
    {
        // total_selected_lib++;
        // cout<<Library[index].lib_id<<" ";
        vector<long long> temp_selected_books;
        long long rem_days = td - Library[index].sign_up_days;
        long long total_scan_books = rem_days * Library[index].total_capacity;
        auto it = Library[index].books_id.begin();
        // bool flag = false;
        while (total_scan_books && it != Library[index].books_id.end())
        {
            if (!selected_books[(*it).second])
            {
                temp_selected_books.push_back((*it).second);
                selected_books[(*it).second] = true;
                // flag = true;
            }
            it++;
            total_scan_books--;
        }
        if (temp_selected_books.size())
        {
            ans.push_back(temp_selected_books);
            Lib_id.push_back(index);
            ans_ct++;
        }
        total_days_copy -= Library[index].sign_up_days;
        index++;
    }
    cout << ans_ct << endl;
    for (long long i = 0; i < ans_ct; i++)
    {
        // if(ans[i].size()){
        cout << Library[Lib_id[i]].lib_id << " " << ans[i].size() << "\n";
        for (auto j : ans[i])
        {
            cout << j << " ";
        }
        if (i != (ans_ct - 1))
        {
            cout << "\n";
        }
        // }
    }
    return 0;
}