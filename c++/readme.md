# 神经网络
## 基本结构

DNN内部的神经网络层可以分为三类，输入层，隐藏层和输出层,如下图示例，一般来说第一层是输入层，最后一层是输出层，而中间的层数都是隐藏层。
DNN神经网络在感知机的模型上做了扩展，总结下主要有三点：
- 加入了隐藏层，隐藏层可以有多层，增强模型的表达能力，模型的复杂度也增加了好多。
- 输出层的神经元也可以不止一个输出，可以有多个输出，这样模型可以灵活的应用于分类回归，以及其他的机器学习领域比如降维和聚类等。
- 对激活函数做扩展，感知机的激活函数是$sign(z)= \begin{cases} -1& {z<0}\\ 1& {z\geq 0} \end{cases}$,虽然简单但是处理能力有限，因此神经网络中一般使用的其他的激活函数，Sigmoid函数，tanh, softmax,和ReLU等。通过使用不同的激活函数，神经网络的表达能力进一步增强。


## 前向传播
节点i的输出: $a_i$
激活函数：sigmoid函数  $\\sigma	(t) = \cfrac{1}{1 + e^{-t}}$

![](media/15506294983612/15506740554697.jpg)
$$
a_4=\sigma(w_{41}x_1+w_{42}x_2+w_{43}x_3+w_{4b})\\
a_5=\sigma(w_{51}x_1+w_{52}x_2+w_{53}x_3+w_{5b})\\
a_6=\sigma(w_{61}x_1+w_{62}x_2+w_{63}x_3+w_{6b})\\
a_7=\sigma(w_{71}x_1+w_{72}x_2+w_{73}x_3+w_{7b})\\
$$
接着，定义网络的输入向量和隐藏层每个节点的权重向量$\vec{w_j}$。令

$$
\begin{split}
\vec{x}&=\begin{bmatrix}x_1\\x_2\\x_3\\1\end{bmatrix}\\
\vec{w}_4&=[w_{41},w_{42},w_{43},w_{4b}]\\
\vec{w}_5&=[w_{51},w_{52},w_{53},w_{5b}]\\
\vec{w}_6&=[w_{61},w_{62},w_{63},w_{6b}]\\
\vec{w}_7&=[w_{71},w_{72},w_{73},w_{7b}]\\
f(x)&=\sigma(x)
\end{split}
$$
代入上式得：
$$
\begin{split}
a_4&=f(\vec{w_4}\centerdot\vec{x})\\
a_5&=f(\vec{w_5}\centerdot\vec{x})\\
a_6&=f(\vec{w_6}\centerdot\vec{x})\\
a_7&=f(\vec{w_7}\centerdot\vec{x})
\end{split}
$$

现在，我们把上述计算的四个式子写到一个矩阵里面，每个式子作为矩阵的一行，就可以利用矩阵来表示它们的计算了。令
$$
\vec{a}=
\begin{bmatrix}
a_4 \\
a_5 \\
a_6 \\
a_7 \\
\end{bmatrix},\qquad W=
\begin{bmatrix}
\vec{w}_4 \\
\vec{w}_5 \\
\vec{w}_6 \\
\vec{w}_7 \\
\end{bmatrix}=
\begin{bmatrix}
w_{41},w_{42},w_{43},w_{4b} \\
w_{51},w_{52},w_{53},w_{5b} \\
w_{61},w_{62},w_{63},w_{6b} \\
w_{71},w_{72},w_{73},w_{7b} \\
\end{bmatrix}
,\qquad f(
\begin{bmatrix}
x_1\\
x_2\\
x_3\\
.\\
.\\
.\\
\end{bmatrix})=
\begin{bmatrix}
f(x_1)\\
f(x_2)\\
f(x_3)\\
.\\
.\\
.\\
\end{bmatrix}
$$
最终得到某一层的输出表示，这就是前向传播：
$$
\begin{equation}
\vec{a}=f(W\centerdot\vec{x})
\end{equation}
$$
应用上式，如下举例：
![](media/15506294983612/15506737139665.jpg)
$$
\begin{split}
&\vec{a}_1=f(W_1\centerdot\vec{x})\\
&\vec{a}_2=f(W_2\centerdot\vec{a}_1)\\
&\vec{a}_3=f(W_3\centerdot\vec{a}_2)\\
&\vec{y}=f(W_4\centerdot\vec{a}_3)\\
\end{split}
$$

