void bridge()
  {
    String sen = String (chopsticks);
    mydisplay_background(black);
    mydisplay(sen, 20, 10, 2, white); 
    encoderPoss=0;   
    if(chopsticks < 20)
      {
        lasts_time = millis();
        while(millis() - lasts_time < 1200)
        //while(encoderPoss < time_chopsticks)      
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
              PID_output = (8 * P) + (0.00015 * I) +(15* D); 
              
              Motor(80 - PID_output, 80 + PID_output, 80 - PID_output, 80 + PID_output); 
           
           }
       Motor(-60,-60,-60,-60);delay(70);
       Motor(0,0,0,0);delay(300);
       ch_l_chopstick();  //---------->>สไลเช็คซ้าย
      
        goto end_bridge;
      }
    else
      {
          Motor(0,0,0,0);delay(200);
          encoderPoss = 0;
          while(encoderPoss < time_bridge)      
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
                PID_output = (6 * P) + (0.00015 * I) +(15* D); 
                
                Motors(70 - PID_output, 70 + PID_output, 70 - PID_output, 70 + PID_output); 

              }
          Motor(0,0,0,0);delay(200);
      }

    re_bri: delay(10);
    
    ch_line_r = 0;
    while(digitalRead(26)==1)     //----->> เดินลงสะพาน 
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
          PID_output = (6 * P) + (0.00015 * I) +(15* D); 
          
          Motors(50 - PID_output, 50 + PID_output, 50 - PID_output, 50 + PID_output); 
          if(mcp_f(0) > md_sensors(0) && mcp_f(1) < md_sensors(1)-50)
            {
              ch_r = 1;
              Motor(-50,50,50,-50);
            }
          else if(mcp_f(0) < md_sensors(0)-50 && mcp_f(1) > md_sensors(1))
            {
              ch_l = 1;
              Motor(50,-50,-50,50);
            }
          else if(mcp_f(0) < md_sensors(0)-100 && mcp_f(1) < md_sensors(1)-100)
            {              
               Motor(-70,-70,-70,-70);delay(100);
               Motor(0,0,0,0);delay(200);  
               ch_line_bridge ++;             
               set_bl(1);
               if(ch_line_bridge == 1)
                 {
                   bw(45, 120);
                    //-------------------------------------------->>> หมุน 90 องศา
                   calibration_Yak(); 
                   do{Motor(61,-61,61,-61);}while(error_Yaw()< deg_90_R);
                   Motor(-61,61,-61,61);delay(80);
                   Motor(0,0,0,0);delay(200);
                   
                   for(int i=0; i<5; i++)
                    {
                      sensor_maxs[i] = mcp_f(i);
                      delay(10);
                    }
                  }
                else
                  {
                    bw(45, 120);
                     //-------------------------------------------->>> หมุน 180 องศา
                     calibration_Yak(); 
                     do{Motor(61,-61,61,-61);}while(error_Yaw()< 178);
                     Motor(-61,61,-61,61);delay(100);
                     Motor(0,0,0,0);delay(200);
                     
                     for(int i=0; i<5; i++)
                      {
                        sensor_maxs[i] = mcp_f(i);
                        delay(10);
                      }
                  }
               calibration_Yak(); 
               goto re_bri;  //------------->> กลับขึ้นข้างบน ลงสะพานใหม่
            }  
         
       }
     
      encoderPoss=0; 
      while(encoderPoss < 360)     //----->> เดินลงสะพาน 
        {          
          //check_color_roll();
          errors = error_Yaw();
          I = 0;
          previous_I = 0;
          previous_error = 0;
          P = errors;
          I = I + previous_I;
          D = errors - previous_error ;            
          previous_I=I;
          previous_error=errors  ;  
          PID_output = (5 * P) + (0.00015 * I) +(15* D); 
          
          Motor(55 - PID_output, 55 + PID_output, 55 - PID_output, 55 + PID_output);  
         
       }
    Motor(-60,-60,-60,-60);delay(70);
    Motor(0,0,0,0);delay(300);
    if(ch_l == 1 && ch_r == 0)
      {
        encoderPoss=0;                                    
        do{Motor(50,-50,-50,50);}while(encoderPoss > -50);
        Motor(0,0,0,0);delay(100);
      }
    else if(ch_r == 1 && ch_l == 0)
      {
        encoderPoss=0;                                    
        do{Motor(-50,50,50,-50);}while(encoderPoss < 50);
        Motor(0,0,0,0);delay(100);
      }
    else{}
    end_bridge:delay(10);
    ch_r=0;
    ch_l=0;
    encoderPoss=0; 
    ch_line_bridge = 0;
    calibration_Yak();
    
    chopsticks = 0;   
  }


void slide_l_blalan()
  {
    encoderPoss=0;
    while(encoderPoss < 1000)        
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
          
          Motor(-(65 + PID_output), 65+PID_output, 65 - PID_output, -(65 - PID_output));
          if(mcp_f(0)<md_sensors(0) || mcp_f(2)<md_sensors(2))
            {
              Motor(70,-70,-70,70);delay(100);
              Motor(0,0,0,0);delay(100); 
              if(mcp_f(0)<md_sensors(0)&& mcp_f(2)>md_sensors(2))
                {
                  do{Motor(10,-10,70,-70);}while(mcp_f(2)>md_sensors(2));
                  Motor(0,0,-70,70);delay(70);
                  Motor(0,0,0,0);delay(200);
                  break; 
                }
              else if(mcp_f(2)<md_sensors(2)&& mcp_f(0)>md_sensors(0))
                {
                  do{Motor(-70,70,-10,10);}while(mcp_f(0)>md_sensors(0));
                  Motor(70,-70,0,0);delay(70);   
                  Motor(0,0,0,0);delay(200); 
                  break;              
                }
              else
                {                   
                   Motor(0,0,0,0);delay(200);
                   break; 
                }

             }
        }
       encoderPoss=0;
       while(encoderPoss > -180)     //----------------------->> สไลขวาออกมา     
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
             PID_output = (7 * P) + (0.00015 * I) +(10* D); 
                  
             Motor(65-PID_output, -(65 - PID_output),-(65 + PID_output), 65 + PID_output);
                 
           }
         Motor(-55,55,55,-55);delay(50);
         Motor(0,0,0,0);delay(300);
    
  }
