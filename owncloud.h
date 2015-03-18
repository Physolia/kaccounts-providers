/*************************************************************************************
 *  Copyright (C) 2012 by Alejandro Fiestas Olivares <afiestas@kde.org>              *
 *                                                                                   *
 *  This program is free software; you can redistribute it and/or                    *
 *  modify it under the terms of the GNU General Public License                      *
 *  as published by the Free Software Foundation; either version 2                   *
 *  of the License, or (at your option) any later version.                           *
 *                                                                                   *
 *  This program is distributed in the hope that it will be useful,                  *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of                   *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                    *
 *  GNU General Public License for more details.                                     *
 *                                                                                   *
 *  You should have received a copy of the GNU General Public License                *
 *  along with this program; if not, write to the Free Software                      *
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA   *
 *************************************************************************************/

#ifndef OWNCLOUD_H
#define OWNCLOUD_H

#include <QWizard>
#include <QUrl>

class OwnCloudWizard : public QWizard
{
    Q_OBJECT
    public:
        explicit OwnCloudWizard(QWidget* parent = 0, Qt::WindowFlags flags = 0);
        virtual ~OwnCloudWizard();

        virtual void done(int result);

        void setUsername(const QString &username);
        void setPassword(const QString &password);
        void setServer(const QUrl &server);

        const QString username() const;
        const QString password() const;
        const QUrl server() const;

        void activateOption(const QString& name, bool checked);

    Q_SIGNALS:
        void newAccount(const QString &type, const QString &name);

    private:
        QString m_username;
        QString m_password;
        QUrl m_server;

        QHash<QString, int> m_services;
};

#endif //OWNCLOUD_H