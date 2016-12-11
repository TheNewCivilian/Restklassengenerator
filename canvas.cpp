#include "canvas.h"

Canvas::Canvas()
{
    QPalette palette(Canvas::palette());
    palette.setColor(backgroundRole(), Qt::white);
    setPalette(palette);
    zoom = 1;
    invert = 0;
    setMinimumSize(512*zoom,512*zoom);
}

void Canvas::setZoom(int x)
{
  zoom = x;
  setMinimumSize(512*zoom,512*zoom);
}

void Canvas::setInvert()
{
  if (invert == 0){
    invert = 1;
  }else{
    invert = 0;
  }
}

void Canvas::setValue(int x){
  int f;
  for (f = 0; f<= mod_wx*mod_wx; f++){
    rect[f] = QRect(0,0,0,0);
  }
  mod_wx = x;
  int i = 1, j = 1,c = 0;
  int xlen = 512*zoom/mod_wx;
  int ylen = 512*zoom/mod_wx;
  for(i= 1;i<mod_wx ;i++) {
    for(j=1; j<mod_wx ;j++){
      int a = (i*j)%mod_wx ;
      if(a > mod_wx/2) {

        rect[c] = QRect(i*xlen-xlen+10, j*ylen-ylen+10, xlen, ylen);
        if (invert == 1){
          mod_info[c] = (mod_wx -a)*-1;
        }else{
          mod_info[c] = a;
        }
        //painter.drawText(rect, Qt::AlignCenter,"0"); //(mod_wx -a)*-1
        //printf("%4i", (mod_x -a)*-1);
        c++;
      } else {
        rect[c] = QRect(i*xlen-xlen+10, j*ylen-ylen+10, xlen, ylen);
        mod_info[c] = a;
        //painter.drawText(rect, Qt::AlignCenter,"0");
        //printf("%4i", a);
        c++;
      }
    }
    //printf("\n");
  }
  //printf("Test");
}

void Canvas::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::darkGreen);
    int i = 0;
    //painter.drawRect(1, 1, mod_wx, mod_wx);
    //rect[1] = QRect(10, 10, i, 2*mod_wx);
    for(i=0; i< mod_wx*mod_wx;i++){
      painter.eraseRect(rect[i]);
      painter.drawRect(rect[i]);
      painter.fillRect(rect[i],qRgb(256-mod_info[i]*4,128-mod_info[i]*4,mod_info[i]*2));
      if (512*zoom/mod_wx>= 32){
        painter.setPen(Qt::black);
        painter.drawText(rect[i],Qt::AlignCenter,QString::number(mod_info[i]));
      }
    }
    //RgB(r,g,b)
    //painter.fillRect(rect[1],qRgb(232,121,10));
    //painter.drawLine(2, 8, 6, 2);

}
