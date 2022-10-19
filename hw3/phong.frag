// Fragment shader:
// ================
#version 330 core
out vec4 FragColor;

in vec3 FragPos;
in vec3 Normal;
in vec3 LightPos;   // extra in variable, since we need the light position in view space we calculate this in the vertex shader

uniform vec3 lightColor;
uniform vec3 objectColor;

void main()
{
    // ambient
    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * lightColor;    
    
     //-- diffuse function
    vec3 normValue = normalize(Normal);
    vec3 lightDir = normalize(LightPos - FragPos);

    //-- difference in normal value and light direction
    float diff = max(dot(normValue, lightDir), 0.0);

  
    //-- diffuse the values
    vec3 diffuse = diff * lightColor;
    
    // specular
    float specularStrength = 0.5;
    vec3 viewDir = normalize(-FragPos); // the viewer is always at (0,0,0) in view-space, so viewDir is (0,0,0) - Position => -Position

    //-- reflectDir -light direction by normal value
    vec3 reflectDir = reflect(-lightDir, normValue);  
    //-- power of view direction and reflect direction
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    //-- multiply lightColor spec and specular strength
    vec3 specular = specularStrength * spec * lightColor; 
    
    vec3 result = (ambient + diffuse + specular) * objectColor;
    FragColor = vec4(result, 1.0);

  
}