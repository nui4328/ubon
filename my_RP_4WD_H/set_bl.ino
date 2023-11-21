void set_bl(int num)
  {
    Motor(0,0,0,0);delay(50);
    encoderPoss=0;
    do{Motor(-55,-55,-55,-55);}while(encoderPoss > -40);
    for(int i=0; i< num; i++)
      {      
        
        while(1)
          {
            if(mcp_f(0)<md_sensors(0)+150 && mcp_f(1)> md_sensors(1))
              {
                do{Motor(-10,60,-10,60);}while(mcp_f(1)> md_sensors(1)+150);
                //Motor(0,0,0,0);delay(150);
                break;
              }
            else if(mcp_f(0)> md_sensors(0) && mcp_f(1)<md_sensors(1)+150)
              {
                do{Motor(60,-10,60,-10);}while(mcp_f(0)>md_sensors(0)+150);
                //Motor(0,0,0,0);delay(150);
                break;
              }
            else if(mcp_f(0)< md_sensors(0)+150&& mcp_f(1)<md_sensors(1)+150)
              {
                //Motor(0,0,0,0);delay(150);
                break;
              }
            else
              {
                Motor(55,55,55,55);
              }
          }
        Motor(0,0,0,0);delay(200);
        encoderPoss=0;
        do{Motor(-70,-70,-70,-70);}while(encoderPoss > -20);
        Motor(0,0,0,0);delay(250);
        while(1)
          {
            if(mcp_f(0)<md_sensors(0)+150 && mcp_f(1)> md_sensors(1))
              {
                do{Motor(-10,70,-10,70);}while(mcp_f(1)>md_sensors(1)+150);
                //Motor(0,0,0,0);delay(150);
                break;
              }
            else if(mcp_f(0)> md_sensors(0)+150 && mcp_f(1)<md_sensors(1)+150)
              {
                do{Motor(70,-10,70,-10);}while(mcp_f(0)>md_sensors(0)+150);
                //Motor(0,0,0,0);delay(150);
                break;
              }
            else if(mcp_f(0)< md_sensors(0)+150&& mcp_f(1)<md_sensors(1)+150)
              {
                //Motor(0,0,0,0);delay(150);
                break;
              }
            else
              {
                Motor(65,65,65,65);
              }
          }
         Motor(0,0,0,0);delay(200);
      }
  }

void set_bl_min(int num)
  {
    encoderPoss=0;
    do{Motor(-65,-65,-65,-65);}while(encoderPoss > -70);
    for(int i=0; i< num; i++)
      {      
        
        while(1)
          {
            if(mcp_f(0)<md_sensors(0)+150 && mcp_f(1)> md_sensors(1))
              {
                do{Motor(-10,60,-10,60);}while(mcp_f(1)> md_sensors(1)+150);
                //Motor(0,0,0,0);delay(150);
                break;
              }
            else if(mcp_f(0)> md_sensors(0) && mcp_f(1)<md_sensors(1)+150)
              {
                do{Motor(60,-10,60,-10);}while(mcp_f(0)>md_sensors(0)+150);
                //Motor(0,0,0,0);delay(150);
                break;
              }
            else if(mcp_f(0)< md_sensors(0)+150&& mcp_f(1)<md_sensors(1)+150)
              {
                //Motor(0,0,0,0);delay(150);
                break;
              }
            else
              {
                Motor(50,50,50,50);
              }
          }
        Motor(0,0,0,0);delay(100);
        encoderPoss=0;
        do{Motor(-70,-70,-70,-70);}while(encoderPoss > -30);
        Motor(0,0,0,0);delay(150);
        while(1)
          {
            if(mcp_f(0)<md_sensors(0)+150 && mcp_f(1)> md_sensors(1))
              {
                do{Motor(-10,70,-10,70);}while(mcp_f(1)>md_sensors(1)+150);
                //Motor(0,0,0,0);delay(150);
                break;
              }
            else if(mcp_f(0)> md_sensors(0)+150 && mcp_f(1)<md_sensors(1)+150)
              {
                do{Motor(70,-10,70,-10);}while(mcp_f(0)>md_sensors(0)+150);
                //Motor(0,0,0,0);delay(150);
                break;
              }
            else if(mcp_f(0)< md_sensors(0)+150&& mcp_f(1)<md_sensors(1)+150)
              {
                //Motor(0,0,0,0);delay(150);
                break;
              }
            else
              {
                Motor(50,50,50,50);
              }
          }
         Motor(0,0,0,0);delay(200);
      }
  }
void set_bl_yello(int num)
  {
    for(int i=0; i<6; i++)
      {
        sensor_maxs[i] = mcp_f(i);
        delay(10);
      }
    encoderPoss=0;
    while(mcp_f(0)>sensor_maxs[0]-200)
      {
        Motor(45,45,45,45);
        if(encoderPoss > 120)
          {              
            Motor(0,0,0,0);delay(50);   
            check_color_roll_bz(); 
            if(color_ch == "none")
              {                
                none_yello = 1;  //------------->>> ตัวแปร ไม่ใช่เหลือง
                break;                
              }
            else{break;}
          }
      }
    if(none_yello == 1)
      {
        goto en_ch_yelo;
      }
    Motor(0,0,0,0);delay(100);
    encoderPoss=0;
    do{Motor(-60,-60,-60,-60);}while(encoderPoss > -30);
    Motor(0,0,0,0);delay(50);
    for(int i=0; i< num; i++)
      {          
        while(1)
          {
            if(mcp_f(0)< md_sensors(0)-100 && mcp_f(1)>sensor_maxs[1]-150)
              {
                do{Motor(-20, 55,-20, 55);}while(mcp_f(1)> md_sensors(0));
                
                break;
              }
            else if(mcp_f(0)> md_sensors(0) && mcp_f(1)< md_sensors(0)-100)
              {
                do{Motor(55,-20,55,-20);}while(mcp_f(0)>md_sensors(0));
                
                break;
              }
            else if(mcp_f(0)< md_sensors(0)-100 && mcp_f(1)<md_sensors(0)-100)
              {
                
                break;
              }
            else
              {
                Motor(55,55,55,55);
              }
          }
        Motor(0,0,0,0);delay(50);
        encoderPoss=0;
        do{Motor(-50,-50,-50,-50);}while(encoderPoss > -30);
        Motor(0,0,0,0);delay(50);
        
      }
    while(1)
          {
             if(mcp_f(0)< md_sensors(0)-100 && mcp_f(1)>sensor_maxs[1]-150)
              {
                do{Motor(-20, 55,-20, 55);}while(mcp_f(1)> md_sensors(0));
                
                break;
              }
            else if(mcp_f(0)> md_sensors(0) && mcp_f(1)< md_sensors(0)-100)
              {
                do{Motor(55,-20,55,-20);}while(mcp_f(0)>md_sensors(0));
                
                break;
              }
            else if(mcp_f(0)< md_sensors(0)-100 && mcp_f(1)<md_sensors(0)-100)
              {
                
                break;
              }
            else
              {
                Motor(55,55,55,55);
              }
          }
         en_ch_yelo: delay(10);
         Motor(0,0,0,0);delay(200);
  }
void set_cop()
  {
    while(1)
          {
            if(mcp_f(0)<md_sensors(0) && mcp_f(1)>md_sensors(1))
              {
                do{Motor(-20,50,-20,50);}while(mcp_f(1)>md_sensors(1));
                Motor(0,0,0,0);delay(200);
                break;
              }
            else if(mcp_f(0)> md_sensors(0) && mcp_f(1)<md_sensors(1))
              {
                do{Motor(50,-20,50,-20);}while(mcp_f(0)>md_sensors(0));
                Motor(0,0,0,0);delay(200);
                break;
              }
            else if(mcp_f(0)< md_sensors(0) && mcp_f(1)<md_sensors(1))
              {
                break;
              }
            else
              {
                Motor(40,40,40,40);
              }
          }
         Motor(0,0,0,0);delay(300);
     
  }
void bw(int sp, volatile int tm)
  {
    calibration_Yak();
    encoderPoss=0;
    while(encoderPoss > -tm)     
        {
          errors = error_Yaw_float();
          I = 0;
          previous_I = 0;
          previous_error = 0;
          P = errors;
          I = I + previous_I;
          D = errors - previous_error ;            
          previous_I=I;
          previous_error=errors  ;  
          PID_output = (6 * P) + (0.00015 * I) +(8* D); 
          
          Motor(-(sp + PID_output), -(sp - PID_output), -(sp + PID_output), -(sp - PID_output));
                 
       }
     Motor(sp,sp,sp,sp);delay(30);
     Motor(0,0,0,0);delay(300);

  }

void slide_l_online()
  {
    Motor(0,0,0,0);delay(200);
    encoderPoss=0;
    while(encoderPoss < 285) 
      {
        errors = error_Yaw_float();
        I = 0;
        previous_I = 0;
        previous_error = 0;
        P = errors;
        I = I + previous_I;
        D = errors - previous_error ;            
        previous_I=I;
        previous_error=errors  ;  
        PID_output = (6 * P) + (0.00015 * I) +(10* D); 
                
        Motor(-(52 + PID_output), 52+PID_output, 52 - PID_output, -(52 - PID_output));  //------> สไลซ้ายเข้าหาเส้น  
        if(mcp_f(0)<md_sensors(0)&& mcp_f(2)>md_sensors(2))
            {
               encoderPoss=0;
               while(mcp_f(2)> md_mcp_f(2))
                    {
                      Motor(10,-10,70,-70);
                      if(error_Yaw()>10)
                        {
                          Motor(0,0,0,0);delay(300); 
                          do{ Motor(0,0,-70,70);}while(error_Yaw()>1);
                          Motor(0,0,0,0);delay(200);                         
                          goto en_mcp2;                
                        }
                    } 
            }
           else if(mcp_f(2)<md_sensors(2)&& mcp_f(0)>md_sensors(0))
             {
               do{Motor(-70,70,-10,10);}while(mcp_f(0)>md_sensors(0));
               Motor(70,-70,0,0);delay(50);   
               Motor(0,0,0,0);delay(50); 
                         
             }
           else if(mcp_f(2)<md_sensors(2)+50&& mcp_f(0)<md_sensors(0)+50)
             {  
               Motor(50,-50,-50,50);delay(30);
               Motor(0,0,0,0);delay(200); 
               ch_line_l = 1;               
               break;              
             }

         }
       en_mcp2:delay(10);
       Motor(0,0,0,0);delay(200);    
       if(ch_line_l == 1)
         {
           encoderPoss=0;
           while(encoderPoss > -120)   //-------------------->>  สไลขวาเข้ามา     
             {                  
                 errors = error_Yaw_float();
                 I = 0;
                 previous_I = 0;
                 previous_error = 0;
                 P = errors;
                 I = I + previous_I;
                 D = errors - previous_error ;            
                 previous_I=I;
                 previous_error=errors  ;  
                 PID_output = (7 * P) + (0.00015 * I) +(15* D); 
                                  
                 Motor(52-PID_output, -(52 - PID_output),-(52 + PID_output), 52 + PID_output);
                               
              }
            Motor(-61,61,61,-61);delay(30);
            Motor(0,0,0,0);delay(300);
            //-------------------------------------------->>> หมุน 180 องศา
            setup_mpu();
            encoderPoss=0; 
            calibration_Yak();
            encoderPoss=0; 
            calibration_Yak();
            calibration_Yak(); 
            do{Motor(51,-51,51,-51);}while(error_Yaw_float()<174);
            Motor(-51,51,-51,51);delay(80);
            Motor(0,0,0,0);delay(300);
             
         }
       else
          {
            encoderPoss=0;
            while(encoderPoss > -200)        
               {                  
                  errors = error_Yaw_float();
                  I = 0;
                  previous_I = 0;
                  previous_error = 0;
                  P = errors;
                  I = I + previous_I;
                  D = errors - previous_error ;            
                  previous_I=I;
                  previous_error=errors  ;  
                  PID_output = (7 * P) + (0.00015 * I) +(15* D); 
                                    
                  Motor(61-PID_output, -(61 - PID_output),-(61 + PID_output), 61 + PID_output);
                                   
                }
              Motor(-61,61,61,-61);delay(30);
              Motor(0,0,0,0);delay(300);
                  
                           //-------------------------------------------->>> หมุน 90 องศา
              setup_mpu();
              encoderPoss=0; 
              calibration_Yak();
              encoderPoss=0; 
              calibration_Yak();
              do{Motor(-51,51,-51,51);}while(error_Yaw_float()> -deg_90_R);
              Motor(61,-61,61,-61);delay(70);
              Motor(0,0,0,0);delay(300);
          }
       ch_line_l =0;
  }

void ch_l_chopstick()
  {
    encoderPoss=0;
    //while(encoderPoss < 265)  
    lasts_time = millis();
    while(millis() - lasts_time < 800)       
        { 
   
          if(mcp_f(0)<md_sensors(0)&& mcp_f(2)>md_sensors(2))
            {
               do{Motor(10,-10,70,-70);}while(mcp_f(2)>md_sensors(2));
               Motor(0,0,-70,70);delay(70);
               Motor(0,0,0,0);delay(200);
               ch_line_l = 1;
               break; 
            }
           else if(mcp_f(2)<md_sensors(2)&& mcp_f(0)>md_sensors(0))
             {
               do{Motor(-70,70,-10,10);}while(mcp_f(0)>md_sensors(0));
               Motor(70,-70,0,0);delay(70);   
               Motor(0,0,0,0);delay(200); 
               ch_line_l = 1;
               break;              
             }
           else if(mcp_f(2)<md_sensors(2)&& mcp_f(0)<md_sensors(0))
             {  
               Motor(0,0,0,0);delay(200); 
               ch_line_l = 1;
               break;              
             }
           else
             {
                errors = error_Yaw_float();
                I = 0;
                previous_I = 0;
                previous_error = 0;
                P = errors;
                I = I + previous_I;
                D = errors - previous_error ;            
                previous_I=I;
                previous_error=errors  ;  
                PID_output = (6 * P) + (0.00015 * I) +(10* D); 
                
                Motor(-(52 + PID_output), 52+PID_output, 52 - PID_output, -(52 - PID_output));  //------> สไลซ้ายเข้าหาเส้น           
             }
         }   
       if(ch_line_l == 1)
         {
           encoderPoss=0;
           while(encoderPoss > -140)   //-------------------->>  สไลขวาออกมา     
             {                  
                 errors = error_Yaw_float();
                 I = 0;
                 previous_I = 0;
                 previous_error = 0;
                 P = errors;
                 I = I + previous_I;
                 D = errors - previous_error ;            
                 previous_I=I;
                 previous_error=errors  ;  
                 PID_output = (7 * P) + (0.00015 * I) +(15* D); 
                                  
                 Motor(52-PID_output, -(52 - PID_output),-(52 + PID_output), 52 + PID_output);
                               
              }
            Motor(-61,61,61,-61);delay(30);
            Motor(0,0,0,0);delay(300);
             
         }
       else
          {
            encoderPoss=0;
            while(encoderPoss > -200)        
               {                  
                  errors = error_Yaw_float();
                  I = 0;
                  previous_I = 0;
                  previous_error = 0;
                  P = errors;
                  I = I + previous_I;
                  D = errors - previous_error ;            
                  previous_I=I;
                  previous_error=errors  ;  
                  PID_output = (7 * P) + (0.00015 * I) +(15* D); 
                                    
                  Motor(61-PID_output, -(61 - PID_output),-(61 + PID_output), 61 + PID_output);
                                   
                }
              Motor(-61,61,61,-61);delay(30);
              Motor(0,0,0,0);delay(300);
                  
                           //-------------------------------------------->>> หมุน 90 องศา
              setup_mpu();
              encoderPoss=0; 
              calibration_Yak();
              encoderPoss=0; 
              calibration_Yak();
              do{Motor(-51,51,-51,51);}while(error_Yaw_float()> -85);
              Motor(51,-51,51,-51);delay(70);
              Motor(0,0,0,0);delay(300);
          }
    
     
  }
void slide_r()
  {
    //do{Motor(50,50,50,50);}while(mcp_f(0)>md_sensors(0));
    Motor(0,0,0,0);delay(200);
    calibration_Yak();
    encoderPoss=0;
    while(1)           
        {          
          errors = error_Yaw_float();
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
          if(mcp_f(4)<md_sensors(4) || mcp_f(3)<md_sensors(3)) //----------------->> ถ้ามีเส้นดำด้านข้าง
            {
              ch_line = 1;
              Motor(-80,80,80,-80);delay(60);
              Motor(0,0,0,0);delay(100);
              
              encoderPoss=0;
              while(encoderPoss < 120)      //----------------->> สไลออกมา 
                {                  
                  errors = error_Yaw_float();
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

  }
 
