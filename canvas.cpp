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
        c++;
      } else {
        rect[c] = QRect(i*xlen-xlen+10, j*ylen-ylen+10, xlen, ylen);
        mod_info[c] = a;
        c++;
      }
    }
  }
}

void Canvas::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::darkGreen);
    int i = 0;
    for(i=0; i< mod_wx*mod_wx;i++){
      painter.eraseRect(rect[i]);
      painter.drawRect(rect[i]);
      painter.fillRect(rect[i],qRgb(256-mod_info[i]*4,128-mod_info[i]*4,mod_info[i]*2));
      if (512*zoom/mod_wx>= 32){
        painter.setPen(Qt::black);
        painter.drawText(rect[i],Qt::AlignCenter,QString::number(mod_info[i]));
      }
    }

    //Paint to PNG File
    /*
    QPixmap output;
    output.load("res/output.png");
    QPainter pixPaint(&output);
    pixPaint.setRenderHint(QPainter::Antialiasing);
    pixPaint.setPen(Qt::darkGreen);
    int it = 0;
    for(it=0; it< mod_wx*mod_wx;it++){
      pixPaint.eraseRect(rect[it]);
      pixPaint.drawRect(rect[it]);
      pixPaint.fillRect(rect[it],qRgb(256-mod_info[it]*4,128-mod_info[it]*4,mod_info[it]*2));
      if (512*zoom/mod_wx>= 32){
        pixPaint.setPen(Qt::black);
        pixPaint.drawText(rect[it],Qt::AlignCenter,QString::number(mod_info[it]));
      }
    }
    */

}
