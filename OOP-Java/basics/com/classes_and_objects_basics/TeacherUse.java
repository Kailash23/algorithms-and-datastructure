package com.classes_and_objects_basics;

import com.classes_and_objects_basics.Teacher;

public class TeacherUse {

    public static void main(String args[]) {
        Teacher t1 = new Teacher("Ramani", 23);
//        System.out.println("2 :"+ t1);
        t1.print();

        Teacher t2 = new Teacher("Ankush", 11);
        t2.print();

        System.out.println(Teacher.getNumTeachers());

    }

}

/*
   Ramani 23 1
   Ankush 11 2
   2
 */
