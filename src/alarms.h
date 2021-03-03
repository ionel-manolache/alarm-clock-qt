#ifndef ALARMS_H
#define ALARMS_H

#include <QObject>

class Alarms : public QObject
{
    Q_OBJECT

public:
    explicit Alarms(QObject* parent = nullptr);

};

#endif // ALARMS_H
