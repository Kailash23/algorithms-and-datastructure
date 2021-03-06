/*
   What will be the Output ?
   Both classes are in same package.
 */

package com.output3;

 class Box{
     int width;
     int height;
     int length;
     void volume(){
         System.out.println(length * width * height);
     }
 }

 public class BoxUse {
     public static void main(String[] args) {
         Box b = new Box();
         b.height = 5;
         b.width = 4;
         b.volume();
     }
 }

/*
   0
   Default value for an integer data member of a class is 0. Thus default value for length is 0, whereas height and width are initialised to 5 and 4 respectively. Volume will thus be 0.
 */
