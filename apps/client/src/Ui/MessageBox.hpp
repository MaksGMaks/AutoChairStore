#pragma once

#include <QMessageBox>
#include <QPushButton>

class MessageBox :public QMessageBox {
    Q_OBJECT
public:
    explicit MessageBox(QWidget *parent = nullptr);
    virtual ~MessageBox() = default;
    
    void showMessageBox(const QString &title, const QString &message, const QString &approveButtonText, 
                        const QString &rejectButtonText, const QMessageBox::Icon &icon);

    void showErrorMessage(const QString &message);
    void showInformationMessage(const QString &title, const QString &message);

signals:
    void approveButtonClicked();
    void rejectButtonClicked();
    void anyAction();

private slots:
    void onApproveButtonClicked();
    void onRejectButtonClicked();

private:
    void setupConnections();
    
    QPushButton *m_approveButton;
    QPushButton *m_rejectButton;
};

