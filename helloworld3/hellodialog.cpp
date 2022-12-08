#include "hellodialog.h"
#include "ui_hellodialog.h"

HelloDialog::HelloDialog(QWidget *parent)
QDialog(parent);
{
ui = new HelloDialog;
ui->setupUi(this);
}

HelloDialog::~HelloDialog()
{
    delete ui;
}
