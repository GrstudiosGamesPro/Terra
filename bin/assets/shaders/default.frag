#version 330 core
    in vec2 TexCoord;
    out vec4 FragColor;

    uniform sampler2D textureSampler;

    void main() {
        FragColor = vec4(1.0);
        //FragColor = texture(textureSampler, TexCoord);
    }