#version 330 core
in vec2 TexCoord;
out vec4 FragColor;

void main() {
    // Definir los tres colores
    vec3 color1 = vec3(1.0, 0.0, 0.0);  // Rojo
    vec3 color2 = vec3(0.0, 1.0, 0.0);  // Verde
    vec3 color3 = vec3(0.0, 0.0, 1.0);  // Azul

    // Calcular el índice de color basado en la coordenada x
    float colorIndex = TexCoord.x * 3.0;

    // Seleccionar el color basado en el índice
    vec3 finalColor;
    if (colorIndex < 1.0) {
        finalColor = mix(color1, color2, colorIndex);
    } else if (colorIndex < 2.0) {
        finalColor = mix(color2, color3, colorIndex - 1.0);
    } else {
        finalColor = mix(color3, color1, colorIndex - 2.0);
    }

    // Asignar el color al fragmento
    FragColor = vec4(finalColor, 1.0);
}
