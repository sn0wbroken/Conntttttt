xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 78;
 0.00000;0.15000;0.00000;,
 0.10607;0.10607;0.00000;,
 0.09799;0.09799;-0.07654;,
 0.00000;0.13858;-0.07654;,
 0.15000;0.00000;-0.00000;,
 0.13858;0.00000;-0.07654;,
 0.10607;-0.10607;-0.00000;,
 0.09799;-0.09799;-0.07654;,
 0.00000;-0.15000;0.00000;,
 0.00000;-0.13858;-0.07654;,
 -0.10607;-0.10607;0.00000;,
 -0.09799;-0.09799;-0.07654;,
 -0.15000;0.00000;0.00000;,
 -0.13858;0.00000;-0.07654;,
 -0.10607;0.10607;0.00000;,
 -0.09799;0.09799;-0.07654;,
 0.00000;0.15000;0.00000;,
 0.00000;0.13858;-0.07654;,
 0.07500;0.07500;-0.14142;,
 0.00000;0.10607;-0.14142;,
 0.10607;0.00000;-0.14142;,
 0.07500;-0.07500;-0.14142;,
 0.00000;-0.10607;-0.14142;,
 -0.07500;-0.07500;-0.14142;,
 -0.10607;0.00000;-0.14142;,
 -0.07500;0.07500;-0.14142;,
 0.00000;0.10607;-0.14142;,
 0.04059;0.04059;-0.18478;,
 0.00000;0.05740;-0.18478;,
 0.05740;0.00000;-0.18478;,
 0.04059;-0.04059;-0.18478;,
 0.00000;-0.05740;-0.18478;,
 -0.04059;-0.04059;-0.18478;,
 -0.05740;0.00000;-0.18478;,
 -0.04059;0.04059;-0.18478;,
 0.00000;0.05740;-0.18478;,
 0.00000;0.00000;-0.20000;,
 0.00000;0.00000;-0.20000;,
 0.00000;0.00000;-0.20000;,
 0.00000;0.00000;-0.20000;,
 0.00000;0.00000;-0.20000;,
 0.00000;0.00000;-0.20000;,
 0.00000;0.00000;-0.20000;,
 0.00000;0.00000;-0.20000;,
 0.00000;0.15000;0.20000;,
 0.10607;0.10607;0.20000;,
 0.10607;0.10607;0.00000;,
 0.00000;0.15000;0.00000;,
 0.15000;-0.00000;0.20000;,
 0.15000;0.00000;-0.00000;,
 0.10607;-0.10607;0.20000;,
 0.10607;-0.10607;-0.00000;,
 -0.00000;-0.15000;0.20000;,
 0.00000;-0.15000;0.00000;,
 -0.10607;-0.10607;0.20000;,
 -0.10607;-0.10607;0.00000;,
 -0.15000;0.00000;0.20000;,
 -0.15000;0.00000;0.00000;,
 -0.10607;0.10607;0.20000;,
 -0.10607;0.10607;0.00000;,
 0.00000;0.15000;0.20000;,
 0.00000;0.15000;0.00000;,
 0.00000;-0.00000;0.20000;,
 0.00000;-0.00000;0.20000;,
 0.00000;-0.00000;0.20000;,
 0.00000;-0.00000;0.20000;,
 0.00000;-0.00000;0.20000;,
 0.00000;-0.00000;0.20000;,
 0.00000;-0.00000;0.20000;,
 0.00000;-0.00000;0.20000;,
 0.00000;0.00000;0.00000;,
 0.00000;0.00000;0.00000;,
 0.00000;0.00000;0.00000;,
 0.00000;0.00000;0.00000;,
 0.00000;0.00000;0.00000;,
 0.00000;0.00000;0.00000;,
 0.00000;0.00000;0.00000;,
 0.00000;0.00000;0.00000;;
 
 56;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;6,8,9,7;,
 4;8,10,11,9;,
 4;10,12,13,11;,
 4;12,14,15,13;,
 4;14,16,17,15;,
 4;3,2,18,19;,
 4;2,5,20,18;,
 4;5,7,21,20;,
 4;7,9,22,21;,
 4;9,11,23,22;,
 4;11,13,24,23;,
 4;13,15,25,24;,
 4;15,17,26,25;,
 4;19,18,27,28;,
 4;18,20,29,27;,
 4;20,21,30,29;,
 4;21,22,31,30;,
 4;22,23,32,31;,
 4;23,24,33,32;,
 4;24,25,34,33;,
 4;25,26,35,34;,
 3;28,27,36;,
 3;27,29,37;,
 3;29,30,38;,
 3;30,31,39;,
 3;31,32,40;,
 3;32,33,41;,
 3;33,34,42;,
 3;34,35,43;,
 4;44,45,46,47;,
 4;45,48,49,46;,
 4;48,50,51,49;,
 4;50,52,53,51;,
 4;52,54,55,53;,
 4;54,56,57,55;,
 4;56,58,59,57;,
 4;58,60,61,59;,
 3;62,45,44;,
 3;63,48,45;,
 3;64,50,48;,
 3;65,52,50;,
 3;66,54,52;,
 3;67,56,54;,
 3;68,58,56;,
 3;69,60,58;,
 3;70,47,46;,
 3;71,46,49;,
 3;72,49,51;,
 3;73,51,53;,
 3;74,53,55;,
 3;75,55,57;,
 3;76,57,59;,
 3;77,59,61;;
 
 MeshMaterialList {
  2;
  56;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0;;
  Material {
   1.000000;1.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   1.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  43;
  0.000000;0.989054;-0.147552;,
  0.699367;0.699367;-0.147552;,
  0.989054;0.000000;-0.147552;,
  0.699367;-0.699367;-0.147552;,
  0.000000;-0.989054;-0.147552;,
  -0.699367;-0.699367;-0.147552;,
  -0.989054;0.000000;-0.147552;,
  -0.699367;0.699367;-0.147552;,
  0.000000;0.953127;-0.302570;,
  0.673963;0.673963;-0.302570;,
  0.953127;0.000000;-0.302570;,
  0.673963;-0.673963;-0.302570;,
  0.000000;-0.953127;-0.302570;,
  -0.673963;-0.673963;-0.302570;,
  -0.953127;0.000000;-0.302570;,
  -0.673963;0.673963;-0.302570;,
  0.000000;0.792171;-0.610299;,
  0.560150;0.560150;-0.610298;,
  0.792171;0.000000;-0.610299;,
  0.560150;-0.560150;-0.610298;,
  0.000000;-0.792171;-0.610299;,
  -0.560150;-0.560150;-0.610298;,
  -0.792171;0.000000;-0.610299;,
  -0.560150;0.560150;-0.610298;,
  0.000000;0.470462;-0.882420;,
  0.332667;0.332667;-0.882420;,
  0.470462;0.000000;-0.882420;,
  0.332667;-0.332667;-0.882420;,
  0.000000;-0.470462;-0.882420;,
  -0.332667;-0.332667;-0.882420;,
  -0.470462;0.000000;-0.882420;,
  -0.332667;0.332667;-0.882420;,
  0.000000;0.000000;-1.000000;,
  0.000000;0.000000;1.000000;,
  0.000000;1.000000;0.000000;,
  0.707107;0.707107;0.000000;,
  1.000000;0.000000;0.000000;,
  0.707107;-0.707107;-0.000000;,
  0.000000;-1.000000;-0.000000;,
  -0.707107;-0.707107;0.000000;,
  -1.000000;0.000000;0.000000;,
  -0.707107;0.707107;0.000000;,
  0.000000;0.000000;-1.000000;;
  56;
  4;0,1,9,8;,
  4;1,2,10,9;,
  4;2,3,11,10;,
  4;3,4,12,11;,
  4;4,5,13,12;,
  4;5,6,14,13;,
  4;6,7,15,14;,
  4;7,0,8,15;,
  4;8,9,17,16;,
  4;9,10,18,17;,
  4;10,11,19,18;,
  4;11,12,20,19;,
  4;12,13,21,20;,
  4;13,14,22,21;,
  4;14,15,23,22;,
  4;15,8,16,23;,
  4;16,17,25,24;,
  4;17,18,26,25;,
  4;18,19,27,26;,
  4;19,20,28,27;,
  4;20,21,29,28;,
  4;21,22,30,29;,
  4;22,23,31,30;,
  4;23,16,24,31;,
  3;24,25,32;,
  3;25,26,32;,
  3;26,27,32;,
  3;27,28,32;,
  3;28,29,32;,
  3;29,30,32;,
  3;30,31,32;,
  3;31,24,32;,
  4;34,35,35,34;,
  4;35,36,36,35;,
  4;36,37,37,36;,
  4;37,38,38,37;,
  4;38,39,39,38;,
  4;39,40,40,39;,
  4;40,41,41,40;,
  4;41,34,34,41;,
  3;33,33,33;,
  3;33,33,33;,
  3;33,33,33;,
  3;33,33,33;,
  3;33,33,33;,
  3;33,33,33;,
  3;33,33,33;,
  3;33,33,33;,
  3;42,42,42;,
  3;42,42,42;,
  3;42,42,42;,
  3;42,42,42;,
  3;42,42,42;,
  3;42,42,42;,
  3;42,42,42;,
  3;42,42,42;;
 }
 MeshTextureCoords {
  78;
  0.000000;0.500000;,
  0.125000;0.500000;,
  0.125000;0.625000;,
  0.000000;0.625000;,
  0.250000;0.500000;,
  0.250000;0.625000;,
  0.375000;0.500000;,
  0.375000;0.625000;,
  0.500000;0.500000;,
  0.500000;0.625000;,
  0.625000;0.500000;,
  0.625000;0.625000;,
  0.750000;0.500000;,
  0.750000;0.625000;,
  0.875000;0.500000;,
  0.875000;0.625000;,
  1.000000;0.500000;,
  1.000000;0.625000;,
  0.125000;0.750000;,
  0.000000;0.750000;,
  0.250000;0.750000;,
  0.375000;0.750000;,
  0.500000;0.750000;,
  0.625000;0.750000;,
  0.750000;0.750000;,
  0.875000;0.750000;,
  1.000000;0.750000;,
  0.125000;0.875000;,
  0.000000;0.875000;,
  0.250000;0.875000;,
  0.375000;0.875000;,
  0.500000;0.875000;,
  0.625000;0.875000;,
  0.750000;0.875000;,
  0.875000;0.875000;,
  1.000000;0.875000;,
  0.062500;1.000000;,
  0.187500;1.000000;,
  0.312500;1.000000;,
  0.437500;1.000000;,
  0.562500;1.000000;,
  0.687500;1.000000;,
  0.812500;1.000000;,
  0.937500;1.000000;,
  0.000000;0.000000;,
  0.125000;0.000000;,
  0.125000;1.000000;,
  0.000000;1.000000;,
  0.250000;0.000000;,
  0.250000;1.000000;,
  0.375000;0.000000;,
  0.375000;1.000000;,
  0.500000;0.000000;,
  0.500000;1.000000;,
  0.625000;0.000000;,
  0.625000;1.000000;,
  0.750000;0.000000;,
  0.750000;1.000000;,
  0.875000;0.000000;,
  0.875000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.062500;0.000000;,
  0.187500;0.000000;,
  0.312500;0.000000;,
  0.437500;0.000000;,
  0.562500;0.000000;,
  0.687500;0.000000;,
  0.812500;0.000000;,
  0.937500;0.000000;,
  0.062500;1.000000;,
  0.187500;1.000000;,
  0.312500;1.000000;,
  0.437500;1.000000;,
  0.562500;1.000000;,
  0.687500;1.000000;,
  0.812500;1.000000;,
  0.937500;1.000000;;
 }
}
