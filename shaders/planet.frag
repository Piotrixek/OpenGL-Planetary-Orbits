// planet.frag
#version 330 core
in vec3 FragPos;
in vec3 Normal;
uniform vec3 objectColor;
uniform float time;
out vec4 FragColor;
void main(){
    float pulsate = 0.5 + 0.5 * sin(time * 2.0);
    float intensity = pow(max(dot(normalize(Normal), vec3(0.0, 0.0, 1.0)), 0.0), 3.0);
    vec3 color = objectColor * pulsate * (0.5 + 0.5 * intensity);
    FragColor = vec4(color, 1.0);
}
