# 1.数据操作、数据预处理

## 1.1 张量的广播机制

> 广播机制:
>
> 1. 通过适当复制元素来扩展一个或两个数组，以便在转换之后，两个张量具有相同的形状；
> 2. 对生成的数组执行按元素操作。

```python
a = torch.arange(3).reshape((3, 1))
b = torch.arange(2).reshape((1, 2))
print(a)
print(b)
print(a + b)
```

```
(tensor([[0],
         [1],
         [2]]),
         
 tensor([[0, 1]]))
 
 tensor([[0, 1],
        [1, 2],
        [2, 3]])
```

## 1.2 矩阵的Sum操作

> 当矩阵为多维矩阵时候，假设矩阵为(2,5,4)即两个[5,4]矩阵
>
> axis=0的时候，那么运算后矩阵为(5,4)
>
> axis = 1的时候, 那么运算后矩阵为(2,4)
>
> axis = 2的时候，那么运算后矩阵为(2,5)
>
> ![](https://pic.superbed.cc/item/66af4879fcada11d3790066d.png)

```python
# 矩阵某轴求和(维度丢失)
# ① 指定张量沿哪一个轴来通过求和降低维度。
A = torch.arange(20*2).reshape(2,5,4)

print(A)
A_sum_axis0 = A.sum(axis=0) # (2,5,4) 对第一个维度进行求和，剩下两个维度留下来了,那么就是剩下(5,4)的矩阵
print(A_sum_axis0)
print(A_sum_axis0.shape)

A_sum_axis1 = A.sum(axis=1) # (2,5,4) 对第二个维度进行求和，剩下两个维度留下来了，那么剩下(2,4)矩阵
print(A_sum_axis1)
print(A_sum_axis1.shape)

A_sum_axis2 = A.sum(axis=2) # (2,5,4) 对第三个维度进行求和，��下一个维度留下来了,那么剩下(2,5)矩阵
print(A_sum_axis2)
print(A_sum_axis2.shape)

A_sum_axis1 = A.sum([0,1]) # (2,5,4) 对第一、二个维度进行求和，剩下一个维度留下来了    
print(A_sum_axis1)
print(A_sum_axis1.shape)
```

```
tensor([[[ 0,  1,  2,  3],
         [ 4,  5,  6,  7],
         [ 8,  9, 10, 11],
         [12, 13, 14, 15],
         [16, 17, 18, 19]],

        [[20, 21, 22, 23],
         [24, 25, 26, 27],
         [28, 29, 30, 31],
         [32, 33, 34, 35],
         [36, 37, 38, 39]]])
tensor([[20, 22, 24, 26],
        [28, 30, 32, 34],
        [36, 38, 40, 42],
        [44, 46, 48, 50],
        [52, 54, 56, 58]])
torch.Size([5, 4])
tensor([[ 40,  45,  50,  55],
        [140, 145, 150, 155]])
torch.Size([2, 4])
tensor([[  6,  22,  38,  54,  70],
        [ 86, 102, 118, 134, 150]])
torch.Size([2, 5])
tensor([180, 190, 200, 210])
torch.Size([4])
```

# 2.线性回归模型

## 2.1 线性回归

> 按照batch_size返回
>
> 

### 2.1.1 小批量随机算法

```python
'''
Author: Jean_Leung
Date: 2024-08-07 16:45:46
LastEditors: Jean_Leung
LastEditTime: 2024-08-07 16:47:45
FilePath: \LinearModel\Linearexercise.py
Description: 李沐学ai 线性回归、优化算法学习

Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved. 
'''
import random
import torch
from d2l import torch as d2l


# 定义一个函数来生成模拟数据集
# 生成数据集

def synthetic_data(w,b,num_examples):
    """生成 y = Xw + b + 噪声"""
    X = torch.normal(0,1,(num_examples,len(w))) # 均值为0，标准差为1,且size为(num_examples,len(w))的X张量
    y = torch.matmul(X,w) + b # torch.matmul()是矩阵乘法 利用广播机制
    print("y.shape:",y.shape)
    y += torch.normal(0,0.01,y.shape)  # 加入高斯噪声 # 均值为0，标准差为0.01，size为y.shape的向量
    return X, y.reshape((-1,1))

true_w = torch.tensor([2,-3.4])
true_b = 4.2
features, labels = synthetic_data(true_w,true_b,1000) # X的size为(1000,2), y的size为(1000,1)

# print("features:",features[0],"labels:",labels[0])
# print("features:",features[:,1])
d2l.set_figsize() #  Set the figure size for matplotlib.
# # scatter(x, y, s=None, c=None, marker=None, cmap=None, norm=None, vmin=None, vmax=None, alpha=None, linewidths=None, verts=<deprecated parameter>, edgecolors=None, *, plotnonfinite=False, data=None, **kwargs)
# x 为x轴，y为y轴，只有detach后才能转到numpy里面去
d2l.plt.scatter(features[:,1].detach().numpy(),labels.detach().numpy(),1) # 将features的第二列所有数据先detach()后numpy化, labels的数据同样操作 
d2l.plt.show()


# print("features.size",features.shape)
# print("labels.size",labels.shape)

# 读取小批量
# 随机批量梯度算法

# data_iter函数接收批量大小、特征矩阵和标签向量作为输入，生成大小为batch_size的小批量
# 生成batch_size大小的随机小批量数据
def data_iter(batch_size, features, labels):
    # 先将序列号确定
    # indices = torch.randperm(features.shape[0]) # 随机将0到features.shape[0] - 1的数打乱
    num_examples = len(features) # 样本个数
    indices = list(range(num_examples)) # 0到nnum_examples - 1的数
    # print(indices[:]) # 从0~999的索引号
    random.shuffle(indices) # 随机打乱 indices
    # print(indices[:])
    # 然后将打乱的序列号分为多个batch
    for i in range(0,num_examples, batch_size):
        # print("i:",i)
        # indices里面索引号还是0~999，但是索引号对应的空间放的是随机数0~999
        batch_indices = torch.tensor(indices[i:min(i+batch_size,num_examples)]) # 当i+batch_size超出时，取num_examples
        # print(batch_indices)
        yield features[batch_indices], labels[batch_indices] # yield可以暂时理解为return，但是下次继续执行该函数时候，从未完成开始

batch_size = 10

# 读取并打印第一个小批量
for X, y in data_iter(batch_size, features, labels):
    print("X:", X, "\ny:", y)
    break


# 定义初始化模型参数
# w初始化为均值0，标准差0.01，大小为(2,1)的列向量,可以放置梯度
w = torch.normal(0,0.01,size=(2,1),requires_grad=True)
# b初始化为0的标量，也可以放置梯度
b = torch.zeros(1,requires_grad=True)

# 完整训练模型
# 损失函数
def squared_loss(y_hat,y):
    return (y_hat - y.reshape(y_hat.shape))**2 / 2 # 将y统一成与y_hat一样同尺寸 

# 线性回归方程组
# 定义模型
def linreg(X,w,b):
    """线性回归模型"""
    return torch.matmul(X,w)+b

# 定义优化w的算法
# sgd是 随机小批量梯度下降
def sgd(params,lr,batch_size):
    """小批量随即梯度下降"""
    with torch.no_grad(): # 不产生梯度计算，减少内存消耗
            for param in params: # 遍历每个参数
                param -= lr * param.grad / batch_size # 将进行梯度下降
                param.grad.zero_() # 进行梯度清零，方便下次计算，不让这次梯度影响下次梯度


# 定义训练函数
def train(features, labels, batch_size, lr, num_epochs):
    """线性回归模型的训练"""
    # w,b = w.clone().detach(), b.clone().detach() # 克��w和b，并detach()，让w和b不参与梯度度计算
    # print("w.grad:",w.grad)
    # print("b.grad:",b.grad)
    for epoch in range(num_epochs):
        for X, y in data_iter(batch_size, features, labels):
            # linreg是y_hat的值，也就是预估值，y是真实值，y从data_iter中随机生成出来，模拟真实数据
            l = squared_loss(linreg(X, w, b), y) # 计算x和y的小批量损失
            # print(X[:])
            # 因为l是形状是(batch_size,1)，而不是一个标量。l中所有元素被加到一起
            # 并以此计算关于[w,b]的梯度
            l.sum().backward() # 反向传播
            sgd([w, b], lr, batch_size) # 随机小批量度下降，使用参数更新梯度
        with torch.no_grad(): # 这个是如果不计算梯度下降的时候
            # 这个不是随机小批量数据进行运算，直接1000个数据进行计算
            train_l = squared_loss(linreg(features,w,b),labels)
            # print(train_l[:])
            print(f'epoch{epoch+1},loss{float(train_l.mean()):f}')
            # print(f"epoch {epoch+1}, loss {l.item():f}") 
    # 比较真实参数和通过训练学到的参数来评估训练的成功程度
    # true_w是提前设定的w参数
    print(f'w的估计误差：{true_w-w.reshape(true_w.shape)}')
    print(f'b的估计误差：{true_b-b}')

# 开始训练

train(features, labels, batch_size, lr=0.03, num_epochs=3)


```



## 2.2 Softmax回归

### 2.2.1 回归 vs 分类

> 1. 回归估计一个连续值
> 2. 分类预测一个离散类别

### 2.2.2 交叉熵函数

# 3. 多层感知机(多层神经网络)

## 3.1 隐藏层(MLP)

> 单隐藏层的多层感知机，hidden layer就是隐藏层的代表

![](https://pic.superbed.cc/item/66c49965fcada11d378734c3.png)

## 3.2 线性-非线性

### 3.2.1 线性模型

> 如果不加激活函数，那么整个模型都是线性的

$$
\begin{array}{l}
\mathbf{H}=\mathbf{X} \mathbf{W}^{(1)}+\mathbf{b}^{(1)},\mathbf{X}\in R^{n\times d}代表n个小批量,\mathbf{W}^{(1)} \in \mathbb{R}^{d \times h}则\mathbf{H} \in \mathbb{R}^{n \times h}\\
\mathbf{O}=\mathbf{H} \mathbf{W}^{(2)}+\mathbf{b}^{(2)},\mathbf{W}^{(2)} \in \mathbb{R}^{h \times q}, \mathbf{O} \in \mathbb{R}^{n \times q} \\
\mathbf{O}=\left(\mathbf{X} \mathbf{W}^{(1)}+\mathbf{b}^{(1)}\right) \mathbf{W}^{(2)}+\mathbf{b}^{(2)}=\mathbf{X} \mathbf{W}^{(1)} \mathbf{W}^{(2)}+\mathbf{b}^{(1)} \mathbf{W}^{(2)}+\mathbf{b}^{(2)}=\mathbf{X} \mathbf{W}+\mathbf{b} .
\end{array}
$$

### 3.2.2 非线性模型

> 如果加了`激活函数`，那么则会个那个模型就变成非线性

$$
\begin{array}{l}
\mathbf{H}=\sigma\left(\mathbf{X} \mathbf{W}^{(1)}+\mathbf{b}^{(1)}\right) \\
\mathbf{O}=\mathbf{H W}^{(2)}+\mathbf{b}^{(2)}\\
\mathbf{H}^{(1)}=\sigma_{1}\left(\mathbf{X} \mathbf{W}^{(1)}+\mathbf{b}^{(1)}\right) \text { 和 } \mathbf{H}^{(2)}=\sigma_{2}\left(\mathbf{H}^{(1)} \mathbf{W}^{(2)}+\mathbf{b}^{(2)}\right)
\end{array}
$$

### 3.2.3 激活函数

#### 3.2.3.1 ReLU函数(线性整流单元)

> 通过将相应的激活值设为0来仅保留正元素丢弃所有负元素

$$
\operatorname{ReLU}(x)=\max (x, 0)
$$

![](https://pic.superbed.cc/item/66c4a492fcada11d37876aa4.png)

> 选择ReLU原因,使得求导表现特别好,要么让参数消失，要么参数通过并且ReLU减轻了困扰

#### 3.2.3.2 pReLU函数

> 原函数

![](https://pic.superbed.cc/item/66c4af83fcada11d3787a4f0.png)

```python
'''
Author: Jean_Leung
Date: 2024-08-20 22:37:05
LastEditors: Jean_Leung
LastEditTime: 2024-08-20 22:54:51
FilePath: \LinearModel\net\activation_function.py
Description: 

Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved. 
'''
import torch
from d2l import torch as d2l

x = torch.arange(-8.0, 8.0, 0.1, requires_grad=True)
alpha = torch.range(0.025,0.025,0.1,requires_grad=True)
# print("alpha: ",alpha) # 打印出来的是张量tensor类型
# alpha = torch.arange()
y = torch.prelu(x,alpha)
d2l.plot(x.detach(),y.detach(),x.grad,'x','prelu(x)',figsize=(5,2.5))
d2l.plt.show()

# 接下来是prelu导函数
y.backward(torch.ones_like(x),retain_graph=True)
d2l.plot(x.detach(),x.grad,'x','grad of prelu(x)',figsize=(5,2.5))
d2l.plt.show()
```

$$
\operatorname{pReLU}(x)=\max (0, x)+\alpha \min (0, x)
$$

> 导函数

$$
\frac{d}{d x} pReLU(x) = \frac{d}{d x}(\max (0, x)+\alpha \min (0, x))=\frac{\partial \max (x, 0)}{\partial x} + \frac{\partial \min (x, 0)}{\partial x} =\left\{\begin{array}{ll}
1 & \text { if } x>0 \\
\alpha  & \text { if } x<0 
\end{array}\right.
$$

![](https://pic.superbed.cc/item/66c5629efcada11d378af8c6.png)

#### 3.2.3.3 sigmoid函数

> 原函数

$$
\operatorname{sigmoid}(x)=\frac{1}{1+\exp (-x)}
$$

![](https://pic.superbed.cc/item/66c4a75ffcada11d37877677.png)

> 导数

$$
\begin{array}{l}
\text { sigmoid函数的导数为下面的公式: }\\
\frac{d}{d x} \operatorname{sigmoid}(x)=\frac{\exp (-x)}{(1+\exp (-x))^{2}}=\operatorname{sigmoid}(x)(1-\operatorname{sigmoid}(x))\\

\end{array}
$$

![](https://pic.superbed.cc/item/66c4a83bfcada11d37877ab6.png)

#### 3.2.3.4 tanh函数(双曲正切函数)

> 原函数

$$
\tanh (x)=\frac{1-\exp (-2 x)}{1+\exp (-2 x)}
$$

![](https://pic.superbed.cc/item/66c4a8b6fcada11d37877c84.png)

> 导函数

$$
\frac{d}{d x} \tanh (x)=1-\tanh ^{2}(x)
$$

![](https://pic.superbed.cc/item/66c4a927fcada11d37877e18.png)

#### 3.2.3.5 练习题目

> 1. 计算pReLU激活函数的导数
>
> 见上文pReLU函数

> 2. 证明⼀个仅使⽤ReLU（或pReLU）的多层感知机构造了⼀个连续的分段线性函数。
>
> 不理解什么意思

> 3. 证明tanh(x) + 1 = 2 sigmoid(2x)

![](https://pic.superbed.cc/item/66c5725ffcada11d378b66ba.png)

```python
import torch
from d2l import torch as d2l

x = torch.arange(-8.0, 8.0, 0.1, requires_grad=True)

# alpha = torch.range(0.025,0.025,0.1,requires_grad=True)
# # print("alpha: ",alpha) # 打印出来的是张量tensor类型
# # alpha = torch.arange()
# y = torch.prelu(x,alpha)
# d2l.plot(x.detach(),y.detach(),x.grad,'x','prelu(x)',figsize=(5,2.5))
# d2l.plt.show()

# # 接下来是prelu导函数
# y.backward(torch.ones_like(x),retain_graph=True)
# d2l.plot(x.detach(),x.grad,'x','grad of prelu(x)',figsize=(5,2.5))
# d2l.plt.show()

# 接下来是tanh导函数
# tanh(x) + 1
y = torch.tanh(x) + 1
d2l.plt.subplot(1,2,1)
d2l.plot(x.detach(),y.detach(),x.grad,'x','tanh(x)',figsize=(5,2.5))
d2l.plt.title('tanh(x) + 1')
# 接下来是2*sigmoid(2x)导函数
y = 2 * torch.sigmoid(2 * x)
d2l.plt.subplot(1,2,2)
d2l.plot(x.detach(),y.detach(),x.grad,'x','2 * sigmoid(2x)',figsize=(5,2.5))
d2l.plt.title('2 * sigmoid(2x)')
d2l.plt.show()
```

$$
\begin{array}{l}
\begin{aligned}
& \tanh (\mathrm{x})=\frac{1-\exp (-2 \mathrm{x})}{1+\exp (-2 \mathrm{x})}, \quad \text { sigmoid }=\frac{1}{1+\exp (-x)} \\
& \tanh (\mathrm{x})+1=\frac{2}{1+\exp (-2 \mathrm{x})} \\
2 & \operatorname{sigmoid}(2 \mathrm{x})=\frac{2}{1+\exp (-2 \mathrm{x})} \\
\therefore & \tanh (\mathrm{x})+1=2 \operatorname{sigmoid}(2 \mathrm{x})
\end{aligned}
\end{array}
$$

> 4. 假设我们有⼀个⾮线性单元，将它⼀次应⽤于⼀个小批量的数据。你认为这会导致什么样的问题?
>
> ----------不确定，稍作以后解答

### 3.2.4 多层感知机的简洁实现

![](https://pic.superbed.cc/item/66c5b2d0fcada11d3793d220.png)

#### 3.2.4.1 自定义实现

```python
'''
                       _oo0oo_
                      o8888888o
                      88" . "88
                      (| -_- |)
                      0\  =  /0
                    ___/`---'\___
                  .' \\|     |// '.
                 / \\|||  :  |||// \
                / _||||| -:- |||||- \
               |   | \\\  - /// |   |
               | \_|  ''\---/''  |_/ |
               \  .-\__  '-'  ___/-. /
             ___'. .'  /--.--\  `. .'___
          ."" '<  `.___\_<|>_/___.' >' "".
         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
         \  \ `_.   \_ __\ /__ _/   .-` /  /
     =====`-.____`.___ \_____/___.-`___.-'=====
                       `=---='


     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

           佛祖保佑     永不宕机     永无BUG
'''
'''
Author: Jean_Leung
Date: 2024-08-21 13:01:07
LastEditors: Jean_Leung
LastEditTime: 2024-08-21 13:01:19
FilePath: \LinearModel\net\multilayer_perceptron.py
Description: 多层感知机从零开始,自定义多层感知机

Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved. 
'''
import torch
from torch import nn
from d2l import torch as d2l
batch_size = 256
# 加载数据集合
train_iter, test_iter = d2l.load_data_fashion_mnist(batch_size)

# 定义图片输入参数, 每张图片都是28*28的灰度像素组成，所有图片分为10个类别
# 隐藏层单元有256个,通常定义2的幂次方
num_inputs, num_outputs, num_hiddens = 784, 10, 256
# 定义W1的维度为 784 * 256
W1 = nn.Parameter(torch.randn(num_inputs,num_hiddens,requires_grad=True))
# 定义b1的维度为 256 
b1 = nn.Parameter(torch.zeros(num_hiddens,requires_grad=True))
# 定义W1的维度为 256*10
W2 = nn.Parameter(torch.randn(num_hiddens,num_outputs,requires_grad=True))
# 定义W1的维度为 10
b2 = nn.Parameter(torch.zeros(num_outputs,requires_grad=True))

# 定义多层感知机
params = [W1,b1,W2,b2]

# 定义激活函数RELU函数
def relu(X):
    a = torch.zeros_like(X) # 返回一个和X同个维度的0矩阵
    return torch.max(X,a)

# 定义最简单单层隐藏层模型
def net(X):
    X = X.reshape(-1, num_inputs) # 展平每张图片
    H = relu(torch.matmul(X, W1) + b1) # 隐藏层
    return torch.matmul(H, W2) + b2 # 输出层

loss = nn.CrossEntropyLoss()

num_epochs, lr = 30, 0.1
updater = torch.optim.SGD(params, lr=lr)
d2l.train_ch3(net, train_iter, test_iter, loss, num_epochs, updater)
d2l.plt.show()
```

##### 练习题目

> 1. 在所有其他参数保持不变的情况下，更改超参数num_hiddens的值，并查看此超参数的变化对结果有
>    何影响。确定此超参数的最佳值。

![](https://pic.superbed.cc/item/66c5b557fcada11d3794facc.png)

> 2. 尝试添加更多的隐藏层，并查看它对结果有何影响。

`这个是双层隐藏层，256，64`

![](https://pic.superbed.cc/item/66c6ea98fcada11d37ab0a28.png)

`这个是单层隐藏层，256`

![](https://pic.superbed.cc/item/66c6ece8fcada11d37ab2907.png)

> 3. 改变学习速率会如何影响结果？保持模型结构和其他超参数(包括迭代周期数)不变，学习率设置为多少
>    会带来最好的结果？

`这个是学习速率为0.3的结果图`

![](https://pic.superbed.cc/item/66c6ee0cfcada11d37ab341f.png)



#### 3.2.4.2框架实现

```python
'''
Author: Jean_Leung
Date: 2024-08-21 16:56:51
LastEditors: Jean_Leung
LastEditTime: 2024-08-21 17:02:22
FilePath: \LinearModel\net\multilayer_perceptron2.py
Description: 多层感知机使用框架

Copyright (c) 2024 by ${robotlive limit}, All Rights Reserved. 
'''
import torch
from torch import nn
from d2l import torch as d2l

net = nn.Sequential(nn.Flatten(),nn.Linear(784,256),nn.ReLU(),nn.Linear(256,10))

# 初始化权重
def init_weights(m):
    if type(m) == nn.Linear:
        nn.init.normal_(m.weight, std=0.01)

net.apply(init_weights)


batch_size, lr, num_epochs = 256,0.1,10

loss = nn.CrossEntropyLoss()

trainer = torch.optim.SGD(net.parameters(),lr=lr)

train_iter, test_iter = d2l.load_data_fashion_mnist(batch_size)

d2l.train_ch3(net, train_iter, test_iter, loss, num_epochs, trainer)

```

##### 练习题目

>  1.尝试添加不同数量的隐藏层（也可以修改学习率）。怎么样设置效果最好？





>2. 尝试不同的激活函数。哪个效果最好？

`这个是Relu函数`

![](https://pic.superbed.cc/item/66c6f1a5fcada11d37ab692e.png)

`这个是sigmoid函数`

![](https://pic.superbed.cc/item/66c6f2befcada11d37ab7200.png)

`这个是tanh函数`

![](https://pic.superbed.cc/item/66c6f3abfcada11d37ab7771.png)

结论:`从三个结果图来看，tanh函数的效果最好，因为train_acc和test_acc更高，loss更低且更快收敛`

> 3. 尝试不同的⽅案来初始化权重。什么⽅法效果最好？

`1.使用0矩阵进行初始化使用随机数进行初始化`

`2.使用随机数进行初始化`

`3.使用抑制梯度异常初始化参数(He论文方法)`------经常用到`

![](https://pic.superbed.cc/item/66c6f81ffcada11d37ab9122.png)

- xavier_uniform初始化

![](https://pic.superbed.cc/item/66c6fcf9fcada11d37abc670.png)

- normal初始化

![](https://pic.superbed.cc/item/66c6f1a5fcada11d37ab692e.png)

`明显是xavier_uniform初始化比较好,但是最好还得尝试`

#### 3.2.4.3 小结

> 1. 参数初始化还需要重新探讨，但是xavier_uniform初始化肯定效果比normal要较为好

### 3.2.5 模型选择、欠拟合和过拟合

