#ifndef LOGI_H
#define LOGI_H

#include <QTextBrowser>

class Logi : public QTextBrowser
{
private:
    static Logi *wsk;

public:
    Logi(QWidget *parent);
    Logi(const Logi &logi);
};

#endif // LOGI_H
