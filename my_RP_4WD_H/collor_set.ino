void check_color_roll()
  {
     float red, green, blue;
     uint16_t r, g, b, c;
     tcss.getRawData(&r, &g, &b, &c);     
     float averag = (r+g+b)/3;
     red = r/averag; ;
     green = g/averag; 
     blue = b/averag;
     if(red > _coolor_red[0]-0.35 && red < _coolor_red[0]+0.35)
        {
          color_ch = "red";
        }
      //else if(green > 1.35 && blue > red  )
     else if(red > _coolor_green[0]-0.25 && red < _coolor_green[0]+0.25 && green > _coolor_green[1]-0.25 && green < _coolor_green[1]+0.25 )
        {
          color_ch = "green";
        } 
     else if(blue > _coolor_blue[2]-0.25 && blue < _coolor_blue[2]+0.25)
        {
          color_ch = "blue";
        }
      //else if(red >1.3 && red <1.6 && green > blue )
     else if(red > _coolor_yello[0]-0.25 && red < _coolor_yello[0]+0.25&& green > _coolor_yello[1]-0.25 && green < _coolor_yello[1]+0.25  )
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
     if(red > _coolor_red[0]-0.35 && red < _coolor_red[0]+0.35)
        {
          bz(50);
          bz(300);
          color_ch = "red";
        }
      //else if(green > 1.35 && blue > red  )
      else if(red > _coolor_green[0]-0.25 && red < _coolor_green[0]+0.25 && green > _coolor_green[1]-0.25 && green < _coolor_green[1]+0.25 )
        {
          bz(50);
          bz(50);
          bz(300);
          color_ch = "green";
        } 
      else if(blue > _coolor_blue[2]-0.25 && blue < _coolor_blue[2]+0.25)
        {
          bz(50);
          bz(50);
          bz(50);
          bz(300);
          color_ch = "blue";
        }
      //else if(red >1.3 && red <1.6 &&green > blue )
      else if(red > _coolor_yello[0]-0.25 && red < _coolor_yello[0]+0.25&& green > _coolor_yello[1]-0.25 && green < _coolor_yello[1]+0.25  )
        {
          bz(50);
          bz(50);
          bz(50);
          bz(300);
          bz(300);
          color_ch = "yello";
        }
      else
        {
          color_ch = "none";
        }
  }
