#version 330 core
in vec3 vertexNormals;
in vec3 fragmentPosition;
out vec4 fragmentColor;
uniform vec3 LightPosition;
uniform vec3 viewPosition;
vec3 normalNormalized = normalize(vertexNormals);
vec3 lightDirection = normalize(LightPosition - fragmentPosition);
vec3 objectColor = vec3(1.0, 0.5, 0.0);
vec3 lightColor = vec3(1.0, 1.0, 1.0);
uniform vec3 light = vec3(0.15, 1.0, 0.4);
void main()
{
   float ambientStrength = light.x;
   float specularStrength = light.z;
   vec3 viewDirection = normalize(viewPosition - fragmentPosition);
   vec3 reflectDirection = reflect(-lightDirection, normalNormalized);
   float specular = pow(max(dot(viewDirection, reflectDirection), 0.0), 64);
   vec3 specularColor = specularStrength * specular * lightColor;
   vec3 ambientColor = ambientStrength * lightColor;
   float diffuse = max(dot(normalNormalized, lightDirection), 0.0);
   vec3 diffuseColor = diffuse * lightColor;
   if(light.y == 0.0) diffuseColor = vec3(0.0);
   fragmentColor = vec4(objectColor * (ambientColor + diffuseColor + specularColor), 1.0);
}