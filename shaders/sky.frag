// sky.frag
#version 330 core
in vec2 uv;
out vec4 FragColor;
float rand(vec2 co){
    return fract(sin(dot(co.xy, vec2(12.9898, 78.233))) * 43758.5453);
}
void main(){
    vec3 skyColor = vec3(0.0);
    float star = step(0.998, rand(uv * 1000.0));
    float brightness = rand(uv * 500.0);
    skyColor += star * vec3(brightness);
    FragColor = vec4(skyColor, 1.0);
}
