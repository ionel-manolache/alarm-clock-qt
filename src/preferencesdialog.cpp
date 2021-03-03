#include "preferencesdialog.h"
#include "ui_preferencesdialog.h"

#include "settings.h"

PreferencesDialog::PreferencesDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PreferencesDialog)
{
    ui->setupUi(this);

    connect(this, &QDialog::accepted, this, &PreferencesDialog::onAccepted);
}

PreferencesDialog::~PreferencesDialog()
{
    delete ui;
}

void PreferencesDialog::setSettings(Settings *settings)
{
    m_settings = settings;
}

void PreferencesDialog::loadSettings()
{
    // TODO: load settings
}

void PreferencesDialog::onAccepted()
{
    // TODO: save settings
    // like:
    // m_settings->setStuff(stuff);
}
