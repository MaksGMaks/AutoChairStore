#pragma once

#include <QWidget>

#include "Ui/ViewModels/IViewModel.hpp"
#include "Ui/MessageBox.hpp"

class IView : public QWidget {
    Q_OBJECT
public:
    IView(IViewModel *viewModel, QWidget *parent = nullptr);
    virtual ~IView() = default;

private:
    MessageBox *m_errorMessageBox;
private slots:
    void onErrorOccurred(const QString &errorMessage);

};