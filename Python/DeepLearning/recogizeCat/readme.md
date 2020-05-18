# 介绍
这是吴恩达《Deeplearning.ai》课程，第一次编程作业，识别一只猫，datasets存放的是以h5存放的图片提取后的数据。
isCat.py是用线性回归实现的作业。
isCat_v2.py是用神经网络时间的作业。
## 实验零
只用线性回归，一个激活函数为sigmoid的神经元。
最后 训练集的识别结果为0.9952；测试集的识别结果为0.7

## 实验一
在用神经网络实现这个作业的时候，如果节点都用sigmoid做激活函数，在几万次的训练来看，损失下降的太慢，变化都在0.00001左右，这大概就是sigmoid梯度下降太满导致的吧。
后来改用前几层是relu最后一层是sigmod，在3万次训练的时候，梯度骤然下降，但是测试集的损失一直在增加。
![8:4:1神经网络](https://github.com/Curricane/codeplace/blob/master/Python/DeepLearning/recogizeCat/isCat_v2_epoch_10w.png "损失下降曲线")
最后 训练集的识别结果为0.9569；测试集的识别结果为0.6

## 实验二
改用两层神经网络，第一层为32个激活函数为relu的神经元，输出层为1个激活函数为sigmoid的神经元。
发现梯度下降的很快。
最后 训练集的识别结果为1；测试集的识别结果为0.72
![32relu:1sigmoid](https://github.com/Curricane/codeplace/blob/master/Python/DeepLearning/recogizeCat/isCat_v2_32relu_1sigmoid.png "损失下降曲线")

## 疑问
1，为什么测试集的损失曲线在涨，但测试结果显示提升了？