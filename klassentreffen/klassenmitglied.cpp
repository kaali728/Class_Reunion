#include "klassenmitglied.h"
#include <iostream>


Klassenmitglied::Klassenmitglied(QString id, QString vorname,QString nachname,
                                 QString land,QString email,QString ort,QString plz)
                                : selected_id{id}, vorname{vorname}, nachname{nachname},
                                  land{land}, email{email}, ort{ort}, plz{plz}{
}


Klassenmitglied::~Klassenmitglied()
{

}

QString Klassenmitglied::getVorname() const
{
    return vorname;
}

void Klassenmitglied::setVorname(const QString &value)
{
    vorname = value;
}

QString Klassenmitglied::getNachname() const
{
    return nachname;
}

void Klassenmitglied::setNachname(const QString &value)
{
    nachname = value;
}

QString Klassenmitglied::getLand() const
{
    return land;
}

void Klassenmitglied::setLand(const QString &value)
{
    land = value;
}

QString Klassenmitglied::getEmail() const
{
    return email;
}

void Klassenmitglied::setEmail(const QString &value)
{
    email = value;
}

QString Klassenmitglied::getOrt() const
{
    return ort;
}

void Klassenmitglied::setOrt(const QString &value)
{
    ort = value;
}

QString Klassenmitglied::getPlz() const
{
    return plz;
}

void Klassenmitglied::setPlz(const QString &value)
{
    plz = value;
}

QStringList Klassenmitglied::getTel() const
{
    return tel;
}

void Klassenmitglied::setTel(const QStringList &value)
{
    tel = value;
}

QString Klassenmitglied::getSelected_id() const
{
    return selected_id;
}

void Klassenmitglied::setSelected_id(QString &value)
{
    selected_id = value;
}
