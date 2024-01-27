void fw_ch_r(int sp, int encoderPoss_fw)
  {
     int encoderPos_last = 0;
     int encoderPos_fw = 0;
     mcp_f0 = 0;
     mcp_f1 = 0;
     ch_line_l =0;
     if(bg_st == 1)
      {
        goto bridge_ch; 
      }

    //------------------>> เดินหน้าที่ละแผ่น
    for(int i=0; i<6; i++)
      {
        sensor_maxs[i] = mcp_f(i);
        delay(10);
      }
    color_ch="none";
    encoderPoss = 0;
    while(encoderPoss < encoderPoss_fw)      
        {          
          check_color_roll();   
          errors = error_Yaw();
          I = 0;
          previous_I = 0;
          previous_error = 0;
          P = errors;
          I = I + previous_I;
          D = errors - previous_error ;            
          previous_I=I;
          previous_error=errors  ;  
          PID_output = (3 * P) + (0.00015 * I) +(2* D); 
          
          Motor(sp - PID_output, sp + PID_output, sp - PID_output, sp + PID_output); 

          if(digitalRead(26)==0)
            {
              chopsticks = 1;
              //Motor(0,0,0,0);delay(10);
               encoderPoss=0; 
               while(encoderPoss < 250)
                  { 
                    errors = error_Yaw();
                    
                    I = 0;
                    previous_I = 0;
                    previous_error = 0;
                    P = errors;
                    I = I + previous_I;
                    D = errors - previous_error ;            
                    previous_I=I;
                    previous_error=errors  ;  
                    PID_output = (6 * P) + (0.00015 * I) +(15* D); 
                    
                    Motor(80 - PID_output, 80 + PID_output, 80 - PID_output, 80 + PID_output); 
                    if(digitalRead(26)==0)
                      {
                        chopsticks ++;   
                      }                    
                  }               
               
               //Motor(0,0,0,0);delay(100);
               bridge();  ///---------------------->>  ขึ้นสะพานและตะเกียบ   1000 คือค่าที่วิ่งขึ้นไปกลางสะพาน หรือผ่านตะเกียบ
               
               goto bridge_ch;             
            } 
          
         if(mcp_f(0) < md_mcp_f(0) || mcp_f(1) < md_mcp_f(1))  //------->> ตวจสอบเส้นด้านหน้า
            {    
                           
               if(mcp_f(0) < md_mcp_f(0))
                  {
                     mcp_f0 = 1;
                  }
               if(mcp_f(1) < md_mcp_f(1))
                  {
                     mcp_f1 = 1;
                  }
               Motor(-60,-60,-60,-60);delay(70); 
               Motor(0,0,0,0);delay(300);   
                    
               color_ch="none";
               encoderPos_last = encoderPoss ;  
               encoderPos_fw = encoderPoss_fw - encoderPos_last;

               ///------------------------------------------------------------------------------------------\\\\\
                   check_color_roll();
                   check_color_roll_bz(); 
                    if(color_ch=="red"||color_ch=="green"||color_ch=="blue")  //------>> ตรวจสอบสี
                       {                                                                  
                         if(color_ch=="red")
                           {   
                            display_color();
                             encoderPoss=0;                                   
                             do{Motor(-50,-50,-50,-50);}while(encoderPoss > -40);
                              Motor(0,0,0,0);delay(50);
                                      red_box =1; 
                                      servo_red();                                       
                                    }
                                 else if(color_ch=="green")
                                    {
                                      display_color();
                                      encoderPoss=0;
                                      do{Motor(-50,-50,-50,-50);}while(encoderPoss > -40);
                                      Motor(0,0,0,0);delay(50);
                                      green_box =1; 
                                      servo_green();                               
                                    }
                                 else if(color_ch=="blue")
                                    {
                                      display_color();
                                      encoderPoss=0;
                                      do{Motor(-50,-50,-50,-50);}while(encoderPoss > -40);
                                      Motor(0,0,0,0);delay(50);
                                      blue_box =1;
                                      servo_blue();                               
                                    }
 
                                  slide_r();                                     
                                  //set_bl(1);   
                                  encoderPoss=0; 
                                  ch_line_r = 0;
                                  calibration_Yak();
                                  bw(51, 250);
                                  slide_l_online();
                                  color_ch="none";
                                  goto end_line; 
                       }
              ///------------------------------------------------------------------------------------------\\\\\
              
               if(mcp_f0 == 0 && mcp_f1 == 1)
                  {                  
                    while(1)
                      {                        
                        Motor(40,40,40,40);          
                        if(mcp_f(5) > sensor_maxs[5]-100)  //------->> ตวจสอบผนังด้านหน้า
                          {  
                              ch_mcp_f5 ++; 
                              Motor(0,0,0,0);delay(100);
                              if(ch_mcp_f5 == 1)
                                {
                                  bw(45, 80);
                                  goto bridge_ch;
                                }
                              else
                                {
                                  bw(45, 80);
                                  slide_l_online();
                                  ch_mcp_f5 = 0;
                                  goto end_line;
                                } 
                          }
                        if( mcp_f(0) < md_mcp_f(0))
                          {
                             Motor(-60,-60,-60,-60);delay(60);
                             Motor(0,0,0,0);delay(300);
                             check_color_roll_bz(); 
                             mydisplay_background(black);
                             mydisplay(color_ch, 20, 10, 2, white);
                             if(color_ch=="red"||color_ch=="green"||color_ch=="blue")  //------>> ตรวจสอบสี
                               {                                                                  
                                 if(color_ch=="red")
                                    {  
                                      display_color();
                                      encoderPoss=0;                                    
                                      do{Motor(-50,-50,-50,-50);}while(encoderPoss > -40);
                                      Motor(0,0,0,0);delay(50);
                                      red_box =1; 
                                      servo_red();                                       
                                    }
                                 else if(color_ch=="green")
                                    {
                                      display_color();
                                      encoderPoss=0;
                                      do{Motor(-50,-50,-50,-50);}while(encoderPoss > -40);
                                      Motor(0,0,0,0);delay(50);
                                      green_box =1; 
                                      servo_green();                               
                                    }
                                 else if(color_ch=="blue")
                                    {
                                      display_color();
                                      encoderPoss=0;
                                      do{Motor(-50,-50,-50,-50);}while(encoderPoss > -40);
                                      Motor(0,0,0,0);delay(50);
                                      blue_box =1;
                                      servo_blue();                               
                                    }
                                 
                                  slide_r();                                     
                                  //set_bl(1);   
                                  encoderPoss=0; 
                                  ch_line_r = 0;
                                  calibration_Yak();
                                  bw(51, 250);
                                  slide_l_online();
                                  color_ch="none";
                                  goto end_line; 
                               }
                            if(encoderPoss > 100)
                               {
                                    set_bl_min(1);
                                    encoderPoss=0;
                                    //bz(300);
                                    do{Motor(-50,-50,-50,-50);}while(encoderPoss > -90);
                                    Motor(0,0,0,0);delay(300); 
                                    String sen_en = String (encoderPoss);    
                                    mydisplay_background(black);
                                    mydisplay("encode "+ sen_en, 20, 10, 2, white);                                   
                                    goto bridge_ch;                  
                                }
                             else
                                {
                                  set_bl_min(1);
                                  String sen_en = String (encoderPoss);    
                                  mydisplay_background(black);
                                  mydisplay("encode "+ sen_en, 20, 10, 2, white);                                    
                                  bw(61, 90);
                                  slide_l_online();
                                  goto end_line;
                                }
                          }
                        if( mcp_f(4) < md_mcp_f(4))
                          {
                            Motor(-80,-80,-80,-80);delay(70);
                            Motor(0,0,0,0);delay(200);
                            Motor(-60,60,60,-60);delay(240);
                            Motor(0,0,0,0);delay(200);
                            encoderPoss=0; 
                            while(encoderPoss < encoderPos_fw-70)
                              {
                                Motor(45,45,45,45);
                                if(mcp_f(0) < md_mcp_f(0))
                                  {
                                    Motor(-50,-50,-50,-50);delay(50);
                                    Motor(0,0,0,0);delay(200);
                                    bw(50, 40);
                                    break;
                                  }
                              }
                            Motor(0,0,0,0);delay(200);
                            goto en_r_line;
                          }
                      }
                  }
               else if(mcp_f0 == 1&& mcp_f1 == 0)
                  {
                    while(1)
                      {
                        Motor(40,40,40,40); 
                        if( mcp_f(1) < md_mcp_f(1))
                          {
                             Motor(-100,-100,-100,-100);delay(30);
                             Motor(0,0,0,0);delay(200);
                             check_color_roll_bz(); 
                             mydisplay_background(black);
                             mydisplay(color_ch, 20, 10, 2, white);
                             if(color_ch=="red"||color_ch=="green"||color_ch=="blue")  //------>> ตรวจสอบสี
                               {                                                                  
                                 if(color_ch=="red")
                                    {   
                                      display_color();
                                      encoderPoss=0;                                   
                                      do{Motor(-50,-50,-50,-50);}while(encoderPoss > -40);
                                      Motor(0,0,0,0);delay(50);
                                      red_box =1; 
                                      servo_red();                                       
                                    }
                                 else if(color_ch=="green")
                                    {
                                      display_color();
                                      encoderPoss=0;
                                      do{Motor(-50,-50,-50,-50);}while(encoderPoss > -40);
                                      Motor(0,0,0,0);delay(50);
                                      green_box =1; 
                                      servo_green();                               
                                    }
                                 else if(color_ch=="blue")
                                    {
                                      display_color();
                                      encoderPoss=0;
                                      do{Motor(-50,-50,-50,-50);}while(encoderPoss > -40);
                                      Motor(0,0,0,0);delay(50);
                                      blue_box =1;
                                      servo_blue();                               
                                    }

                                  slide_r();                                     
                                  //set_bl(1);   
                                  encoderPoss=0; 
                                  ch_line_r = 0;
                                  calibration_Yak();
                                  bw(51, 250);
                                  slide_l_online();
                                  color_ch="none";
                                  goto end_line; 
                              }
                            if(encoderPoss > 100)
                                {
                                    set_bl_min(1);
                                    encoderPoss=0;
                                    //bz(300);
                                    do{Motor(-50,-50,-50,-50);}while(encoderPoss > -80);
                                    Motor(0,0,0,0);delay(300); 
                                    
                                    String sen_en = String (encoderPoss);    
                                    mydisplay_background(black);
                                    mydisplay("encode "+ sen_en, 20, 10, 2, white);                                   
                                    goto bridge_ch;                  
                                }
                              else
                                {
                                  set_bl_min(1);
                                  String sen_en = String (encoderPoss);    
                                  mydisplay_background(black);
                                  mydisplay("encode "+ sen_en, 20, 10, 2, white);                                    
                                  bw(61, 90);
                                  slide_l_online();
                                  goto end_line;
                                }
                          }
                        if( mcp_f(2) < md_mcp_f(2))
                          {
                            Motor(-80,-80,-80,-80);delay(50);
                            Motor(0,0,0,0);delay(200);
                            Motor(60,-60,-60,60);delay(300);
                            Motor(0,0,0,0);delay(200);
                            calibration_Yak();  
                            do{ Motor(50,-50,50,-50);}while(error_Yaw()<10);
                            Motor(-50,0,-50,0);delay(20);
                            Motor(0,0,0,0);delay(200); 
                            calibration_Yak();                            
                            
                            encoderPoss=0; 
                            do{Motor(50,50,50,50);}while(encoderPoss < encoderPos_fw-70);
                            Motor(0,0,0,0);delay(200);
                            goto en_r_line;
                          }
                      }
                  }
                else
                  {                    
                    encoderPoss=0;
                    Motor(0,0,0,0);delay(250);
                    check_color_roll_bz(); 
                    if(color_ch=="red"||color_ch=="green"||color_ch=="blue")  //------>> ตรวจสอบสี
                       {                                                                  
                         if(color_ch=="red")
                           {   
                            display_color();
                             encoderPoss=0;                                   
                             do{Motor(-50,-50,-50,-50);}while(encoderPoss > -40);
                              Motor(0,0,0,0);delay(50);
                                      red_box =1; 
                                      servo_red();                                       
                                    }
                                 else if(color_ch=="green")
                                    {
                                      display_color();
                                      encoderPoss=0;
                                      do{Motor(-50,-50,-50,-50);}while(encoderPoss > -40);
                                      Motor(0,0,0,0);delay(50);
                                      green_box =1; 
                                      servo_green();                               
                                    }
                                 else if(color_ch=="blue")
                                    {
                                      display_color();
                                      encoderPoss=0;
                                      do{Motor(-50,-50,-50,-50);}while(encoderPoss > -40);
                                      Motor(0,0,0,0);delay(50);
                                      blue_box =1;
                                      servo_blue();                               
                                    }
 
                                  slide_r();                                     
                                  //set_bl(1);   
                                  encoderPoss=0; 
                                  ch_line_r = 0;
                                  calibration_Yak();
                                  bw(51, 250);
                                  slide_l_online();
                                  color_ch="none";
                      }
                    else
                      {
                        do{Motor(-50,-50,-50,-50);}while(encoderPoss > -70);
                        Motor(0,0,0,0);delay(150);
                        ch_line_r = 0;
                        slide_l_online();
                      }
                    goto end_line;            
                  }
            }  
         if(mcp_f(5) > sensor_maxs[5]+100)  //------->> ตวจสอบเส้นด้านหน้า
            {  
              ch_mcp_f5 ++; 
              Motor(0,0,0,0);delay(100);
              if(ch_mcp_f5 == 1)
                {
                  bw(45, 80);
                  goto bridge_ch;
                }
              else
                {
                  bw(45, 60);
                  slide_l_online();
                  ch_mcp_f5 = 0;
                  goto end_line;
                } 
            }
         if(digitalRead(26)==0)
            {
              chopsticks = 1;
              //Motor(0,0,0,0);delay(10);
               encoderPoss=0; 
               while(encoderPoss < 250)
                  { 
                    errors = error_Yaw();
                    
                    I = 0;
                    previous_I = 0;
                    previous_error = 0;
                    P = errors;
                    I = I + previous_I;
                    D = errors - previous_error ;            
                    previous_I=I;
                    previous_error=errors  ;  
                    PID_output = (6 * P) + (0.00015 * I) +(15* D); 
                    
                    Motor(80 - PID_output, 80 + PID_output, 80 - PID_output, 80 + PID_output); 
                    if(digitalRead(26)==0)
                      {
                        chopsticks ++;    //-------> chopsticks = 1 คือ ตะเกียบ
                      }
                    
                  }               
               
               //Motor(0,0,0,0);delay(100);
               bridge();  ///---------------------->>  ขึ้นสะพานและตะเกียบ   1000 คือค่าที่วิ่งขึ้นไปกลางสะพาน หรือผ่านตะเกียบ
               
               goto bridge_ch;             
            } 
         
         if(color_ch=="yello")
            {
               display_color();
               Motor(-70,-70,-70,-70);delay(70);
               Motor(0,0,0,0);delay(30);
               check_color_roll_bz();                   
               set_bl_yello(1);
               if(none_yello == 1)  //------------------->> เจอจุดเช็คพอยต์  
                  {
                    ch_poit ++;
                    none_yello = 0;
                    if(ch_poit == 1)
                      {
                        bz(300);
                      }
                    else if (ch_poit >= 2)
                      {
                        bz(300);bz(300);
                      }
                    if(red_box == 1 && green_box == 1 && blue_box == 1 && yello_box == 1 && ch_poit >= 2)
                      {
                        bz(300);bz(300);bz(300);
                        servo(28, 20);
                        delay(500000);        
                      }
                    goto bridge_ch;  
                  }
               encoderPoss=0; 
               calibration_Yak();                       
               encoderPoss=0; 
               bw(41, 300);
               yello_box =1;
               servo_yello();                        
               
                slide_r();
                encoderPoss=0;
                calibration_Yak();  
                bw(51, 331);
                slide_l_online();
                color_ch="none";
                goto end_line;    
            }
         if(color_ch=="red"||color_ch=="green"||color_ch=="blue")
            {  
               Motor(-70,-70,-70,-70);delay(70);
               Motor(0,0,0,0);delay(150);               
               check_color_roll_bz(); 
               mydisplay_background(black);
               mydisplay(color_ch, 20, 10, 2, white);  
               if(color_ch=="red")
                                    {   
                                      display_color();
                                      encoderPoss=0;                                   
                                      do{Motor(-50,-50,-50,-50);}while(encoderPoss > -40);
                                      Motor(0,0,0,0);delay(50);
                                      red_box =1; 
                                      servo_red();                                       
                                    }
                                 else if(color_ch=="green")
                                    {
                                      display_color();
                                      encoderPoss=0;
                                      do{Motor(-50,-50,-50,-50);}while(encoderPoss > -40);
                                      Motor(0,0,0,0);delay(50);
                                      green_box =1; 
                                      servo_green();                               
                                    }
                                 else if(color_ch=="blue")
                                    {
                                      display_color();
                                      encoderPoss=0;
                                      do{Motor(-50,-50,-50,-50);}while(encoderPoss > -40);
                                      Motor(0,0,0,0);delay(50);
                                      blue_box =1;
                                      servo_blue();                               
                                    }

                  mydisplay_background(black);
                  mydisplay(color_ch, 20, 10, 2, white); 
                  do{Motor(-40,-40,-40,-40);}while(mcp_f(1)<md_mcp_f(1));
                  slide_r();                                     
                  //set_bl(1);   
                  encoderPoss=0; 
                  ch_line_r = 0;
                  calibration_Yak();
                  bw(51, 250);
                  slide_l_online();
                  color_ch="none";
                  goto end_line; 
           }
         
       }

    ///-------------------------------------------------------------------------------->>>>  จบการเดินหน้าที่ละบล๊อก  <<---------
    Motor(-50,-50,-50,-50);delay(50);      
    Motor(0,0,0,0);delay(200);  
    bridge_ch:delay(10); //------------>> เมื่อมีการขึ้นสะพานมา
    en_r_line: delay(10);
    sr:delay(10);
    for(int i=0; i<5; i++)
      {
        sensor_maxs[i] = mcp_f(i);
        delay(10);
      }
    //--------------------------------->> สไลข้างขวาพร้อมเช็ค เส้นดำ
    calibration_Yak();     
    begin_slide_R: delay(10);    //----------------->??
    encoderPoss=0;
    calibration_Yak();
    Motor(0,0,0,0);delay(100);
    
    //lasts_time = millis();
    //while(millis() - lasts_time < 700)
    while(encoderPoss > -255)           
        {          
          errors = error_Yaw();          
          I = 0;
          previous_I = 0;
          previous_error = 0;
          P = errors;
          I = I + previous_I;
          D = errors - previous_error ;            
          previous_I=I;
          previous_error=errors  ;  
          PID_output = (4 * P) + (0.00015 * I) +(8* D); 
          
          Motor(52-PID_output, -(52 - PID_output),-(52 + PID_output), 52 + PID_output); 
         // Motor(61, -61,-61, 61); 
          if(mcp_f(1)<md_mcp_f(1) || mcp_f(3)<md_mcp_f(3)) //----------------->> ถ้ามีเส้นดำด้านข้าง
            {
              Motor(-56,56,56,-56);delay(70);
              Motor(0,0,0,0);delay(30);
              if(mcp_f(1)<md_mcp_f(1)&& mcp_f(4)>md_mcp_f(4))
                {
                   encoderPoss=0;
                   while(1)
                    {
                      Motor(0,0,-80,80);
                      if(encoderPoss < -50)
                        {
                          Motor(0,0,80,-80);delay(30);                        
                          Motor(0,0,0,0);delay(300); 
                          
                          do{Motor(0,0,80,-80);}while(error_Yaw()<10);
                          Motor(0,0,0,0);delay(200); 
                          //Motor(-70,-70,-70,-70); delay(200); 
                          //Motor(0,0,0,0);delay(300);
                          Motor(-70,70,70,-70); delay(200); 
                          Motor(0,0,0,0);delay(300); 
                          Motor(70,70,70,70); delay(200); 
                          Motor(0,0,0,0);delay(300); 
                          break;                
                        }
                      if(mcp_f(4)<md_mcp_f(4))
                        {
                          Motor(0,0,80,-80);delay(30);                        
                          Motor(0,0,0,0);delay(300); 

                          break;
                        }
                    }
                  Motor(0,0,0,0);delay(300);
                }
              else if(mcp_f(3)<md_mcp_f(3)&& mcp_f(4)>md_mcp_f(4))
                {
                  encoderPoss=0;
                  while(1)
                    {
                      Motor(80,-80,0,0);
                      if(error_Yaw()>10)
                        {
                          Motor(0,0,0,0);delay(100);
                          do{Motor(-80,80,0,0);}while(error_Yaw()>1); 
                          Motor(80,-80,0,0); delay(40);
                          Motor(0,0,0,0);delay(200);
                          Motor(-81, 81, 81, -81);delay(250);
                          Motor(81, -81, -81, 81);delay(30);
                          Motor(0,0,0,0);delay(100);
                          Motor(80,80,80,80);delay(250);
                          Motor(-80,-80,-80,-80);delay(30);
                          Motor(0,0,0,0);delay(100);
                          goto sr;                    //-------------->>  กลัีบขึ้นไปไสลด์เช็คขวาใหม่
                        }
                      if(mcp_f(4)< md_mcp_f(4))
                        {
                          Motor(-80,80,0,0);delay(30);                        
                          Motor(0,0,0,0);delay(300); 
                          break;
                        }
                    }               
                }
              else
                {                   
                   //Motor(0,0,0,0);delay(200);
                }

              Motor(-60,60,60,-60);delay(100);
              Motor(0,0,0,0);delay(200);
              while(1)
                {
                  if(mcp_f(1)<md_mcp_f(1) || mcp_f(3)<md_mcp_f(3)) //----------------->> ถ้ามีเส้นดำด้านข้าง
                    {
                      Motor(0,0,0,0);delay(50);
                      if(mcp_f(1)<md_mcp_f(1)&& mcp_f(4)>md_mcp_f(4))
                        {
                          do{Motor(60,40,-60,60);}while(mcp_f(4)>md_mcp_f(4));
                          Motor(0,0,0,0);delay(300);
                          
                        }
                      else if(mcp_f(3)<md_mcp_f(3)&& mcp_f(4)>md_mcp_f(4))
                        {
                          do{Motor(60,-60,-60,-40);}while(mcp_f(4)>md_mcp_f(4));
                          Motor(0,0,0,0);delay(300);      
                                 
                        }
                      break;
                    }
                  else
                    {                   
                      Motor(40,-40,-40,40);
                    }
                }
              
              ch_line_r = 1;
              //Motor(-60,60,60,-60);delay(70);
              Motor(0,0,0,0);delay(300);

              calibration_Yak(); 
              encoderPoss=0;
              //while(encoderPoss < dis_line_r)      //----------------->> สไลออกมา 
              lasts_time = millis();
              while(millis() - lasts_time < 400)
                {                  
                  errors = error_Yaw();                  
                  I = 0;
                  previous_I = 0;
                  previous_error = 0;
                  P = errors;
                  I = I + previous_I;
                  D = errors - previous_error ;            
                  previous_I=I;
                  previous_error=errors  ;  
                  PID_output = (4 * P) + (0.00015 * I) +(10* D); 
                  
                  //Motor(-61, 61, 61, -61);
                  Motor(-(52 + PID_output), 52+PID_output, 52 - PID_output, -(52 - PID_output));
                 
               }
              Motor(61,-61,-61,61);delay(70);
              Motor(0,0,0,0);delay(300);
              break; 
            }          
       }
     if(ch_line_r == 0)  //------------------>>  ด้านข้างไม่มีเส้น
      {
        Motor(-60,60,60,-60);delay(70);
        Motor(0,0,0,0);delay(300);
        calibration_Yak(); 
        encoderPoss=0;
        while(encoderPoss < 250)   //----------------->> สไลซ้ายกลับมา       
           {                  
             errors = error_Yaw();
             I = 0;
             previous_I = 0;
             previous_error = 0;
             P = errors;
             I = I + previous_I;
             D = errors - previous_error ;            
             previous_I=I;
             previous_error=errors  ;  
             PID_output = (5 * P) + (0.00015 * I) +(10* D); 
                  
             Motor(-(52 + PID_output), 52+PID_output, 52 - PID_output, -(52 - PID_output));
             //Motor(-61, 61, 61, -61);    
           }
         Motor(61,-61,-61,61);delay(30);
         Motor(0,0,0,0);delay(400);

         begin_slide_L:delay(10);
         //-------------------------------------------->>> หมุน 90 องศา
         calibration_Yak(); 
         do{Motor(51,-51,51,-51);}while(error_Yaw()< deg_90_R);
         Motor(-61,61,-61,61);delay(60);
         Motor(0,0,0,0);delay(200);
         for(int i=0; i<5; i++)
          {
            sensor_maxs[i] = mcp_f(i);
            delay(10);
          }
            
      } 

    end_line:delay(10);
    encoderPoss=0; 
    ch_line_r = 0;
    calibration_Yak();
    ch_bridge = 0;
    bg_st = 0;
   
    
  }
void fw_begin(int sp, volatile int encoderPoss_fw)
  {
    
    encoderPoss = 0;
    while(encoderPoss < encoderPoss_fw)      
        {          
          check_color_roll();   
          errors = error_Yaw();
          I = 0;
          previous_I = 0;
          previous_error = 0;
          P = errors;
          I = I + previous_I;
          D = errors - previous_error ;            
          previous_I=I;
          previous_error=errors  ;  
          PID_output = (5 * P) + (0.00015 * I) +(8* D); 
          
          Motor(sp - PID_output, sp + PID_output, sp - PID_output, sp + PID_output); 
          if(digitalRead(26)==0)
            {
              chopsticks = 1;
              Motor(0,0,0,0);delay(10);
               encoderPoss=0; 
               while(encoderPoss < 280)
                  { 
                    errors = error_Yaw();
                    
                    I = 0;
                    previous_I = 0;
                    previous_error = 0;
                    P = errors;
                    I = I + previous_I;
                    D = errors - previous_error ;            
                    previous_I=I;
                    previous_error=errors  ;  
                    PID_output = (6 * P) + (0.00015 * I) +(15* D); 
                    
                    Motor(80 - PID_output, 80 + PID_output, 80 - PID_output, 80 + PID_output); 
                    if(digitalRead(26)==0)
                      {
                        chopsticks ++;    //-------> chopsticks = 1 คือ ตะเกียบ
                      }
                    
                  }               
               
              
               bridge();  ///---------------------->>  ขึ้นสะพานและตะเกียบ   1000 คือค่าที่วิ่งขึ้นไปกลางสะพาน หรือผ่านตะเกียบ
            }   
        }
      Motor(-50,-50,-50,-50);delay(50);
      Motor(0,0,0,0);delay(300);
     for(int i=0; i<5; i++)
      {
        sensor_maxs[i] = mcp_f(i);
        delay(10);
      }
      bg_st = 1;
  }
