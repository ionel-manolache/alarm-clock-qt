#include "alarmsdialog.h"
#include "ui_alarmsdialog.h"

#include "alarms.h"

AlarmsDialog::AlarmsDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AlarmsDialog)
{
    ui->setupUi(this);

    connect(this, &QDialog::accepted, this, &AlarmsDialog::onAccepted);
}

AlarmsDialog::~AlarmsDialog()
{
    delete ui;
}

void AlarmsDialog::setAlarms(Alarms* alarms)
{
    // TODO: set alarms
}

void AlarmsDialog::loadAlarms()
{
    // TODO: load alarms
}

void AlarmsDialog::onAccepted()
{
    // TODO: save alarms
}
