#version 120

uniform float pointRadius; 
uniform sampler2D texture;
varying vec4 texCoord;
 
void main(void) {
    // calculate eye-space sphere normal from texture coordinates
    vec3 N;
    N.xy = gl_TexCoord[0].xy*vec2(2.0, -2.0) + vec2(-1.0, 1.0);
    float r2 = dot(N.xy, N.xy);

    if (r2 > 1.0) discard;   // kill pixels outside circle
    N.z = sqrt(1.0-r2);

    //  float alpha = saturate(1.0 - r2);
    float alpha = clamp((1.0 - r2), 0.0, 1.0);
    alpha *= gl_Color.w;

    vec2 test = vec2((N.x + 1.0)/2.0,(N.y + 1.0)/2.0);
    //gl_FragColor = vec4(gl_Color.xyz * alpha, alpha);
    gl_FragColor = texture2D(texture, test);
    //gl_FragColor = texture2D(texture, gl_PointCoord) * texCoord;
}