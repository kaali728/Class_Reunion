#ifndef KLASSENMITGLIED_H
#define KLASSENMITGLIED_H

#include <QString>
#include <QStringList>

class Klassenmitglied
{
public:
    Klassenmitglied(QString id, QString vorname,QString nachname,
                    QString land,QString email,QString ort,QString plz);
    ~Klassenmitglied();


    QString getSelected_id() const;
    void setSelected_id(QString &value);

    QString getVorname() const;
    void setVorname(const QString &value);

    QString getNachname() const;
    void setNachname(const QString &value);

    QString getLand() const;
    void setLand(const QString &value);

    QString getEmail() const;
    void setEmail(const QString &value);

    QString getOrt() const;
    void setOrt(const QString &value);

    QString getPlz() const;
    void setPlz(const QString &value);

    QStringList getTel() const;
    void setTel(const QStringList &value);

private:
    QString selected_id, vorname, nachname, land, email, ort, plz;
    QStringList tel;
};

#endif // KLASSENMITGLIED_H
