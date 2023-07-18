#version 330 core
layout (location = 0) in vec3 aPos;   // λ�ñ���������λ��ֵΪ 0 
layout (location = 1) in vec3 aColor; // ��ɫ����������λ��ֵΪ 1

out vec3 ourColor;
void main()
{
    gl_Position = vec4(aPos, 1.0);
    ourColor = aPos;    //����λ�������Ƭ����ɫ��
}

//ϰ��1
//out vec3 ourcolor; // ��Ƭ����ɫ�����һ����ɫ
//void main()
//{
//    gl_position = vec4(apos.x, 0 - apos.y, apos.z, 1.0);
//    ourcolor = acolor; // ��ourcolor����Ϊ���ǴӶ�����������õ���������ɫ
//}


//ϰ��2
//out vec3 ourcolor; // ��Ƭ����ɫ�����һ����ɫ
//uniform float offset;
//void main()
//{
//    gl_position = vec4(apos.x + offset, apos.y, apos.z, 1.0);
//    ourcolor = acolor; // ��ourcolor����Ϊ���ǴӶ�����������õ���������ɫ
//}