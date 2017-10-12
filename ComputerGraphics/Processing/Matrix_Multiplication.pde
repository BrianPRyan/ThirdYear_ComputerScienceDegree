/************Brian Ryan***********12 October 2016***********  
Tranforming points through matrix multiplication...  
Pressing the mouse button turns on looping, and relasing it turns off looping
*/

//points
float[] p1 = {10.0,10.0,1.0};  // X,Y,H -> Homogeneous coordinate, facilitates use of matrix
float[] p2 = {10.0,150.0,1.0};
float[] p3 = {250.0,150.0,1.0};
float[] p4 = {250.0,10.0,1.0};
float[] p5 = {290.0,10.0,1.0};
float[] p6 = {230.0,-40.0,1.0};
float[] p7 = {90.0,-40.0,1.0};
float[] p8 = {90.0,-80.0,1.0};
float[] p9 = {50.0,-80.0,1.0};
float[] p10 = {50.0,-40.0,1.0};
float[] p11 = {30.0,-40.0,1.0};
float[] p12 = {-30.0,10.0,1.0};
float[] p13 = {10.0,10.0,1.0};

// transform matrix
float[][] t_matrix = {{1.0,0.0,0.0},{0.0,1.0,0.0},{6.0,6.0,1.0}}; // translate 6,6 
// Translate in Column order
 /*    1  0  6        // 1st column
    =  0  1  6        // 2nd column
       0  0  1      // 3rd column
 */
           
float[][] s_matrix = {{1.2,0.0,0.0},{0.0,1.2,0.0},{0.0,0.0,1.0}};  // scale 1.2,1
 /*    2  0   0
    =  0  2   0
       0  0   1
 */

float[][] r_matrix = {{1.0,0.0,0.0},{0.0,1.0,0.0},{0.0,0.0,1.0}};   // empty
 /*    1  0   0
    =  0  1   0
       0  0   1
 */

float[][] m; 

void r_matrix()
{
  p1 = transform_point(r_matrix, p1); 
  p2 = transform_point(r_matrix, p2);
  p3 = transform_point(r_matrix, p3);
  p4 = transform_point(r_matrix, p4);
  p5 = transform_point(r_matrix, p5);
  p6 = transform_point(r_matrix, p6);
  p7 = transform_point(r_matrix, p7);
  p8 = transform_point(r_matrix, p8);
  p9 = transform_point(r_matrix, p9);
  p10 = transform_point(r_matrix, p10);
  p11 = transform_point(r_matrix, p11);
  p12 = transform_point(r_matrix, p12);
  p13 = transform_point(r_matrix, p13); 
}

void t_matrix()
{
  p1 = transform_point(t_matrix, p1); 
  p2 = transform_point(t_matrix, p2);
  p3 = transform_point(t_matrix, p3);
  p4 = transform_point(t_matrix, p4);
  p5 = transform_point(t_matrix, p5);
  p6 = transform_point(t_matrix, p6);
  p7 = transform_point(t_matrix, p7);
  p8 = transform_point(t_matrix, p8);
  p9 = transform_point(t_matrix, p9);
  p10 = transform_point(t_matrix, p10);
  p11 = transform_point(t_matrix, p11);
  p12 = transform_point(t_matrix, p12);
  p13 = transform_point(t_matrix, p13); 
}

void s_matrix()
{
  p1 = transform_point(s_matrix, p1); 
  p2 = transform_point(s_matrix, p2);
  p3 = transform_point(s_matrix, p3);
  p4 = transform_point(s_matrix, p4);
  p5 = transform_point(s_matrix, p5);
  p6 = transform_point(s_matrix, p6);
  p7 = transform_point(s_matrix, p7);
  p8 = transform_point(s_matrix, p8);
  p9 = transform_point(s_matrix, p9);
  p10 = transform_point(s_matrix, p10);
  p11 = transform_point(s_matrix, p11);
  p12 = transform_point(s_matrix, p12);
  p13 = transform_point(s_matrix, p13); 
}

void setup() 
{
  size(900,650);                // set up size
  stroke(255);                    // set up stroke
  
  // rotation angle
  float theta = radians(5);       // convert degrees to radians
  
  // need to change r_matrix 
  // matrix3 = rotate... 
  r_matrix[0][0] = cos(theta);    // row 0, column 0 = (0, 0)
  r_matrix[0][1] = - sin(theta);  // (0, 1)
  r_matrix[1][0] = sin(theta);    // (1, 0)
  r_matrix[1][1] = cos(theta);    // (1, 1)
  // Matrix is now over-written and handling our 2D transformation

 /*    cos(theta) -sin(theta)   0
    =  sin(theta)  cos(theta)   0
           0             0      1
 */

  noLoop();
  
  frameRate(1);
}

/*draw will draw the shape on screen*/
void draw() 
{
  // by commenting the background() call out, the background is not refreshed, so each transformation can be seen.
  //background(102);
         
  fill(255);    // blank the screen
  
  r_matrix();
  //t_matrix();
  //s_matrix();
  
  translate(mouseX, mouseY);
  myBox();      // draw the box again

}


//Transform_point() function
//Multiplies 3x3 matrix by a 1 dimensional matrix that contains the x
float[] transform_point(float[][] m, float[] p)
{

   float[] p_new = {0.0,0.0,0.0};  // declare array of matrices
   
   p_new[0] = m[0][0] * p[0] + m[1][0] * p[1] + m[2][0] * p[2];  // multiplies row x column
   p_new[1] = m[0][1] * p[0] + m[1][1] * p[1] + m[2][1] * p[2];
   p_new[2] = m[0][2] * p[0] + m[1][2] * p[1] + m[2][2] * p[2];
  
   return p_new;
}



float[][] mult_matrix(float[][] m1, float[][] m2)
{
   float[][] m_new = {{0.0,0.0,0.0},{0.0,0.0,0.0},{0.0,0.0,0.0}};
   
   m_new[0][0] = m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1] + m1[2][0] * m2[0][2];
   m_new[0][1] = m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1] + m1[2][1] * m2[0][2];
   m_new[0][2] = m1[0][2] * m2[0][0] + m1[1][2] * m2[0][1] + m1[2][2] * m2[0][2];

   m_new[1][0] = m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1] + m1[2][0] * m2[1][2];
   m_new[1][1] = m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1] + m1[2][1] * m2[1][2];
   m_new[1][2] = m1[0][2] * m2[1][0] + m1[1][2] * m2[1][1] + m1[2][2] * m2[1][2];

   m_new[2][0] = m1[0][0] * m2[2][0] + m1[1][0] * m2[2][1] + m1[2][0] * m2[2][2];
   m_new[2][1] = m1[0][1] * m2[2][0] + m1[1][1] * m2[2][1] + m1[2][1] * m2[2][2];
   m_new[2][2] = m1[0][2] * m2[2][0] + m1[1][2] * m2[2][1] + m1[2][2] * m2[2][2];
  
   return m_new;
}

/* 
setting a low framerate() and noLoop() in setup() 
and turning looping on and off with mousePress and mouseRelease
allows us to see each itteration of 'draw()'
*/

void mousePressed() 
{ 
  loop(); 
} 
 
void mouseReleased() 
{ 
  noLoop(); 
} 
/*shape is defined as elements in the array*/
void myBox () 
{
  //draw a line from coordinate to coordinate
  line(p1[0],p1[1], p2[0],p2[1]);
  line(p2[0],p2[1], p3[0],p3[1]);
  line(p3[0],p3[1], p4[0],p4[1]);
  line(p4[0],p4[1], p5[0],p5[1]);
  line(p5[0],p5[1], p6[0],p6[1]);  
  line(p6[0],p6[1], p7[0],p7[1]);
  line(p7[0],p7[1], p8[0],p8[1]);
  line(p8[0],p8[1], p9[0],p9[1]);
  line(p9[0],p9[1], p10[0],p10[1]);
  line(p10[0],p10[1], p11[0],p11[1]);
  line(p11[0],p11[1], p12[0],p12[1]);
  line(p12[0],p12[1], p13[0],p13[1]);
  line(p13[0],p13[1], p1[0],p1[1]);    
}
