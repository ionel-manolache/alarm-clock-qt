#include "application.h"

#include <QAction>
#include <QApplication>
#include <QMenu>
#include <QMessageBox>

#include "alarms.h"
#include "settings.h"
#include "alarmsdialog.h"
#include "preferencesdialog.h"

Application::Application(QObject *parent)
    : QObject(parent)
    , m_trayIcon(new QSystemTrayIcon(this))
    , m_settings(new Settings(this))
    , m_alarms(new Alarms(this))
    , m_preferencesDialog(new PreferencesDialog)
    , m_alarmsDialog(new AlarmsDialog)
{
    m_preferencesDialog->setSettings(m_settings);
    connect(m_preferencesDialog, &PreferencesDialog::accepted, this, &Application::onPreferencesSaved);

    m_alarmsDialog->setAlarms(m_alarms);
    connect(m_alarmsDialog, &AlarmsDialog::accepted, this, &Application::onAlarmsSaved);

    m_icon = QIcon(":/icons/alarm-clock.png");
    m_trayIcon->setIcon(m_icon);

    setupActions();

    setupContextMenu();
}

void Application::show()
{
    m_trayIcon->show();
}

void Application::onAbout()
{
    QMessageBox::about(nullptr, tr("About %1").arg(qApp->applicationName()), tr("Get up in the morning!").arg(qApp->applicationName()));
}

void Application::onPreferences()
{
    m_preferencesDialog->loadSettings();
    m_preferencesDialog->show();
}

void Application::onPreferencesSaved()
{
    // TODO: save preferences here
}

void Application::onAlarms()
{
    m_alarmsDialog->loadAlarms();
    m_alarmsDialog->show();
}

void Application::onAlarmsSaved()
{
    // TODO: save alarms here
}

void Application::loadSettings()
{
    // TODO: load settings
}

void Application::saveSettings()
{
    // TODO: save settings
}

void Application::setupActions()
{
    m_aboutAction = new QAction(tr("About %1").arg(qApp->applicationName()), this);
    m_alarmsAction = new QAction(tr("Alarms..."), this);
    m_preferencesAction = new QAction(tr("Preferences..."), this);

    connect(m_aboutAction, &QAction::triggered, this, &Application::onAbout);
    connect(m_alarmsAction, &QAction::triggered, this, &Application::onAlarms);
    connect(m_preferencesAction, &QAction::triggered, this, &Application::onPreferences);
}

void Application::setupContextMenu()
{
    QAction* quit = new QAction(tr("Quit"), this);
    quit->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q));
    connect(quit, &QAction::triggered, qApp, &QApplication::quit);

    QMenu* contextMenu = new QMenu();
    contextMenu->addAction(m_aboutAction);
    contextMenu->addAction(m_alarmsAction);
    contextMenu->addAction(m_preferencesAction);

    m_trayIcon->setContextMenu(contextMenu);
}
