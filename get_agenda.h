#ifndef GET_AGENDA_H
#define GET_AGENDA_H

#include <QDialog>
#include "atendente.h"

namespace Ui {
class get_agenda;
}

class get_agenda : public QDialog
{
    Q_OBJECT

public:
    explicit get_agenda(QWidget *parent = nullptr);
    ~get_agenda();

private slots:
    void on_pushButton_clicked();

private:
    Ui::get_agenda *ui;
};

#endif // GET_AGENDA_H
