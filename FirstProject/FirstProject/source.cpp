#include "source.h"
using namespace std;


void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
    std::cout << "窗口大小发生变化!" << std::endl;
}

void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

const char* vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

const char* fragShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";

const char* fragShaderSource2 = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 1.0f, 0.f, 1.0f);\n"
    "}\n\0";


int main()
{

    //glfw初始化和配置
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);  
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);  
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    //创建glfw窗口
    GLFWwindow* window = glfwCreateWindow(800, 600, "openGL", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    
    //加载所有openGL函数指针
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    //编译着色器程序
    // -----------------------------------------
    //顶点着色器
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    //检查顶点着色器编译是否成功
    int  success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    //片段着色器
    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragShaderSource, NULL);
    glCompileShader(fragmentShader);

    //检查片段着色器是否编译成功
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    //习题3,片段着色器2
    unsigned int fragmentShader2;
    fragmentShader2 = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader2, 1, &fragShaderSource2, NULL);
    glCompileShader(fragmentShader2);

    //检查片段着色器2是否编译成功
    glGetShaderiv(fragmentShader2, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader2, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT2::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    //连接着色器, 着色器程序1
    unsigned int shaderProgramer;
    shaderProgramer = glCreateProgram();
    glAttachShader(shaderProgramer, vertexShader);
    glAttachShader(shaderProgramer, fragmentShader);
    glLinkProgram(shaderProgramer);

    
    glGetProgramiv(shaderProgramer, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgramer, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }


    //习题3,
    //连接着色器, 着色器程序2
    unsigned int shaderProgramer2;
    shaderProgramer2 = glCreateProgram();
    glAttachShader(shaderProgramer2, vertexShader);
    glAttachShader(shaderProgramer2, fragmentShader2);
    glLinkProgram(shaderProgramer2);


    glGetProgramiv(shaderProgramer2, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgramer2, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM2::LINKING_FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    glDeleteShader(fragmentShader2);

    //float vertices[] = {
    //    -0.5f, -0.5f, 0.0f,
    //    0.5f, -0.5f, 0.0f,
    //    0.0f, 0.5f, 0.0f
    //};

    //float vertices[] = {
    //    0.5f, 0.5f, 0.0f,   // 右上角
    //    0.5f, -0.5f, 0.0f,  // 右下角
    //    -0.5f, -0.5f, 0.0f, // 左下角
    //    -0.5f, 0.5f, 0.0f   // 左上角
    //};

    ////习题1,习题2的数据
    float vertices[] = {
        // 第一个三角形
        0.5f, 0.5f, 0.0f,   // 右上角
        0.5f, -0.5f, 0.0f,  // 右下角
        -0.5f, 0.5f, 0.0f,  // 左上角
        // 第二个三角形
        0.5f, -0.5f, 0.0f,  // 右下角
        -0.5f, -0.5f, 0.0f, // 左下角
        -0.5f, 0.5f, 0.0f   // 左上角
    };

    unsigned int indices[] = {
        0, 1, 3,            //左上
        1, 2, 3             //右下
    };

    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
       
    //绑定VAO，表示在这之后针对 VBO 的解析都会记录在 VAO 中
    glBindVertexArray(VAO);
    //复制顶点属性到缓冲中供openGL使用
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) / 2, vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    //设置顶点属性指针
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    //习题2
    glBindVertexArray(0);   //解绑
    unsigned int VAO1;
    unsigned int VBO1;
    
    glGenVertexArrays(1, &VAO1);
    glGenBuffers(1, &VBO1);

    glBindVertexArray(VAO1);
    glBindBuffer(GL_ARRAY_BUFFER, VBO1);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) / 2, &vertices[9], GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    //渲染循环
    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);   
        glClear(GL_COLOR_BUFFER_BIT);           //状态使用

        //处理输入
        processInput(window);
        
        glUseProgram(shaderProgramer);
        glBindVertexArray(VAO);
        //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        //习题1
        glDrawArrays(GL_TRIANGLES, 0, 3);

        //习题3,着色器程序2
        glUseProgram(shaderProgramer2);
        glBindVertexArray(VAO1);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        //检查并调用事件, 交换缓冲
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgramer);

    glDeleteVertexArrays(1, &VAO1);
    glDeleteBuffers(1, &VBO1);
    glDeleteProgram(shaderProgramer2);

    glfwTerminate();
    return 0;
}