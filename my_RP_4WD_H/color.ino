void check_color_roll()
  {
     float red, green, blue;
     uint16_t r, g, b, c;
     tcss.getRawData(&r, &g, &b, &c);     
     float averag = (r+g+b)/3;
     red = r/averag; ;
     green = g/averag; 
     blue = b/averag;
      if(red > 1.4 )
        {
          color_ch = "red";
        }
      //else if(green > 1.35 && blue > red  )
     else if(green > 1.35  && red < blue )
        {
          color_ch = "green";
        } 
     else if(blue > 1.3 )
        {
          color_ch = "blue";
        }
      //else if(red >1.3 && red <1.6 && green > blue )
     else if(green > 1.20  && red > blue )
        {
          color_ch = "yello";
        }
     else
        {
          color_ch = "none";
        }
  }

void check_color_roll_bz()
  {
     float red, green, blue;
     uint16_t r, g, b, c;
     tcss.getRawData(&r, &g, &b, &c);     
     float averag = (r+g+b)/3;
     red = r/averag; ;
     green = g/averag; 
     blue = b/averag;
      if(red > 1.4 )
        {
          bz(50);
          bz(300);
          color_ch = "red";
        }
      //else if(green > 1.35 && blue > red  )
      else if(green >1.35  && red < blue )
        {
          bz(50);
          bz(50);
          bz(300);
          color_ch = "green";
        } 
      else if(blue > 1.3 )
        {
          bz(50);
          bz(50);
          bz(50);
          bz(300);
          color_ch = "blue";
        }
      //else if(red >1.3 && red <1.6 &&green > blue )
      else if(green >1.20  && red > blue )
        {
          bz(50);
          bz(50);
          bz(50);
          bz(50);
          bz(300);
          color_ch = "yello";
        }
      else
        {
          color_ch = "none";
        }
  }
