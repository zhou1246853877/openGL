#version 330 core
out vec4 FragColor;  
in vec3 ourColor;

void main()
{
    FragColor = vec4(ourColor, 1.0);

//    float vertices[] = {
//        // λ��              
//         0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // ����
//        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // ����
//         0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // ����
//       ����λ�������Ƭ����ɫ����, ���½���0.5f, -0.5f, 0.0f(��), ������0.0f,  0.5f, 0.0f(��), ���½���-0.5f, -0.5f, 0.0f(��)    
//    };
}