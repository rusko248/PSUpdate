#version 120

uniform sampler2D texture;
varying vec4 texCoord;
 
void main(void) {
    //gl_FragColor = vec4(1,1,0,1);
    //vec2 center=vec2(gl_TexCoord[0])-vec2(0.5);
	//float cendist=1.0-length(center)*2.0;
	//gl_FragColor = vec4(0,0,0,clamp(cendist,0.0,1.0));
    vec3 N;
    N.xy = gl_PointCoord* 2.0 - vec2(1.0);
    float mag = dot(N.xy, N.xy);
    if(mag > 1.0)
     discard; // kill pixels outside circle
    gl_FragColor = texture2D(texture, gl_PointCoord) * texCoord;
}