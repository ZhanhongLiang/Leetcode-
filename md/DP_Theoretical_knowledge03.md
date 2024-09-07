# 前言:

## 1. 模型搭建-训练-测试过程

### 训练集、验证集和测试集

![](https://pic.imgdb.cn/item/661fca8f0ea9cb1403af5d60.png)

> 1. 工作流程:
>    1. `想法idea(论文中的想法)--->选择初始的参数值----->构建神经网络模型结构----->写代码(实现神经网络)------->实验验证参数对应神经网络的表现性能------->根据验证结果，对参数进行调整优化`
>    2. 重复以上过程，然后选定最佳参数，使得神经网络最优
> 2. 加速训练过程
>    1. 设置Train/Dev/Test 集合 :
>       1. Train(训练集合): 训练算法模型
>       2. Dev(验证集合): 验证不同算法的表现情况
>       3. Test(测试集合): 测试最好算法的实际表现，作为该算法的无偏估计
>    2. `选取 合适 的Train/Dev/Test 集合:`
>       1. 大样本 : Train:Dev:Test = 98% : 1% : 1% 或者 Train:Dev:Test = 99.5% : 0.5% : 0.5%
>    3. 选取样本尽量保证来自同一分布
>       1. Dev 和 Test集合 尽量保证来自同一分布
>    4. 不够样本如何` "增加"` 样本数量-----`即使样本来自不同分布，也能提高模型性能`
>       1. 进行图片的翻转、裁切和增加随机噪声，扩大样本数量

## 2. 偏差/方差

### 2.1 Definition 偏差(bias)和方差(Variance)

 ![](https://pic.imgdb.cn/item/661fcae50ea9cb1403b37abd.png)

> 1. 偏差(bias)代表 `欠拟合`
>    1. 偏差指的是算法的期望预测与真实预测之间的偏差程度， 反应了模型本身的`拟合`能力
> 2. 方差(Variance)代表` 过拟合`
>    1. 方差度量了同等大小的`训练集`的变动导致学习性能的变化， 刻画了数据扰动所导致的影响。
> 3. 模型越`复杂`，`拟合程度越高`，`偏差越小`，但`方差越大，进而该模型过拟合`
> 4. 模型越`简单`，`拟合程度越低`，`偏差越大`，但`方差越小，进而该模型欠拟合`

![这里写图片描述](https://img-blog.csdn.net/20180905202253853?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NpbmF0XzMwMzUzMjU5/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)

### 2.2 偏差和方差 分析

- `train error 、Dev error 、bias 、variance、过拟合、欠拟合`概念

> 1. `train error: 训练集合 模型预测的值和真实值之间的误差（一次测量准确性）`
> 2. `Dev error: 验证集合中, 模型预测的值和真实值之间的误差（多次测量准确性）`
> 3. bias: 偏差，高偏差体现欠拟合
> 4. variance: 方差，高方差体现过拟合
>
> ![](https://pic.imgdb.cn/item/661fabc70ea9cb1403777842.png)
>
> 5. 某个点上的平方误差期望值:
>
> $$
> \operatorname{Err}(x)=E\left[(Y-\hat{f}(x))^{2}\right]
> $$
>
> 6. 误差分解:
>    $$
>    \begin{array}{c}
>    \operatorname{Err}(x)=(E[\hat{f}(x)]-f(x))^{2}+E\left[(\hat{f}(x)-E[\hat{f}(x)])^{2}\right]+\sigma_{e}^{2} \\
>    \operatorname{Err}(x)=\operatorname{Bias}^{2}+\text { Variance + Irreducible Error }
>    \end{array}
>    $$
>    ![](https://pic.imgdb.cn/item/661fad320ea9cb1403843b0c.png)

- error体现bias和varriance

> 1. `Train集合error偏小(1%)，Dev集合error偏大(15%)`---->模型对`训练样本`有`过拟合`，泛化能力不强------->`高方差`
> 2. `Train集error偏大(15%)，Dev集合error偏大(16%),两者相近`------>模型对训练样本和验证样本识别都不好，存在`欠拟合`------->`高偏差`
> 3. `Train集合error偏大(15%),Dev集合error偏大(30%)`----->模型存在`高偏差和高方差`----->最坏结果
> 4. `Train集合error偏小(0.5%),Dev集合error偏小(0.5%)`----->模型`低偏差和低方差`------>最好结果

![](https://pic.imgdb.cn/item/661fa74e0ea9cb140350b30d.png)

> 该图代表`部分区域存在过拟合`情况，但`部分区域存在欠拟合`情况

- 如何 评价该模型好坏

> 1. 传统算法中，`bias和variance是对立的，减少bias会增加variance，增加bias会增加bias`
> 2. 现代深度学习中，`bias和variance是 鱼和熊掌可兼得`
> 3. 我们`优化模型目标:  低偏差和低方差`

# 1. 深度神经网络的初始化

## 1.1 梯度消失和梯度爆炸现象<背景>

参考这位知乎大佬的手推

[https://zhuanlan.zhihu.com/p/76772734](https://zhuanlan.zhihu.com/p/76772734)

> 总结:
>
> ![](https://pic.imgdb.cn/item/661fc1700ea9cb14034a9636.png)
> $$
> 可以推导出
> 
> \begin{array}{l}
> \frac{\partial C}{\partial b_{1}}=\frac{\partial C}{\partial y_{4}} \frac{\partial y_{4}}{\partial z_{4}} \frac{\partial z_{4}}{\partial x_{4}} \frac{\partial x_{4}}{\partial z_{3}} \frac{\partial z_{3}}{\partial x_{3}} \frac{\partial x_{3}}{\partial z_{2}} \frac{\partial z_{2}}{\partial x_{2}} \frac{\partial x_{2}}{\partial z_{1}} \frac{\partial z_{1}}{\partial b_{1}} \\
> =\frac{\partial C}{\partial y_{4}} \sigma^{\prime}\left(z_{4}\right) w_{4} \sigma^{\prime}\left(z_{3}\right) w_{3} \sigma^{\prime}\left(z_{2}\right) w_{2} \sigma^{\prime}\left(z_{1}\right)
> \end{array}
> $$
> 
>
> - sigmoid手动推导
>
> $$
> S(x)=\operatorname{Sigmoid}(x)=\frac{1}{1+e^{-x}}
> $$
>
> $$
> 求导过程:
> 
> \begin{array}{l}
> S^{\prime}(x)=-\frac{1}{\left(1+e^{-x}\right)^{2}} \times\left(1+e^{-x}\right)^{\prime}=-\frac{1}{\left(1+e^{-x}\right)^{2}} \times\left(-e^{-x}\right)=\frac{1}{1+e^{-x}} \times \frac{e^{-x}}{1+e^{-x}}=\frac{1}{1+e^{-x}} \\
> \times \frac{1+e^{-x}-1}{1+e^{-x}}=S(x)(1-S(x))
> \end{array}
> $$
>
> - 由函数和图像得到
>
> $$
> sigmoid <= 0.25\begin{cases}
>  当w矩阵参数都 {\color{Red} 小于}  1的时候,\left|\sigma^{\prime}(z) w\right| \leq \frac{1}{4}\Rightarrow\frac{\partial C}{\partial y_{4}} \sigma^{\prime}\left(z_{4}\right) w_{4} \sigma^{\prime}\left(z_{3}\right) w_{3} \sigma^{\prime}\left(z_{2}\right) w_{2} \sigma^{\prime}\left(z_{1}\right){\color{Red} \downarrow}   \\
> 当w矩阵参数都{\color{Red} 大于} 1的时候,\left|\sigma^{\prime}(z) w\right| >  1\Rightarrow\frac{\partial C}{\partial y_{4}} \sigma^{\prime}\left(z_{4}\right) w_{4} \sigma^{\prime}\left(z_{3}\right) w_{3} \sigma^{\prime}\left(z_{2}\right) w_{2} \sigma^{\prime}\left(z_{1}\right){\color{Red} \uparrow } 
> 
> \end{cases}
> $$
>
> $$
> w^{[l]} = w^{[l]} - \alpha dw^{[l]}\Rightarrow \begin{cases}
> dw^{[l]}\downarrow ,w^{[l]}更新过慢 \\
> dw^{[l]}\uparrow ,w^{[l]} 更新过快
> 
> \end{cases}
> $$
>
> 
>
> 1. 显而易见，`梯度爆炸跟层数成正比，由于层数的增加，容易导致梯度消失或梯度下降`
> 2. `且初始矩阵w过大时候，容易导致梯度爆炸现象`

## 1.2 W和b参数初始化

- 初始化方式

> 1. 使用0矩阵进行初始化
> 2. 使用随机数进行初始化
> 3. `使用抑制梯度异常初始化参数(He论文方法)`------经常用到

- 初始化目的

> 1. 加快模型下降、模型收敛
> 2. 减少梯度下降收敛过程出现误差的几率

## 1.3 零矩阵初始化代码及原理

> 原理:
>
> 1. 输入参数全部初始化为零矩阵, 核心代码为
>
>    parameters['W' + str(l)] = np.zeros((layers_dims[l], layers_dims[l-1])) # W矩阵初始化为零矩阵
>     parameters['b' + str(l)] = np.zeros((layers_dims[l], 1)) #b矩阵初始化为零向量

- 初始化代码

```python
'''
Author: Jean_Leung
Date: 2024-04-15 23:03:15
LastEditors: Jean_Leung
LastEditTime: 2024-04-16 10:08:41
FilePath: \Chap2\chap5exercise.py
Description: 深度神经网络的初始化测试
             一: 我们来说一下步骤：
                1.初始化网络参数
                    1.1 w和b是零矩阵
                    1.2 随机初始化w和b矩阵
                    1.3 He的论文中方法

Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved. 
'''

import numpy as np
import matplotlib.pyplot as plt
import sklearn
import sklearn.datasets
import init_utils
from init_utils import load_dataset

# # 如果使用的是Jupyter Notebook，加上 %matplotlib inline
# plt.rcParams['figure.figsize'] =(7.0,4.0)
# plt.rcParams['image.interpolation'] = 'nearest'
# plt.rcParams['image.cmap'] = 'gray'
# # 加载图像数据集:蓝色/红色的圆点
train_X, train_Y, test_X, test_Y = load_dataset(is_plot=False)
# plt.show()

#三种初始化方法

# 初始化为零
'''
description: 第一种w和b矩阵初始化方法，需要初始化为零
param {*} layers_dims
return {*}
'''
def initialize_parameters_zeros(layers_dims):
    """
    参数：
        layers_dims - 包含我们网络中每个图层的节点数量的列表
    返回：
        parameters - 包含参数“W1”，“b1”，...，“WL”，“bL”的字典：
    """
    # np.random.seed(1)
    parameters = {}
    L = len(layers_dims)# 层数
    for l in range(1, L):
        parameters['W' + str(l)] = np.zeros((layers_dims[l], layers_dims[l-1]))
        parameters['b' + str(l)] = np.zeros((layers_dims[l], 1))
        assert(parameters['W' + str(l)].shape == (layers_dims[l],layers_dims[l-1]))
        assert(parameters['b' + str(l)].shape == (layers_dims[l],1))
    return parameters

# # 测试
# print("=====初始化为零测试=====")
# parameters = initialize_parameters_zeros([3,2,1])
# print("W1 = " + str(parameters["W1"]))
# print("b1 = " + str(parameters["b1"]))
# print("W2 = " + str(parameters["W2"]))
# print("b2 = " + str(parameters["b2"]))
```

## 1.4 随机矩阵初始化代码

> 原理:
>
> 1. 输入参数W矩阵初始化为权重值较大的随机矩阵,以达到模拟`梯度爆炸`的效果
>
>    parameters['W' + str(l)] = np.random.randn(layers_dims[l], layers_dims[l - 1]) * 10

- 随机矩阵初始化代码

```python
'''
Author: Jean_Leung
Date: 2024-04-15 23:03:15
LastEditors: Jean_Leung
LastEditTime: 2024-04-16 10:08:41
FilePath: \Chap2\chap5exercise.py
Description: 深度神经网络的初始化测试
             一: 我们来说一下步骤：
                1.初始化网络参数
                    1.1 w和b是零矩阵
                    1.2 随机初始化w和b矩阵
                    1.3 He的论文中方法

Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved. 
'''

import numpy as np
import matplotlib.pyplot as plt
import sklearn
import sklearn.datasets
import init_utils
from init_utils import load_dataset

# # 如果使用的是Jupyter Notebook，加上 %matplotlib inline
# plt.rcParams['figure.figsize'] =(7.0,4.0)
# plt.rcParams['image.interpolation'] = 'nearest'
# plt.rcParams['image.cmap'] = 'gray'
# # 加载图像数据集:蓝色/红色的圆点
train_X, train_Y, test_X, test_Y = load_dataset(is_plot=False)
# plt.show()
'''
description: 随机数初始化
param {*} layers_dims
return {*}
'''
def initialize_parameters_random(layers_dims):
    """
    参数：
        layers_dims - 包含我们网络中每个图层的节点数量的列表
    返回：
        parameters - 包含参数“W1”，“b1”，...，“WL”，“bL”的字典：
    """
    np.random.seed(3)
    parameters = {}
    L = len(layers_dims)# 层数
    for l in range(1, L):
        parameters['W' + str(l)] = np.random.randn(layers_dims[l], layers_dims[l-1]) * 10
        parameters['b' + str(l)] = np.zeros((layers_dims[l], 1))
        assert(parameters['W' + str(l)].shape == (layers_dims[l],layers_dims[l-1]))
        assert(parameters['b' + str(l)].shape == (layers_dims[l],1))
    return parameters

# # 测试
# print("=====随机初始化测试=====")
# parameters = initialize_parameters_random([3,2,1])
# print("W1 = " + str(parameters["W1"]))
# print("b1 = " + str(parameters["b1"]))
# print("W2 = " + str(parameters["W2"]))
# print("b2 = " + str(parameters["b2"]))
```

## 1.5  "He"论文中的初始化代码及其原理

参考这篇文章的推导过程

https://blog.csdn.net/xbinworld/article/details/107890916

> 原理:
>
> 1. 论文将权重初始化为按比例缩放的随机值，核心代码为
>
>    parameters['W' + str(l)] = np.random.randn(layers_dims[l], layers_dims[l - 1]) * np.sqrt(2 / layers_dims[l - 1])
>
> 2. 总结:
>    $$
>    He论文\Rightarrow \begin{cases}
>     当激活函数={\color{Red} ReLu函数} ,使用{\color{Red} \sqrt{\frac{2}{n^{[l-1]}} }} 来初始化,n^{[l-1]}代表l-1层的神经元数量  \\
>     当激活函数={\color{Red} tanh函数} ,使用{\color{Red} \sqrt{\frac{1}{n^{[l-1]}} }} 来初始化,n^{[l-1]}代表l-1层的神经元数量 
>    
>    \end{cases}
>    $$
>
>    $$
>    Yoshua Bengio论文\Rightarrow \begin{cases}
>     使用{\color{Red} \sqrt{\frac{1}{n^{[l-1]}+n^{[l]}} }}  来进行初始化
>    
>    \end{cases}
>    $$

```python

'''
Author: Jean_Leung
Date: 2024-04-15 23:03:15
LastEditors: Jean_Leung
LastEditTime: 2024-04-16 10:08:41
FilePath: \Chap2\chap5exercise.py
Description: 深度神经网络的初始化测试
             一: 我们来说一下步骤：
                1.初始化网络参数
                    1.1 w和b是零矩阵
                    1.2 随机初始化w和b矩阵
                    1.3 He的论文中方法

Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved. 
'''

import numpy as np
import matplotlib.pyplot as plt
import sklearn
import sklearn.datasets
import init_utils
from init_utils import load_dataset

# # 如果使用的是Jupyter Notebook，加上 %matplotlib inline
# plt.rcParams['figure.figsize'] =(7.0,4.0)
# plt.rcParams['image.interpolation'] = 'nearest'
# plt.rcParams['image.cmap'] = 'gray'
# # 加载图像数据集:蓝色/红色的圆点
train_X, train_Y, test_X, test_Y = load_dataset(is_plot=False)
# plt.show()
# 论文中的"He"初始化
'''
description: He初始化
param {*} layers_dims
return {*}
'''
def initialize_parameters_he(layers_dims):
    """
    参数：
        layers_dims - 包含我们网络中每个图层的节点数量的列表
    返回：
        parameters - 包含参数“W1”，“b1”，...，“WL”，“bL”的字典：
    """
    np.random.seed(3)
    parameters = {}
    L = len(layers_dims)# 层数
    for l in range(1, L):
        parameters['W' + str(l)] = np.random.randn(layers_dims[l], layers_dims[l-1]) * np.sqrt(2/(layers_dims[l-1]))
        parameters['b' + str(l)] = np.zeros((layers_dims[l], 1))
        assert(parameters['W' + str(l)].shape == (layers_dims[l],layers_dims[l-1]))
        assert(parameters['b' + str(l)].shape == (layers_dims[l],1))
    return parameters

# # 测试
# print("=====He始化测试=====")
# parameters = initialize_parameters_he([3,2,1])
# print("W1 = " + str(parameters["W1"]))
# print("b1 = " + str(parameters["b1"]))
# print("W2 = " + str(parameters["W2"]))
# print("b2 = " + str(parameters["b2"]))
```

## 1.6 总代码

- 主代码

```python
'''
Author: Jean_Leung
Date: 2024-04-15 23:03:15
LastEditors: Jean_Leung
LastEditTime: 2024-04-18 00:25:27
FilePath: \Chap2\chap5exercise.py
Description: 深度神经网络的初始化测试
             一: 我们来说一下步骤：
                1.初始化网络参数
                    1.1 w和b是零矩阵
                    1.2 随机初始化w和b矩阵
                    1.3 He的论文中方法

Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved. 
'''

import numpy as np
import matplotlib.pyplot as plt
import sklearn
import sklearn.datasets
import init_utils
from init_utils import load_dataset

plt.rcParams['figure.figsize'] = (10.0, 10.0) # set default size of plots
plt.rcParams['image.interpolation'] = 'nearest'
plt.rcParams['image.cmap'] = 'gray'

# # 如果使用的是Jupyter Notebook，加上 %matplotlib inline
# plt.rcParams['figure.figsize'] =(7.0,4.0)
# plt.rcParams['image.interpolation'] = 'nearest'
# plt.rcParams['image.cmap'] = 'gray'
# # 加载图像数据集:蓝色/红色的圆点
train_X, train_Y, test_X, test_Y = load_dataset(is_plot=False)
# plt.show()

#三种初始化方法

# 初始化为零
'''
description: 第一种w和b矩阵初始化方法，需要初始化为零
param {*} layers_dims
return {*}
'''
def initialize_parameters_zeros(layers_dims):
    """
    参数：
        layers_dims - 包含我们网络中每个图层的节点数量的列表
    返回：
        parameters - 包含参数“W1”，“b1”，...，“WL”，“bL”的字典：
    """
    # np.random.seed(1)
    parameters = {}
    L = len(layers_dims)# 层数
    for l in range(1, L):
        parameters['W' + str(l)] = np.zeros((layers_dims[l], layers_dims[l-1]))
        parameters['b' + str(l)] = np.zeros((layers_dims[l], 1))
        assert(parameters['W' + str(l)].shape == (layers_dims[l],layers_dims[l-1]))
        assert(parameters['b' + str(l)].shape == (layers_dims[l],1))
    return parameters

# # 测试
# print("=====初始化为零测试=====")
# parameters = initialize_parameters_zeros([3,2,1])
# print("W1 = " + str(parameters["W1"]))
# print("b1 = " + str(parameters["b1"]))
# print("W2 = " + str(parameters["W2"]))
# print("b2 = " + str(parameters["b2"]))



'''
description: 随机数初始化
param {*} layers_dims
return {*}
'''
def initialize_parameters_random(layers_dims):
    """
    参数：
        layers_dims - 包含我们网络中每个图层的节点数量的列表
    返回：
        parameters - 包含参数“W1”，“b1”，...，“WL”，“bL”的字典：
    """
    np.random.seed(3)
    parameters = {}
    L = len(layers_dims)# 层数
    for l in range(1, L):
        parameters['W' + str(l)] = np.random.randn(layers_dims[l], layers_dims[l-1]) * 10
        parameters['b' + str(l)] = np.zeros((layers_dims[l], 1))
        assert(parameters['W' + str(l)].shape == (layers_dims[l],layers_dims[l-1]))
        assert(parameters['b' + str(l)].shape == (layers_dims[l],1))
    return parameters

# # 测试
# print("=====随机初始化测试=====")
# parameters = initialize_parameters_random([3,2,1])
# print("W1 = " + str(parameters["W1"]))
# print("b1 = " + str(parameters["b1"]))
# print("W2 = " + str(parameters["W2"]))
# print("b2 = " + str(parameters["b2"]))

# 论文中的"He"初始化
'''
description: He初始化
param {*} layers_dims
return {*}
'''
def initialize_parameters_he(layers_dims):
    """
    参数：
        layers_dims - 包含我们网络中每个图层的节点数量的列表
    返回：
        parameters - 包含参数“W1”，“b1”，...，“WL”，“bL”的字典：
    """
    np.random.seed(3)
    parameters = {}
    L = len(layers_dims)# 层数
    for l in range(1, L):
        parameters['W' + str(l)] = np.random.randn(layers_dims[l], layers_dims[l-1]) * np.sqrt(2/(layers_dims[l-1]))
        parameters['b' + str(l)] = np.zeros((layers_dims[l], 1))
        assert(parameters['W' + str(l)].shape == (layers_dims[l],layers_dims[l-1]))
        assert(parameters['b' + str(l)].shape == (layers_dims[l],1))
    return parameters

# # 测试
# print("=====He始化测试=====")
# parameters = initialize_parameters_he([3,2,1])
# print("W1 = " + str(parameters["W1"]))
# print("b1 = " + str(parameters["b1"]))
# print("W2 = " + str(parameters["W2"]))
# print("b2 = " + str(parameters["b2"]))


'''
description: 总测试代码,包括模型的正向、反向和更新，最后输出代码
param {*} X
param {*} Y
param {*} learning_rate
param {*} num_iterations
param {*} print_cost
param {*} initialization
param {*} is_polt
return {*}
'''
def model(X,Y,learning_rate = 0.01, num_iterations = 15000,print_cost = True,initialization="he",is_polt=True,k=1):
    """
    参数：
        X - 数据集,维度为（2，示例数）
        Y - 标签，维度为（1，示例数）
        num_iterations - 表示用于优化参数的迭代次数的超参数
        print_cost - 如果为True，则每1000次迭代打印一次成本数值
        initialization - 表示初始化方法的超参数
        is_plot - 设置为true以每100次迭代打印成本
    返回：
        d  - 包含有关模型信息的字典。
    """
    graads = {}
    costs = []
    m = X.shape[1] # 样本数
    layers_dims = [X.shape[0],10,5,1] # 深度神经网络层数数组
    # n = X.shape[0] # 特征数
    # 初始化参数
    if initialization == 'zeros':
        parameters = initialize_parameters_zeros(layers_dims)
    elif initialization == 'random':
        parameters = initialize_parameters_random(layers_dims)
    elif initialization == 'he':
        parameters = initialize_parameters_he(layers_dims)
    else :
        print("格式不正确")
        exit
    # 开始迭代
    for i in range(0,num_iterations):
        #前向传播
        a3 , cache = init_utils.forward_propagation(X,parameters)
        
        #计算成本        
        cost = init_utils.compute_loss(a3,Y)
        
        #反向传播
        grads = init_utils.backward_propagation(X,Y,cache)
        
        #更新参数
        parameters = init_utils.update_parameters(parameters,grads,learning_rate)
        
        #记录成本
        if i % 1000 == 0:
            costs.append(cost)
            #打印成本
            if print_cost:
                print("第" + str(i) + "次迭代，成本值为：" + str(cost))
        
    
    #学习完毕，绘制成本曲线
    if is_polt:
        plt.subplot(2,2,k)
        plt.plot(costs)
        plt.ylabel('cost')
        plt.xlabel('iterations (per hundreds)')
        plt.title("Learning rate  = " + str(learning_rate) +"with" + initialization)
        # plt.show()
    
    #返回学习完毕后的参数
    return parameters


# 测试，测试模型
initialization_list = ["random","zeros","he"]
for k in range(0,len(initialization_list)):
    parameters = model(train_X,train_Y,learning_rate = 0.01, num_iterations = 15000,print_cost = True,initialization=initialization_list[k],is_polt=True,k=k+1)
    print("训练集合")
    predictions_train = init_utils.predict(train_X,train_Y,parameters)
    print("测试集合")
    predictions_test = init_utils.predict(test_X,test_Y,parameters)
    # 绘制决策边界
    print("predicitions_train = " + str(predictions_train))
    print("predictions_test = " + str(predictions_test))
    # plt.subplot(3,2,i+1)
    # plt.title("Model with " + initialization_list[i])
    # axes = plt.gca()
    # axes.set_xlim([-1.5,1.5])
    # axes.set_ylim([-1.5,1.5])
    # # lambda表达式
    # init_utils.plot_decision_boundary(lambda x: init_utils.predict_dec(parameters,x.T),train_X,train_Y)
plt.show()
```

- init_utils.py 代码

```python
'''
Author: Jean_Leung
Date: 2024-04-15 23:05:58
LastEditors: Jean_Leung
LastEditTime: 2024-04-16 10:21:50
FilePath: \Chap2\init_utils.py
Description: 参数矩阵初始化工具包

Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved. 
'''
# -*- coding: utf-8 -*-

#init_utils.py

import numpy as np
import matplotlib.pyplot as plt
import sklearn
import sklearn.datasets


def sigmoid(x):
    """
    Compute the sigmoid of x
 
    Arguments:
    x -- A scalar or numpy array of any size.
 
    Return:
    s -- sigmoid(x)
    """
    s = 1/(1+np.exp(-x))
    return s
 
def relu(x):
    """
    Compute the relu of x
 
    Arguments:
    x -- A scalar or numpy array of any size.
 
    Return:
    s -- relu(x)
    """
    s = np.maximum(0,x)
    
    return s
    
def compute_loss(a3, Y):
    
    """
    Implement the loss function
    
    Arguments:
    a3 -- post-activation, output of forward propagation
    Y -- "true" labels vector, same shape as a3
    
    Returns:
    loss - value of the loss function
    """
    
    m = Y.shape[1]
    logprobs = np.multiply(-np.log(a3),Y) + np.multiply(-np.log(1 - a3), 1 - Y)
    loss = 1./m * np.nansum(logprobs)
    
    return loss
    
def forward_propagation(X, parameters):
    """
    Implements the forward propagation (and computes the loss) presented in Figure 2.
    
    Arguments:
    X -- input dataset, of shape (input size, number of examples)
    Y -- true "label" vector (containing 0 if cat, 1 if non-cat)
    parameters -- python dictionary containing your parameters "W1", "b1", "W2", "b2", "W3", "b3":
                    W1 -- weight matrix of shape ()
                    b1 -- bias vector of shape ()
                    W2 -- weight matrix of shape ()
                    b2 -- bias vector of shape ()
                    W3 -- weight matrix of shape ()
                    b3 -- bias vector of shape ()
    
    Returns:
    loss -- the loss function (vanilla logistic loss)
    """
        
    # retrieve parameters
    W1 = parameters["W1"]
    b1 = parameters["b1"]
    W2 = parameters["W2"]
    b2 = parameters["b2"]
    W3 = parameters["W3"]
    b3 = parameters["b3"]
    
    # LINEAR -> RELU -> LINEAR -> RELU -> LINEAR -> SIGMOID
    z1 = np.dot(W1, X) + b1
    a1 = relu(z1)
    z2 = np.dot(W2, a1) + b2
    a2 = relu(z2)
    z3 = np.dot(W3, a2) + b3
    a3 = sigmoid(z3)
    
    cache = (z1, a1, W1, b1, z2, a2, W2, b2, z3, a3, W3, b3)
    
    return a3, cache
 
def backward_propagation(X, Y, cache):
    """
    Implement the backward propagation presented in figure 2.
    
    Arguments:
    X -- input dataset, of shape (input size, number of examples)
    Y -- true "label" vector (containing 0 if cat, 1 if non-cat)
    cache -- cache output from forward_propagation()
    
    Returns:
    gradients -- A dictionary with the gradients with respect to each parameter, activation and pre-activation variables
    """
    m = X.shape[1]
    (z1, a1, W1, b1, z2, a2, W2, b2, z3, a3, W3, b3) = cache
    
    dz3 = 1./m * (a3 - Y)
    dW3 = np.dot(dz3, a2.T)
    db3 = np.sum(dz3, axis=1, keepdims = True)
    
    da2 = np.dot(W3.T, dz3)
    dz2 = np.multiply(da2, np.int64(a2 > 0))
    dW2 = np.dot(dz2, a1.T)
    db2 = np.sum(dz2, axis=1, keepdims = True)
    
    da1 = np.dot(W2.T, dz2)
    dz1 = np.multiply(da1, np.int64(a1 > 0))
    dW1 = np.dot(dz1, X.T)
    db1 = np.sum(dz1, axis=1, keepdims = True)
    
    gradients = {"dz3": dz3, "dW3": dW3, "db3": db3,
                 "da2": da2, "dz2": dz2, "dW2": dW2, "db2": db2,
                 "da1": da1, "dz1": dz1, "dW1": dW1, "db1": db1}
    
    return gradients
 
def update_parameters(parameters, grads, learning_rate):
    """
    Update parameters using gradient descent
    
    Arguments:
    parameters -- python dictionary containing your parameters 
    grads -- python dictionary containing your gradients, output of n_model_backward
    
    Returns:
    parameters -- python dictionary containing your updated parameters 
                  parameters['W' + str(i)] = ... 
                  parameters['b' + str(i)] = ...
    """
    
    L = len(parameters) // 2 # number of layers in the neural networks
 
    # Update rule for each parameter
    for k in range(L):
        parameters["W" + str(k+1)] = parameters["W" + str(k+1)] - learning_rate * grads["dW" + str(k+1)]
        parameters["b" + str(k+1)] = parameters["b" + str(k+1)] - learning_rate * grads["db" + str(k+1)]
        
    return parameters
    
def predict(X, y, parameters):
    """
    This function is used to predict the results of a  n-layer neural network.
    
    Arguments:
    X -- data set of examples you would like to label
    parameters -- parameters of the trained model
    
    Returns:
    p -- predictions for the given dataset X
    """
    
    m = X.shape[1]
    p = np.zeros((1,m), dtype = np.int)
    
    # Forward propagation
    a3, caches = forward_propagation(X, parameters)
    
    # convert probas to 0/1 predictions
    for i in range(0, a3.shape[1]):
        if a3[0,i] > 0.5:
            p[0,i] = 1
        else:
            p[0,i] = 0
 
    # print results
    print("Accuracy: "  + str(np.mean((p[0,:] == y[0,:]))))
    
    return p
    
def load_dataset(is_plot=True):
    np.random.seed(1)
    train_X, train_Y = sklearn.datasets.make_circles(n_samples=300, noise=.05)
    np.random.seed(2)
    test_X, test_Y = sklearn.datasets.make_circles(n_samples=100, noise=.05)
    # Visualize the data
    if is_plot:
        plt.scatter(train_X[:, 0], train_X[:, 1], c=train_Y, s=40, cmap=plt.cm.Spectral);
    train_X = train_X.T
    train_Y = train_Y.reshape((1, train_Y.shape[0]))
    test_X = test_X.T
    test_Y = test_Y.reshape((1, test_Y.shape[0]))
    return train_X, train_Y, test_X, test_Y
 
def plot_decision_boundary(model, X, y):
    # Set min and max values and give it some padding
    x_min, x_max = X[0, :].min() - 1, X[0, :].max() + 1
    y_min, y_max = X[1, :].min() - 1, X[1, :].max() + 1
    h = 0.01
    # Generate a grid of points with distance h between them
    xx, yy = np.meshgrid(np.arange(x_min, x_max, h), np.arange(y_min, y_max, h))
    # Predict the function value for the whole grid
    Z = model(np.c_[xx.ravel(), yy.ravel()])
    Z = Z.reshape(xx.shape)
    # Plot the contour and training examples
    plt.contourf(xx, yy, Z, cmap=plt.cm.Spectral)
    plt.ylabel('x2')
    plt.xlabel('x1')
    plt.scatter(X[0, :], X[1, :], c=y, cmap=plt.cm.Spectral)
    plt.show()
 
def predict_dec(parameters, X):
    """
    Used for plotting decision boundary.
    
    Arguments:
    parameters -- python dictionary containing your parameters 
    X -- input data of size (m, K)
    
    Returns
    predictions -- vector of predictions of our model (red: 0 / blue: 1)
    """
    
    # Predict using forward propagation and a classification threshold of 0.5
    a3, cache = forward_propagation(X, parameters)
    predictions = (a3>0.5)
    return predictions
```

## 1.7  运行结果

![](https://pic.imgdb.cn/item/662076c30ea9cb1403469540.png)

![](https://pic.imgdb.cn/item/662076d30ea9cb140346ebad.png)

# 2. 深度神经网络的正则化和Dropout处理

## 2.1 背景

> 前文说过，如果一个模型出现 `过拟合`现象，high variance现象,应该怎么解决,这时我们该如何解决?
>
> 解决方法:
>
> 1. 扩大训练样本-------难以实现
> 2. L2正则化处理和L1正则化
> 3. Dropout处理

## 2.2 L2正则化

- 公式推导

> 表达公式
> $$
> \begin{array}{c}
> J\left(w^{[1]}, b^{[1]}, \cdots, w^{[L]}, b^{[L]}\right)=\frac{1}{m} \sum_{i=1}^{m} L\left(\hat{y}^{(i)}, y^{(i)}\right)+\frac{\lambda}{2 m} \sum_{l=1}^{L}\left\|w^{[l]}\right\|^{2} \\
> \left\|w^{[l]}\right\|^{2}=\sum_{i=1}^{n^{[l]}} \sum_{j=1}^{n^{[l-1]}}\left(w_{i j}^{[l]}\right)^{2} \\ 
> \left\|w^{[l]}\right\|^{2}称为Frobenius范数
> \end{array}
> $$
> 矩阵的范数计算
> $$
> \|A\|_{F}=\sqrt{\sum_{i=1}^{m} \sum_{j=1}^{n}\left|a_{i j}\right|^{2}}
> $$
> 所以由于我们Lost函数加了正则化项，所以反向传播和更新w参数步骤需要做出改变
>
> 1. `反向传播公式出现变化`
>
> $$
> \begin{align}
> &由J\left(w^{[1]}, b^{[1]}, \cdots, w^{[L]}, b^{[L]}\right)_{after}=\frac{1}{m} \sum_{i=1}^{m} L\left(\hat{y}^{(i)}, y^{(i)}\right)+\frac{\lambda}{2 m} \sum_{l=1}^{L}\left\|w^{[l]}\right\|^{2} =\frac{1}{m} \sum_{i=1}^{m} L\left(\hat{y}^{(i)}, y^{(i)}\right)+ \left(w_{1 1}^{[l]}\right)^{2}+\cdots+\left(w_{i j}^{[l]}\right)^{2} 得\\
>  & 且\frac{\partial J_{before}}{\partial w^{[l]}} = dw^{[l]}_{before},令Q = \left(w_{i j}^{[l]}\right)^{2}得\\
>  & 得\frac{dQ}{dw} = 2 \left(w_{i j}^{[l]}\right)\\
> &最终得 \frac{\partial J_{after}}{\partial w^{[l]}} = dw^{[l]}_{before}+\frac{\lambda}{2m} \cdot2\left(w_{i j}^{[l]}\right)=dw^{[l]}_{before}+{\color{Red} \frac{\lambda \cdot  \left(w^{[l]}\right)}{m}} 
> \end{align}
> $$
>
> 2. `更新参数公式发生变化`
>
> $$
> \begin{aligned}
> w^{[l]} & :=w^{[l]}-\alpha \cdot d w^{[l]} \\
> & =w^{[l]}-\alpha \cdot\left(d w_{\text {before }}^{[l]}+\frac{\lambda}{m} w^{[l]}\right) \\
> & =\left(1-\alpha \frac{\lambda}{m}\right) w^{[l]}-\alpha \cdot d w_{\text {before }}^{[l]} \\
> &其中，  \left(1-\alpha \frac{\lambda}{m}\right)<1  。
> \end{aligned}
> $$
>
> 3. 总结:
>    1. 看到w更新参数公式需要多减去正则项，所以w衰减的更快,那么也就是迭代过程中，w不断进行衰减

- 原理说明

> ![](https://pic.imgdb.cn/item/66208b560ea9cb1403c1b93e.png)
>
> 1. 由前向传播公式得
>
> $$
> \begin{aligned}
> Z^{[1]} & =W^{[1]} X+b^{[1]} \\
> A^{[1]} & =g^{[1]}\left(Z^{[1]}\right) \\
> Z^{[2]} & =W^{[2]} A^{[1]}+b^{[2]} \\
> A^{[2]} & =g^{[2]}\left(Z^{[2]}\right) \\
> \vdots & \\
> A^{[L]} & =g^{[L]}\left(Z^{[L]}\right)=\hat{Y}
> \end{aligned}
> $$
>
> 由前面看到
> $$
> \begin{align}
> &由w^{[l]} = \left(1-\alpha \frac{\lambda}{m}\right) w^{[l]}-\alpha \cdot d w_{\text {before }}^{[l]}\downarrow \\
> &则Z^{[2]}  =W^{[2]} A^{[1]}+b^{[2]}\downarrow  \\
> &也就是说{\color{Red} Z不断衰减} \Rightarrow {\color{Red} 网络中某些神经元不起作用} \Rightarrow {\color{Red} 变相提高方差，也就是减少过拟合} 
> \end{align}
> $$
>
> 2. 第二种解释:
>
> ![](https://pic.imgdb.cn/item/66208f5b0ea9cb1403db8a48.png)

## 2.3 Dropout调整

- 原理说明

>  Dropout是指在深度学习网络的训练过程中，对于每层的神经元，按照`一定的概率将其暂时从网络中丢弃`。也就是说，每次训练时，`每一层都有部分神经元不工作，起到简化复杂网络模型的效果，从而避免发生过拟合`。
>
> ![](https://pic.imgdb.cn/item/662090760ea9cb1403e30e77.png)
>
> 1. `不同隐藏层的dropout系数keep_prob可以不同`。一般来说，`神经元越多的隐藏层，keep_out可以设置得小一些`，例如0.5；`神经元越少的隐藏层，keep_out可以设置的大一些`，例如0.8，设置是1。
> 2. `实际应用中，不建议对输入层进行dropout，如果输入层维度很大，例如图片，那么可以设置dropout，但keep_out应设置的大一些，例如0.8，0.9`
> 3. 值得注意的是，使用dropout训练结束后，在测试和实际应用模型时，不需要进行dropout和随机删减神经元，所有的神经元都在工作

## 2.4 数据增强

> 1. 其中一种方法是增加训练样本数量。但是通常成本较高，难以获得额外的训练样本。但是，我们可以对已有的训练样本进行一些处理来“制造”出更多的样本，称为data augmentation。
>
> 2. 图片识别问题中，可以对已有的图片进行水平翻转、垂直翻转、任意角度旋转、缩放或扩大
>
> ![](https://pic.imgdb.cn/item/662091990ea9cb1403ea0244.png)

## 2.5 L2正则化代码

- L2正则化代码

```python
'''
Author: Jean_Leung
Date: 2024-04-16 10:11:58
LastEditors: Jean_Leung
LastEditTime: 2024-04-18 14:21:34
FilePath: \Chap2\chap6exercise.py
Description: 深度神经网络的正则化
            具体实现:
                1.不使用正则化
                2.使用正则化
                    2.1 使用L2正则化
                    2.2 使用随机节点删除
Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved. 
'''

# import packages
import numpy as np
import matplotlib.pyplot as plt
from reg_utils import * 
import sklearn
import sklearn.datasets
from testCase import *

# # 设置 plot 的默认大小
# plt.rcParams['figure.figsize'] = (7.0, 4.0) 
# plt.rcParams['image.interpolation'] = 'nearest'
# plt.rcParams['image.cmap'] = 'gray' 


plt.rcParams['figure.figsize'] = (20.0, 30.0) # set default size of plots
plt.rcParams['image.interpolation'] = 'nearest'
plt.rcParams['image.cmap'] = 'gray'

train_X, train_Y, test_X, test_Y = load_2D_dataset(is_plot=False)
# plt.show()

# 使用正则化正向传播
def compute_cost_with_regularization(A3, Y, parameters, lambd):
    """
    实现公式2的L2正则化计算成本
    
    参数：
        A3 - 正向传播的输出结果，维度为（输出节点数量，训练/测试的数量）
        Y - 标签向量，与数据一一对应，维度为(输出节点数量，训练/测试的数量)
        parameters - 包含模型学习后的参数的字典
        lambda - 进行正则化因子
    返回：
        cost - 使用公式2计算出来的正则化损失的值
    """
    m = Y.shape[1]
    W1 = parameters["W1"]
    W2 = parameters["W2"]
    W3 = parameters["W3"]
    # 先计算原先的compute_cost值
    cross_entropy_cost = compute_cost(A3,Y)
    # 这就是正则化公式，额外多出来的部分正则式
    L2_regularization_cost = lambd * (np.sum(np.square(W1)) + np.sum(np.square(W2)) + np.sum(np.square(W3))) / (2 * m)
    # 初始+正则化公式 = 新的costJ函数
    cost = cross_entropy_cost + L2_regularization_cost
    return cost

# 测试compute_cost_with_regularization函数
# print("============测试正则化后的cost函数==========")
# A3 , Y_assess,parameters = compute_cost_with_regularization_test_case()
# print("cost = " + str(compute_cost_with_regularization(A3,Y_assess,parameters,lambd=0.1)))

# 当然，因为改变了成本函数，我们也必须改变向后传播的函数， 
# 所有的梯度都必须根据这个新的成本值来计算。
'''
description: 有正则表达式的反向传输
param {*} X
param {*} Y
param {*} cache
param {*} lambd
return {*}
'''
def backward_propagation_with_regularization(X,Y,cache,lambd):
    """
    实现我们添加了L2正则化的模型的后向传播。
    
    参数：
        X - 输入数据集，维度为（输入节点数量，数据集里面的数量）
        Y - 标签，维度为（输出节点数量，数据集里面的数量）
        cache - 来自forward_propagation（）的cache输出
        lambda - regularization超参数，实数
    
    返回：
        gradients - 一个包含了每个参数、激活值和预激活值变量的梯度的字典
    """
    m = X.shape[1]
    # 首先，从字典 之前正向计算搜索出对应各类参数
    (Z1, A1, W1, b1, Z2, A2, W2, b2, Z3, A3, W3, b3) = cache
    # 正向传播的梯度
    dZ3 = A3 - Y
    # 加上正则表达式，正则部分的导数为 lambd * W3 / m
    dW3 = 1/m * np.dot(dZ3,A2.T) + ((lambd * W3) / m)
    db3 = 1/m * np.sum(dZ3,axis=1,keepdims=True)

    dA2 = np.dot(W3.T,dZ3)
    dZ2 = np.multiply(dA2, np.int64(A2 > 0))
    dW2 = 1/m * np.dot(dZ2,A1.T) + ((lambd * W2) / m)
    db2 = 1/m * np.sum(dZ2,axis=1,keepdims=True)

    dA1 = np.dot(W2.T,dZ2)
    dZ1 = np.multiply(dA1, np.int64(A1 > 0))
    dW1 = 1/m * np.dot(dZ1,X.T) + ((lambd * W1) / m)
    db1 = 1/m * np.sum(dZ1,axis=1,keepdims=True)

    gradients = {"dZ3": dZ3, "dW3": dW3, "db3": db3, "dA2": dA2,
                 "dZ2": dZ2, "dW2": dW2, "db2": db2, "dA1": dA1, 
                 "dZ1": dZ1, "dW1": dW1, "db1": db1}
    return gradients

# X_assess,Y_assess,cache = backward_propagation_with_regularization_test_case()
# # 测试backward_propagation_with_regularization函数
# grads = backward_propagation_with_regularization(X_assess,Y_assess,cache,lambd=0.7)
# print("dW1 = " + str(grads["dW1"]))
# print("dW2 = " + str(grads["dW2"]))
# print("dW3 = " + str(grads["dW3"]))

'''
description: 总模型
param {*} X
param {*} Y
param {*} learning_rate
param {*} num_iterations
param {*} print_cost
param {*} is_plot
param {*} lambd
param {*} keep_prob
param {*} k 用来表示显示图片的图层
return {*}
'''
def model(X,Y,learning_rate=0.3,num_iterations=30000,print_cost=True,is_plot=True,lambd=0,keep_prob=1,k=1):
    """
    实现一个三层的神经网络：LINEAR ->RELU -> LINEAR -> RELU -> LINEAR -> SIGMOID
    
    参数：
        X - 输入的数据，维度为(2, 要训练/测试的数量)
        Y - 标签，【0(蓝色) | 1(红色)】，维度为(1，对应的是输入的数据的标签)
        learning_rate - 学习速率
        num_iterations - 迭代的次数
        print_cost - 是否打印成本值，每迭代10000次打印一次，但是每1000次记录一个成本值
        is_polt - 是否绘制梯度下降的曲线图
        lambd - 正则化的超参数，实数
        keep_prob - 随机删除节点的概率
    返回
        parameters - 学习后的参数
    """
    
    grads = {}
    costs = []
    m = X.shape[1]
    print("X 输入维度" + str(X.shape[0]))
    # print("m = ", m)
    layers_dims = [X.shape[0],20,3,1]
    
    # 初始化参数
    parameters = initialize_parameters(layers_dims)
    
    # 开始学习
    for i in range(0,num_iterations):
        # 前向传播
        ## 是否随机删除节点
        if keep_prob == 1:
            ### 不随机删除节点
            a3 , cache = forward_propagation(X,parameters)
        elif keep_prob < 1:
            ### 随机删除节点
            a3 , cache = forward_propagation_with_dropout(X,parameters,keep_prob)
        else:
            print("keep_prob参数错误！程序退出。")
            exit
        
        # 计算成本
        ## 是否使用二范数
        if lambd == 0:
            ### 不使用 L2 正则化
            cost = compute_cost(a3,Y)
        else:
            ### 使用 L2 正则化
            cost = compute_cost_with_regularization(a3,Y,parameters,lambd)
        
        
        ## 可以同时使用 L2 正则化和随机删除节点，但是本次实验不同时使用。
        assert(lambd == 0  or keep_prob == 1)

        # 反向传播
        ## 两个参数的使用情况
        if (lambd == 0 and keep_prob == 1):
            ### 不使用 L2 正则化和不使用随机删除节点
            grads = backward_propagation(X,Y,cache)
        elif lambd != 0:
            ### 使用 L2 正则化，不使用随机删除节点
            grads = backward_propagation_with_regularization(X, Y, cache, lambd)
        elif keep_prob < 1:
            ### 使用随机删除节点，不使用 L2 正则化
            grads = backward_propagation_with_dropout(X, Y, cache, keep_prob)
        
        #更新参数
        parameters = update_parameters(parameters, grads, learning_rate)
        
        # 记录并打印成本
        if i % 1000 == 0:
            ## 记录成本
            costs.append(cost)
            if (print_cost and i % 10000 == 0):
                # 打印成本
                print("第" + str(i) + "次迭代，成本值为：" + str(cost))
        
    # 是否绘制成本曲线图
    if is_plot:
        plt.subplot(3,2,k)
        plt.plot(costs)
        plt.ylabel('cost')
        plt.xlabel('iterations (x1,000)')
        # plt.title("Learning rate =" + str(learning_rate) +"\ndropout with keep_prob = " + str(keep_prob))
        plt.title("Learning rate =" + str(learning_rate) +"\nregression with lambd = " + str(lambd))
        # plt.show()
    
    # 返回学习后的参数
    return parameters

# # 测试使用L2正则化，但是不使用删除节点
# parameters = model(train_X,train_Y,lambd=0.7,is_plot=True)
# print("使用正则化，训练集:")
# predictions_train = predict(train_X, train_Y, parameters)
# print("使用正则化，测试集:")
# predictions_test = predict(test_X, test_Y, parameters)
# plt.title("Model with L2-regularization")
# axes = plt.gca()
# axes.set_xlim([-0.75,0.40])
# axes.set_ylim([-0.75,0.65])
# plot_decision_boundary(lambda x: predict_dec(parameters, x.T), train_X, train_Y)
# plt.show()

'''
description: 反向drop_out技术实现
param {*} X
param {*} parameters
param {*} keep_prob
return {*}
'''
def forward_propagation_with_dropout(X, parameters, keep_prob = 0.5):
    """
    Implements the forward propagation: LINEAR -> RELU + DROPOUT -> LINEAR -> RELU + DROPOUT -> LINEAR -> SIGMOID.
    
    Arguments:
    X -- input dataset, of shape (2, number of examples)
    parameters -- python dictionary containing your parameters "W1", "b1", "W2", "b2", "W3", "b3":
                    W1 -- weight matrix of shape (20, 2)
                    b1 -- bias vector of shape (20, 1)
                    W2 -- weight matrix of shape (3, 20)
                    b2 -- bias vector of shape (3, 1)
                    W3 -- weight matrix of shape (1, 3)
                    b3 -- bias vector of shape (1, 1)
    keep_prob - probability of keeping a neuron active during drop-out, scalar
    
    Returns:
    A3 -- last activation value, output of the forward propagation, of shape (1,1)
    cache -- tuple, information stored for computing the backward propagation
    """

    np.random.seed(1)
    # Retrieve each parameter from the dictionary "parameters"
    W1 = parameters["W1"]
    b1 = parameters["b1"]
    W2 = parameters["W2"]
    b2 = parameters["b2"]
    W3 = parameters["W3"]
    b3 = parameters["b3"]

    # LINEAR -> RELU -> LINEAR -> RELU -> LINEAR -> SIGMOID
    Z1 = np.dot(W1,X) + b1
    A1 = relu(Z1)
    # START CODE HERE
    D1 = np.random.rand(A1.shape[0],A1.shape[1])
    D1 = D1 < keep_prob
    A1 = A1 * D1
    A1 = A1 / keep_prob
    # END CODE HERE
    Z2 = np.dot(W2,A1) + b2
    A2 = relu(Z2)

    D2 = np.random.rand(A2.shape[0],A2.shape[1])
    D2 = D2 < keep_prob
    A2 = A2 * D2
    A2 = A2 / keep_prob

    Z3 = np.dot(W3,A2) + b3
    A3 = sigmoid(Z3)
    # 也需要返回D矩阵，因为需要根据D矩阵进行掩码操作
    cache = (Z1, D1, A1, W1, b1, Z2, D2, A2, W2, b2, Z3, A3, W3, b3)
    return A3, cache

# X_assess, parameters = forward_propagation_with_dropout_test_case()

# # 测试forward_propagation_with_dropout函数

# A3, cache = forward_propagation_with_dropout(X_assess,parameters,keep_prob = 0.5)
# print("A3 = " + str(A3))

# 带有dropout的反向传输
def backward_propagation_with_dropout(X, Y, cache, keep_prob):
    """
    Implements the backward propagation of our baseline model to which we added dropout.
    
    Arguments:

    X -- input dataset, of shape (2, number of examples)
    Y -- "true" labels vector, of shape (output size, number of examples)
    cache -- cache output from forward_propagation_with_dropout()
    keep_prob - probability of keeping a neuron active during drop-out, scalar
    
    Returns:
    gradients -- A dictionary with the gradients with respect to each parameter, activation and pre-activation variables
    """
    m = X.shape[1]
    (Z1, D1, A1, W1, b1, Z2, D2, A2, W2, b2, Z3, A3, W3, b3) = cache
    # Retrieve each parameter from the dictionary "parameters"
    dZ3 = A3 - Y
    dW3 = 1./ m * np.dot(dZ3, A2.T)
    db3 = 1./ m * np.sum(dZ3, axis = 1, keepdims = True)
    dA2 = np.dot(W3.T,dZ3)
    # 关闭操作
    dA2 = dA2 * D2
    dA2 = dA2 / keep_prob

    dZ2 = np.multiply(dA2, np.int64(A2 > 0))
    dW2 = 1./m * np.dot(dZ2, A1.T)
    db2 = 1./m * np.sum(dZ2, axis=1, keepdims = True)

    dA1 = np.dot(W2.T,dZ2)

    dA1 = dA1 * D1
    dA1 = dA1 / keep_prob

    dZ1 = np.multiply(dA1,np.int64(A1 > 0))
    dW1 = 1./m * np.dot(dZ1, X.T)
    db1 = 1./m * np.sum(dZ1, axis=1, keepdims = True)
    gradients = {"dZ3": dZ3, "dW3": dW3, "db3": db3,"dA2": dA2,
                 "dZ2": dZ2, "dW2": dW2, "db2": db2, "dA1": dA1, 
                 "dZ1": dZ1, "dW1": dW1, "db1": db1}
    
    return gradients

# X_assess, Y_assess, cache = backward_propagation_with_dropout_test_case()

# gradients = backward_propagation_with_dropout(X_assess, Y_assess, cache, keep_prob = 0.8)

# print ("dA1 = " + str(gradients["dA1"]))
# print ("dA2 = " + str(gradients["dA2"]))

# 测试kee_prob因子，以一定概率的舍弃权重
keep_prob_list = [1.0,0.96,0.86,0.8,0.75,0.7]
lambd_list = [20.0,15.0,10.0,5.0,1.0,0]
# 没使用L2正则化，只测试keep_prob因子
for k in range(0,len(lambd_list)):
    parameters = model(train_X,train_Y,learning_rate=0.3,num_iterations=30000,print_cost=True,is_plot=True,lambd=lambd_list[k],keep_prob=1.0,k= k +1)
    print("使用正则化，训练集:")
    predictions_train = predict(train_X, train_Y, parameters)
    print("使用正则化，测试集:")
    predictions_test = predict(test_X, test_Y, parameters)
    # plt.subplot(3,2,k+1)
    # # plt.title("Model with Dropout" + "\nkeep_prob is" + str(keep_prob_list[k]))
    # plt.title("Model with regression" + "\nlambd" + str(lambd_list[k]))
    # axes = plt.gca()
    # axes.set_xlim([-0.75,0.40])
    # axes.set_ylim([-0.75,0.65])
    # plot_decision_boundary(lambda x: predict_dec(parameters, x.T), train_X, train_Y)
plt.show()

```

![](C:\Users\25212\OneDrive\吴恩达DL\正则化测试结果.png)

![](C:\Users\25212\OneDrive\吴恩达DL\正则化测试结果2.png)

> 结论
>
> 1. `当lambd=0的时候，明显从结果图可以看出,过拟合严重，lambd增大的时候，就在提高w的衰减，过拟合趋势减少，但是一旦lamda过大，就会使得方差过高，导师模型错误，所以lambd不宜过高`

## 2.6 Dropout代码

- Dropout代码

```python
'''
Author: Jean_Leung
Date: 2024-04-16 10:11:58
LastEditors: Jean_Leung
LastEditTime: 2024-04-18 11:45:03
FilePath: \Chap2\chap6exercise.py
Description: 深度神经网络的正则化
            具体实现:
                1.不使用正则化
                2.使用正则化
                    2.1 使用L2正则化
                    2.2 使用随机节点删除
Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved. 
'''

# import packages
import numpy as np
import matplotlib.pyplot as plt
from reg_utils import * 
import sklearn
import sklearn.datasets
from testCase import *

# # 设置 plot 的默认大小
# plt.rcParams['figure.figsize'] = (7.0, 4.0) 
# plt.rcParams['image.interpolation'] = 'nearest'
# plt.rcParams['image.cmap'] = 'gray' 


plt.rcParams['figure.figsize'] = (20.0, 20.0) # set default size of plots
plt.rcParams['image.interpolation'] = 'nearest'
plt.rcParams['image.cmap'] = 'gray'

train_X, train_Y, test_X, test_Y = load_2D_dataset(is_plot=False)
# plt.show()

# 使用正则化正向传播
def compute_cost_with_regularization(A3, Y, parameters, lambd):
    """
    实现公式2的L2正则化计算成本
    
    参数：
        A3 - 正向传播的输出结果，维度为（输出节点数量，训练/测试的数量）
        Y - 标签向量，与数据一一对应，维度为(输出节点数量，训练/测试的数量)
        parameters - 包含模型学习后的参数的字典
        lambda - 进行正则化因子
    返回：
        cost - 使用公式2计算出来的正则化损失的值
    """
    m = Y.shape[1]
    W1 = parameters["W1"]
    W2 = parameters["W2"]
    W3 = parameters["W3"]
    # 先计算原先的compute_cost值
    cross_entropy_cost = compute_cost(A3,Y)
    # 这就是正则化公式，额外多出来的部分正则式
    L2_regularization_cost = lambd * (np.sum(np.square(W1)) + np.sum(np.square(W2)) + np.sum(np.square(W3))) / (2 * m)
    # 初始+正则化公式 = 新的costJ函数
    cost = cross_entropy_cost + L2_regularization_cost
    return cost

# 测试compute_cost_with_regularization函数
# print("============测试正则化后的cost函数==========")
# A3 , Y_assess,parameters = compute_cost_with_regularization_test_case()
# print("cost = " + str(compute_cost_with_regularization(A3,Y_assess,parameters,lambd=0.1)))

# 当然，因为改变了成本函数，我们也必须改变向后传播的函数， 
# 所有的梯度都必须根据这个新的成本值来计算。
'''
description: 有正则表达式的反向传输
param {*} X
param {*} Y
param {*} cache
param {*} lambd
return {*}
'''
def backward_propagation_with_regularization(X,Y,cache,lambd):
    """
    实现我们添加了L2正则化的模型的后向传播。
    
    参数：
        X - 输入数据集，维度为（输入节点数量，数据集里面的数量）
        Y - 标签，维度为（输出节点数量，数据集里面的数量）
        cache - 来自forward_propagation（）的cache输出
        lambda - regularization超参数，实数
    
    返回：
        gradients - 一个包含了每个参数、激活值和预激活值变量的梯度的字典
    """
    m = X.shape[1]
    # 首先，从字典 之前正向计算搜索出对应各类参数
    (Z1, A1, W1, b1, Z2, A2, W2, b2, Z3, A3, W3, b3) = cache
    # 正向传播的梯度
    dZ3 = A3 - Y
    # 加上正则表达式，正则部分的导数为 lambd * W3 / m
    dW3 = 1/m * np.dot(dZ3,A2.T) + ((lambd * W3) / m)
    db3 = 1/m * np.sum(dZ3,axis=1,keepdims=True)

    dA2 = np.dot(W3.T,dZ3)
    dZ2 = np.multiply(dA2, np.int64(A2 > 0))
    dW2 = 1/m * np.dot(dZ2,A1.T) + ((lambd * W2) / m)
    db2 = 1/m * np.sum(dZ2,axis=1,keepdims=True)

    dA1 = np.dot(W2.T,dZ2)
    dZ1 = np.multiply(dA1, np.int64(A1 > 0))
    dW1 = 1/m * np.dot(dZ1,X.T) + ((lambd * W1) / m)
    db1 = 1/m * np.sum(dZ1,axis=1,keepdims=True)

    gradients = {"dZ3": dZ3, "dW3": dW3, "db3": db3, "dA2": dA2,
                 "dZ2": dZ2, "dW2": dW2, "db2": db2, "dA1": dA1, 
                 "dZ1": dZ1, "dW1": dW1, "db1": db1}
    return gradients

# X_assess,Y_assess,cache = backward_propagation_with_regularization_test_case()
# # 测试backward_propagation_with_regularization函数
# grads = backward_propagation_with_regularization(X_assess,Y_assess,cache,lambd=0.7)
# print("dW1 = " + str(grads["dW1"]))
# print("dW2 = " + str(grads["dW2"]))
# print("dW3 = " + str(grads["dW3"]))

'''
description: 总模型
param {*} X
param {*} Y
param {*} learning_rate
param {*} num_iterations
param {*} print_cost
param {*} is_plot
param {*} lambd
param {*} keep_prob
param {*} k 用来表示显示图片的图层
return {*}
'''
def model(X,Y,learning_rate=0.3,num_iterations=30000,print_cost=True,is_plot=True,lambd=0,keep_prob=1,k=1):
    """
    实现一个三层的神经网络：LINEAR ->RELU -> LINEAR -> RELU -> LINEAR -> SIGMOID
    
    参数：
        X - 输入的数据，维度为(2, 要训练/测试的数量)
        Y - 标签，【0(蓝色) | 1(红色)】，维度为(1，对应的是输入的数据的标签)
        learning_rate - 学习速率
        num_iterations - 迭代的次数
        print_cost - 是否打印成本值，每迭代10000次打印一次，但是每1000次记录一个成本值
        is_polt - 是否绘制梯度下降的曲线图
        lambd - 正则化的超参数，实数
        keep_prob - 随机删除节点的概率
    返回
        parameters - 学习后的参数
    """
    
    grads = {}
    costs = []
    m = X.shape[1]
    layers_dims = [X.shape[0],20,3,1]
    
    # 初始化参数
    parameters = initialize_parameters(layers_dims)
    
    # 开始学习
    for i in range(0,num_iterations):
        # 前向传播
        ## 是否随机删除节点
        if keep_prob == 1:
            ### 不随机删除节点
            a3 , cache = forward_propagation(X,parameters)
        elif keep_prob < 1:
            ### 随机删除节点
            a3 , cache = forward_propagation_with_dropout(X,parameters,keep_prob)
        else:
            print("keep_prob参数错误！程序退出。")
            exit
        
        # 计算成本
        ## 是否使用二范数
        if lambd == 0:
            ### 不使用 L2 正则化
            cost = compute_cost(a3,Y)
        else:
            ### 使用 L2 正则化
            cost = compute_cost_with_regularization(a3,Y,parameters,lambd)
        
        # 反向传播
        ## 可以同时使用 L2 正则化和随机删除节点，但是本次实验不同时使用。
        assert(lambd == 0  or keep_prob ==1)
        
        ## 两个参数的使用情况
        if (lambd == 0 and keep_prob == 1):
            ### 不使用 L2 正则化和不使用随机删除节点
            grads = backward_propagation(X,Y,cache)
        elif lambd != 0:
            ### 使用 L2 正则化，不使用随机删除节点
            grads = backward_propagation_with_regularization(X, Y, cache, lambd)
        elif keep_prob < 1:
            ### 使用随机删除节点，不使用 L2 正则化
            grads = backward_propagation_with_dropout(X, Y, cache, keep_prob)
        
        #更新参数
        parameters = update_parameters(parameters, grads, learning_rate)
        
        # 记录并打印成本
        if i % 1000 == 0:
            ## 记录成本
            costs.append(cost)
            if (print_cost and i % 10000 == 0):
                # 打印成本
                print("第" + str(i) + "次迭代，成本值为：" + str(cost))
        
    # 是否绘制成本曲线图
    if is_plot:
        plt.plot(costs)
        plt.ylabel('cost')
        plt.xlabel('iterations (x1,000)')
        plt.title("Learning rate =" + str(learning_rate))
        plt.show()
    
    # 返回学习后的参数
    return parameters

# # 测试使用L2正则化，但是不使用删除节点
# parameters = model(train_X,train_Y,lambd=0.7,is_plot=True)
# print("使用正则化，训练集:")
# predictions_train = predict(train_X, train_Y, parameters)
# print("使用正则化，测试集:")
# predictions_test = predict(test_X, test_Y, parameters)
# plt.title("Model with L2-regularization")
# axes = plt.gca()
# axes.set_xlim([-0.75,0.40])
# axes.set_ylim([-0.75,0.65])
# plot_decision_boundary(lambda x: predict_dec(parameters, x.T), train_X, train_Y)
# plt.show()

'''
description: 反向drop_out技术实现
param {*} X
param {*} parameters
param {*} keep_prob
return {*}
'''
def forward_propagation_with_dropout(X, parameters, keep_prob = 0.5):
    """
    Implements the forward propagation: LINEAR -> RELU + DROPOUT -> LINEAR -> RELU + DROPOUT -> LINEAR -> SIGMOID.
    
    Arguments:
    X -- input dataset, of shape (2, number of examples)
    parameters -- python dictionary containing your parameters "W1", "b1", "W2", "b2", "W3", "b3":
                    W1 -- weight matrix of shape (20, 2)
                    b1 -- bias vector of shape (20, 1)
                    W2 -- weight matrix of shape (3, 20)
                    b2 -- bias vector of shape (3, 1)
                    W3 -- weight matrix of shape (1, 3)
                    b3 -- bias vector of shape (1, 1)
    keep_prob - probability of keeping a neuron active during drop-out, scalar
    
    Returns:
    A3 -- last activation value, output of the forward propagation, of shape (1,1)
    cache -- tuple, information stored for computing the backward propagation
    """

    np.random.seed(1)
    # Retrieve each parameter from the dictionary "parameters"
    W1 = parameters["W1"]
    b1 = parameters["b1"]
    W2 = parameters["W2"]
    b2 = parameters["b2"]
    W3 = parameters["W3"]
    b3 = parameters["b3"]

    # LINEAR -> RELU -> LINEAR -> RELU -> LINEAR -> SIGMOID
    Z1 = np.dot(W1,X) + b1
    A1 = relu(Z1)
    # START CODE HERE
    D1 = np.random.rand(A1.shape[0],A1.shape[1])
    D1 = D1 < keep_prob
    A1 = A1 * D1
    A1 = A1 / keep_prob
    # END CODE HERE
    Z2 = np.dot(W2,A1) + b2
    A2 = relu(Z2)

    D2 = np.random.rand(A2.shape[0],A2.shape[1])
    D2 = D2 < keep_prob
    A2 = A2 * D2
    A2 = A2 / keep_prob

    Z3 = np.dot(W3,A2) + b3
    A3 = sigmoid(Z3)
    # 也需要返回D矩阵，因为需要根据D矩阵进行掩码操作
    cache = (Z1, D1, A1, W1, b1, Z2, D2, A2, W2, b2, Z3, A3, W3, b3)
    return A3, cache

# X_assess, parameters = forward_propagation_with_dropout_test_case()

# # 测试forward_propagation_with_dropout函数

# A3, cache = forward_propagation_with_dropout(X_assess,parameters,keep_prob = 0.5)
# print("A3 = " + str(A3))

# 带有dropout的反向传输
def backward_propagation_with_dropout(X, Y, cache, keep_prob):
    """
    Implements the backward propagation of our baseline model to which we added dropout.
    
    Arguments:

    X -- input dataset, of shape (2, number of examples)
    Y -- "true" labels vector, of shape (output size, number of examples)
    cache -- cache output from forward_propagation_with_dropout()
    keep_prob - probability of keeping a neuron active during drop-out, scalar
    
    Returns:
    gradients -- A dictionary with the gradients with respect to each parameter, activation and pre-activation variables
    """
    m = X.shape[1]
    (Z1, D1, A1, W1, b1, Z2, D2, A2, W2, b2, Z3, A3, W3, b3) = cache
    # Retrieve each parameter from the dictionary "parameters"
    dZ3 = A3 - Y
    dW3 = 1./ m * np.dot(dZ3, A2.T)
    db3 = 1./ m * np.sum(dZ3, axis = 1, keepdims = True)
    dA2 = np.dot(W3.T,dZ3)
    # 关闭操作
    dA2 = dA2 * D2
    dA2 = dA2 / keep_prob

    dZ2 = np.multiply(dA2, np.int64(A2 > 0))
    dW2 = 1./m * np.dot(dZ2, A1.T)
    db2 = 1./m * np.sum(dZ2, axis=1, keepdims = True)

    dA1 = np.dot(W2.T,dZ2)

    dA1 = dA1 * D1
    dA1 = dA1 / keep_prob

    dZ1 = np.multiply(dA1,np.int64(A1 > 0))
    dW1 = 1./m * np.dot(dZ1, X.T)
    db1 = 1./m * np.sum(dZ1, axis=1, keepdims = True)
    gradients = {"dZ3": dZ3, "dW3": dW3, "db3": db3,"dA2": dA2,
                 "dZ2": dZ2, "dW2": dW2, "db2": db2, "dA1": dA1, 
                 "dZ1": dZ1, "dW1": dW1, "db1": db1}
    
    return gradients

# X_assess, Y_assess, cache = backward_propagation_with_dropout_test_case()

# gradients = backward_propagation_with_dropout(X_assess, Y_assess, cache, keep_prob = 0.8)

# print ("dA1 = " + str(gradients["dA1"]))
# print ("dA2 = " + str(gradients["dA2"]))

# 测试kee_prob因子，以一定概率的舍弃权重
keep_prob_list = [0.86,0.8,0.75,0.7,0.6]
# 没使用L2正则化，只测试keep_prob因子
for k in range(0,len(keep_prob_list)):
    parameters = model(train_X,train_Y,learning_rate=0.3,num_iterations=30000,print_cost=True,is_plot=False,lambd=0,keep_prob=keep_prob_list[k],k=k)
    print("使用正则化，训练集:")
    predictions_train = predict(train_X, train_Y, parameters)
    print("使用正则化，测试集:")
    predictions_test = predict(test_X, test_Y, parameters)
    plt.subplot(3,2,k+1)
    plt.title("Model with Dropout")
    axes = plt.gca()
    axes.set_xlim([-0.75,0.40])
    axes.set_ylim([-0.75,0.65])
    plot_decision_boundary(lambda x: predict_dec(parameters, x.T), train_X, train_Y)
plt.show()

```

- 测试效果

![](C:\Users\25212\OneDrive\吴恩达DL\dropout测试结果图.png)

![](C:\Users\25212\OneDrive\吴恩达DL\dropout测试结果图2.png)

> 结论:
>
> 1. 此次测试网络为(2,20,3,1为三层网络)，也就是针对与20的第一层，可以keep_prob调小一点，以舍弃更多的神经元，那么这就可以达到避免 过拟合的效果
> 2. 当 keep_prob= 1的时候，模型的过拟合很明显从上图测试结果图一可以看出,当keep_prob变小的时候，过拟合明显变小，方差变小

# 3. 深度神经网络的梯度校验

## 3.1 背景

> Back Propagation神经网络有一项重要的测试是梯度检查（gradient checking）。
>
> 其目的是检查验证反向传播过程中梯度下降算法是否正确。

## 3.2 梯度校验原理

![](C:\Users\25212\OneDrive\吴恩达DL\高纬度梯度显示.png)

> 1. 在高数中，我们有导数的定义
>
> $$
> \begin{align}
> & 导数定义:\tan \alpha=\lim _{\Delta x \rightarrow 0} \tan \varphi=\lim _{\Delta x \rightarrow 0} \frac{f\left(x_{0}+\Delta x\right)-f\left(x_{0}\right)}{\Delta x}\\
> \end{align}
> $$
>
> ![undefined](https://upload.wikimedia.org/wikipedia/commons/thumb/d/de/Derivative_-_geometric_meaning.svg/1280px-Derivative_-_geometric_meaning.svg.png)
>
> 2. 由前面笔记可得,二元函数的梯度就是在该点的斜率,那么在某点的梯度就表示为
>
> ![](C:\Users\25212\OneDrive\吴恩达DL\梯度.png)
>
> 那么我们可以得到
> $$
> g^{'}(\theta)=\lim_{\varepsilon    \to 0} \frac{f(\theta+\varepsilon)-f(\theta-\varepsilon)}{2 \varepsilon}
> $$
>
> 3. 一元函数 y = θx 求解过程:
>
> $$
> \begin{align}
> &1.  \theta^{+}= \theta+\varepsilon \\
> &2.  \theta^{-}  = \theta-\varepsilon \\
> &3.  J^{+}  = J\left(\theta^{+}\right) \\
> &4.  J^{-}  = J\left(\theta^{-}\right)\\
> &5. gradapprox  = \frac{J^{+}-J^{-}}{2 \varepsilon } \\
> &6. 反向传播计算梯度,将结果存储在grad中 \\
> &7. 计算\text { difference }=\frac{\| \text { grad-gradapprox } \|_{2}}{\| \text { grad }\left\|_{2}+\right\| \text { gradapprox } \|_{2}}
> \end{align}
> $$
>
> 4. 多维度函数 J求解过程
>    $$
>    J\left(w^{[1]}, b^{[1]}, \cdots, w^{[L]}, b^{[L]}\right)
>    $$
>    根据`测试案例`设置
>
>    ![](C:\Users\25212\OneDrive\吴恩达DL\三层神经网络.png)
>    $$
>    W^{[1]} = \begin{bmatrix}
>      W^{11}& W^{12} & W^{13} & W^{14} \\
>      W^{21}& W^{22} & W^{23} & W^{24} \\
>      W^{31}& W^{32} & W^{33} & W^{34} \\
>      W^{41}& W^{42} & W^{43} & W^{44} \\
>      W^{51}& W^{52} & W^{53} & W^{54}
>    \end{bmatrix}
>    $$
>
>    $$
>    W^{[2]}=\begin{bmatrix}
>      W^{11}& W^{12} & W^{13} & W^{14} & W^{15}\\
>      W^{21}& W^{22} & W^{23} & W^{24} & W^{25}\\
>      W^{31}& W^{32} & W^{33} & W^{34} & W^{35}\\
>    \end{bmatrix}
>    $$
>
>    $$
>    W^{[1]}=\begin{bmatrix}
>      W^{11}& W^{12} & W^{13} \\
>      
>    \end{bmatrix}
>    $$
>
>    $$
>    b^{[1]}=\begin{bmatrix}
>      b^{11} \\
>      b^{21}\\
>      b^{31}\\
>      b^{41}\\
>      b^{51}
>    \end{bmatrix}
>    $$
>
>    $$
>    b^{[2]}=\begin{bmatrix}
>      b^{11} \\
>      b^{21}\\
>      b^{31}\\
>    \end{bmatrix}
>    $$
>
>    $$
>    b^{[3]}=b^{11}
>    $$
>
>    ![](C:\Users\25212\OneDrive\吴恩达DL\向量转矩阵.png)
>
>    将parameters字典数组转化为列向量,方便运算
>
>    ![](C:\Users\25212\OneDrive\吴恩达DL\梯度校验迭代过程.png)

## 3.3 梯度校验代码

- 主代码

```python
'''
Author: Jean_Leung
Date: 2024-04-16 21:05:57
LastEditors: Jean_Leung
LastEditTime: 2024-04-18 17:10:31
FilePath: \Chap2\chap7exercise.py
Description: 深度神经网络的梯度检验

Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved. 
'''
import numpy as np
from gc_utils import sigmoid, relu, dictionary_to_vector, vector_to_dictionary, gradients_to_vector   
from testCase import *

import numpy as np
from gc_utils import sigmoid, relu, dictionary_to_vector, vector_to_dictionary, gradients_to_vector   
from testCase import *

# 正向传播
'''
description: 正向传播
param {*} X
param {*} Y
param {*} parameters
return {*}
'''
def forward_propagation_n(X,Y,parameters):
    """
    正向传播
    
    Arguments:
    X -- 输入数据
    Y -- 标签数据
    parameters -- 神经网络的参数
    
    Returns:
    cost -- 成本函数
    cache -- 用于后向传播的缓存
    """
    m = X.shape[1]
    W1 = parameters["W1"]
    b1 = parameters["b1"]
    W2 = parameters["W2"]
    b2 = parameters["b2"]
    W3 = parameters["W3"]
    b3 = parameters["b3"]
    # LINEAR -> RELU -> LINEAR -> RELU -> LINEAR -> SIGMOID
    Z1 = np.dot(W1,X) + b1
    A1 = relu(Z1)

    Z2 = np.dot(W2,A1) + b2
    A2 = relu(Z2)

    Z3 = np.dot(W3,A2) + b3
    A3 = sigmoid(Z3)
    # 计算成本
    logprobs = np.multiply(-np.log(A3),Y) + np.multiply(-np.log(1-A3),1-Y)
    cost = (1/m) * np.sum(logprobs)
    cache = (Z1, A1, W1, b1, Z2, A2, W2, b2, Z3, A3, W3, b3)
    return cost, cache

# 反向传播
'''
description: 反向传播
param {*} X
param {*} Y
param {*} cache
return {*}
'''
def backward_propagation_n(X, Y, cache):
    """
    反向传播
    
    Arguments:
    X -- 输入数据
    Y -- 标签数据
    cache -- 用于后向传播的缓存
    
    Returns:
    grads -- 梯度
    """
    m = X.shape[1]
    (Z1, A1, W1, b1, Z2, A2, W2, b2, Z3, A3, W3, b3) = cache
    dZ3 = A3 - Y
    dW3 = 1/m * np.dot(dZ3,A2.T)
    db3 = 1/m * np.sum(dZ3,axis=1,keepdims=True)

    dA2 = np.dot(W3.T, dZ3)
    dZ2 = np.multiply(dA2, np.int64(A2 > 0))
    dW2 = 1./m * np.dot(dZ2, A1.T)
    db2 = 1./m * np.sum(dZ2, axis=1, keepdims = True)
    
    dA1 = np.dot(W2.T, dZ2)
    dZ1 = np.multiply(dA1, np.int64(A1 > 0))
    dW1 = 1./m * np.dot(dZ1, X.T)
    db1 = 1./m * np.sum(dZ1, axis=1, keepdims = True)
    
    gradients = {"dZ3": dZ3, "dW3": dW3, "db3": db3,
                 "dA2": dA2, "dZ2": dZ2, "dW2": dW2, "db2": db2,
                 "dA1": dA1, "dZ1": dZ1, "dW1": dW1, "db1": db1}
    
    return gradients


'''
description: 梯度检查代码
param {*} parameters
param {*} gradients
param {*} X
param {*} Y
param {*} epsilon
return {*}
'''
def gradient_check_n(parameters,gradients,X,Y,epsilon=1e-7):
    """
    检查梯度是否正确
    
    Arguments:
    parameters -- 神经网络的参数
    gradients -- 梯度字典
    X -- 输入数据
    Y -- 标签数据
    epsilon -- 数值比较精度
    
    Returns:

    """
    m = X.shape[1]
    W1 = parameters["W1"]
    b1 = parameters["b1"]
    W2 = parameters["W2"]
    b2 = parameters["b2"]
    W3 = parameters["W3"]
    b3 = parameters["b3"]
    # 先准备paramters矩阵，然后将parameters矩阵进行向量化
    # parameters_values 为parameters向量
    parameters_values, key = dictionary_to_vector(parameters)
    # gradients_values 为梯度向量
    gradients_values = gradients_to_vector(gradients)
    num_parameters = parameters_values.shape[0] # 向量维度,有多少个梯度，就需要迭代多少次
    # print(num_parameters) # 包括W1,b1,W2,b2,W3,b3的所有参数，共47个
    # print(gradients_values.shape[0]) # 一样是47个参数
    J_plus = np.zeros((num_parameters,1)) # 将J_plus初始化为(47,1)的列向量,也就是cost损失函数值
    J_minus = np.zeros((num_parameters,1))# 将J_minus初始化为(47,1)的列向量,也就是cost损失函数值
    gradapprox = np.zeros((num_parameters,1)) # 将gradapprox初始化为(47,1)的列向量
    for i in range(0,num_parameters):
        # 算左极限函数
        thetaplus = np.copy(parameters_values) # 将θ设置为parameters_values
        thetaplus[i][0] = thetaplus[i][0] + epsilon # 将θi = θi + epsilon
        J_plus[i], cache = forward_propagation_n(X,Y,vector_to_dictionary(thetaplus))  # Step 3 ，cache用不到,正向遍历,算出最后Jplus函数,
        # 同理，算右极限函数
        thetaminus = np.copy(parameters_values) # 将θ设置为parameters_values
        thetaminus[i][0] = thetaminus[i][0] - epsilon # 将θi = θi + epsilon
        J_minus[i], cache = forward_propagation_n(X,Y,vector_to_dictionary(thetaminus))  # Step 3 ，cache用不到,正向遍历,算出最后Jplus函数

        # 计算 gradapprox[i],这一步就是导数的极限定义
        gradapprox[i] = (J_plus[i] - J_minus[i]) / (2 * epsilon)
        # print(gradapprox[i])
    numerator = np.linalg.norm(gradients_values - gradapprox)
    denominator = np.linalg.norm(gradients_values) + np.linalg.norm(gradapprox)
    difference = numerator / denominator

    if difference > 1e-7:
        print ("\033[93m" + "There is a mistake in the backward propagation! difference = " + str(difference) + "\033[0m")
    else:
        print ("\033[92m" + "Your backward propagation works perfectly fine! difference = " + str(difference) + "\033[0m")
    
    return difference


X, Y, parameters = gradient_check_n_test_case()
cost, cache = forward_propagation_n(X, Y, parameters)
gradients = backward_propagation_n(X, Y, cache)
difference = gradient_check_n(parameters, gradients, X, Y)
# print(difference)
```

- gc_utils代码

```python
'''
Author: Jean_Leung
Date: 2024-04-16 21:08:25
LastEditors: Jean_Leung
LastEditTime: 2024-04-18 15:41:20
FilePath: \Chap2\gc_utils.py
Description: 深度神经网络梯度校验工具类

Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved. 
'''
import numpy as np

def sigmoid(x):
    """
    Compute the sigmoid of x
    Arguments:
    x -- A scalar or numpy array of any size.
    Return:
    s -- sigmoid(x)
    """
    s = 1/(1+np.exp(-x))
    return s

def relu(x):
    """
    Compute the relu of x
    Arguments:
    x -- A scalar or numpy array of any size.
    Return:
    s -- relu(x)
    """
    s = np.maximum(0,x)
    
    return s

'''
description: 字典向量化
param {*} parameters
return {*}
'''
def dictionary_to_vector(parameters):
    """
    Roll all our parameters dictionary into a single vector satisfying our specific required shape.
    """
    keys = []
    count = 0
    for key in ["W1", "b1", "W2", "b2", "W3", "b3"]:
        
        # flatten parameter
        new_vector = np.reshape(parameters[key], (-1,1))
        keys = keys + [key]*new_vector.shape[0]
        
        if count == 0:
            theta = new_vector
        else:
            theta = np.concatenate((theta, new_vector), axis=0)
        count = count + 1

    return theta, keys

def vector_to_dictionary(theta):
    """
    Unroll all our parameters dictionary from a single vector satisfying our specific required shape.
    """
    parameters = {}
    parameters["W1"] = theta[:20].reshape((5,4))
    parameters["b1"] = theta[20:25].reshape((5,1))
    parameters["W2"] = theta[25:40].reshape((3,5))
    parameters["b2"] = theta[40:43].reshape((3,1))
    parameters["W3"] = theta[43:46].reshape((1,3))
    parameters["b3"] = theta[46:47].reshape((1,1))

    return parameters

'''
description: 将gradietns字典，也就是梯度字典向量化
param {*} gradients
return {*}
'''
def gradients_to_vector(gradients):
    """
    Roll all our gradients dictionary into a single vector satisfying our specific required shape.
    """
    
    count = 0
    for key in ["dW1", "db1", "dW2", "db2", "dW3", "db3"]:
        # flatten parameter
        new_vector = np.reshape(gradients[key], (-1,1))
        
        if count == 0:
            theta = new_vector
        else:
            theta = np.concatenate((theta, new_vector), axis=0)
        count = count + 1

    return theta
```

- 测试结果

![](C:\Users\25212\OneDrive\吴恩达DL\梯度校验结果.png)

# 4. 深度经网络梯度下降优化算法

## 4.1 背景

> 1. 需要大量的数据集来训练神经网络，而在巨大的数据集基础上训练速度很慢，需要快速的优化算法，才能提高效率

## 4.2 Mini-batch梯度下降(Mini-batch gradient descent)

- 原理

> 1. 训练过程对所有m个样本，称为batch
> 2. 如果m很大，百万数量级，导致训练速度很慢，这种传统的训练方式称为Batch gradient descent
> 3. 为了解决这个问题,将m个训练样本分为若干个子集, mini-batches，每个子集包含的数据量就小了
>
> ![](https://pic.superbed.cc/item/667278fdfcada11d3754b002.png)
>
> 4. 先将总训练样本分为T个子集，然后每个mini-batch进行神经网络训练(Forward Cost Backward), 循环至T个mini-batch训练完毕

- epoch概念

> 1. 对于Batch Gradient Descent，一个epoch只进行一次梯度下降算法
> 2. Mini-Batches Gradient Descent，`一个epoch进行T次梯度下降算法`
> 3. Mini Batches GD的时候，`每次epoch，将总体数据重新打乱，重新分成T组mini-batches`

- Batch GD 与 Mini Batches GD的对比

![](https://pic.superbed.cc/item/6672820bfcada11d37553ddd.png)

> 值得注意
>
> 1. 使用Batch GD，随着迭代次数增加，cost是不断减小的,Mini-batch GD，随着Mini-batch上迭代训练，cost不是单调下降，出现振荡，整体的趋势是下降
> 2. ![](https://pic.superbed.cc/item/667ea51dfcada11d37c48504.png)

## 4.3 三种梯度下降的本质比较

> `三种梯度下降的本质区别是` batch size 的大小
>
> 1. 随机梯度下降(SGD):当batch size = 1的时候，也就是每个样本都是一个mini-batch，也就是每个样本独自走完一个epoch，也就是每次循环`总样本数量=M`次，循环至M个mini-batch训练完毕
> 2. 经典梯度下降(GD) :当batch size = M时候，也就是整体样本都是一个mini-batch，那么需要整体样本进行迭代,这样训练速度很慢
> 3. 批量梯度下降(Mini-GD): 当batch size >1 且 batch size < M ,那么就是分出M / batch size个组别，那么需要每次循环M/batch size次，每次循环中迭代的样本数量不多，加快了速度

```python
for  t=1,⋯,T {
    Forward Propagation
    ComputeCostFunction
    BackwardPropagation
    W:=W−α⋅dW
    b:=b−α⋅db
}
```

> 1. 当t = M的时候，就是随机梯度下降，每个样本都要经历Forward-COST-Back-更新
> 2. 当t = 1的时候，就是经典梯度下降，整体样本经历Forward....过程
> 3. 当1<t<m的时候，就是批量梯度下降，分批量经历Forward....过程

```python
#仅做比较，不运行。

#批量梯度下降，又叫梯度下降
X = data_input
Y = labels

parameters = initialize_parameters(layers_dims)
for i in range(0,num_iterations):
    #前向传播
    A,cache = forward_propagation(X,parameters)
    #计算损失
    cost = compute_cost(A,Y)
    #反向传播
    grads = backward_propagation(X,Y,cache)
    #更新参数
    parameters = update_parameters(parameters,grads)

#随机梯度下降算法：
X = data_input
Y = labels
parameters = initialize_parameters(layers_dims)
for i in (0,num_iterations):
    for j in m:
        #前向传播
        A,cache = forward_propagation(X,parameters)
        #计算成本
        cost = compute_cost(A,Y)
        #后向传播
        grads = backward_propagation(X,Y,cache)
        #更新参数
        parameters = update_parameters(parameters,grads)
```



![](https://pic.superbed.cc/item/667eae16fcada11d37c65175.png)

> 图揭示了梯度的过程，蓝色为经典梯度下降，绿色为分批量梯度下降，紫色为随机梯度下降
>
> ① 实际使用中，mini-batch size不能设置得太大（Batch gradient descent），也不能设置得太小（Stachastic gradient descent）。
>
> ② 这样，相当于结合了Batch gradient descent(经典梯度下降)和Stachastic gradient descent(随机梯度下降)各自的优点，既能使用向量化优化算法，又能较快速地找到最小值。
>
> ③ `mini-batch gradient descent的梯度下降曲线如下图绿色所示，每次前进速度较快，且振荡较小，基本能接近全局最小值`

## 4.4 加权平均

- 指数加权平均:

$$
V_{t}=\beta V_{t-1}+(1-\beta) \theta_{t}
$$

$$
\beta^{\frac{1}{1-\beta}}=\frac{1}{e}
$$

$$
\beta^{\frac{1}{1-\beta}}=\frac{1}{e}


令  \frac{1}{1-\beta}=N ， N>0  ，则  \beta=1-\frac{1}{N} ， \frac{1}{N}<1  。即证明转化为:

\left(1-\frac{1}{N}\right)^{N}=\frac{1}{e}
$$

> 此式子是用极限来证明，令N=x,x定义在R定义内，可以先①对数化②无穷小替换

# 5. 超参数调试、Batch正则化和程序框架

