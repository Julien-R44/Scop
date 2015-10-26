#version 150 core

in vec3 vertexPosition_modelspace;
uniform mat4 MVP;

void main(){

    // Obtient la position du sommet, dans l'espace de découpe : MVP * position
    vec4 v = vec4(vertexPosition_modelspace,1); // Transforme un vecteur 4D homogène, vous vous souvenez ?
    gl_Position = MVP * v;
}
