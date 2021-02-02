#include "peashooter.h"
#include<iostream>
 peashooter::peashooter(int x,int y)
 {
     
    // std::cout << "yolo";
     Plant::setcord( x, y);
     
     afiseaza(Plant::getcord());
    // attack();
}
 peashooter::peashooter()
 {
     ;
 }
 void peashooter::afiseaza(COORD pos)
 {

     COORD num = pos;
     Plant::gotoxy(num.X, num.Y);
     aprox_cooord(num.X, num.Y);
     drawpixel9(num.X , num.Y, 6);
     drawpixel9(num.X + 1, num.Y, 2);
     drawpixel9(num.X + 2, num.Y, 2);
     drawpixel9(num.X + 3, num.Y, 2);
     drawpixel9(num.X + 3, num.Y + 1, 2);
   //  drawpixel9(num.X + 2, num.Y + 1, 2);
     drawpixel9(num.X + 1, num.Y + 1, 2);
     drawpixel9(num.X , num.Y + 2, 9);
     drawpixel9(num.X + 1, num.Y + 2, 9);
    

 }
 bullet* peashooter::attack()
 {
     COORD num = Plant::getcord();
     num.X++;
     num.X++;
     bullet* ammo=new bullet(num.X,num.Y);
     

     return ammo;
 }
 
 