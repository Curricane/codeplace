#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

namespace SimpleFactory
{

// 比较字符串忽略大小写（只限于比较字母）
bool equalIgnoreCase(string a, string b)
{
    if (a.size() != b.size())
        return false;
    if (a == b)
        return true;
    for (int i = 0; i < a.size(); ++i)
    {
        if (!(a[i] - b[i] == 0 || (a[i] - b[i]) == ('A' - 'a') || (a[i] - b[i]) == ('a' - 'A')))
            return false;
    }

    return true;
};

// 接口
class Chart
{
public:
    virtual void display() = 0;
    // {
    //     cout << "play in Chart way" << endl;
    // };
    virtual ~Chart()
    {
        cout << "bye Chart" << endl;
    };
};

// 柱状图
class HistogramChart: public Chart
{
public:
    HistogramChart()
    {
        cout << "HistogramChart created" << endl;
    };

    void display()
    {
        cout << "play in HistogramChart way" << endl;
    };

    ~HistogramChart()
    {
        cout << "bye HistogramChart" << endl;
    };
};

// 折线图
class LineChart: public Chart
{
public:
    LineChart()
    {
        cout << "LineChart created" << endl;
    };

    void display()
    {
        cout << "play in LineChart way" << endl;
    };

    ~LineChart()
    {
        cout << "bye LineChart" <<endl;
    };
};

// 工厂
class ChartFactory
{
public:
    Chart* getChart(string type)
    {
        // 通过判断来产生不同的产品，
        // 缺点在于每次增加一个类别，需要修改这一部分的代码 违反了开闭原则
        if (equalIgnoreCase(type, string("histogram")))
        {

            Chart *chart = new HistogramChart();
            
            return chart;
        }
        else 
        {
            Chart *chart = new LineChart();
            return chart;
        } 
    }

};

}; // SimpleFactory

int main()
{
    SimpleFactory::Chart *chart = nullptr;
    SimpleFactory::ChartFactory cf;
    chart = cf.getChart(string("Histogram"));
    if (nullptr != chart)
    {
        chart->display();
        delete chart;
    }
    return 0;
}