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

#include "aboutdlg.h"
#include "appinfo.h"
#include "common.h"

AboutDlg::AboutDlg(QWidget* parent)
: QDialog(parent, QT_DEFAULT_DIALOG_HINTS)
{
    ui.setupUi(this);
    setWindowIcon(QIcon(APPICON));

    QString compile = QString(tr("Compiled on %1 %2 using Qt %3 (Qt %4 used by this instance).")).arg(__DATE__).arg(__TIME__).arg(QT_VERSION_STR).arg(qVersion()) + "\r\n" +
        tr("Version ") + (TEAMTALK_VERSION ".\r\n");
    if(sizeof(void*) == 8)
        compile += QString(tr("TeamTalk 64-bit DLL version %1.")).arg(_Q(TT_GetVersion()));
    else
        compile += QString(tr("TeamTalk 32-bit DLL version %1.")).arg(_Q(TT_GetVersion()));
    ui.compileLabel->setText(compile);
    ui.compileLabel->setAccessibleName(compile);
    ui.versionLabel->setText(APPVERSION);
    ui.versionLabel->setAccessibleName(APPVERSION);
    ui.iconLabel->setPixmap(QPixmap(APPICON));
}
