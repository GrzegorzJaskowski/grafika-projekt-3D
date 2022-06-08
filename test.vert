#version 330 core
layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normals;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
out vec3 vertexNormals;
out vec3 fragmentPosition;
void main()
{
   gl_Position = projection * view * model * vec4(position, 1.0);
   vertexNormals = mat3(transpose(inverse(model))) * normals;
   fragmentPosition = vec3(model * vec4(position, 1.0));
}