#ifndef SANTAKWINDOW_H
#define SANTAKWINDOW_H

#include <QWidget>


class QPushButton;
class SantakWindow : public QWidget
{
 Q_OBJECT
 public:
  explicit SantakWindow(QWidget *parent = 0);
 private:
   QPushButton *clear_button;
   QPushButton *search_button;


 signals:
 public slots:
};

#endif // SANTAKWINDOW_H
