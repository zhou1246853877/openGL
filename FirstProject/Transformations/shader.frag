#version 330 core
out vec4 FragColor;  

in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D texture1;
uniform sampler2D texture2;
uniform float alpha;

void main()
{

    //FragColor = texture(texture2, TexCoord);
    float temp = clamp(alpha, 0, 1);
    FragColor = mix(texture(texture1, TexCoord), texture(texture2, TexCoord), temp);

//    //œ∞Ã‚1   
//    vec2 reverse_texCoord = vec2(1 - TexCoord.x, TexCoord.y);
//    FragColor = mix(texture(texture1, TexCoord), texture(texture2, reverse_texCoord), 0.2);
}