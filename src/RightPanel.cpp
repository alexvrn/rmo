#include "RightPanel.h"
#include "ui_RightPanel.h"

RightPanel::RightPanel(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::RightPanel)
{
    ui->setupUi(this);
}

RightPanel::~RightPanel()
{
    delete ui;
}
