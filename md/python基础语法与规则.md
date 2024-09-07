# Numpy常用方法

## permutation方法

```python
>>> import numpy as np
>>> m = 5
>>> permutation = list(np.random.permutation(m))
>>> permutation
[3, 2, 4, 0, 1] 
# new row 0 is old row 3
# new row 1 is old row 2
# new row 2 is old row 4
# new row 3 is old row 0
# new row 4 is old row 1
# m**2代表m^2 = 25
>>> X = np.arange(m**2).reshape((m,m)) 
>>> X
array([[ 0,  1,  2,  3,  4],
       [ 5,  6,  7,  8,  9],
       [10, 11, 12, 13, 14],
       [15, 16, 17, 18, 19],
       [20, 21, 22, 23, 24]])
# 代表X的行按照permutation的下标进行重新排列
# [15, 16, 17, 18, 19]代表下标3
# [10, 11, 12, 13, 14]代表下标2
# [20, 21, 22, 23, 24]代表下标4
# [ 0,  1,  2,  3,  4]代表下标0
# [ 5,  6,  7,  8,  9]代表下标1
>>> X[permutation,:]
array([[15, 16, 17, 18, 19],
       [10, 11, 12, 13, 14],
       [20, 21, 22, 23, 24],
       [ 0,  1,  2,  3,  4],
       [ 5,  6,  7,  8,  9]])
# 代表X的列按照permutation的下标进行重新排列
# [ 0,  1,  2,  3,  4]
#   ^   ^   ^   ^   ^
#   0   1   2   3   4
#         变成
# [ 3,  2,  4,  0,  1]
#   ^   ^   ^   ^   ^
#   3   2   4   0   1
# 
# [ 5,  6,  7,  8,  9]
#   ^   ^   ^   ^   ^
#   0   1   2   3   4
# 变成
# [ 8,  7,  9,  5,  6]
#   ^   ^   ^   ^   ^
#   3   2   4   0   1
>>> X[:,permutation]
array([[ 3,  2,  4,  0,  1],
       [ 8,  7,  9,  5,  6],
       [13, 12, 14, 10, 11],
       [18, 17, 19, 15, 16],
       [23, 22, 24, 20, 21]])
>>> X[:,permutation].reshape((1,m**2))
array([[ 3,  2,  4,  0,  1,  8,  7,  9,  5,  6, 13, 12, 14, 10, 11, 18,
        17, 19, 15, 16, 23, 22, 24, 20, 21]])```
```

## pad方法

```python
# 比如：
# 导入numpy库进行数值计算
import numpy as np
# 创建一个3维数组，包含3个2维子数组
arr3D = np.array([[[1, 1, 2, 2, 3, 4],
             [1, 1, 2, 2, 3, 4], 
             [1, 1, 2, 2, 3, 4]], 
             
            [[0, 1, 2, 3, 4, 5], 
             [0, 1, 2, 3, 4, 5], 
             [0, 1, 2, 3, 4, 5]], 
             
            [[1, 1, 2, 2, 3, 4], 
             [1, 1, 2, 2, 3, 4], 
             [1, 1, 2, 2, 3, 4]]])

# 打印边界填充后的结果
print('constant:  \n' + str(np.pad(arr3D, ((0, 0), (1, 1), (2, 2)), 'constant')))
```

> 参考链接: https://blog.csdn.net/zenghaitao0128/article/details/78713663n

## randn用法

```python
print("=====我们来测试一下=====")
np.random.seed(1)
x = np.random.randn(4,3,3,2)

print ("x.shape =", x.shape)
print("x = " , x)
print ("x[1, 1] =", x[1, 1])

# 绘制图
fig , axarr = plt.subplots(1,2)  # 一行两列
axarr[0].set_title('x')
axarr[0].imshow(x[0,:,:,0])
plt.show()
```

> 参考链接:https://juejin.cn/post/7115205069120733215

# 基础语法

## 1.1 yield与next的搭配使用

> 要理解yield的意思必须先第一步将yield看成是return的意思

## 1.2 矩阵基础语法

### 1.2.1 np.power用法

> np.power是矩阵的幂函数用法



# Pytorch+anaconda 配置

## 1.1 激活环境

```
conda create -n 环境名 --clone base
```

## 1.2 进入环境

```
conda activate 环境名
```





## 1.3 设置默认环境(选做)

>可以修改/.bashrc文件的配置，即在/.bashrc文件的末尾添加如下一行：

```
source activate 环境名
```

>保存后关闭当前窗口，并重新打开新的窗口，可以看到默认启动环境已经不再是base了：



## 1.4 安装Pytorch(待续)

>

# Pytorch基础语法

## 1.torchvision.transforms

### 1.1 transforms.ToTensor()

> 把一个取值范围是`[0,255]`的`PIL.Image`或者`shape`为`(H,W,C)`的`numpy.ndarray`，转换成形状为`[C,H,W]`，取值范围是`[0,1.0]`的`torch.FloadTensor`

```python
data = np.random.randint(0, 255, size=300)
img = data.reshape(10,10,3)
print(img.shape)
img_tensor = transforms.ToTensor()(img) # 转换成tensor
print(img_tensor)
```

### 1.2 transforms.Resize(x)

> 简单来说就是**调整PILImage对象的尺寸**，注意不能是用io.imread或者cv2.imread读取的图片，这两种方法得到的是ndarray。
>
> 将图片短边缩放至x，长宽比保持不变

```python
transforms.Resize(x)
```

> 而一般输入深度网络的特征图长宽是相等的，就不能采取等比例缩放的方式了，需要同时指定长宽：

```python
transforms.Resize([h, w])
```

> 例如transforms.Resize([224, 224])就能将输入图片转化成224×224的输入特征图。
>
> 这样虽然会改变图片的长宽比，但是本身并没有发生裁切，仍可以通过resize方法返回原来的形状：

```python
from PIL import Image
from torchvision import transforms

img = Image.open('1.jpg')
w, h = img.size
resize = transforms.Resize([224,244])
img = resize(img)
img.save('2.jpg')
resize2 = transforms.Resize([h, w])
img = resize2(img)
img.save('3.jpg')
```

### 1.3 transforms.Compose(transforms)

> 将多个`transform`组合起来使用。
>
> `transforms`： 由`transform`构成的列表. 例子：
>
> 
>
> 本文的主题是其中的torchvision.transforms.Compose()类。这个类的主要作用是串联多个图片变换的操作。
>
> 这个类的构造很简单：



```python
class torchvision.transforms.Compose(transforms):
 # Composes several transforms together.
 # Parameters: transforms (list of Transform objects) – list of transforms to compose.
 
Example # 可以看出Compose里面的参数实际上就是个列表，而这个列表里面的元素就是你想要执行的transform操作。
>>> transforms.Compose([
>>>     transforms.CenterCrop(10),
>>>     transforms.ToTensor(),])
```

> 事实上，Compose()类会将transforms列表里面的transform操作进行遍历。实现的代码很简单：

```python
## 这里对源码进行了部分截取。
def __call__(self, img):
    for t in self.transforms:   
        img = t(img)
    return img
```

## 2. torch.utils.data

### 2.1 torch.utils.data.DataLoader()

> 数据加载器。组合数据集和采样器，并在数据集上提供单进程或多进程迭代器。

```python
class torch.utils.data.DataLoader(dataset, batch_size=1, shuffle=False, sampler=None, num_workers=0, collate_fn=<function default_collate>, pin_memory=False, drop_last=False)
```

**参数：**

- **dataset** (*Dataset*) – 加载数据的数据集。
- **batch_size** (*int*, optional) – 每个batch加载多少个样本(默认: 1)。
- **shuffle** (*bool*, optional) – 设置为`True`时会在每个epoch重新打乱数据(默认: False).
- **sampler** (*Sampler*, optional) – 定义从数据集中提取样本的策略。如果指定，则忽略`shuffle`参数。
- **num_workers** (*int*, optional) – 用多少个子进程加载数据。0表示数据将在主进程中加载(默认: 0)
- **collate_fn** (*callable*, optional) –
- **pin_memory** (*bool*, optional) –
- **drop_last** (*bool*, optional) – 如果数据集大小不能被batch size整除，则设置为True后可删除最后一个不完整的batch。如果设为False并且数据集的大小不能被batch size整除，则最后一个batch将更小。(默认: False)

> https://blog.csdn.net/zfhsfdhdfajhsr/article/details/116836851

## 3.torch.tensor

### 3.1 matmul

> orch.matmul是tensor的乘法，输入可以是高维的。
> 当输入都是二维时，就是普通的[矩阵乘法](https://so.csdn.net/so/search?q=矩阵乘法&spm=1001.2101.3001.7020)，和tensor.mm函数用法相同。

```python
import torch
a = torch.ones(3,4)
b = torch.ones(4,2)
c = torch.matmul(a,b)
print(c.shape)
```

```
size([3,2])
```

## 4.torch.nn

### init

> 随机初始化权重参数算法

当然可以，以下是每种初始化方法的用途、代码实现、数学公式以及进一步的解释：

#### 1. **均匀分布初始化 (`torch.nn.init.uniform_`)**
   - **用途**：用于从均匀分布中随机初始化权重。适用于在不确定最佳初始化范围时，为所有权重赋予一个均匀分布的值。

   - **公式**：
     $$
     (\mathbf{W}_{ij} \sim \mathcal{U}(a, b))
     $$
     
     
     - 
     
       
       $$
       (\mathcal{U}(a, b))
       $$
       表示均匀分布，区间为 \([a, b]\)。
     
   - **代码示例**：
     
     ```python
     import torch
import torch.nn as nn
     
     tensor = torch.empty(3, 5)
     nn.init.uniform_(tensor, a=0, b=1)
     ```
     
   - **解释**：将张量 `tensor` 的每个元素初始化为范围在 \([0, 1]\) 的均匀随机值。这种方法的简单性使其适用于各种场景。

#### 2. **正态分布初始化 (`torch.nn.init.normal_`)**
   - **用途**：用于从正态分布中随机初始化权重，适合期望权重值围绕某个均值对称分布的情况。

   - **公式**：
     $$
     (\mathbf{W}_{ij} \sim \mathcal{N}(\mu, \sigma^2))
     $$
     
     
     - 
       $$
       (\mathcal{N}(\mu, \sigma^2))
       $$
        表示均值为 \(\mu\)、方差为 \(\sigma^2\) 的正态分布。
     
   - **代码示例**：
     
     ```python
     tensor = torch.empty(3, 5)
     nn.init.normal_(tensor, mean=0, std=1)
     ```
     
   - **解释**：将张量 `tensor` 的每个元素初始化为均值为 0，标准差为 1 的正态分布随机值。这种初始化在实践中经常使用，尤其在期望值接近零的情况下效果良好。

#### 3. **常量初始化 (`torch.nn.init.constant_`)**
   - **用途**：将所有权重初始化为相同的常量值，通常用于偏置初始化。

   - **公式**：
     $$
     (\mathbf{W}_{ij} = c)
     $$
     
     
     - \(c\) 是一个常数值。
     
   - **代码示例**：
     ```python
     tensor = torch.empty(3, 5)
     nn.init.constant_(tensor, 0.1)
     ```
     
   - **解释**：将张量 `tensor` 的每个元素初始化为 0.1。常量初始化通常用于网络中的偏置，因为偏置的初始值可能不需要变化太大。

#### 4. **单位矩阵初始化 (`torch.nn.init.eye_`)**
   - **用途**：初始化二维张量为单位矩阵，通常用于某些线性层的特殊初始化场景。

   - **公式**：
     $$
     (\mathbf{W} = \mathbf{I}_n)
     $$
     
     
     - 
       $$
       (\mathbf{I}_n)
       $$
        是 \(n\) 维单位矩阵。
     
   - **代码示例**：
     
     ```python
     tensor = torch.empty(3, 3)
     nn.init.eye_(tensor)
     ```
     
   - **解释**：将 `tensor` 初始化为一个 \(3 \times 3\) 的单位矩阵（对角线为 1，其他元素为 0）。这种初始化通常在某些特定的线性变换或 RNN 层中有用。

5. **Xavier 均匀分布初始化 (`torch.nn.init.xavier_uniform_`)**

   - **用途**：用于避免梯度消失或爆炸，特别是在深层网络中。此方法考虑了输入和输出的规模。

   - **公式**：
     $$
     (\mathbf{W}_{ij} \sim \mathcal{U}\left(-\sqrt{\frac{6}{n_{in} + n_{out}}}, \sqrt{\frac{6}{n_{in} + n_{out}}}\right))
     $$
     
     
     - 
       $$
       (n_{in}) 和 (n_{out})
       $$
        分别为输入和输出的单元数。
     
   - **代码示例**：
     
     ```python
     tensor = torch.empty(3, 5)
     nn.init.xavier_uniform_(tensor)
     ```
     
   - **解释**：将权重初始化为在 \(\left[-\sqrt{\frac{6}{n_{in} + n_{out}}}, \sqrt{\frac{6}{n_{in} + n_{out}}}\right]\) 之间的均匀分布随机值。这种初始化方式通常适用于带有 Sigmoid 或 Tanh 激活函数的神经网络。

#### 6. **Xavier 正态分布初始化 (`torch.nn.init.xavier_normal_`)**
   - **用途**：与 Xavier 均匀分布类似，但使用正态分布进行初始化，适用于深度神经网络。

   - **公式**：
     $$
     (\mathbf{W}_{ij} \sim \mathcal{N}\left(0, \frac{2}{n_{in} + n_{out}}\right))
     $$
     
   - **代码示例**：
     
     ```python
     tensor = torch.empty(3, 5)
     nn.init.xavier_normal_(tensor)
     ```
     
   - **解释**：将权重初始化为均值为 0，方差为
     $$
     (\frac{2}{n_{in} + n_{out}})
     $$
      的正态分布随机值。这种方法同样适用于具有 Sigmoid 或 Tanh 激活函数的神经网络。

#### 7. **Kaiming 均匀分布初始化 (`torch.nn.init.kaiming_uniform_`)**
   - **用途**：适用于 ReLU 及其变体激活函数的网络初始化，考虑了非线性激活的影响。

   - **公式**：
     $$
     (\mathbf{W}_{ij} \sim \mathcal{U}\left(-\sqrt{\frac{6}{n_{in}}}, \sqrt{\frac{6}{n_{in}}}\right))
     $$
     
     
     - 这里的 
       $$
       (n_{in})
       $$
        是输入单元数。
     
   - **代码示例**：
     
     ```python
     tensor = torch.empty(3, 5)
     nn.init.kaiming_uniform_(tensor, nonlinearity='relu')
     ```
     
   - **解释**：将权重初始化为在 \(\left[-\sqrt{\frac{6}{n_{in}}}, \sqrt{\frac{6}{n_{in}}}\right]\) 之间的均匀分布随机值。Kaiming 初始化通过考虑 ReLU 激活函数的特性，确保了在深层网络中更稳定的训练。

#### 8. **Kaiming 正态分布初始化 (`torch.nn.init.kaiming_normal_`)**
   - **用途**：与 Kaiming 均匀分布初始化类似，但使用正态分布进行初始化，适用于使用 ReLU 激活函数的深度神经网络。

   - **公式**：
     $$
     (\mathbf{W}_{ij} \sim \mathcal{N}\left(0, \frac{2}{n_{in}}\right))
     $$
     
   - **代码示例**：
     
     ```python
     tensor = torch.empty(3, 5)
     nn.init.kaiming_normal_(tensor, nonlinearity='relu')
     ```
     
   - **解释**：将权重初始化为均值为 0，方差为 \(\frac{2}{n_{in}}\) 的正态分布随机值。这种方法尤其适合于深层网络，特别是使用 ReLU 及其变体激活函数的网络。

#### 9. **Orthogonal 初始化 (`torch.nn.init.orthogonal_`)**
   - **用途**：确保权重矩阵的正交性，这在某些情况下可以提高训练的稳定性和模型性能。

   - **公式**：
     $$
     (\mathbf{W}\mathbf{W}^T = \mathbf{I})
     $$
     
   - **代码示例**：
     
     ```python
     tensor = torch.empty(3, 5)
     nn.init.orthogonal_(tensor)
     ```
     
   - **解释**：将张量 `tensor` 初始化为正交矩阵，使其转置矩阵与自身相乘后为单位矩阵。这种初始化在某些特殊网络结构中表现良好，如 RNN 和自编码器。

#### 10. **Sparse 初始化 (`torch.nn.init.sparse_`)**
   - **用途**：初始化稀疏矩阵，使得权重矩阵中大部分元素为零，这对于某些需要稀疏表示的网络结构有用。

   - **公式**：
     $$
     (\mathbf{W}_{ij} = \begin{cases}
      \mathcal{N}(0, \sigma^2) & \text{以概率 \(p\) 保留非零元素} \\
      0 & \text{以概率 \(1-p\) 置为零}
      \end{cases})
$$
   
   
   - **代码示例**：
     ```python
     tensor = torch.empty(10, 10)
     nn.init
     ```

### 5. MSELoss

`MSELoss` 是 PyTorch 中用于计算均方误差 (Mean Squared Error, MSE) 的损失函数。MSE 是神经网络训练中常用的一种回归损失函数，它计算预测值和目标值之间的差异的平方和的平均值。其公式如下：

### 数学公式
$$
\text{MSE} = \frac{1}{n} \sum_{i=1}^{n} (y_i - \hat{y}_i)^2
$$
- 
$$
  y_i 是第 i 个目标值（真实值）。
$$
- 
$$
   \hat{y}_i  是第 i 个预测值。
  $$


- n  是样本的总数。

### 代码示例

```python
import torch
import torch.nn as nn

# 定义 MSELoss 函数
criterion = nn.MSELoss()

# 创建一些示例数据
predicted = torch.tensor([2.5, 0.0, 2.0, 8.0])  # 模型的预测值
target = torch.tensor([3.0, -0.5, 2.0, 7.0])    # 真实目标值

# 计算 MSE Loss
loss = criterion(predicted, target)
print(loss)
```

### 解释

- **用途**：`MSELoss` 通常用于回归任务中，在这种任务中，模型预测的是连续值而非类别。MSE 计算预测值和真实值之间的误差并对其平方，因此更关注大的误差，因为平方会放大它们的影响。
- **优势**：简单且易于解释，损失值越小，预测值与目标值越接近。
- **缺点**：由于平方放大了误差，MSE 对于异常值（outliers）非常敏感，这可能会导致模型偏向那些异常值。

`MSELoss` 是构建回归模型时的重要组成部分，通常与优化器（如 SGD 或 Adam）一起使用，以最小化模型在训练集上的误差。



# 