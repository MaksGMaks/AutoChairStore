#include "TimerButton.hpp"

TimerButton::TimerButton(QPushButton *button, QLabel *timeLeft, QObject *parent)
: QObject(parent)
, m_button(button)
, m_label(timeLeft) {
    m_timer = new QTimer(this);
    m_updateTimer = new QTimer(this);
    m_time = 0;

    setupConnections();
}

void TimerButton::startTimer(const int &time) {
    m_time = time;
    m_label->setText(QString::number(m_time) + "s");
    m_timer->start(time * 1000);
    m_updateTimer->start(1000);
}

void TimerButton::stopTimer() {
    m_timer->stop();
    m_updateTimer->stop();
    m_time = 0;
    m_label->setText("");
    m_button->setEnabled(true);
}

void TimerButton::onButtonClicked() {
    m_button->setEnabled(false);
    startTimer(60);
}

void TimerButton::onTimerTimeout() {
    stopTimer();
}

void TimerButton::onUpdateTimerTimeout() {
    m_time--;
    if(m_time > 0) {
        m_label->setText(QString::number(m_time) + "s");
    } else {
        m_label->setText("");
        m_updateTimer->stop();
    }
}

void TimerButton::setupConnections() {
    connect(m_button, &QPushButton::clicked, this, &TimerButton::onButtonClicked);
    connect(m_timer, &QTimer::timeout, this, &TimerButton::onTimerTimeout);
    connect(m_updateTimer, &QTimer::timeout, this, &TimerButton::onUpdateTimerTimeout);
}
