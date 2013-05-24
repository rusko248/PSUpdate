// phong.frag

/*
  This fragment implements the Phong Reflection model.
*/

// The input image we will be filtering in this kernel.
uniform sampler2D normalTex;

varying vec3 modelPos;    // fragment position in model space
varying vec2 texPos;      // fragment position in texture space
varying vec3 lightSource; // light source position in model space
varying vec3 normal;	  // fragment normal in model space

varying float displacement;
//varying vec3 illumination;

void main()
{
    // Sample from the normal map, if we're not doing displacement mapping
    vec3 N;
	if (displacement < 0.0)
		N = 2.*texture2D(normalTex, texPos).xyz - 1.;
	else
		N = normal;

    vec3 C = vec3(0.0, 0.0, 0.0); // camera position

    vec3 ambientColor  = gl_LightSource[0].ambient.xyz;
    vec3 diffuseColor  = gl_LightSource[0].diffuse.xyz;
    vec3 specularColor = gl_LightSource[0].specular.xyz;

    vec3 materialColor = gl_FrontMaterial.ambient.xyz;
    vec3 materialSpec  = gl_FrontMaterial.specular.xyz;
    float shininess    = gl_FrontMaterial.shininess;

	/* CS 148 TODO: Implement the Phong reflectance model here */
    /*
     vec3 lSource = abs(modelPos - lightSource).norm;
     vec3 normedNormal = normal.norm;
     vec3 reflect = lSource reflected across N normed;
     vec3 viewer = abs(modelPos - C).norm;
     vec3 ambient = materialColor*ambientColor;
     vec3 diffuse = abs(dot(lSource, normedNormal))*materialColor*diffuseColor;
     vec3 specular = pow(abs(dot(reflect, viewer)),shineiness)*materialSpec*specularColor;
     illumination = ambient + diffuse + specular;
     gl_FragColor = vec4(illumination, 1.0);
     */
    gl_FragColor = vec4(materialColor, 1.0);
}
