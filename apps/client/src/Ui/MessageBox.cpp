#include "MessageBox.hpp"

MessageBox::MessageBox(QWidget *parent)
    : QMessageBox(parent) {
    m_approveButton = this->addButton("Approve", QMessageBox::AcceptRole);
    m_rejectButton = this->addButton("Reject", QMessageBox::RejectRole);
    setDefaultButton(m_rejectButton);
    
    setupConnections();
}

void MessageBox::showMessageBox(const QString &title, const QString &message, const QString &approveButtonText, 
                                const QString &rejectButtonText, const QMessageBox::Icon &icon) {
    setWindowTitle(title);
    setText(message);
    setIcon(icon);
    
    m_approveButton->setText(approveButtonText);
    m_rejectButton->setText(rejectButtonText);
    m_rejectButton->show();
    
    exec();
}

void MessageBox::showErrorMessage(const QString &message) {
    setWindowTitle("Error");
    setText(message);
    setIcon(QMessageBox::Critical);

    m_rejectButton->hide();
    m_approveButton->setText("Ok");
    
    exec();
}

void MessageBox::showInformationMessage(const QString &title, const QString &message) {
    setWindowTitle(title);
    setText(message);
    setIcon(QMessageBox::Information);

    m_rejectButton->hide();
    m_approveButton->setText("Ok");
    
    exec();
}

void MessageBox::onApproveButtonClicked() {
    emit approveButtonClicked();
}

void MessageBox::onRejectButtonClicked() {
    emit rejectButtonClicked();
}

void MessageBox::setupConnections() {
    connect(m_approveButton, &QPushButton::clicked, this, &MessageBox::onApproveButtonClicked);
    connect(m_rejectButton, &QPushButton::clicked, this, &MessageBox::onRejectButtonClicked);
    connect(this, &QMessageBox::buttonClicked, this, [this] {
        emit anyAction();
    });
}