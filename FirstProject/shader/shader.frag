#version 330 core
out vec4 FragColor;  
in vec3 ourColor;

void main()
{
    FragColor = vec4(ourColor, 1.0);

//    float vertices[] = {
//        // 位置              
//         0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // 右下
//        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // 左下
//         0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // 顶部
//       顶点位置输出到片段着色器后, 右下角是0.5f, -0.5f, 0.0f(红), 顶部是0.0f,  0.5f, 0.0f(绿), 左下角是-0.5f, -0.5f, 0.0f(黑)    
//    };
}