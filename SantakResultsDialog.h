//results dialog display

#include <QWidget>
#include <QDialog>
#include "SantakChar.h"

class SantakResultsDialog: public QDialog{
  Q_OBJECT
  public:
    //constructor with vector of SantakChar objects
    SantakResultsDialog(QWidget *parent, std::vector<SantakChar> char_list);

};
