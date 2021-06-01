#ifndef QTKLASSENMITGLIEDDAO_H
#define QTKLASSENMITGLIEDDAO_H

#include "klassenmitglieddao.h"
#include <QtSql>

class QtKlassenmitgliedDAO: public KlassenmitgliedDAO
{
public:
    QtKlassenmitgliedDAO();
    ~QtKlassenmitgliedDAO();

    bool aktualisieren(Klassenmitglied &k);
    QSqlQuery auswaehlen(QString &n);
    bool einfuegen(Klassenmitglied &k);
    bool loeschen(QString &id);
    bool suchen(Klassenmitglied &k);
    bool telefonUpdate(QString &nummer, QString &id);
    bool loginCheck(QString &email, QString &password);
    QSqlQuery getAll();

};

#endif // QTKLASSENMITGLIEDDAO_H
