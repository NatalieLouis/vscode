#include <iostream>
#include"pool2.h"
using namespace std;


int calc(int x, int y)
{
    int res = x + y;
    //cout << "res = " << res << endl;
    this_thread::sleep_for(chrono::seconds(2));
    return res;
}

int main()
{
    ThreadPool pool(4);
    vector<future<int>> results;

    for (int i = 0; i < 10; ++i)
    {
        results.emplace_back(pool.addTask(calc, i, i * 2));
    }

    // 等待并打印结果
    for (auto&& res : results)
    {
        cout << "ans:" << res.get() << endl;
    }

    return 0;
}
