#ifndef APPLICATION_H
#define APPLICATION_H

#include <QIcon>
#include <QObject>
#include <QSystemTrayIcon>

class QAction;

class Alarms;
class AlarmsDialog;
class PreferencesDialog;
class Settings;

class Application : public QObject
{
    Q_OBJECT
public:
    explicit Application(QObject *parent = nullptr);

    void show();

private slots:
    void onAbout();

    void onPreferences();
    void onPreferencesSaved();

    void onAlarms();
    void onAlarmsSaved();

private:
    void loadSettings();
    void saveSettings();

    void setupActions();
    void setupContextMenu();

private:
    QSystemTrayIcon *m_trayIcon{nullptr};

    QAction* m_aboutAction{nullptr};
    QAction* m_alarmsAction{nullptr};
    QAction* m_preferencesAction{nullptr};

    Settings* m_settings{nullptr};
    Alarms* m_alarms{nullptr};

    PreferencesDialog* m_preferencesDialog{nullptr};
    AlarmsDialog* m_alarmsDialog{nullptr};

    QIcon m_icon;
};

#endif // APPLICATION_H
