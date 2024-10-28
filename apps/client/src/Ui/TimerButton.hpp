#pragma once

#include <QTimer>
#include <QLabel>
#include <QPushButton>

class TimerButton : public QObject {
    Q_OBJECT

public:
    explicit TimerButton(QPushButton *button, QLabel *timeLeft, QObject *parent = nullptr);
    ~TimerButton() = default;

    void startTimer(const int &time);
    void stopTimer();

private slots:
    void onButtonClicked();
    void onTimerTimeout();
    void onUpdateTimerTimeout();

private:
    void setupConnections();

    QPushButton *m_button;
    QLabel *m_label;
    QTimer *m_timer;
    QTimer *m_updateTimer;

    int m_time;

};