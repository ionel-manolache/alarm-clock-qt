#ifndef ALARMSDIALOG_H
#define ALARMSDIALOG_H

#include <QDialog>

class Alarms;

namespace Ui
{
class AlarmsDialog;
}

class AlarmsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AlarmsDialog(QWidget *parent = nullptr);
    ~AlarmsDialog();

    void setAlarms(Alarms* alarms);
    void loadAlarms();

private slots:
    void onAccepted();

private:
    Ui::AlarmsDialog *ui;

    Alarms* m_alarms{nullptr};
};

#endif // ALARMSDIALOG_H
