# 简介

> 1. CAT识别器
> 2. 构建神经网络，Momentum RMSProp 和 adma优化算法
> 3. how to structure your machine learning project，训练集和测试集来自不同分布问题解决，end to end深度学习
> 4. CNN，卷积图片
> 5. 序列模型，NLP:RNN 以及 LSTM模型，处理NLP问题

# 1.Waht is a Neural Network

## RELU function(Rectified Linerar Unite)线性整流函数

> 1.Housing Price Prediciton(房子预测模型)
>
> ![](https://pic.imgdb.cn/item/660ebf2c68eb935713f228ca.png)
>
> ​	X是输入，圆圈代表`隐藏神经元`(神经网络)   y是输出
>
>    x为`输入层`  y为`输出层`
>
> ![](https://pic.imgdb.cn/item/660ec2ff68eb935713fdb17d.png)

## 监督学习和神经网络

> 1. Nerual Network examples 神经网络经典模型
>
> ![](https://pic.imgdb.cn/item/660ecbc668eb93571306fea7.png)
>
> SNN , CNN , RNN
>
> 2. Structured Data(结构性数据) Unstructured Data(非结构性数据)
>
> ![](https://pic.imgdb.cn/item/660ecd5068eb93571308a91b.png)
>
> 结构性数据和非结构性数据
>
> 结构性数据: 是Mysql之类的数据
>
> 非结构型数据: 音频，图片，text文件
>
> 3. Why DL is popular in recent years?
>
> ![](https://pic.imgdb.cn/item/660ed03568eb9357130f89de.png)
>
> 因为m代表数据量，近年来m越来越多，还有算力越来越强，所以AI就发展的特别快

## 课后作业

[https://github.com/AccumulateMore/CV/blob/main/306_%E8%AF%BE%E7%A8%8B1_%E7%AC%AC1%E5%91%A8_%E6%B5%8B%E9%AA%8C%E9%A2%98.ipynb](https://github.com/AccumulateMore/CV/blob/main/306_%E8%AF%BE%E7%A8%8B1_%E7%AC%AC1%E5%91%A8_%E6%B5%8B%E9%AA%8C%E9%A2%98.ipynb)

# 2. Basics of Neural Network programming

## 1. 二分类(Binary Classification)

### 1.1二分类的定义(Definition)

- 图片的x输入定义

> 图片输入特征:
>
> ![](https://pic.imgdb.cn/item/660f53ae68eb935713b9d5b0.png)
>
> 一张图片经典就是`三通道`，RGB矩阵，然后如果我们需要判断输出y是否是一只猫，需要将三通道合成一个`向量`,即Nx维的向量，`Nx=像素*像素*3`

### 1.2 ` 二分类的python代码演示(数组重组)`

```python
# 数组的重组，3D数组转换为向量
# This is a 3 by 3 by 2 array, typically images will be (num_px_x, num_px_y,3) where 3 represents the RGB values
image = np.array([[[ 0.67826139,  0.29380381],
        [ 0.90714982,  0.52835647],
        [ 0.4215251 ,  0.45017551]],

       [[ 0.92814219,  0.96677647],
        [ 0.85304703,  0.52351845],
        [ 0.19981397,  0.27417313]],

       [[ 0.60659855,  0.00533165],
        [ 0.10820313,  0.49978937],
        [ 0.34144279,  0.94630077]]])


def image2vector(image):
    v = image.reshape(image.shape[0] * image.shape[1], image.shape[2],1)
    return v

# 打印图像的(lenght , height, 3),也就是(lenght, height,2),2代表通道数量，
# 其实是3个通道，但是从1开始，默认从零开始
print(image.shape)

print("image2vector(image)" + str(image2vector(image)))

```

- 运行结果

```
(3, 3, 2)
image2vector(image)[[[0.67826139]
  [0.29380381]]

 [[0.90714982]
  [0.52835647]]

 [[0.4215251 ]
  [0.45017551]]

 [[0.92814219]
  [0.96677647]]

 [[0.85304703]
  [0.52351845]]

 [[0.19981397]
  [0.27417313]]

 [[0.60659855]
  [0.00533165]]

 [[0.10820313]
  [0.49978937]]

 [[0.34144279]
  [0.94630077]]]
```



- m个样本的输入定义

> ![](https://pic.imgdb.cn/item/660f556e68eb935713bce229.png)
>
> ![](https://pic.imgdb.cn/item/660f564668eb935713be61f9.png)
>
> X是`输入矩阵`，x(1) x(2)....x(m)代表`m张图片`，也就是`m个样本`,组成了`n(x) * m维`的矩阵
>
> Y是`输出矩阵`,y(1) y(2)...y(m)代表m个输出结果,Y是1*m维的矩阵

## 2. 逻辑回归的代价函数(Logistic Regression Cost Function)

- 代价函数定义

>![](https://pic.imgdb.cn/item/660fc49f68eb935713a1bbd9.png)

$$
代价函数\begin{cases}
 \hat{y} ^{(i)}是第x(i)个输入值的预测输出值\\
 \sigma  为Sigmoid激活函数，\sigma(z) =\frac{1}{1+e^{z}}  \\
{\color{Red}  w和b为预测模型所要找到的参数} \\
\end{cases}
$$

- 损失函数(单个样本)

$$
L(\hat{y}, y)=-y \log (\hat{y})-(1-y) \log (1-\hat{y})
$$

> 1. `尽量使得 yhat与y之间的差值最小`
>
> ![](https://pic.imgdb.cn/item/660fc7d068eb935713a7d688.png)

- 代价函数(全部训练样本)

$$
J(w, b)=\frac{1}{m} \sum_{i=1}^{m} L\left(\hat{y}^{(i)}, y^{(i)}\right)=\frac{1}{m} \sum_{i=1}^{m}\left(-y^{(i)} \log \hat{y}^{(i)}-\left(1-y^{(i)}\right) \log \left(1-\hat{y}^{(i)}\right)\right)
$$

> `训练逻辑回归模型的时候，需要找到合适的w和b，使得代价函数J的总代价降到最低`

## 3. 梯度下降法(Gradient Descent)

$$
Gradient Descent:

\begin{array}{l}
\text { Recap: } \hat{y}=\sigma\left(w^{T} x+b\right), \sigma(z)=\frac{1}{1+e^{-z}} \\
J(w, b)=\frac{1}{m} \sum_{i=1}^{m} \mathcal{L}\left(\hat{y}^{(i)}, y^{(i)}\right)=-\frac{1}{m} \sum_{=1}^{m} y^{(i)} \log \hat{y}^{(i)}+\left(1-y^{(i)}\right) \log \left(1-\hat{y}^{(i)}\right)
\end{array}
$$

### 3.1 梯度下降法(GD)的定义(Definition)

![img](https://img-blog.csdnimg.cn/e85b37d7db3b415d95c84c140bade375.png)

> 定义: 找到函数的局部极小值,`必须向函数上当前对应梯度的反方向的规定步长距离进行迭代搜索`
>
> 目的: `找到局部极小值或者全局极小值`

### 3.2 GD的原理

> 下山的人看作J(W),表示目标函数，目的地是最低点，而中间如何到达最低点则是需要解决的问题
>
> ![img](https://img-blog.csdnimg.cn/e28700e5449d41428dae3ff86cf817a8.png)
>
> 求解过程:在当前位置求偏导，即梯度，正常的梯度方向类似于上山的方向，是使值函数增大的，下山最快需使最小，从`负梯度`求最小值，这就是梯度下降。`梯度上升是直接求偏导，梯度下降则是梯度上升的负值`。由于不知道怎么下山，于是需要走一步算一步，继续求解当前位置的偏导数。这样一步步的走下去，当走到了最低点，此时我们能得到一个近似最优解
>
> 注意事项:
>
> 1. 梯度下降有时得到的是`局部最优解`，如果损失函数是`凸函数`，梯度下降法得到的解就是`全局最优解`。

### 3.3 GD的求解步骤

1. 如果损失函数为`一元函数`，`梯度`为该函数的`导数`

$$
\nabla f(x)=f^{\prime}(x)
$$

2. 如果为`二元函数`,梯度定义:

$$
\nabla f\left(x_{1}, x_{2}\right)=\frac{\partial y}{\partial x_{1}} i+\frac{\partial y}{\partial x_{2}} j
$$

3. 梯度下降公式:

$$
\theta_{i}=\theta_{i}-\alpha \frac{\partial J\left(\theta_{0}, \theta_{1}, \cdots, \theta_{n}\right)}{\partial \theta_{i}}
$$

> 求解步骤:
>
> ![](https://pic.imgdb.cn/item/660fd8be68eb935713c96740.png)

> `吴恩达版本解释:`
>
> 1. 当J(W)是一元函数的是时候,
>
> $$
> w:=w-a \frac{d J(w)}{d w}
> $$
>
> := 代表更新参数
> $$
> \alpha是控制步长的，即向下走一步的长度\frac{dJ(w)}{dw},就是函数J(w)对w求导
> $$
>
> 2. 当dJ(w)/dw > 0时候，向左逼近
>
> ![](https://pic.imgdb.cn/item/660fdae868eb935713cf779e.png)
>
> 2. 当dJ(w)/dw < 0时候，向右逼近
>
> ![](https://pic.imgdb.cn/item/660fdaf468eb935713cf908b.png)

### 3.4 GD的分类

> 1. 全梯度下降算法(FG)/批量梯度下降算法
>
> $$
> \theta=\theta-\eta \cdot \nabla_{\theta} J(\theta)
> $$
>
> `计算训练集所有样本误差，对其求和再取平均值作为目标函数`
>
> 
>
> 2. `随机梯度下降算法(SG)`
>
> $$
> \theta=\theta-\eta \cdot \nabla_{\theta} J\left(\theta ; x^{(i)} ; y^{(i)}\right)
> ;x^{i}为一条训练样本的特征值，y^{i}为一条训练样本的标签值
> $$
>
> `SG是FG的改进方案`;
>
> `FG`每迭代更新一次权重都需要计算所有样本误差,故`效率偏低`，且容易陷入局部最优解;
>
> SG:每轮计算的目标函数不再是全体样本误差，而仅是`单个样本误差`，即每次只代入计算一个样本目标函数的梯度来更新权重，再取下一个样本重复此过程，直到`损失函数值停止下降或损失函数值小于某个设定的阈值`。此过程简单，高效，通常可以较好地`避免更新迭代收敛到局部最优解`
>
> 
>
> 3. `小批量梯度下降法`
>
> $$
> \theta=\theta-\eta \cdot \nabla_{\theta} J\left(\theta ; x^{(i: i+ n)} ; y^{(i: i +n)}\right)x^{i:i+n}为小样本集的特征值，y^{i:i+n}为小样本集的标签值
> $$
>
> 小批量梯度下降算法是`FG和SG的折中方案`，在一定程度上兼顾了以上两种方法的优点。
>
> 每次从训练样本集上随机抽取一个`小样本集`，在抽出来的小样本集上采用`FG迭代`更新权重。被抽出的小样本集所含`样本点的个数称为batch_size`，通常设置为2的幂次方，更有利于GPU加速处理。特别的，若`batch_size=1，则变成了SG`；若`batch_size=n，则变成了FG`。

### 3.5 GD计算图定义(Definition)

> 1. 神经网络的计算，都是按照前向或反向传播过程组织的；
> 2. `前向过程: 计算出新的网络输出`
> 3. `反向传输: 计算对应的梯度或导数`

### 3.6 `GD 计算注意事项`

> 1. 由于我们需要计算dw1.....dwn 的导数值，并且需要针对m个样本进行计算
>    1. `多样本的时候dw1......dwn求解的时候，需要for循环进行求解，消耗过多时间`
>    2. 所以需要进行调用np的向量化工具  np.dot(s1,s2),`这个进行两个矩阵的点积运算`

![](https://pic.imgdb.cn/item/6615142e68eb9357133ce1c2.png)

```python
import numpy as np
import time
# 产生随机数
a = np.random.rand(100000) #通过 rand 随机得到两个一百万维度的数组
b = np.random.rand(100000)

tic = time.time() #测量一下现在时间
c = np.dot(a,b)
toc = time.time() # 测量当前时间

print(str((toc - tic)*1000) + "ms") # 打印消耗时间
```

## 4.  向量化的好处

### 4.1 for循环简化成向量化

> 你想计算向量𝑢 = 𝐴𝑣，这时矩阵乘法定义为，矩阵乘法的定义就是：𝑢𝑖 = ∑𝑗 𝐴ij𝑣𝑖 ，这取决于你怎么定义𝑢𝑖 值。
>
> 同样使用非向量化实现，𝑢 =𝑛𝑝. 𝑧𝑒𝑟𝑜𝑠(𝑛, 1)， 并且通过`两层循环𝑓𝑜𝑟(𝑖): 𝑓𝑜𝑟(𝑗)`:，得到`𝑢[𝑖] = 𝑢[𝑖] + 𝐴[i][j] ∗ 𝑣[𝑗] `。现在就有了𝑖 和 𝑗 的两层循环，这就是非向量化。
>
> `向量化方式就可以用𝑢 = 𝑛𝑝. 𝑑𝑜𝑡(𝐴, 𝑣)`，右边这种向量化实现方式，消除了两层循环使得代码运行速度更快。

### `4.2 向量化逻辑回归`(z = w^T * x + b的简化运算)

> ![](https://pic.imgdb.cn/item/66151aae68eb93571346490c.png)
>
> 1. `进行向量化的话，不需要进行for循环操作，能节省很多时间`
>
> $$
> [z^{(1)},z^{(2)},z^{(3)},....,z^{(m)}]=[w^{T}x^{(1)}+b,w^{T}x^{(2)}+b,.....w^{T}x^{(m)}+b]
> $$
>
> ​    z矩阵为1*m矩阵, x为 n * 1列向量,  w为1 * n行向量
>
> m为样本数    n为特征值数(例如n个像素值)  
>
> ```python
> z = np.dot(w.T,X) + b
> ```

### 4.3 dw，db和dz的向量化简化运算

> 1. 应用场景，前面提到,dw是各个样本的dw(i)累加起来的，`dw = dw(1)+dw(2) + ......+dw(n)，则需要for循环进行累加,但是这样会消耗时间`。
> 2. `所以我们需要将dw进行np的点积操作`
>
> ![](https://pic.imgdb.cn/item/66164d1b68eb93571340d8d9.png)
>
> 
>
> ![](https://pic.imgdb.cn/item/66164d7368eb935713423fa2.png)

### 4.4 `python的广播`

![](https://pic.imgdb.cn/item/6616516468eb935713511b89.png)

```python
# 演示python的广播技术
A = np.array([[56.0,0.0,4.4,68.0],
             [1.2,104.0,52.0,8.0],
             [1.8,135.0,99.0,0.9]])
print(A)
print(str("------------------------------------------------"))
cal = A.sum(axis=0)
print(cal)

print(str("------------------------------------------------"))
percentage = 100 * A / cal.reshape(1,4)
print(percentage)

B = np.array([100, 200, 300,400])

C = A + B # 广播技术
print(str("------------------------------------------------"))

print(C)


```

```python
[[ 56.    0.    4.4  68. ]
 [  1.2 104.   52.    8. ]
 [  1.8 135.   99.    0.9]]
------------------------------------------------
[ 59.  239.  155.4  76.9] #这里是A.sum(axis=0)的结果
------------------------------------------------
[[94.91525424  0.          2.83140283 88.42652796]
 [ 2.03389831 43.51464435 33.46203346 10.40312094]  #这里是100 * A / cal.reshape(1,4)的结果
 [ 3.05084746 56.48535565 63.70656371  1.17035111]]
------------------------------------------------
[[156.  200.  304.4 468. ]
 [101.2 304.  352.  408. ]   #体现了python的广播技术,[3,4]的矩阵 与 [1,4]的矩阵相加，得到[3,4]的矩阵
 [101.8 335.  399.  400.9]]
```

### 4.5 python 的numpy介绍

```python
a = np.random.randn(5)
print(a)

print(a.shape) # 显示a的列数

print(a.T) # a的转置

print(np.dot(a,a.T))

a = np.random.randn(5,1) #
print(a.shape) # 显示a的列数 和 行数
print(a)

print(a.T)

print(np.dot(a,a.T)) # 矩阵点积
```

```python
[-0.22343252 -0.42352862 -0.12695163  0.43828608 -1.88933865]
(5,)
[-0.22343252 -0.42352862 -0.12695163  0.43828608 -1.88933865]
4.00711051999369
(5, 1)
[[ 1.70172731]
 [ 1.27203578]
 [ 1.13277369]
 [-2.06694967]
 [-0.35722262]]
[[ 1.70172731  1.27203578  1.13277369 -2.06694967 -0.35722262]]
[[ 2.89587584  2.16465803  1.92767193 -3.5173847  -0.6078955 ]
 [ 2.16465803  1.61807504  1.44092867 -2.62923395 -0.45439996]
 [ 1.92767193  1.44092867  1.28317624 -2.34138621 -0.40465239]
 [-3.5173847  -2.62923395 -2.34138621  4.27228094  0.73836119]
 [-0.6078955  -0.45439996 -0.40465239  0.73836119  0.127608  ]]
```

## 5.  前向传播、反向传播(计算图过程)

目标：得到更接近你想要的输出o1,o2，即更准确地预测

过程：`固定的输入x1,x2..==>**通过反向传播不断更新权重**==>得到更接近你想要的输出o1,o2...`

![img](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9pbWFnZXMyMDE1LmNuYmxvZ3MuY29tL2Jsb2cvODUzNDY3LzIwMTYwNi84NTM0NjctMjAxNjA2MzAxNDE0NDk2NzEtMTA1ODY3Mjc3OC5wbmc?x-oss-process=image/format,png)

> 1. 第一层是输入层: 神经元i1 和 神经元 i2,截距项b1
> 2. 第二层是隐含层: 神经元h1和神经元h2,截距项b2
> 3. 第三层是输出层: 神经元o1和神经元o2
> 4. `每条线标的是wi是层与层之间连接的权重`
> 5. `激活函数默认为sigmoid函数`

![img](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9pbWFnZXMyMDE1LmNuYmxvZ3MuY29tL2Jsb2cvODUzNDY3LzIwMTYwNi84NTM0NjctMjAxNjA2MzAxNDIwMTkxNDAtNDAyMzYzMzE3LnBuZw?x-oss-process=image/format,png)

> 进行赋值

### 4.1 前向传播

> 1. 输入层----->隐含层------->输出层
>

### 4.2 反向传播

> 1. 计算总误差
> 2. 隐含层------>输出层的权值更新

![img](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9pbWFnZXMyMDE1LmNuYmxvZ3MuY29tL2Jsb2cvODUzNDY3LzIwMTYwNi84NTM0NjctMjAxNjA2MzAxNTIwMTg5MDYtMTUyNDMyNTgxMi5wbmc?x-oss-process=image/format,png)



### 4.3 前向传播和反向传播参考链接

[前向传播和反向传播]: https://blog.csdn.net/weixin_43135178/article/details/115294747





# 3. `神经网络思想实现Logisitic回归作业`吴恩达作业

## 3.1  逻辑回归学习算法一般步骤

> 1. 预处理数据集
>    1. 找出数据的尺寸和维度(m_train, m_test, num_px等)
>    2. 重塑数据集，以使每个示例都是大小为(num_px * num_px * 3, 1)的向量
>    3. `"标准化"数据`
> 2. 建立神经网络
>    1. 定义模型结构(输入的特征的数量)
>    2. 初始化模型的参数(initialize()函数)
>    3. 循环
>       1. 计算当前损失(正向传播)
>          1. ![](https://pic.imgdb.cn/item/6617e42168eb935713e7b9f2.png)
>       2. 计算当前梯度(反向传播)
>       3. 更新参数(梯度下降)，得到w和b参数
>          1. ![](https://pic.imgdb.cn/item/6617e48b68eb935713e8c048.png)
>    4. 用上述w和b参数预测数据集X的标签
>       1. ![](https://pic.imgdb.cn/item/6617e50b68eb935713e93a2c.png)

## 3.2 整体代码和数据集合

#### 3.2.1 模型代码

```python
'''
Author: Jean_Leung
Date: 2024-04-11 09:58:40
LastEditors: Jean_Leung
LastEditTime: 2024-04-11 20:40:56
FilePath: \Chap2\exercisepicture.py
Description: 

Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved. 
'''

import numpy as np
import h5py
import matplotlib.pyplot as plt
import scipy
import scipy.misc

from PIL import Image
from scipy import ndimage
from lr_utils import load_dataset


train_set_x_orig, train_set_y, test_set_x_orig, test_set_y, classes = load_dataset()

# index = 6
# plt.imshow(train_set_x_orig[index]) 
# print ("y = " + str(train_set_y[:, index]) + ", it's a '" + classes[np.squeeze(train_set_y[:, index])].decode("utf-8") +  "' picture.")



#----------------------------------------------------------------
# 第一部分，预处理数据
'''
description: 显示训练集和测试集合的数量
return {*}
'''
def show_train_set_test_set():
    m_train = train_set_x_orig.shape[0] # 训练集里图片的数量。
    m_test = test_set_x_orig.shape[0] # 测试集里图片的数量。
    num_px = train_set_x_orig.shape[1] # 训练集里图片的宽度
    num_py = test_set_x_orig.shape[1] # 测试集里图片的宽度

    print ("Number of training examples: m_train = " + str(m_train))

    print ("Number of testing examples: m_test = " + str(m_test))

    print ("Each image is of size: (" + str(num_px) + ", " + str(num_py) + ", 3)")

    print("train_set_x shape:" + str(train_set_x_orig.shape))

    # test_set_y_orig 为局部变量，返回赋给 train_set_y 了
    print("train_set_y shape: " + str(train_set_y.shape))
    print ("test_set_x shape: " + str(test_set_x_orig.shape))
    print ("test_set_y shape: " + str(test_set_y.shape))

'''
description: 将训练集的维度降低并转置。
            数组变为209行的矩阵（因为训练集里有209张图片），但是我懒得算列有多少，于是我就用-1告诉程序你帮我算，最后程序算出来时12288列。
            然后一个T转置一下
            数据标准化处理
return {*}
'''
def reshpe_dimensions():
    '''
    重塑数据集，以使每个示例都是大小为（num_px * num_px * 3，1）的向量
    返回 train_set_x 和 test_set_x矩阵
    '''
    # 1.先重塑数组
    train_set_x_flatten = train_set_x_orig.reshape(train_set_x_orig.shape[0],-1).T
    test_set_x_flatten = test_set_x_orig.reshape(test_set_x_orig.shape[0],-1).T
    print("训练集降维最后的维度: " + str(train_set_x_flatten.shape))
    print ("训练集_标签的维数: " + str(train_set_y.shape))
    print ("测试集降维之后的维度: " + str(test_set_x_flatten.shape))
    print ("测试集_标签的维数: " + str(test_set_y.shape))
    # 将降维度的数据集进行标准化处理，因为像素值是0~255之间，所以我们可以将所有所有数据除于255
    # 2.再将数据进行标准化处理
    train_set_x = train_set_x_flatten / 255 # 也就是标准化之后，所有的像素值位于0~1之间
    test_set_x = test_set_x_flatten / 255 
    return train_set_x, test_set_x

# 进行标准化
train_set_x,test_set_x = reshpe_dimensions()

'''
预处理过程:
        1.找出数据的尺寸和维度（m_train，m_test，num_px等）
        2.重塑数据集，以使每个示例都是大小为（num_px * num_px * 3，1）的向量
        3.“标准化”数据
'''
# show_train_set_test_set()
# reshpe_dimensions()


#----------------------------------------------------------------
# 第二部分，建立神经网络

#建立sigmoid()函数
'''
description:  激活函数
param {*} z
return {*}
'''
def sigmoid(z):
    s = 1 / (1 + np.exp(-z))
    return s

# 参数初始化函数
'''
description: 
           此函数为w创建一个维度为（dim，1）的0向量，并将b初始化为0。
        
        参数：
            dim  - 我们想要的w矢量的大小（或者这种情况下的参数数量）
        
        返回：
            w  - 维度为（dim，1）的初始化向量。
            b  - 初始化的标量（对应于偏差）
param {*} dim
return {*}
'''
def initialize_with_zeros(dim):
    """
    This function creates a vector of zeros of shape (dim, 1) for w and initializes b to 0.
    
    Argument:
    dim -- size of the w vector we want (or number of parameters in this case)
    
    Returns:
    w -- initialized vector of shape (dim, 1)
    b -- initialized scalar (corresponds to the bias)
    """
    
    w = np.zeros((dim, 1))
    b = 0
    # w 的维度是(dim, 1)
    # 使用断言来确保我要的数据是正确的
    assert(w.shape == (dim, 1))
    # b的类型是float 或者是int
    assert(isinstance(b, float) or isinstance(b, int))
    
    return w, b

#测试 初始化函数
# dim = 2

# w, b = initialize_with_zeros(dim)

# print ("w = " + str(w))
# print(w.shape)

# print ("b = " + str(b))

'''
description: 计算w导数 和 b导数
param {*} w
param {*} b
param {*} X
param {*} Y
return {*}
'''
def propagate(w,b,X,Y):
    """
    实现前向和后向传播的传播函数，计算成本函数及其梯度。
    参数：
        w  - 权重，大小不等的数组（num_px * num_px * 3，1）
        b  - 偏差，一个标量
        X  - 矩阵类型为（num_px * num_px * 3，训练数量）
        Y  - 真正的“标签”矢量（如果非猫则为0，如果是猫则为1），矩阵维度为(1,训练数据数量),即y(i)

    返回：
        cost- 逻辑回归的负对数似然成本
        dw  - 相对于w的损失梯度，因此与w相同的形状
        db  - 相对于b的损失梯度，因此与b的形状相同
    """
    m = X.shape[1] # 训练数据数量
    # 计算z
    z = np.dot(w.T, X) + b
    # 计算激活函数
    A = sigmoid(z)
    # 计算损失函数
    cost = -1 / m * np.sum(Y * np.log(A) + (1 - Y) * np.log(1 - A))
    # 计算梯度
    dw = 1 / m * np.dot(X, (A - Y).T)
    db = 1 / m * np.sum(A - Y)
    #使用断言确保我的数据是正确的
    assert(dw.shape == w.shape)
    assert(db.dtype == float)
    cost = np.squeeze(cost)
    assert(cost.shape == ())
    # 第一步: 计算A,也就是z
    # 正向传播
    # 计算激活函数
    A = sigmoid(np.dot(w.T, X) + b)
    # 第二步: 计算损失函数
    cost = -1 / m * np.sum(Y * np.log(A) + (1 - Y)* np.log(1 - A)) # 这个就是损失函数J
    
    # 第三步: 计算梯度，反向传播
    # 计算梯度
    dw = 1 / m * np.dot(X, (A - Y).T)
    db = 1 / m * np.sum(A - Y)
    #使用断言确保我的数据是正确的
    assert(dw.shape == w.shape)
    assert(db.dtype == float)
    cost = np.squeeze(cost)
    assert(cost.shape == ())
    # 第四步: 返回梯度
    grads = {"dw": dw,
             "db": db}
    return grads, cost

# print("-------------测试propagate---------------")
# # w 为权重值序列 w 为2 维列向量 b为2 X为2维*2维矩阵    Y为2维行向量
# w,b,X,Y = np.array([[1],[2]]),2,np.array([[1,2],[3,4]]),np.array([[1,0]])

# grads, cost = propagate(w,b,X,Y)
# print("dw = " + str(grads["dw"]))
# print("dw = " + str(grads["db"]))
# print("cost = " + str(cost))

# print(w.shape)
# print(b)
# print(X.shape)
# print(Y.shape)

def optimize(w, b, X, Y, num_iterations, learning_rate, print_cost = False):
    """
    此函数通过运行梯度下降算法来优化w和b
    参数：
        w  - 权重，大小不等的数组（num_px * num_px * 3，1）
        b  - 偏差，一个标量
        X  - 维度为（num_px * num_px * 3，训练数据的数量）的数组。
        Y  - 真正的“标签”矢量（如果非猫则为0，如果是猫则为1），矩阵维度为(1,训练数据的数量)
        num_iterations  - 优化循环的迭代次数
        learning_rate  - 梯度下降更新规则的学习率
        print_cost  - 每100步打印一次损失值
    
    返回：
        params  - 包含权重w和偏差b的字典
        grads  - 包含权重和偏差相对于成本函数的梯度的字典
        成本 - 优化期间计算的所有成本列表，将用于绘制学习曲线。
    
    提示：
    我们需要写下两个步骤并遍历它们：
        1）计算当前参数的成本和梯度，使用propagate（）。
        2）使用w和b的梯度下降法则更新参数。
    """
    costs = []
    
    for i in range(num_iterations):
        grads, cost = propagate(w, b, X, Y)
        # 使用w和b的梯度下降法则更新参数
        w = w - learning_rate * grads["dw"]
        b = b - learning_rate * grads["db"]
        # 打印成本
        if i % 100 == 0:
            costs.append(cost)
            # 打印成本
        if print_cost and i % 100 == 0:
            print ("Cost after iteration %i: %f" %(i, cost))
    
    params = {"w": w,
              "b": b}
    
    grads = {"dw": grads["dw"],
             "db": grads["db"]}
    
    return params, grads, costs


# print("---------------optimize测试-----------------")

# w, b, X, Y = np.array([[1],[2]]),2,np.array([[1,2],[3,4]]),np.array([[1,0]])

# params, grads, costs = optimize(w, b, X, Y, num_iterations = 1500, learning_rate = 0.5, print_cost = False)

# print("w = " + str(params["w"]))

# print("b = " + str(params["b"]))

# print("X = " + str(X))

# print("Y = " + str(Y))

# print("costs = " + str(costs))

# print("dw = " + str(grads["dw"]))

# print("db = " + str(grads["db"]))
# print(costs)

def predict(w,b,X):
    '''
    预测函数
    参数：
        w  - 权重，大小不等的数组（num_px * num_px * 3，1）
        b  - 偏差，一个标量
        X  - 维度为（num_px * num_px * 3，训练数据的数量）的数组。
    
    返回：
        Y_prediction  - 预测结果，一个向量（1维）
    '''
    # m为样本数量(图片数量)
    m = X.shape[1]
    Y_prediction = np.zeros((1,m))
    w = w.reshape(X.shape[0],1)
    # 预测猫在图片中出现的概率
    A = sigmoid(np.dot(w.T, X) + b)

    for i in range(A.shape[1]):
        # 将概率 a[0，i] 转换为实际预测 p[0，i]
        if A[0,i] > 0.5:
            Y_prediction[0,i] = 1
        else:
            Y_prediction[0,i] = 0
    # 使用断言
    assert(Y_prediction.shape == (1,m)) # m维行向量
    return Y_prediction


# print("---------------predict测试-----------------")

# w, b, X, Y = np.array([[1],[2]]),2,np.array([[1,2],[3,4]]),np.array([[1,0]])

# print("prediction" + str(predict(w,b,X)))


def model(X_train, Y_train, X_test,Y_test,num_iterations = 2000, learning_rate = 0.5, print_cost = False):
    """
    通过调用之前实现的函数来构建逻辑回归模型
    
    参数：
        X_train  - numpy的数组,维度为（num_px * num_px * 3，m_train）的训练集
        Y_train  - numpy的数组,维度为（1，m_train）（矢量）的训练标签集
        X_test   - numpy的数组,维度为（num_px * num_px * 3，m_test）的测试集
        Y_test   - numpy的数组,维度为（1，m_test）的（向量）的测试标签集
        num_iterations  - 表示用于优化参数的迭代次数的超参数
        learning_rate  - 表示optimize（）更新规则中使用的学习速率的超参数
        print_cost  - 设置为true以每100次迭代打印成本
    
    返回：
        d  - 包含有关模型信息的字典。
    """
    # 第一步初始化参数w和b,就是以训练集的维度构建
    w,b = initialize_with_zeros(X_train.shape[0])

    # 第二步 进行optimese算出w和b,梯度下降，就是算出w和b，已经更新完后
    params, grads, costs = optimize(w, b, X_train, Y_train, num_iterations, learning_rate, print_cost)
    # 从“parameters”字典中检索参数w和b
    w = params["w"]
    b = params["b"]
    # 预测测试/训练集的例子
    Y_prediction_test = predict(w,b,X_test)
    Y_prediction_train = predict(w,b,X_train)

    # 打印训练后的准确性
    print("train accuracy: {} %".format(100 - np.mean(np.abs(Y_prediction_train - Y_train)) * 100))
    print("test accuracy: {} %".format(100 - np.mean(np.abs(Y_prediction_test - Y_test)) * 100))
    # 字典集合
    d = {"costs": costs,
         "Y_prediction_test": Y_prediction_test, 
         "Y_prediction_train" : Y_prediction_train, 
         "w" : w, 
         "b" : b,
         "learning_rate" : learning_rate,
         "num_iterations": num_iterations}
    return d

print("-------------------测试model---------------")
# 加载数据集里面的真实的数据
d = model(train_set_x,train_set_y,test_set_x,test_set_y,num_iterations = 2000, learning_rate = 0.005, print_cost = True)

num_px = train_set_x_orig.shape[1]    # 训练集里图片的宽度
num_py = train_set_x_orig.shape[2]    # 训练集里图片的宽度


index = 26
plt.imshow(test_set_x[:,index].reshape((num_px, num_px, 3)))
print ("y = " + str(test_set_y[0,index]) + ", you predicted that it is a \"" + classes[int(d["Y_prediction_test"][0,index])].decode("utf-8") +  "\" picture.")
plt.show()

costs = np.squeeze(d['costs'])
plt.plot(costs)
plt.ylabel('cost')
plt.xlabel('iterations (per hundreds)')
plt.title("Learning rate =" + str(d["learning_rate"]))
plt.show()
```

#### 3.2.2 数据集代码

```python
'''
Author: Jean_Leung
Date: 2024-04-11 10:29:38
LastEditors: Jean_Leung
LastEditTime: 2024-04-11 15:03:15
FilePath: \Chap2\lr_utils.py
Description: 

Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved. 
'''
import numpy as np
import h5py
    
    
def load_dataset():
    train_dataset = h5py.File('D:/Learning/Deep learning/pythoncode/Chap2/datasets/train_catvnoncat.h5', "r")
    train_set_x_orig = np.array(train_dataset["train_set_x"][:]) # your train set features
    train_set_y_orig = np.array(train_dataset["train_set_y"][:]) # your train set labels

    test_dataset = h5py.File('D:/Learning/Deep learning/pythoncode/Chap2/datasets/test_catvnoncat.h5', "r")
    test_set_x_orig = np.array(test_dataset["test_set_x"][:]) # your test set features
    test_set_y_orig = np.array(test_dataset["test_set_y"][:]) # your test set labels

    classes = np.array(test_dataset["list_classes"][:]) # the list of classes
    
    train_set_y_orig = train_set_y_orig.reshape((1, train_set_y_orig.shape[0]))
    test_set_y_orig = test_set_y_orig.reshape((1, test_set_y_orig.shape[0]))
    
    return train_set_x_orig, train_set_y_orig, test_set_x_orig, test_set_y_orig, classes
```



#### 3.2.3 结构分布

![](https://pic.imgdb.cn/item/6617e67168eb935713ea622d.png)

#### 3.2.4 运行结果

![](https://pic.imgdb.cn/item/6617e6d568eb935713eb0f7e.png)

![](https://pic.imgdb.cn/item/6617e6e468eb935713eb2ab4.png)