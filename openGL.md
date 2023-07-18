# Tips
[Markdown语法](https://markdown.com.cn/basic-syntax/links.html)。

# 你好三角形

三种对象
![这是图片](/img/三种对象.png "三种对象")

三种图元

GL_POINTS、GL_TRIANGLES、GL_LINE_STRIP

# 渲染管线
## 1. 渲染管线抽象
![](/img/渲染管线.png "Magic Gardens")

## 2. 定点着色器
顶点着色器(Vertex Shader)，它把一个单独的顶点作为输入。顶点着色器主要的目的是把3D坐标转为另一种3D坐标（后面会解释），同时顶点着色器允许我们对顶点属性进行一些基本处理。

### 标准化设备坐标
![](/img/NDC标准化设备坐标.png "标准化设备坐标")

### VBO, VAO EBO
VBO 是纯数据的缓冲区
VAO 告诉openGL,VBO中的数据是如何组织的,保存每一类顶点属性的解析结果
EBO 解决数据冗余的问题
顺序: 绑定VAO, 绑定VBO, 绑定EBO, VBO传输数据, EBO传输数据

# 纹理

## 1. 纹理坐标
![](/img/纹理坐标.jpg "纹理坐标")

## 2. 纹理环绕方式
![](/img/纹理环绕方式.jpg "纹理环绕方式")