#ifndef PREFERENCESDIALOG_H
#define PREFERENCESDIALOG_H

#include <QDialog>

class Settings;

namespace Ui
{
class PreferencesDialog;
}

class PreferencesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PreferencesDialog(QWidget *parent = nullptr);
    ~PreferencesDialog();

    void setSettings(Settings* settings);

    void loadSettings();

private slots:
    void onAccepted();

private:
    Ui::PreferencesDialog* ui;

    Settings* m_settings{nullptr};
};

#endif // PREFERENCESDIALOG_H
