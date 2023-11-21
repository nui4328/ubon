void servo_red()
  {   
    servo(23, servo22-30);
    delay(400);
    servo(23, servo23);
     //------------->>  ตรวจสอบนับการวางกล่องสี
    if(red_box == 1 && green_box == 1 && blue_box == 1 && yello_box == 1 && ch_poit >= 2)
      {
        bz(300);bz(300);bz(300);
        servo(28, 20);
        delay(300000);    
      }
  }

void servo_green()
  {
    servo(23, servo23+30);
    delay(400);
    servo(23, servo23);
    if(red_box == 1 && green_box == 1 && blue_box == 1 && yello_box == 1 && ch_poit >= 2)
      {
        bz(300);bz(300);bz(300);
        servo(28, 20);
        delay(300000);    
      }
  }

void servo_yello()
  {
    servo(22, servo22+30);
    delay(400);
    servo(22, servo23);
    if(red_box == 1 && green_box == 1 && blue_box == 1 && yello_box == 1 && ch_poit >= 2)
      {
        bz(300);bz(300);bz(300);
        servo(28, 20);
        delay(300000);       
      }
  }
void servo_blue()
  {
    servo(22, servo22-30);
    delay(400);
   servo(22, servo23);
    if(red_box == 1 && green_box == 1 && blue_box == 1 && yello_box == 1 && ch_poit >= 2)
      {
        bz(300);bz(300);bz(300);
        servo(28, 20);
        delay(300000);       
      }
  }
