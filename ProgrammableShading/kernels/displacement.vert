// displacement.vert

/*
 This GLSL vertex shader performs displacement mapping
 using an analytical displacement function.
 */

// This 'varying' vertex output can be read as an input
// by a fragment shader that makes the same declaration.
varying vec2 texPos;
varying vec3 modelPos;
varying vec3 lightSource;
varying vec3 normal;

varying float displacement;
float pi = 3.1459;
float delta = .000001;

float h(int x, int y){
    return 5*cos(3*2*pi*x)*cos(3*2*pi*y);
}

void main()
{
    // Tell the fragment shader we have done vertex displacement
    displacement = 1.0;
    
	normal = gl_Normal.xyz;
	modelPos = gl_Vertex.xyz;
    
    // Copy the standard OpenGL texture coordinate to the output.
    texPos = gl_MultiTexCoord0.xy;
    
	/* CS 148 TODO: Modify 'modelPos' and 'normal' using your displacment function */
    /*
     float u = texPos.x;
     float v = texPos.y;
     float height = h(u, v);
     modelPos = modelPos + height * normal;
     float uDif = (h(u+delta,v)-h(u,v))/delta;
     float vDif = (h(u,v+delta)-h(u,v))/delta;
     vec3 T1 = Normalize(vec3(1,uDif,0));
     vec3 T2 = Normalize(vec3(0,-vDif,-1));
     normal = T1 x T2;
     */
    // Render the shape using modified position.
    gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix *  vec4(modelPos,1);
    
    // we may need this in the fragment shader...
    modelPos = (gl_ModelViewMatrix * vec4(modelPos,1)).xyz;
    
	// send the normal to the fragment shader
	normal = (gl_NormalMatrix * normal);
    
    // pass the light source position to the fragment shader
    lightSource = gl_LightSource[0].position.xyz;
}
