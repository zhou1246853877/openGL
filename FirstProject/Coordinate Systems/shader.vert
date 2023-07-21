#version 330 core
layout (location = 0) in vec3 aPos;   // 位置变量的属性位置值为 0 
layout (location = 1) in vec3 aColor; // 颜色变量的属性位置值为 1
layout (location = 2) in vec2 aTexCoord;

out vec3 ourColor;
out vec2 TexCoord;

uniform mat4 transform;

void main()
{
    gl_Position = transform * vec4(aPos, 1.0);
    ourColor = aPos;    //顶点位置输出到片段着色器
    TexCoord = aTexCoord;
}

//习题1
//out vec3 ourcolor; // 向片段着色器输出一个颜色
//void main()
//{
//    gl_position = vec4(apos.x, 0 - apos.y, apos.z, 1.0);
//    ourcolor = acolor; // 将ourcolor设置为我们从顶点数据那里得到的输入颜色
//}


//习题2
//out vec3 ourcolor; // 向片段着色器输出一个颜色
//uniform float offset;
//void main()
//{
//    gl_position = vec4(apos.x + offset, apos.y, apos.z, 1.0);
//    ourcolor = acolor; // 将ourcolor设置为我们从顶点数据那里得到的输入颜色
//}