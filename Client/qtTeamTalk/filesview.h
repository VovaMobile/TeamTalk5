/*
 * Copyright (c) 2005-2018, BearWare.dk
 * 
 * Contact Information:
 *
 * Bjoern D. Rasmussen
 * Kirketoften 5
 * DK-8260 Viby J
 * Denmark
 * Email: contact@bearware.dk
 * Phone: +45 20 20 54 59
 * Web: http://www.bearware.dk
 *
 * This source code is part of the TeamTalk SDK owned by
 * BearWare.dk. Use of this file, or its compiled unit, requires a
 * TeamTalk SDK License Key issued by BearWare.dk.
 *
 * The TeamTalk SDK License Agreement along with its Terms and
 * Conditions are outlined in the file License.txt included with the
 * TeamTalk SDK distribution.
 *
 */

#ifndef FILESVIEW_H
#define FILESVIEW_H

#include "mytreeview.h"

#include <QTreeView>
#include <QList>

class FilesView : public MyTreeView
{
    Q_OBJECT
public:
    FilesView(QWidget* parent);

    QStringList selectedFiles();

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent* event) override;
    void dropEvent(QDropEvent* event) override;

signals:
    void filesSelected(bool);
    void uploadFiles(const QStringList& files);

public:
    void slotNewSelection(const QItemSelection & selected);
};
#endif
