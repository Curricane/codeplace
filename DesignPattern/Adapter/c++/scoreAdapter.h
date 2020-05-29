// 抽象操作类：目标接口
class ScoreOperation
{
public:
    virtual void sort(int* array, int length) = 0;
    virtual int search(int *array, int length, int key) = 0;
};